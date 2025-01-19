#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subArraySum(vector<int>& nums, int k){
    //unordered_map[k]，若不存在键k，则返回值的默认值，这里int型的默认值就是0
    unordered_map<int, int> hash;
    int sum = 0;
    int count = 0;
    hash[0] = 1;
    for(const auto &num: nums){
        sum+=num;
        count+=hash[sum-k];
        hash[sum]+=1; 
    }

    return count;
}

int main(){
    vector<int> nums = {0, 3};
    int k;
    cin>>k;
    cout<<subArraySum(nums, k)<<endl;
    return 0;
}