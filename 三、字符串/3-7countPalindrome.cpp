#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string str){
    int left = 0; 
    int right = str.size()-1;
    while(left<right){
        char left_ch = str[left];
        char right_ch = str[right];

        if(!isalnum(left_ch)){
            left++;
        }
        else if(!isalnum(right_ch)){
            right--;
        }
        else{
            left_ch = tolower(left_ch);
            right_ch = tolower(right_ch);
            if(left_ch!=right_ch)   return false;
            left++;
            right--;
        }
    }

    return true;
}

int countPalindromeBF(string &str){
    int len = str.size();
    if(len==0)  return 0;

    int count = 0;
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            string str_temp = str.substr(i, j-i);
            if(isPalindrome(str_temp))  count++;
        }
    }

    return count;
}

int countP(string& str, int start, int end){
    int count = 0;
    int len = str.size();
    while(start>-1 && end<len){
        if(str[start]!=str[end])    break;
        count++;
        start--;
        end++;
    }

    return count;
}

int countPalindrome(string& str){
    int len = str.size();
    if(len==0)  return 0;

    int count = 0;
    for(int i=0; i<len; i++){
        count+=countP(str, i, i);
        count+=countP(str, i, i+1);
    }

    return count;
}

int main(){
    string str = "aaa";
    cout<<countPalindromeBF(str)<<endl;
    cout<<countPalindrome(str)<<endl;
    return 0;
}
