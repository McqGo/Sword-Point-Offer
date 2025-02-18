#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int cal(int num1, int num2, char op){
    switch(op){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
        default:
            cerr<<"op undefined"<<endl;
            return 0;
    }
}

int evalRPN(vector<char>& RPN){
    stack<int> sta;
    for(const auto& ch:RPN){
        switch(ch){
            case '+':
            case '-':
            case '*':
            case '/':{
                int num1 = sta.top();
                sta.pop();
                int num2 = sta.top();
                sta.pop();
                sta.push(cal(num2, num1, ch));
                break;
            }
            default:
                sta.push(ch-'0');
        }
    }

    return sta.top();
}

int main(){
    vector<char> RPN = {'2', '1', '3', '*', '+'};
    cout<<evalRPN(RPN)<<endl;
    return 0;
}