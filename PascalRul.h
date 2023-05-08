//
// Created by MYF on 3/25/2023.
//

#ifndef LEX_PASCALRUL_H
#define LEX_PASCALRUL_H
/*
 * 定义pascal词法，所有类均继承自lexis，
 * 并重载了rule（）、get_tok（）函数。
 *
 * rule（）函数返回该类型token的string形式词法正则表达式
 *
 * get_tok（）函数输入参数：（string）name，（int）lin，（int）col
 *     name：该token在程序原文中的string
 *     lin：行位置
 *     col：列位置
 * 返回值：Token类型
 * 说明：在函数中可以根据name设置token的不同type值，
 *      value值通常为name，但可以为任何值，可以利用其保存常数具体值
 */
#include "LexRule.h"

class R_ID : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_NUM : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_CHARACTER : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_PAREN : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_SQUAR : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_COMMENT : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_COMMA : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_PERIOD : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_COLON : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_SEMICO : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_CALCUL : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

class R_RELAT : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};

// class R_ASSIGN : public Lexis {
//     std::string rule() override;

//     Token get_tok(std::string, int, int) override;
// };

class R_IGNORE : public Lexis {
    std::string rule() override;

    MyToken get_tok(std::string, int, int) override;
};


class R_SINGLE_QUOTES : public Lexis{
    string rule() override;

    MyToken get_tok(string, int, int) override;
};


#endif //LEX_PASCALRUL_H
