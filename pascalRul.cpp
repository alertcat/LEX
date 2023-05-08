//
// Created by MYF on 3/25/2023.
//
#include "PascalRul.h"

using namespace std;

std::string R_ID::rule() {
    return R"([a-zA-Z][a-zA-Z0-9]*)";
}

MyToken R_ID::get_tok(std::string name, int lin, int col) {
    std::map<std::string, std::string> reserved = {
            //关键字
            {"array",     "ARRAY"},
            {"begin",     "_BEGIN"},
            {"const",     "CONST"},
            {"else",      "ELSE"},
            {"do",        "DO"},
            {"end",       "END"},
            {"for",       "FOR"},
            {"function",  "FUNCTION"},
            {"if",        "IF"},
            {"not",       "NOT"},
            {"of",        "OF"},
            {"procedure", "PROCEDURE"},
            {"program",   "PROGRAM"},
            {"then",      "THEN"},
            {"to",        "TO"},
            {"type",      "TYPE"},
            {"var",       "VAR"},
            {"read",      "READ"},
            {"write",     "WRITE"},
            {"uminus",    "UMINUS"},
            //运算符
            {"and",       "AND"},
            {"div",       "DIV"},
            {"mod",       "MOD"},
            {"or",        "OR"},
            //基本类型
            {"integer",   "INTEGER"},
            {"real",      "REAL"},
            {"char",      "CHAR"},
            {"boolean",   "BOOLEAN"}
    };
    auto word = reserved.find(name);
    if (word == reserved.end())
        return {(std::string) "IDENTIFIER", name, lin, col};
    else
        return {word->second, name, lin, col};
}

std::string R_NUM::rule() {
    return R"([+-]?([1-9]\d*|0)(\.\d+)?)";
}

MyToken R_NUM::get_tok(std::string name, int lin, int col) {
    if (name.find('.') != name.npos)
        return {(std::string) "FLOAT", std::stof(name), lin, col};  
    return {(std::string) "INT", std::stof(name), lin, col};
}


std::string R_CHARACTER::rule() {
    return R"(\'(\\[abfnrtv\'\"\\0]|[\S ])\')";
}

MyToken R_CHARACTER::get_tok(std::string name, int lin, int col) {
    return {(std::string) "CHARACTER", name.substr(1, name.size()-2), lin, col};
}

std::string R_PAREN::rule() {
    return R"(\(|\))";
}

MyToken R_PAREN::get_tok(std::string name, int lin, int col) {
    if ("(" == name)
        return {(std::string) "LPAREN", name, lin, col};
    else if (")" == name)
        return {(std::string) "RPAREN", name, lin, col};
    return {(std::string) "error", name, lin, col};
}

std::string R_SQUAR::rule() {
    return R"(\[|\])";
}

MyToken R_SQUAR::get_tok(std::string name, int lin, int col) {
    if ("[" == name)
        return {(std::string) "LSQUAR", name, lin, col};
    else if ("]" == name)
        return {(std::string) "RSQUAR", name, lin, col};
    return {(std::string) "error", name, lin, col};
}

std::string R_COMMENT::rule() {//注释
    return R"(\{(.|\n)*\})";
}

MyToken R_COMMENT::get_tok(std::string name, int lin, int col) {
    return {(std::string) "ignore", name, lin, col};
}

std::string R_COMMA::rule() {
    return R"(\,)";
}

MyToken R_COMMA::get_tok(std::string name, int lin, int col) {
    return {(std::string) "COMMA", name, lin, col};
}

std::string R_PERIOD::rule() {
    // return R"((\.)+)";
    return R"(\.+)";
}

MyToken R_PERIOD::get_tok(std::string name, int lin, int col) {
    if(name == "..") return {(string) "RANGEDOT", name, lin, col};
    return {(std::string) "PERIOD", name, lin, col};
}



std::string R_SEMICO::rule() {
    return R"(\;)";
}

MyToken R_SEMICO::get_tok(std::string name, int lin, int col) {
    return {(std::string) "SEMICO", name, lin, col};
}

std::string R_CALCUL::rule() {
    return R"(\+|\-|\*|/)";
}

MyToken R_CALCUL::get_tok(std::string name, int lin, int col) {
    if ("+" == name)
        return {(std::string) "ADD", name, lin, col};
    else if ("-" == name)
        return {(std::string) "SUB", name, lin, col};
    else if ("*" == name)
        return {(std::string) "MULT", name, lin, col};
    else if ("/" == name)
        return {(std::string) "DIVIDE", name, lin, col};
    return {(std::string) "error", name, lin, col};
}

std::string R_RELAT::rule() {
    return R"(<=|>=|<>|<|>|=)";
}

MyToken R_RELAT::get_tok(std::string name, int lin, int col) {
    if ("<=" == name)
        return {(std::string) "LESSEQ", name, lin, col};
    else if (">=" == name)
        return {(std::string) "MOREEQ", name, lin, col};
    else if ("<>" == name)
        return {(std::string) "NOTEQ", name, lin, col};
    else if ("<" == name)
        return {(std::string) "LESS", name, lin, col};
    else if (">" == name)
        return {(std::string) "MORE", name, lin, col};
    else if ("=" == name)
        return {(std::string) "EQUAL", name, lin, col};
    return {(std::string) "error", name, lin, col};
}

// std::string R_ASSIGN::rule() {
//     return R"((:=))";
// }

// Token R_ASSIGN::get_tok(std::string name, int lin, int col) {
//     return {(std::string) "ASSIGN", name, lin, col};
// }

std::string R_COLON::rule() {
    return R"(\:=*)";
}

MyToken R_COLON::get_tok(std::string name, int lin, int col) {
    if(name == ":=")
        return {(std::string) "ASSIGN", name, lin, col};
    return {(std::string) "COLON", name, lin, col};
}

std::string R_IGNORE::rule() {
    return R"(\t| )";
}

MyToken R_IGNORE::get_tok(std::string name, int lin, int col) {
    return {(std::string) "ignore", name, lin, col};
}

std::string R_SINGLE_QUOTES::rule(){
    return R"(\')";
}

MyToken R_SINGLE_QUOTES::get_tok(std::string name, int lin, int col){
    return {(string) "SINGLE_QUOTES", name, lin, col};
}

