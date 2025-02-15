#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<unsigned long long, vector<string>> groupAnagramsMapping(vector<string>& groups){
    int hash[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
    61, 67, 71, 73, 79, 83, 89, 97, 101};

    unordered_map<unsigned long long, vector<string>> res;
    for(auto& str: groups){
        unsigned long long word_digest = 1;
        for(int i=0; i<str.size(); i++){
            word_digest*=hash[str[i]-'a'];
        }
        
        res[word_digest].emplace_back(str);
    }

    return res;
}

unordered_map<string, vector<string>> groupAnagrams(vector<string>& groups){
    unordered_map<string, vector<string>> res;
    for(const auto& str:groups){
        string temp = str;
        sort(temp.begin(), temp.end());
        res[temp].emplace_back(str);
    }
    
    return res;
}

int main(){
    vector<string> groups = {"eat", "tea", "tan", "ate", "nat", "bat", "tab", "nnn", "atn"};

    unordered_map<unsigned long long, vector<string>> res = groupAnagramsMapping(groups);
    for(const auto& pair:res){
        for(const auto& str:pair.second){
            cout<<str<<" "<<flush;
        }
        cout<<endl;
    }

    cout<<"============================"<<endl;    
    unordered_map<string, vector<string>> res_ = groupAnagrams(groups);
    for(const auto& pair:res_){
        for(const auto& str:pair.second){
            cout<<str<<" "<<flush;
        }
        cout<<endl;
    }
    
    return 0;
}