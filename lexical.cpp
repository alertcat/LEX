//
// Created by MYF LSJ on 4/19/2023.
//


#include "lexical.h"
#include "yacc.tab.h"
#include <string>

/*
  typedef Token(*LexRulFc)(std::string, int, int);

  typedef std::tuple<std::string, LexRulFc> LexRul;
*/

vector<MyToken> lexical(string fileName) {
    Lexer lexer;
    LexRuls rul;
    R_ID *r1 = new R_ID;//关键字
    rul.push_back(r1);
    R_NUM *r2 = new R_NUM;//常数
    rul.push_back(r2);
    R_CHARACTER *r3 = new R_CHARACTER;//字符
    rul.push_back(r3);
    R_PAREN *r4 = new R_PAREN;//括号()
    rul.push_back(r4);
    R_SQUAR *r5 = new R_SQUAR;//括号[]
    rul.push_back(r5);
    R_COMMENT *r6 = new R_COMMENT;//注释
    rul.push_back(r6);
    R_COMMA *r7 = new R_COMMA;//逗号
    rul.push_back(r7);
    R_PERIOD *r8 = new R_PERIOD;//句号
    rul.push_back(r8);
    R_COLON *r9 = new R_COLON;//冒号
    rul.push_back(r9);
    R_SEMICO *r10 = new R_SEMICO;//分号
    rul.push_back(r10);
    R_CALCUL *r11 = new R_CALCUL;//运算符
    rul.push_back(r11);
    R_RELAT *r12 = new R_RELAT;//比较符
    rul.push_back(r12);
    // R_ASSIGN *r13 = new R_ASSIGN;//赋值符:=
    // rul.push_back(r13);
    R_IGNORE *r14 = new R_IGNORE;//忽略记号如\t
    rul.push_back(r14);


    lexer.setRegex(rul);//设置词法
    // lexer.setFile(fileName);//设置读入的pascal-s文件
    bool isFileOpened = lexer.setFile("./" + fileName);//设置读入的pascal-s文件
    if(!isFileOpened) cout << "yylex_init: File doesn't open" << endl;
    cout << "LEX:" << endl;
    MyToken c = lexer.getToken();

    // vector<Type> types;

    vector<MyToken> tokens;
    // tokens.push_back(c);
    int p = 0;
    while (c.type != "end") {
        // yylval = new MyType;
        // yylval->type = c.type;
        // types.push_back(tmp);
        tokens.push_back(c);
        string test;
        std::cout << c.type << " ";
        if (c.value.type() == typeid(std::string))//类型是字符串
        {
            // yylval->name = any_cast<string>(c.value);
            // test = any_cast<string>(c.value);
            std::cout << "\t\t\t" << std::any_cast<std::string>(c.value) << " ";
        }
        else if (c.value.type() == typeid(int))//类型是整数
        {
            // test = any_cast<int>(c.value);
            // yylval->name = any_cast<int>(c.value);
            std::cout << "\t\t\t" << std::any_cast<int>(c.value) << " ";
        }
        else if (c.value.type() == typeid(float))//类型是浮点数
        {
            // test = any_cast<float>(c.value);
            // yylval->name = any_cast<float>(c.value);
            std::cout << "\t\t\t" << std::any_cast<float>(c.value) << " ";
        }
        // cout << "lexical: test is:" << test << endl;
        // yylval->linenum = c.lin;
        std::cout << c.lin << ' '
                  << c.col << std::endl;
        c = lexer.getToken();
        p++;
    }
    // getchar();
    cout << "lexical: token num = " << p << endl;


    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    delete r6;
    delete r7;
    delete r8;
    delete r9;
    delete r10;
    delete r11;
    delete r12;
    // delete r13;
    delete r14;

    return tokens;
}

