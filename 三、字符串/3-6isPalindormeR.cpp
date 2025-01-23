#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string& str, int start, int end){
    while(start<end){
        if(str[start]!=str[end]){
            break;
        }

        start++;
        end--;
    }
    
    return start>=end;
}

bool validPalindrome(string str){
    int len = str.size();
    int start = 0;
    int end = len-1;;
    int range = len/2;
    while(start<range){
        if(str[start]!=str[end])    break;

        start++;
        end--;
    }

    return start==range
        || isPalindrome(str, start, end-1)
        || isPalindrome(str, start+1, end);
}

int main(){
    cout<<boolalpha<<validPalindrome("abcka")<<endl;
    return 0;
}