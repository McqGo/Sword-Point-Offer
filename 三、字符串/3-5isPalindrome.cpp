#include <iostream>
#include <string>
#include <cctype>
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

bool isPalindrome_(string str){
    int len = str.size();
    int len_left_max = -1;
    int len_right_min = len;
    int len_alnum = 0;

    //统计有效字符（数组或字母）的数量
    for(const auto &ch: str){
        if(isalnum(ch)) len_alnum++;
    }

    //求left的最大值，即下标小于等于left的字符组成的子字符串中字符的数量应当是len_alnum/2
    int len_alnum_ = 0;
    for(const auto &ch: str){
        len_left_max++;
        if(isalnum(ch)) len_alnum_++;
        if(len_alnum/2 == len_alnum_) break;
    }
    int left = len_left_max;

    //求left的最大值，即下标小于等于left的字符组成的子字符串中字符的数量应当是len_alnum/2
    len_alnum_ = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        len_right_min--;
        if (isalnum(*it)) len_alnum_++;
        if(len_alnum/2 == len_alnum_) break;
    }
    int right = len_right_min;

    while(left>-1 && right<len){
        char left_ch = str[left];
        char right_ch = str[right];
        if(!isalnum(left_ch)){
            left--;
        }
        else if(!isalnum(right_ch)){
            right++;
        }
        else{
            left_ch = tolower(left_ch);
            right_ch = tolower(right_ch);
            if(left_ch!=right_ch)   return false;
            left--;
            right++;
        }
    }

    return true;
}

int main(){
    cout<<boolalpha<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<boolalpha<<isPalindrome_("A man, a plan, a canal: Panama")<<endl;
    return 0;
}