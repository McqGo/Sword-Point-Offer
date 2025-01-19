#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


void twoSum(vector<int>& nums, int len, int i, vector<vector<int>>& result){
    int j = i+1;
    int k = len-1;
    while(j<k){
        if(nums[i]+nums[j]+nums[k]==0){
            vector<int> tmp = {nums[i], nums[j], nums[k]};
            result.emplace_back(tmp);

            int temp = nums[j];
            while(j<k && nums[j]==temp){
                j++;
            }
        }
        else if(nums[i]+nums[j]+nums[k]<0){
            j++;
        }
        else{
            k--;
        }
    }
}

void threeSum(vector<int>& nums, vector<vector<int>>& result){
    int len = nums.size();
    if(len>=3){
        sort(nums.begin(), nums.end());

        for(int i=0; i<len-2;){
            twoSum(nums, len, i, result);
            
            int temp = nums[i];
            while(i<len-2 && nums[i]==temp){
                i++;
            }
        }
    }
    
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 10, -10};
    vector<vector<int>> result;
    threeSum(nums, result);
    for(const auto& i: result){
        for(const auto& j: i){
            cout<<setw(3)<<right<<j<<"  ";
        }
        cout<<endl;
    }
    return 0;
}