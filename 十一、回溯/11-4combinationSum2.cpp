#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int getNext(vector<int>& nums, int index){
    int next = index;
    while(next<nums.size() && nums[next]==nums[index]){
        next++;
    }

    return next;
}

void dfs(vector<int>& nums, int target, int i, stack<int>& combination, vector<stack<int>>& res){
    if(target==0){
        res.emplace_back(combination);
    }
    else if(target>0 && i<nums.size()){
        dfs(nums, target, getNext(nums, i), combination, res);

        combination.push(nums[i]);
        dfs(nums, target-nums[i], i+1, combination, res);
        combination.pop();
    }
}

vector<stack<int>> combinationSum2(vector<int>& nums, int target){
    vector<stack<int>> res;
    stack<int> combination;
    dfs(nums, target, 0, combination, res);
    return res;
}

int main(){
    vector<int> nums = {2, 2, 2, 4, 3, 3};
    vector<stack<int>> res = combinationSum2(nums, 8);
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