#include <iostream>
#include "Converter.h"

using namespace std;

int main() {

    string expression;//  example:  "5*((3-7)*2-3*(5+1))-3";
    cout<<"enter the expression to replace with ONP: "<<endl;
    cin>>expression;
    Converter onp(expression);
    onp.conversion();

    return 0;
}
