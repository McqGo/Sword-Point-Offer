#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>target)
            right = mid - 1;
        else    
            left = mid + 1;
    }

    return -1;
}

int main(){
    vector<int> a = {1, 4, 7, 10, 12};
    cout<<search(a, 10)<<endl;
    return 0;
}