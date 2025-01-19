#include <iostream>
#include <vector>
using namespace std;


int pivotIndex(vector<int>& nums){
    int sum = 0;
    int total = 0;
    int len = nums.size();
    for(const auto& num: nums)
        total+=num;

    for(int i=0; i<len; i++){
        sum+=nums[i];
        if(sum-nums[i] == total-sum)
            return i;
    }

    return -1;
}

int main(){
    vector<int> nums = {1, 7, 3, 6, 2, 9};
    cout<<pivotIndex(nums)<<endl;
    return 0;
}