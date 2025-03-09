#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]>=target){
            if(mid==0 || nums[mid-1]<target){
                return mid;
            }

            right = mid-1;
        }
        else 
            left = mid+1;
    }

    return nums.size();
}

int main(){
    vector<int> nums = {1, 3, 4, 5};
    cout<<searchInsert(nums, 2)<<endl;
    return 0;
}