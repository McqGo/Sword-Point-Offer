#include <iostream>
#include <vector>
using namespace std;


int numSubArrayProductLessThanK(vector<int>& nums, int k){
    int count = 0;
    int right = 0;
    int left = 0;
    int product = 1;
    int len = nums.size();
    for(; right<len; right++){
        product*=nums[right];
        for(; (left<=right) && (product>=k); left++){
            product/=nums[left];
        }
        count+= right-left+1>0? right-left+1: 0;
    }

    return count;
}

int main(){
    vector<int> nums = {10, 5, 2, 6};
    int k;
    cin>>k;
    cout<<numSubArrayProductLessThanK(nums, k)<<endl;
    return 0;
}