#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<int>& nums, int index, stack<int>& subset, vector<stack<int>>& res){
    if(index==nums.size()){
        res.emplace_back(subset);
        return ;
    }

    subset.push(nums[index]);
    dfs(nums, index+1, subset, res);
    subset.pop();

    dfs(nums, index+1, subset, res);
}

vector<stack<int>> subsets(vector<int>& nums){
    vector<stack<int>> res;
    stack<int> subset;
    dfs(nums, 0, subset, res);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<stack<int>> res = subsets(nums);
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