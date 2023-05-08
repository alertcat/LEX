/*
普通语法分析树到抽象语法树的转换
*/
// #include "main.h"
#include "ASTnodes.h"
#include <algorithm>

#include "LexRule.h"

int str2int(string str);
float str2float(string str);
void getIdList(MyType *now, vector< pair<string, int> >& res,bool reverseFlag);
void getArrayRangeList(MyType *now, vector< pair<int, int> >& _arrayRangeList);
_Type* getType(MyType *now);
void getVariant(MyType *now, vector<_Variant*>& _variantList);
void getVariantList(MyType *now, vector<_Variant*>& _variantList);
void setConst(MyType *now, _Constant* &_constant);
void getConst(MyType *now, vector<_Constant*>& _constantList);
void getConstList(MyType *now, vector<_Constant*>& _constantList);
void getValueParameter(MyType *now, vector<_FormalParameter*>& _formalParaList, int flag = 0);
void getParameter(MyType *now, vector<_FormalParameter*>& _formalParaList);
void getFormalParameter(MyType *now, vector<_FormalParameter*>& _formalParaList);
void getFormalParaList(MyType *now, vector<_FormalParameter*>& _formalParaList);
void getSubprogramHead(MyType *now, pair<string, int>& functionID, vector<_FormalParameter*>& _formalParaList, pair<string,int> &_type);
_Expression* getFactor(MyType *now);
_Expression* getTerm(MyType *now);
_Expression* getSimpleExpression(MyType *now);
_Expression* getExpression(MyType *now);
void getExpressionList(MyType *now, vector<_Expression*>& _expressionList);
void getVariantReferenceList(MyType *now, vector<_Expression*>& _expressionList);
_VariantReference* getVariantReference(MyType *now);
_Statement* getElseStatement(MyType *now);
_Statement* getProcedureCall(MyType *now);
_Statement* getStatement(MyType *now);
void getStatementList(MyType *now, vector<_Statement*>& _statementList);
_Compound* getCompoundStatement(MyType *now);
void getSubprogramBody(MyType *now, vector<_Constant*>& _constList, vector<_Variant*>& _variantList, _Compound* &_compound);
_FunctionDefinition* getSubprogramDefinition(MyType *now);
void getSubprogramDefinitionList(MyType *now, vector<_FunctionDefinition*>& _subprogramDefinitionList);
_SubProgram* getProgramBody(MyType *now);
void getProgramHead(MyType *now, pair<string, int>& _programId, vector< pair<string, int> >& _paraList);
_Program* getProgram(MyType *now);

int str2int(string str){
    int res=0;
    int len=int(str.length());
    for(int i=0;i<len;i++){
        res=res*10;
        res+=str[i]-'0';
    }
    return res;
}

float str2float(string str){
    float res=0;
    int len=int(str.length());
    int loc=int(str.find('.'));
    for(int i=0;i<loc;i++){
        res*=10;
        res+=str[i]-'0';
    }
    float base=1;
    for(int i=loc+1;i<len;i++){
        base=base*0.1;
        res+=base*(str[i]-'0');
    }
    return res;
}

void getIdList(MyType *now,vector< pair<string,int> >& res,bool reverseFlag){
    cout << "getIdList";
    if(now == nullptr){
        cout << "\tnow is null" << endl;
        return;
    }
    if(now->name!="idlist"){
        cout << "\t" <<now->name << " is not idlist." << endl;
        return;
    }
    if(now->children[0]->type==""){
        cout << "\t" <<now->children[0]->name <<" is not Terminate." << endl;
        res.push_back(make_pair(now->children[2]->name,now->children[2]->linenum));
         
        getIdList(now->children[0],res,reverseFlag);
    }
    else{
        cout << "\t" <<now->children[0]->name <<" is Terminate." << endl;
        res.push_back(make_pair(now->children[0]->name,now->children[0]->linenum));
		if(reverseFlag)
			reverse(res.begin(),res.end());
    }

}

