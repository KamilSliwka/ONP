//
// Created by kamil on 31.07.2023.
//

#include "Converter.h"

using namespace std;

Converter::Converter(const string &expression) : expression(expression) {
}

void Converter::conversion() {
    for(int i = 0;i < expression.length();i++){
        if(expression[i]== '*')
            operatorsWithHigherPriority('*');
        else if(expression[i]== '/')
            operatorsWithHigherPriority('/');
        else if(expression[i]== '+')
            operatorsWithLowerPriority('+');
        else if(expression[i]== '-')
            operatorsWithLowerPriority('-');
        else if(expression[i]== '(')
            stack.push('(');
        else if(expression[i]== ')')
           closingParenthesis();
        else
            cout<<expression[i];
    }
    clearStack();
}

void Converter::operatorsWithHigherPriority(char o){
    while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/'))){
        cout<<stack.top();
        stack.pop();
    }
    stack.push(o);
}

void Converter::operatorsWithLowerPriority(char o){
    while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/')||(stack.top()=='+')||(stack.top()=='-'))){
        cout<<stack.top();
        stack.pop();
    }
    stack.push(o);
}

void Converter::closingParenthesis(){
    while(!stack.empty()&&(stack.top()!='(')){
        cout<<stack.top();
        stack.pop();
    }
    stack.pop();
}

void Converter::clearStack(){
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
}