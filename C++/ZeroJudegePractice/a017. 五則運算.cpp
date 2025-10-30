#include<iostream>
#include<stack>
#include<sstream>
#include<cctype>
#include<string>
using namespace std;
int applyOperation(int, int, char);
int precedence(char);
int evaluate(const string &expr) {
    stack<long long> values;
    stack<char> ops;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) { // 整數
            values.push(stoll(token));
        } 
        else if (token == "(") {
            ops.push('(');
        } 
        else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                long long b = values.top(); values.pop();
                long long a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.pop(); // 移除 '('
        } 
        else { // 運算子
            char op = token[0];
            while (!ops.empty() && precedence(ops.top()) >= precedence(op)) {
                long long b = values.top(); values.pop();
                long long a = values.top(); values.pop();
                char topOp = ops.top(); ops.pop();
                values.push(applyOperation(a, b, topOp));
            }
            ops.push(op);
        }
    }

    while (!ops.empty()) {
        long long b = values.top(); values.pop();
        long long a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main(){
    string expression;
    while(getline(cin, expression)){
        cout<<evaluate(expression)<<endl;
    }
}
int applyOperation(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return b!=0 ? a/b : 0;
        case '%': return b!=0 ? a%b : 0;
    }
    return 0; // Default case (should not reach here if input is valid)
}
int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/' || op=='%') return 2;
    return 0;
}