// #include "lexical.h"
#include "lexical.cpp"
#include <fstream>

// #include "yyheader.h"

#include "ASTnodes.h"
#include "ASTnodes.cpp"
#include "parseTree2AST.cpp"

#include "semanticAnalyse.cpp"
// #include "codeGenerate.cpp"

using namespace std;

extern MyType* ParseTreeHead;

extern int yydebug;

class _Program;
extern _Program* getProgram(MyType* now);


extern void SemanticAnalyse(_Program* ASTRoot);
// extern vector<string> semanticErrorInformation;

extern void codeGenerate(_Program *ASTRoot, string outName);

// extern FILE* yyin;

// extern Lexer yylexer;

void dfs(MyType *now);

template<class T>
void dfs1(T& input, int dep){
    string tmp = typeid(input).name();
    
    int firstSpaceIndex = tmp.find_first_of("_");
    string sub = tmp.substr(firstSpaceIndex);
    cout << sub << " " << dep << " ";
    if(sub == "_Program"){
        cout << ((_Program*)(input))->programId.first << endl;
        dfs1(((_Program*)input)->subProgram, dep+1);
    }
    if(sub == "_SubProgram"){
        vector<_Constant*> constList = ((_SubProgram*)input)->constList;
        for(int i=0; i<constList.size(); i++){
            dfs1(constList[i], dep+1);
        }
        vector<_Variant*> variantList = ((_SubProgram*)input)->variantList;
        for(int i=0; i<variantList.size(); i++){
            dfs1(variantList[i], dep+1);
        }
        vector<_FunctionDefinition*> subPro = ((_SubProgram*)input)->subprogramDefinitionList;
        for(int i=0; i<subPro.size(); i++){
            dfs1(subPro[i], dep+1);
        }
        dfs1(((_SubProgram*)input)->compound, dep+1);
    }
    if(sub == "_Constant"){
        cout << ((_Constant*)input)->type << endl;
    }
    if(sub == "_Variant"){
        dfs1(((_Variant*)input)->type, dep+1);
    }
    if(sub == "_FunctionDefinition"){
        vector<_FormalParameter*> formalParaList = ((_FunctionDefinition*)input)->formalParaList;
        for(int i=0; i< formalParaList.size(); i++){
            dfs1(formalParaList[i], dep+1);
        }
        vector<_Constant*> constList = ((_FunctionDefinition*)input)->constList;
        for(int i=0; i< constList.size(); i++){
            dfs1(constList[i], dep+1);
        }
        vector<_Variant*> variantList = ((_FunctionDefinition*)input)->variantList;
        for(int i=0; i< variantList.size(); i++){
            dfs1(variantList[i], dep+1);
        }
        dfs1(((_FunctionDefinition*)input)->compound, dep+1);
    }
    if(sub == "_Expression"){
        cout << ((_Expression*)input)->type << " " << dep+1 << endl;
    }
    if(sub == "_FunctionCall"){
        vector<_Expression*> actualParaList = ((_FunctionCall*)input)->actualParaList;
        for(int i=0; i<actualParaList.size(); i++){
            dfs1(actualParaList[i], dep+1);
        }
    }
    if(sub == "_VariantReference"){
        cout << ((_VariantReference*)input)->flag << " " << dep+1 << endl;
    }
    if(sub == "_Statement"){
        cout << ((_Statement*)input)->type << " " << dep+1 << endl;
    }
    if(sub == "_Compound"){
        vector<_Statement*> statementList = ((_Compound*)input)->statementList;
        for(int i=0; i<statementList.size(); i++){
            dfs1(statementList[i], dep+1);
        }
    }
    if(sub == "_RepeatStatement"){
        dfs1(((_RepeatStatement*)input)->condition, dep+1);
        dfs1(((_RepeatStatement*)input)->_do, dep+1);
    }
    if(sub == "_ForStatement"){
        dfs1(((_ForStatement*)input)->start, dep+1);
        dfs1(((_ForStatement*)input)->end, dep+1);
        dfs1(((_ForStatement*)input)->_do, dep+1);
    }
    if(sub == "_IfStatement"){
        dfs1(((_IfStatement*)input)->condition, dep+1);
        dfs1(((_IfStatement*)input)->then, dep+1);
        dfs1(((_IfStatement*)input)->els, dep+1);
    }
    if(sub == "_AssignStatement"){
        dfs1(((_AssignStatement*)input)->variantReference, dep+1);
        dfs1(((_AssignStatement*)input)->expression, dep+1);
    }
    if(sub == "_ProcedureCall"){
        vector<_Expression*> actualParaList = ((_ProcedureCall*)input)->actualParaList;
        for(int i=0; i<actualParaList.size(); i++){
            dfs1(actualParaList[i], dep+1);
        }
    }
    if(sub == "_Type"){
        cout << ((_Type*)input)->type.first << " " << dep+1 <<endl;
    }
    if(sub == "_FormalParameter"){
        cout << ((_FormalParameter*)input)->type << " " << dep+1 << endl;
    }

}

extern "C"{
    int yyparse();
}

int main(int argc, char** argv){
    yyLexer = yylex_init(argv[1]);
    
    yydebug = atoi(argv[2]);
    

    int ans = yyparse();

    yylex_exit();

    if(ParseTreeHead != NULL){
        dfs(ParseTreeHead);
    }
    else cout << "main:\tParseTreeHead is null" << endl;

    cout << endl;
    _Program* ASTRoot = getProgram(ParseTreeHead);
    cout << "main:\tAbstract Tree:" << endl;
    dfs1(ASTRoot, 1);



    SemanticAnalyse(ASTRoot);
    cout << "Errors:" << endl;
    for(int i=0; i<semanticErrorInformation.size(); i++){
        cout << semanticErrorInformation[i] << endl;
    }
    
    codeGenerate(ASTRoot, "test_5_7.c");

    delete ParseTreeHead;

    system("pause");

    //词法分析使用
    // lexical(argv[1]);
    // system("pause");
    return 0;
}

void dfs(MyType* now) {//遍历语法树
	if (now->children.size() == 0) {
		if (now->type == "")
		{
            cout << now->name << "\t->\t" << "empty" << endl;
        }

		return;
	}
	cout << now->name << "\t->";
    // cout << now->type << "\t->";
	for (int i = 0; i < now->children.size(); i++) {
		if (now->children[i]->children.size() == 0 && now->children[i]->type != "")
		{
            cout << "\t\"" << now->children[i]->name << "\"" << "(" << now->children[i]->type << ")";
            // cout << "\t\"" << now->children[i]->name << "\"" << "(" << now->children[i]->type << ")";
            //cout << "\t\"" << now->children[i]->type << "\"";
        }
		else{
            cout << "\t" << now->children[i]->name;
        }
			// cout << "\t" << now->children[i]->name;
	}
	cout << endl;
	for (int i = 0; i<now->children.size(); i++)
		dfs(now->children[i]);
}

