//
// Created by MYF on 3/25/2023.
//

#ifndef LEX_LEXRULE_H
#define LEX_LEXRULE_H



#include <iostream>
#include <regex>
#include <string>
#include <any>
#include <typeinfo>
#include <vector>

using namespace std;

// string fileName;//全局文件名称

//记录token的结构
//struct Token
struct MyToken {
    string type;   //保存类型，一般应为全大写。
                        //预置类型ignore（不返回，直接取下一个token）、error（不返回，控制台输出信息，取下一个token）、end（表示结束）
    any value;     //一般保存name即程序原文，但可以保存任何值
    int lin;            //行数
    int col;            //列数

};

// vector<Token> tokens;//记录token序列

class MyType {
public:
    // MyToken token;
    string type;
    string name;
    // any name;
    int linenum;
    vector<MyType*> children;

    MyType(){}
    // MyType(MyToken tok, string nam): token(tok), name(nam){}
    MyType(string str, string val, int line): type(str), name(val), linenum(line){}
    MyType(string nam, vector<MyType*> child): name(nam), children(child){}
};
#define YYSTYPE MyType*


//描述一个类型token的词法
class Lexis {
public:
    virtual std::string rule() = 0; //返回string形式的词法正则表达式

    virtual MyToken get_tok(std::string name, int lin, int col) = 0; //设置该类型token返回的内容
};

using LexRuls = std::vector<Lexis *>; //保存全部词法的类型

#endif //LEX_LEXRULE_H
