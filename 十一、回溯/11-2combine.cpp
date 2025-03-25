#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int n, int k, int i, stack<int>& combination, vector<stack<int>>& res){
    if(combination.size()==k){
        res.emplace_back(combination);
        return ;
    }

    else if(i<=n){
        dfs(n, k, i+1, combination, res);

        combination.push(i);
        dfs(n, k, i+1, combination, res);
        combination.pop();
    }
}

vector<stack<int>> subsets(int n, int k){
    vector<stack<int>> res;
    stack<int> combination;
    dfs(n, k, 1, combination, res);
    return res;
}

int main(){
    vector<stack<int>> res = subsets(3, 2);
    for(auto subset: res){
        while(!subset.empty()){
            int num = subset.top();
            subset.pop();
            cout<<num<<flush;
        }
        cout<<"|"<<endl;
    }
        
    return 0;
}