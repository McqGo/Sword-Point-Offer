#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& nums) {
    int left = 1;
    int right = nums.size()-2;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
        if(nums[mid]>nums[mid-1])
            left = mid+1;
        else
            right = mid-1;
    }

    return -1;
}

int main(){
    vector<int> nums = {1, 3, 4, 5, 2, 0};
    cout<<peakIndexInMountainArray(nums)<<endl;
    return 0;
}