void getArrayRangeList(MyType *now,vector< pair<int,int> >& _arrayRangeList){
    cout << "getArrayRangeList" << endl;
    if(now->name!="."){
        cout << "getArrayRangeList error" << endl;
        return;
    }
    int loc=int(now->children.size()-3);
    _arrayRangeList.push_back(make_pair(str2int(now->children[loc]->name),str2int(now->children[loc+2]->name)));
    if(loc==2)
    {
         
        getArrayRangeList(now->children[0],_arrayRangeList);}
    else
        reverse(_arrayRangeList.begin(),_arrayRangeList.end());
}

_Type* getType(MyType *now){
    cout << "getType" << endl;
    if(now->name!="type"){
        cout << "getType error" << endl;
        return NULL;
    }
    _Type* _type = new _Type;
    int loc=int(now->children.size()-1);
    cout << "GETTYPE: " << now->children[loc]->children[0]->name << endl;
    _type->type=make_pair(now->children[loc]->children[0]->name, now->children[loc]->linenum);
     
    // _type->type=make_pair(now->children[loc]->name,now->children[loc]->linenum);
    if(loc==5){
        _type->flag=1;
         
        getArrayRangeList(now->children[2],_type->arrayRangeList);
    }
    else
        _type->flag=0;
    return _type;
}

void getVariant(MyType *now,vector<_Variant*>& _variantList){
    cout << "getVariant" << endl;
    if(now->name!="var_declaration"){
        cout << "getVariant error" << endl;
        return;
    }
    vector< pair<string,int> > _idList;
    int loc=int(now->children.size()-3);
     
    getIdList(now->children[loc],_idList,false);
     
    _Type* _type=getType(now->children[loc+2]);
    for(int i=0;i<_idList.size();i++)
        _variantList.push_back(new _Variant(_idList[i], _type));
    if(loc==2)
    {
         
        getVariant(now->children[0],_variantList);}
    else
        reverse(_variantList.begin(),_variantList.end());
}

void getVariantList(MyType *now,vector<_Variant*>& _variantList){
    cout << "getVariantList" << endl;
    if(now->name!="var_declarations"){
        cout << "getVariantList error" << endl;
        return;
    }
    if(now->children.size())
    {
         
        getVariant(now->children[1],_variantList);}
}

void setConst(MyType *now,_Constant* &_constant){//pascal在定义常量时，并没有指定常量的类型，所以需要自行判断
    cout << "setConst" << endl;
    if(now->name!="const_value"){
        cout << "setConst error" << endl;
        return;
    }
    int loc=1;
    if(now->children.size()==1)
        loc=0;
    if(now->children[loc]->type=="IDENTIFIER"){//如果右值是标识符
        _constant->type="id";
        _constant->valueId = make_pair(now->children[loc]->name,now->children[loc]->linenum);
		_constant->strOfVal = now->children[loc]->type;
		_constant->isMinusShow = (loc == 1 && now->children[0]->name == "-");
    }
    else if(now->children[loc]->type=="INT"){
        _constant->type="integer";
        _constant->intValue=str2int(now->children[loc]->type);
		_constant->strOfVal = now->children[loc]->type;
		_constant->isMinusShow = (loc == 1 && now->children[0]->name == "-");
    }
    else if(now->children[loc]->type=="FLOAT"){
        _constant->type="real";
        
        _constant->realValue=str2float(now->children[loc]->type);
		_constant->strOfVal = now->children[loc]->type;
		_constant->isMinusShow = (loc == 1 && now->children[0]->name == "-");
    }
    else if(now->children[loc]->type=="CHARACTER"){
        _constant->type="char";
        _constant->charValue=now->children[loc]->type[0];
		_constant->strOfVal = now->children[loc]->type;
    }
    else{
        cout << "setConst error" << endl;
    }
}

void getConst(MyType *now,vector<_Constant*>& _constantList){
    cout << "getConst" << endl;
    if(now->name!="const_declaration"){
        cout << "getConst error" << endl;
        return;
    }
    int loc=int(now->children.size()-3);
    _Constant* _constant=new _Constant;
    _constant->constId=make_pair(now->children[loc]->name,now->children[loc]->linenum);
     
    setConst(now->children[loc+2],_constant);
    _constantList.push_back(_constant);
    if(loc==2)
    {
         
        getConst(now->children[0],_constantList);}
    else
    {
         
        reverse(_constantList.begin(),_constantList.end());}
}

