//
// Created by MYF on 3/25/2023.
//
#include "Lexer.h"

#include <utility>

MyToken Lexer::getToken() {
    std::smatch result, minresult;
    std::string str = data.substr(pos);
    int minpos = data.size();
    int curpos;
    Lexis *lex = nullptr;
    for (auto &rule: rules) {//遍历词法规则
        if (std::regex_search(str, result, std::regex(rule->rule()))) {
            curpos = str.find(result[0]);
            if (curpos < minpos) {
                minpos = curpos;
                lex = rule;
                minresult = result;
            }
        }
    }
    if (lex != nullptr) {
        if (minpos != 0) {
            for (int i = 0; i < minpos; i++) {
                if (str[i] == '\n') {
                    lin++;
                    continue;
                } else {
                    std::cout << "Illegal string:" << str[i] << std::endl;
                }
            }
        }
        pos += minpos;
        int lastl = (data.find_last_of('\n', pos) != data.npos) ? data.find_last_of('\n', pos) : -1;
        col = pos - lastl;
        MyToken tok = lex->get_tok(minresult[0], lin, col);
        if (tok.type == "ignore") {
            pos += minresult[0].length();
            lin += Strdel::getLFNum(minresult[0]);
            return getToken();
        } else if (tok.type == "error") {
            pos += minresult[0].length();
            lin += Strdel::getLFNum(minresult[0]);
            std::cout << "Illegal string:" << minresult[0] << std::endl;
            return getToken();
        } else {
            pos += minresult[0].length();
            lin += Strdel::getLFNum(minresult[0]);
            return tok;
        }
    } else {
        for (int i = pos; i < data.size(); i++) {
            if (data[i] == '\n') {
                lin++;
                continue;
            } else {
                std::cout << "Illegal string:" << data[i] << std::endl;
            }
        }
        int lastl = (data.find_last_of('\n', pos - 1) != data.npos) ? data.find_last_of('\n', pos - 1) : 0;
        col = pos - lastl;
        return {(std::string) "end", (std::string) "nothing", lin, col};
    }
}

std::vector<MyToken> Lexer::getTokenList() {
    return std::vector<MyToken>();
}

bool Lexer::setFile(std::string path) {
    std::ifstream file(path);
    if (!file.is_open())
        return false;
    file.seekg(ios::beg);
    data.clear();
    char c;
    file.get(c);
    while (!file.eof()) {
        data.push_back(c);
        file.get(c);
    }
    lin = 1;
    col = 0;
    pos = 0;
    return true;
}

bool Lexer::setRegex(LexRuls r) {
    rules = std::move(r);
    return false;
}

int Strdel::getLFNum(std::string str) {
    std::size_t n = str.length();
    std::size_t i = 0;
    i = str.find('\n', i);
    int count = 0;
    while (i < n && i != std::string::npos) {
        count++;
        i = str.find('\n', i + 1);
    }
    return count;
}
