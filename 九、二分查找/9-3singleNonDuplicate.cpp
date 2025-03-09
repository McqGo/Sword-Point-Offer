#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size()/2;
    while(left<=right){
        int mid = (left+right)/2;
        int i = mid*2;
        if(i<nums.size()-1 && nums[i]!=nums[i+1]){
            if(nums[i-1]==nums[i-2] || i==0){
                return nums[i];
            }

            right = mid-1;
        }
        else 
            left = mid+1;
    }

    return nums[nums.size()-1];
}

int main(){
    vector<int> nums1 = {1, 1, 4, 5, 5, 7, 7};
    vector<int> nums2 = {1, 1, 5, 5, 7, 7, 100};
    vector<int> nums3 = {1, 4, 4, 5, 5, 7, 7};
    cout<<singleNonDuplicate(nums1)<<endl;
    cout<<singleNonDuplicate(nums2)<<endl;
    cout<<singleNonDuplicate(nums3)<<endl;
    return 0;
}