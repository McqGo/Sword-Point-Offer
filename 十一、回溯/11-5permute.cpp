#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int i, vector<vector<int>>& res){
    if(i==nums.size()){
        vector<int> permutation;
        permutation.reserve(nums.size());
        for(auto num: nums){
            permutation.emplace_back(num);
        }
        res.emplace_back(permutation);
    }
    else{
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            helper(nums, i+1, res);
            swap(nums[i], nums[j]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for(auto subset: res){
        for(auto num: subset)
            cout<<num<<flush;
        cout<<"|"<<endl;
    }

    return 0;
}