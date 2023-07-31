#include <iostream>
#include"stack"
using namespace std;

int main() {
    stack<char> stack;

    string expression;//  example:  "5*((3-7)*2-3*(5+1))-3";
    cout<<"enter the expression to replace with ONP: "<<endl;
    cin>>expression;

    for(int i = 0;i < expression.length();i++){
        if(expression[i]== '*'){
            while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/'))){
                cout<<stack.top();
                stack.pop();
            }
            stack.push('*');
        }
        else if(expression[i]== '/'){
            while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/'))){
                cout<<stack.top();
                stack.pop();
            }
            stack.push('/');
        }
        else if(expression[i]== '+'){
            while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/')||(stack.top()=='+')||(stack.top()=='-'))){
                cout<<stack.top();
                stack.pop();
            }
            stack.push('+');
        }
        else if(expression[i]== '-'){
            while(!stack.empty()&&((stack.top()=='*')||(stack.top()=='/')||(stack.top()=='+')||(stack.top()=='-'))){
                cout<<stack.top();
                stack.pop();
            }
            stack.push('-');
        }
        else if(expression[i]== '('){
            stack.push('(');
        }
        else if(expression[i]== ')'){
            while(!stack.empty()&&(stack.top()!='(')){
                cout<<stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else{
            cout<<expression[i];
        }
    }
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }

    return 0;
}
