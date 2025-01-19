#include <iostream>
#include <vector>

using namespace std;

#define MAX_LEN 0x7FFFFFFF

int minSubArrayLen(int k, vector<int>& nums){
    int len = nums.size();
    int minLen = MAX_LEN;
    int right = 0;
    int left = 0;
    int sum = 0;
    for(; right<len; right++){
        sum+=nums[right];
        for(; (left<=right) && (sum>=k); left++ ){
            minLen = min(minLen, right-left+1);
            sum-=nums[left];
        }
    }

    return minLen==MAX_LEN? 0: minLen;
}

int main(){
    vector<int> nums = {5, 1, 4, 3};
    int k;
    cin>>k;
    cout<<minSubArrayLen(k, nums)<<endl;
    return 0;
}