void getConstList(MyType *now,vector<_Constant*>& _constantList){
    cout << "getConstList" << endl;
    if(now->name!="const_declarations"){
        cout << "getConstList error" << endl;
        return;
    }
    if(now->children.size())
    {
         
        getConst(now->children[1],_constantList);}
}

void getValueParameter(MyType *now,vector<_FormalParameter*>& _formalParaList,int flag){
    cout << "getValuePatameter" << endl;
    if(now->name!="value_parameter"){
        cout << "getValueParameter error" << endl;
        return;
    }
    vector< pair<string,int> > _idList;
     
    getIdList(now->children[0],_idList,false);
    string _type=now->children[2]->type;
    for(int i=0;i<_idList.size();i++)
        _formalParaList.push_back(new _FormalParameter(_idList[i],_type,flag));
}

void getParameter(MyType *now,vector<_FormalParameter*>& _formalParaList){
    cout << "getParameter" << endl;
    if(now->name!="parameter"){
        cout << "getParameter error" << endl;
        return;
    }
    if(now->children[0]->name=="var_parameter")
    {
         
        getValueParameter(now->children[0]->children[1],_formalParaList,1);}
    else if(now->children[0]->name=="value_parameter")
    {
         
        getValueParameter(now->children[0],_formalParaList,0);}
    else
    {
         
        cout << "getParameter error" << endl;}
}

void getFormalParameter(MyType *now,vector<_FormalParameter*>& _formalParaList){
    cout << "getFormalParameter" << endl;
    if(now->name!="parameter_list"){
        cout << "getFormalParameter error" << endl;
        return;
    }
    int loc=int(now->children.size()-1);
     
    getParameter(now->children[loc],_formalParaList);
    if(loc==2)
    {
         
        getFormalParameter(now->children[0],_formalParaList);
    }
    else
    {
         
        reverse(_formalParaList.begin(),_formalParaList.end());
    }
}

void getFormalParaList(MyType *now,vector<_FormalParameter*>& _formalParaList){
    cout << "getFormalParaList" << endl;
    if(now->name!="formal_parameter"){
        cout << "getFormalParaList error" << endl;
        return;
    }
    if(now->children.size())
    {
         
        getFormalParameter(now->children[1],_formalParaList);
    }
}

void getSubprogramHead(MyType *now,pair<string,int>& functionID,vector<_FormalParameter*>& _formalParaList,pair<string,int> &_type){
    cout << "getSubprogramHead" << endl;
    if(now->name!="subprogram_head"){
        cout << "getSubprogramHead error" << endl;
        return;
    }
    functionID=make_pair(now->children[1]->name,now->children[1]->linenum);
     
    getFormalParaList(now->children[2],_formalParaList);
	_type=make_pair("",-1);
    if (now->children.size() == 5) 
		_type = make_pair(now->children[4]->name, now->children[4]->linenum);
}

