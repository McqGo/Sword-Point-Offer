#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool areAllZero(int hash[26]){
    for(int i=0; i<26; i++){
        if(hash[i]!=0)
            return false;
    }

    return true;
}

bool areAllZero(vector<int> hash){
    for(const auto &i: hash){
        if(i!=0)
            return false;
    }

    return true;
}

void getFullPermutation(string &str, int start, vector<string>& result){
    int len = str.size();
    if(start==len){
        result.emplace_back(str);
        return ;
    }

    for(int i=start; i<len; i++){
        //交换字符，固定start位置的字符
        swap(str[start], str[i]);
        //递归
        getFullPermutation(str, start+1, result);
        //恢复至本次交换前的状态，回溯
        swap(str[start], str[i]);
    }
}

bool checkInclusionBF(string& str1, string& str2){
    int len_1 = str1.size();
    int len_2 = str2.size();
    if(len_1>len_2){
        return false;
    }

    vector<string> result;
    //求str1的全排列
    getFullPermutation(str1, 0, result);
    
    for(int i=0; i<=len_2-len_1; i++){
        string sub_str = str2.substr(i, len_1);
        for(const auto &temp_str: result){
            if(temp_str==sub_str)   return true;
        }
    }
    
    return false;
}


bool checkInclusionHash(string& str1, string& str2){
    int len_1 = str1.size();
    int len_2 = str2.size();
    if(len_1>len_2){
        return false;
    }

    vector<int> hash(26, 0);
    vector<int> temp_hash;
    for(int i=0; i<len_1; i++){
        hash[str1[i]-'a']++;
    }
    
    for(int i=0; i<=len_2-len_1; i++){
        string sub_str = str2.substr(i, len_1);
        temp_hash = hash;    
        for(const auto &ch: sub_str){
            temp_hash[ch-'a']--;
        }
        
        if(areAllZero(temp_hash)) return true;
    }
    
    return false;
}

bool checkInclusionHashTP(string& str1, string& str2){
    int len_1 = str1.size();
    int len_2 = str2.size();
    if(len_1>len_2){
        return false;
    }

    int hash[26] = {};
    for(int i=0; i<len_1; i++){
        hash[str1[i]-'a']++;
        hash[str2[i]-'a']--;
    }

    if(areAllZero(hash)) return true;

    for(int i=len_1; i<len_2; i++){
        hash[str2[i]-'a']--;
        hash[str2[i-len_1]-'a']++;
        if(areAllZero(hash)) return true;
    }
    
    return false;
}


int main(){
    string str1 = "hoa";
    string str2 = "sadafoahoufhacabf";
    cout<<boolalpha<<checkInclusionBF(str1, str2)<<endl;
    cout<<boolalpha<<checkInclusionHash(str1, str2)<<endl;
    cout<<boolalpha<<checkInclusionHashTP(str1, str2)<<endl;
    return 0;
}