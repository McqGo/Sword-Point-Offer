#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX_LEN  0

int findMaxLen(vector<int>& nums){
    int len = nums.size();
    int max_len = MAX_LEN;
    int sum = 0;
    unordered_map<int, int> hash;
    hash[0] = -1;
    for(int i=0; i<len; i++){
        sum+=(nums[i]==0? -1: 1);
        if(hash.count(sum)!=0){
            max_len = max(max_len, i-hash[sum]);
        }
        else{
            hash[sum] = i;
        }
    }

    return max_len;
}



int main(){
    vector<int> nums = {0, 1, 0};
    cout<<findMaxLen(nums)<<endl;
    return 0;
}