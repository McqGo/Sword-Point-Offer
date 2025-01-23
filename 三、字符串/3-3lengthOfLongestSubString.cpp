#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hasGreaterThan1(int hash[256]){
    for(int i=0; i<256; i++){
        if(hash[i]>1)
            return true;
    }

    return false;
}

int lengthOfLongestSubString(string str){
    int len = str.size();
    if(len==0)  return 0;

    int hash[256] = {};
    int i = 0;
    int j = -1;
    int longest = 1;
    for(; i<len; i++){
        //str[i]返回的是字符，数组索引是整型，所以这里有一个隐式类型转换，字符转成整型，而具体整型值就是字符对应的ASCII码值
        hash[str[i]]++;
        
        while(hasGreaterThan1(hash)){
            j++;
            hash[str[j]]--;
        }

        longest = max(longest, i-j);
    }

    return longest;
}

int lengthOfLongestSubString_(string str){
    int len = str.size();
    if(len==0)  return 0;

    int hash[256] = {};
    int i = 0;
    int j = -1;
    int longest = 1;
    int count = 0;
    for(; i<len; i++){
        hash[str[i]]++;
        if(hash[str[i]]==2)  count++;
        while(count>0){
            j++;
            hash[str[j]]--;
            if(hash[str[j]]==1)  count--;
        }

        longest = max(longest, i-j);
    }

    return longest;
}


int main(){
    string str = "babcca";
    cout<<lengthOfLongestSubString(str)<<endl;
    cout<<lengthOfLongestSubString_(str)<<endl;
    return 0;
}