#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end){
    while(start<end){
        if(str[start++]!=str[end--]){
            return false;
        }
    }

    return true;
}

void dfs(string& str, int start, vector<string>& sub, vector<vector<string>>& res){
    if(start==str.size()){
        res.emplace_back(sub);
        return ;
    }

    for(int i=start; i<str.size(); i++){
        if(isPalindrome(str, start, i)){
            sub.emplace_back(str.substr(start, i-start+1));
            dfs(str, i+1, sub, res);
            sub.pop_back();
        }
    }
} 

vector<vector<string>> partition(string& str){
    vector<vector<string>> res;
    vector<string> sub;
    dfs(str, 0, sub, res);
    return res;
}

int main(){
    string str = "google";
    vector<vector<string>> res = partition(str);
    for(auto s: res){
        for(auto s_: s)
            cout<<s_<<"|"<<endl;
        cout<<endl;
    }
    return 0;
}