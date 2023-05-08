#include <iostream>
#include <regex>

#include <any>
#include "LexRule.h"
#include "PascalRul.h"
#include "Lexer.cpp"
#include "PascalRul.cpp"
#include "Lexer.h"

using namespace std;

// vector<Type> types;

vector<MyToken> lexical(string fileName);//原词法分析模块函数，在main中不直接调用

Lexer yyLexer;//词法调用器，执行语法分析时会调用

#define YYSTYPE MyType* //声明语法树类



R_ID *r1;//IDENTIFIER
R_NUM *r2;//NUM OR FLOAT
R_CHARACTER *r3;//CHARACTER
R_PAREN *r4;//()
R_SQUAR *r5;//[]
R_COMMENT *r6;//注释
R_COMMA *r7;//,
R_PERIOD *r8;//.
R_COLON *r9;//:
R_SEMICO *r10;//;
R_CALCUL *r11;//+ - * /
R_RELAT *r12;//< > = <= >= <>
R_IGNORE *r13;//可忽略的记号
R_SINGLE_QUOTES *r15;

Lexer yylex_init(char* fileName){//初始化
    Lexer tmpLexer;
    LexRuls rul;
    r1 = new R_ID;//关键字
    r2 = new R_NUM;//常数
    r3 = new R_CHARACTER;//字符
    r4 = new R_PAREN;//括号()
    r5 = new R_SQUAR;//括号[]
    r6 = new R_COMMENT;//注释
    r7 = new R_COMMA;//逗号
    r8 = new R_PERIOD;//句号
    r9 = new R_COLON;//冒号
    r10 = new R_SEMICO;//分号
    r11 = new R_CALCUL;//运算符
    r12 = new R_RELAT;//比较符
    r13 = new R_IGNORE;//忽略记号如\t
    r15 = new R_SINGLE_QUOTES;

    rul.push_back(r1);
    rul.push_back(r2);
    rul.push_back(r3);
    rul.push_back(r4);
    rul.push_back(r5);
    rul.push_back(r6);
    rul.push_back(r7);
    rul.push_back(r8);
    rul.push_back(r9);
    rul.push_back(r10);
    rul.push_back(r11);
    rul.push_back(r12);
    rul.push_back(r13);
    rul.push_back(r15);
    
    tmpLexer.setRegex(rul);//设置词法
    
    bool isFileOpened = tmpLexer.setFile("./" + (string)fileName);//设置读入的pascal-s文件
    if(!isFileOpened) cout << "yylex_init: File doesn't open" << endl;
    // vector<MyToken> tokens;
    // MyToken c = tmpLexer.getToken();
    // while (c.type != "end") {
    //     tokens.push_back(c);
    //     cout << "yylex_init: current type: " << c.type << endl;
    //     c = tmpLexer.getToken();
    // }

    // cout << "yylex_init:\tinitialized" << endl;

    // delete r1;
    // delete r2;
    // delete r3;
    // delete r4;
    // delete r5;
    // delete r6;
    // delete r7;
    // delete r8;
    // delete r9;
    // delete r10;
    // delete r11;
    // delete r12;
    // delete r13;

    return tmpLexer;
}

void yylex_exit(){//删除指针
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
    delete r13;
    delete r15;
}