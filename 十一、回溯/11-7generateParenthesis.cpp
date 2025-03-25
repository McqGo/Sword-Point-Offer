#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int left, int right, string parenthesis, vector<string>& res){
    if(left==0 && right==0){
        res.emplace_back(parenthesis);
        return ;
    }

    if(left>0){
        dfs(left-1, right, parenthesis+"(", res);
    }
    if(left<right){
        dfs(left, right-1, parenthesis+")", res);
    }

}

vector<string> generateRarenthesis(int n){
    vector<string> res;
    dfs(n, n, "", res);
    return res;
}

int main(){
    vector<string> res = generateRarenthesis(4);
    for(auto str: res)
        cout<<str<<"|"<<endl;

    return 0;
}