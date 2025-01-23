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

vector<int>findAllHashTP(string& str1, string& str2){
    vector<int> indexs;
    int len_1 = str1.size();
    int len_2 = str2.size();
    if(len_1>len_2){
        return indexs;
    }

    int hash[26] = {};
    for(int i=0; i<len_1; i++){
        hash[str1[i]-'a']++;
        hash[str2[i]-'a']--;
    }

    if(areAllZero(hash)) indexs.push_back(0);

    for(int i=len_1; i<len_2; i++){
        hash[str2[i]-'a']--;
        hash[str2[i-len_1]-'a']++;
        if(areAllZero(hash)) indexs.push_back(i-len_1+1);
    }
    
    return indexs;
}


int main(){
    string str1 = "hoa";
    string str2 = "saohdafoahoufhacabfaohhoa";
    vector<int> indexs;
    indexs = findAllHashTP(str1, str2);
    for(auto i: indexs)
        cout<<i<<endl;
    return 0;
}