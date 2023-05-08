//
// Created by MYF on 3/25/2023.
//

#ifndef LEX_LEXER_H
#define LEX_LEXER_H

#define YYDEBUG 1

extern int yydebug;
#include "LexRule.h"
#include "fstream"
//词法分析器
class Lexer {
public:
    MyToken getToken(); //获取下一个token

    std::vector<MyToken> getTokenList(); //获取全部token

    bool setFile(std::string);//设置输入文件

    bool setRegex(LexRuls);//设置词法

private:
    int lin;//行号
    int col;//列号
    int pos;//当前分析位置
    std::string name;//token原文
    std::string data;//输入文件的内容
    LexRuls rules;//词法规则
};

//字符串处理
class Strdel {
public:
    static int getLFNum(std::string);//统计换行符数量
};


#endif //LEX_LEXER_H