//"var"表示变量,"integer"表示整数,"real"表示浮点数,"char"表示字符常量
//"function"表示函数调用,"compound"表示复合表达式
//compound有普通的二目运算符，还有minus、not、bracket等单目运算符
_Expression* getFactor(MyType *now){
    cout << "getFactor" << endl;
    if(now->name!="factor"){
        cout << "getFactor error" << endl;
		return NULL;
    }
    _Expression* _expression = new _Expression;
    _expression->operand1=_expression->operand2=NULL;
    if(now->children[0]->type=="INT"){
        _expression->type="integer";
		_expression->strOfNum = now->children[0]->type;
         
        _expression->intNum=str2int(now->children[0]->type);
        _expression->lineNumber=now->children[0]->linenum;
    }
    else if(now->children[0]->type=="FLOAT"){
        _expression->type="real";
		_expression->strOfNum = now->children[0]->type;
         
        _expression->realNum=str2float(now->children[0]->type);
        _expression->lineNumber=now->children[0]->linenum;
    }
    else if(now->children[0]->name=="variable"){
        _expression->type="var";
         
        _expression->variantReference=getVariantReference(now->children[0]);
		_expression->lineNumber = _expression->variantReference->variantId.second;
    }
    else if(now->children[0]->type=="IDENTIFIER"){
        _expression->type="function";
        _expression->functionCall = new _FunctionCall;
        _expression->functionCall->functionId=make_pair(now->children[0]->name,now->children[0]->linenum);
         
        getExpressionList(now->children[2],_expression->functionCall->actualParaList);
		_expression->lineNumber = _expression->functionCall->functionId.second;
    }
    else if(now->children[0]->name=="("){
        _expression->type="compound";
		_expression->operationType = "single";
        _expression->operation="bracket";
         
        _expression->operand1=getExpression(now->children[1]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
    else if(now->children[0]->name=="NOT"){
        _expression->type="compound";
		_expression->operationType = "single";
        _expression->operation="not";
         
        _expression->operand1=getFactor(now->children[1]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
    else if(now->children[0]->name.find("-")){
        _expression->type="compound";
		_expression->operationType = "single";
        _expression->operation="minus";
         
        _expression->operand1=getFactor(now->children[1]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
	else if (now->children[0]->name == "CHAR") {
		_expression->type = "char";
		_expression->charVal = now->children[0]->type[0];
		_expression->lineNumber = now->children[0]->linenum;
	}
    else{
        cout << "getFactor error" << endl;
        return NULL;
    }
    return _expression;
}

_Expression* getTerm(MyType *now){
    cout << "getTerm" << endl;
    if(now->name!="term"){
        cout << "term" << endl;
		return NULL;
    }
    _Expression* _expression=NULL;
    if(now->children.size()==3){
        _expression = new _Expression;
        _expression->type="compound";
        _expression->operation=now->children[1]->type;
        _expression->operationType="mulop";
         
        _expression->operand1=getTerm(now->children[0]);
         
        _expression->operand2=getFactor(now->children[2]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
    else
    {
         
        _expression=getFactor(now->children[0]);
    }
    return _expression;
}

_Expression* getSimpleExpression(MyType *now){
    cout << "getSimpleExpression" << endl;
    if(now->name!="simple_expression"){
        cout << "getSimpleExpression error" << endl;
		return NULL;
    }
    _Expression* _expression=NULL;
    if(now->children.size()==3){
        _expression = new _Expression;
        _expression->type="compound";
        _expression->operation=now->children[1]->type;
        _expression->operationType="addop";
         
        _expression->operand1=getSimpleExpression(now->children[0]);
         
        _expression->operand2=getTerm(now->children[2]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
    else
        _expression=getTerm(now->children[0]);
    return _expression;
}

_Expression* getExpression(MyType *now){
    cout << "getExpression" << endl;
    if(now->name!="expression"){
        cout << "getExpression error" << endl;
		return NULL;
    }
    _Expression* _expression=NULL;
    if(now->children.size()==3){
        _expression = new _Expression;
        _expression->type="compound";
        _expression->operation=now->children[1]->type;
        _expression->operationType="relop";
         
        _expression->operand1=getSimpleExpression(now->children[0]);
         
        _expression->operand2=getSimpleExpression(now->children[2]);
		_expression->lineNumber = _expression->operand1->lineNumber;
    }
    else
    {
         
        _expression=getSimpleExpression(now->children[0]);
    }
    return _expression;
}

void getExpressionList(MyType *now,vector<_Expression*>& _expressionList){
    cout << "getExpressionList" << endl;
    if(now->name!="expression_list"){
        cout << "getExpressionList error" << endl;
        return;
    }
    int loc=int(now->children.size()-1);
     
    _expressionList.push_back(getExpression(now->children[loc]));
    if(loc==2)
    {
         
        getExpressionList(now->children[0],_expressionList);
    }
    else
        reverse(_expressionList.begin(),_expressionList.end());
}

void getVariantReferenceList(MyType *now,vector<_Expression*>& _expressionList){
    cout << "getVariantReferenceList" << endl;
    if(now->name!="id_varpart"){
        cout << "getVariantReferenceList error" << endl;
        return;
    }
    if(now->children.size())
    {
         
        getExpressionList(now->children[1],_expressionList);
    }
}

_VariantReference* getVariantReference(MyType *now){
    cout << "getVariantReference" << endl;
    if(now->name!="variable"){
        cout << "getVariantReference error" << endl;
		return NULL;
    }
    _VariantReference* _variantReference = new _VariantReference;
    _variantReference->variantId=make_pair(now->children[0]->name,now->children[0]->linenum);
     
    getVariantReferenceList(now->children[1],_variantReference->expressionList);
	if (_variantReference->expressionList.size())
		_variantReference->flag = 1;
	else
		_variantReference->flag = 0;
    return _variantReference;
}

_Statement* getElseStatement(MyType *now){
    cout << "getElseStatement" << endl;
    if(now->name!="else_part"){
        cout << "getElseStatement error" << endl;
        return NULL;
    }
    if(now->children.size()==0)
        return NULL;
     
    return getStatement(now->children[1]);
}

_Statement* getProcedureCall(MyType *now) {
    cout << "getProcedureCall" << endl;
	if (now->name != "procedure_call") {
		cout << "getProcedureCall error" << endl;
		return NULL;
	}
	_ProcedureCall *_procedureCall = new _ProcedureCall;
	_procedureCall->lineNumber = now->children[0]->linenum;
	_procedureCall->type = "procedure";
	_procedureCall->procedureId = make_pair(now->children[0]->name, now->children[0]->linenum);
	if (now->children.size() == 4)
    {
         
		getExpressionList(now->children[2], _procedureCall->actualParaList);
    }
	return _procedureCall;
}

_Statement* getStatement(MyType *now){
    cout << "getStatement" << endl;
    if(now->name!="statement"){
        cout << "getStatement error" << endl;
        return NULL;
    }
	if (now->children.size() == 0)
		return NULL;
    if(now->children[0]->name=="variable"){
        _AssignStatement *_assignStatement = new _AssignStatement;
		_assignStatement->lineNumber = now->children[1]->linenum;
        _assignStatement->type="assign";
         
        _assignStatement->variantReference=getVariantReference(now->children[0]);
         
        _assignStatement->expression=getExpression(now->children[2]);
        return _assignStatement;
    }
    else if(now->children[0]->name=="procedure_call")
    {
         
		return getProcedureCall(now->children[0]);
    }
    else if(now->children[0]->name=="compound_statement")
    {
         
		return getCompoundStatement(now->children[0]);
    }
    else if(now->children[0]->name=="IF"){
        _IfStatement* _ifStatement = new _IfStatement;
		_ifStatement->lineNumber = now->children[0]->linenum;
        _ifStatement->type="if";
         
        _ifStatement->condition=getExpression(now->children[1]);
         
        _ifStatement->then=getStatement(now->children[3]);
         
        _ifStatement->els=getElseStatement(now->children[4]);
        return _ifStatement;
    }
    else if(now->children[0]->name=="FOR"){
        _ForStatement* _forStatement = new _ForStatement;
		_forStatement->lineNumber = now->children[0]->linenum;
        _forStatement->type="for";
        _forStatement->id=make_pair(now->children[1]->name,now->children[1]->linenum);
         
        _forStatement->start=getExpression(now->children[3]);
         
        _forStatement->end=getExpression(now->children[5]);
         
        _forStatement->_do=getStatement(now->children[7]);
        return _forStatement;
    }
    // else if(now->children[0]->name=="WHILE"){
    //     _WhileStatement* _whileStatement = new _WhileStatement;
	// 	_whileStatement->lineNumber = now->children[0]->linenum;
    //     _whileStatement->type="while";
    //     _whileStatement->condition=getExpression(now->children[1]);
    //     _whileStatement->_do=getStatement(now->children[3]);
    //     return _whileStatement;
    // }
    // else if(now->children[0]->name=="REPEAT"){
    //     _RepeatStatement* _repeatStatement = new _RepeatStatement;
	// 	_repeatStatement->lineNumber = now->children[0]->linenum;
    //     _repeatStatement->type="repeat";
    //     _repeatStatement->condition=getExpression(now->children[3]);
    //     _repeatStatement->_do=getStatement(now->children[1]);
    //     return _repeatStatement;
    // }
    else{
        cout << "[getStatement] statement token error" << endl;
        return NULL;
    }
}

void getStatementList(MyType *now,vector<_Statement*>& _statementList){
    cout << "getStatementList" << endl;
    if(now->name!="statement_list"){
        cout << "getStatementList error" << endl;
        return;
    }
    int loc=int(now->children.size()-1);
     
	_Statement* statement = getStatement(now->children[loc]);
	if(statement != NULL)
		_statementList.push_back(statement);
    if(loc==2)
    {
         
        getStatementList(now->children[0],_statementList);
    }
    else
    {
         
        reverse(_statementList.begin(),_statementList.end());
    }
}

_Compound* getCompoundStatement(MyType *now){
    cout << "getCompoundStatement" << endl;
    if(now->name!="compound_statement"){
        cout << "getCompoundStatement error" << endl;
        return NULL;
    }
	_Compound *_compound = new _Compound;
	_compound->lineNumber = now->children[0]->linenum;
	_compound->type = "compound";
     
    getStatementList(now->children[1],_compound->statementList);
    return _compound;
}

void getSubprogramBody(MyType *now,vector<_Constant*>& _constList,vector<_Variant*>& _variantList,_Compound* &_compound){
    cout << "getSubprogramBody" << endl;
    if(now->name!="subprogram_body"){
        cout << "getSubprogramBody error" <<endl;
        return;
    }
     
    getConstList(now->children[0],_constList);
     
    getVariantList(now->children[1],_variantList);
     
	_compound = getCompoundStatement(now->children[2]);
}

_FunctionDefinition* getSubprogramDefinition(MyType *now){
    cout << "getSubprogramDefinition" << endl;
    if(now->name!="subprogram"){
        cout << "getSubprogramDefinition error" << endl;
        return NULL;
    }
    _FunctionDefinition *_functionDefinition=new _FunctionDefinition;
     
    getSubprogramHead(now->children[0],_functionDefinition->functionID,_functionDefinition->formalParaList,_functionDefinition->type);
     
    getSubprogramBody(now->children[2],_functionDefinition->constList,_functionDefinition->variantList,_functionDefinition->compound);
    return _functionDefinition;
}

void getSubprogramDefinitionList(MyType *now,vector<_FunctionDefinition*>& _subprogramDefinitionList){
    cout << "getSubprogramDefinitionList" << endl;
    if(now->name!="subprogram_declarations"){
        cout << "getSubprogramDefinitionList error" << endl;
        return;
    }
	if (now->children.size()) {
         
		_subprogramDefinitionList.push_back(getSubprogramDefinition(now->children[1]));
         
		getSubprogramDefinitionList(now->children[0], _subprogramDefinitionList);
	}
    else
        reverse(_subprogramDefinitionList.begin(),_subprogramDefinitionList.end());
}

_SubProgram* getProgramBody(MyType *now){
    cout << "getProgramBody" << endl;
    if(now->name!="program_body"){
        cout << "getProgramBody error" << endl;
        return NULL;
    }
    _SubProgram *_subProgram=new _SubProgram;
     
    getConstList(now->children[0],_subProgram->constList);
     
    getVariantList(now->children[1],_subProgram->variantList);
     
    getSubprogramDefinitionList(now->children[2],_subProgram->subprogramDefinitionList);
     
	_subProgram->compound = getCompoundStatement(now->children[3]);
    return _subProgram;
}

void getProgramHead(MyType *now,pair<string,int>& _programId,vector< pair<string,int> >& _paraList){
    cout << "getProgramHead" << endl;
    if(now->name!="program_head"){
        cout << "\tgetProgramHead error!" << endl;
        return; 
    }
    _programId=make_pair(now->children[1]->name,now->children[1]->linenum);
    // cout << "\t_programId defined." << endl;
    if(now->children.size() != 2)
    {
         
        getIdList(now->children[3], _paraList, true);
        // cout << "\tfinished getIdList." << endl;
    }
}

_Program* getProgram(MyType *now){
    cout << "getProgram" << endl;
    if(now->name!="programstruct"){
        cout << "getProgram error" << endl;
        return NULL;
    }
    _Program* ASTRoot=new _Program;
    // cout << "\tASTRoot defined." << "\tProgramHead.children.size() = " << now->children[0]->children.size() << endl;
     
    getProgramHead(now->children[0],ASTRoot->programId,ASTRoot->paraList);
    // cout << "\tfinished getProgramHead." << endl;
     
    ASTRoot->subProgram=getProgramBody(now->children[2]);
    return ASTRoot;
}