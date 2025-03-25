#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void dfs(vector<int>& nums, int target, int i, stack<int>& combination, vector<stack<int>>& res){
    if(target==0){
        res.emplace_back(combination);
    }
    else if(target>0 && i<nums.size()){
        dfs(nums, target, i+1, combination, res);

        combination.push(nums[i]);
        dfs(nums, target-nums[i], i, combination, res);
        combination.pop();
    }
}

vector<stack<int>> combinationSum(vector<int>& nums, int target){
    vector<stack<int>> res;
    stack<int> combination;
    dfs(nums, target, 0, combination, res);
    return res;
}

int main(){
    vector<int> nums = {2, 3, 5};
    vector<stack<int>> res = combinationSum(nums, 8);
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