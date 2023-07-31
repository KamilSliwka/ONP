//
// Created by kamil on 31.07.2023.
//

#ifndef ONP_CONVERTER_H
#define ONP_CONVERTER_H
#include <iostream>
#include"stack"

using namespace std;

class Converter {
private:
    stack<char> stack;
    string expression;
public:
    explicit Converter(const string &expression);
    void conversion();

    void operatorsWithHigherPriority(char o);

    void operatorsWithLowerPriority(char o);

    void clearStack();

    void closingParenthesis();
};


#endif //ONP_CONVERTER_H
