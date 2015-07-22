#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    while (1){
        cout << "please input the expression." << endl;
        string inputExpr = "";
        getline(cin, inputExpr);

        if (inputExpr.size == 0){
            cout << "please input the expression." << endl;
        }else{
            stack<string> exprStack;
            while (1){
                exprStack.push(inputExpr.substr(0, 1));
            }
           

        }

        cout << inputExpr << endl;

    }
    return 0;
}

//exchange expressions without bracket
string comparePriority(string op1,string op2){
    return "";
}

string calExpr(string op, string lhs, string rhs){
    return "";
}