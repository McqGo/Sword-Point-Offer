#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string binAdd(string str1, string str2){
    string result;
    
    int i = str1.size()-1;
    int j = str2.size()-1;
    result.reserve(i>=j? i+1: j+1);
    int carry = 0;
    while(i>=0 || j>=0){
        int digit1 = i>=0? str1[i--] - '0': 0;
        int digit2 = j>=0? str2[j--] - '0': 0;
        int sum = digit1 + digit2 + carry;
        carry = sum>=2? 1 : 0;
        sum = sum>=2? sum-2 : sum;
        result.push_back(sum+'0');
    }

    if(carry==1)    result.push_back('1');

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    cout<<binAdd(a, b)<<endl;
    return 0;
}