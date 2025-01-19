#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> twoSumBF(const vector<int>& nums, int k){
    int len = nums.size();
    vector<int> result(2,0);
    for(int i=0; i<len; i++){
       for(int j=i+1; j<len; j++){
           if(nums[i]+nums[j]==k){
               result[0] = i;
               result[1] = j;
               return result;
           }
       }
    }

    return result;   
}


vector<int> twoSumBS(const vector<int>& nums, int k){
    int len = nums.size();
    vector<int> result(2,0);
    for(int i=0; i<len-1; i++){
       int dest = k-nums[i];
       int left = i+1;
       int right = len-1;
       int mid;
       while(left<=right){
           mid = (left+right)/2;
           if(nums[mid]==dest){
               result[0] = i;
               result[1] = mid;
               return result;
           }
           else if(nums[mid]>dest) right = mid-1;
           else left = mid+1;
       }
    }

    return result;
}

vector<int> twoSumHash(const vector<int>& nums, int k){
    int len = nums.size();
    vector<int> result(2,0);
    unordered_map<int, int> hash;

    for(int i=0; i<len; i++){
       hash[nums[i]] = i;
    }

    for(int i=0; i<len; i++){
       int dest = k-nums[i];
       auto iter = hash.find(dest);
       if(iter!=hash.end()){
            result[0] = i;
            result[1] = iter->second;
            return result;
       }
    }

    return result;
}

vector<int> twoSumTP(const vector<int>& nums, int k){
    vector<int> result(2,0);
    int i = 0;
    int j = nums.size()-1;
    while((i<j) && nums[i]+nums[j]!=k){
        if(nums[i]+nums[j]<k)   i++;
        else j--;
    }

    result[0] = i;
    result[1] = j;
    return result;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,10,100,210};
    int k;
    cin>>k;
    vector<int> result;

    result = twoSumBF(nums, k);
    for(auto i: result){
        cout<<i<<endl;
    }
    cout<<"--------------------------"<<endl;

    result = twoSumBS(nums, k);
    for(auto i: result){
        cout<<i<<endl;
    }
    cout<<"--------------------------"<<endl;
    
    result = twoSumHash(nums, k);
    for(auto i: result){
        cout<<i<<endl;
    }
    cout<<"--------------------------"<<endl;

    result = twoSumTP(nums, k);
    for(auto i: result){
        cout<<i<<endl;
    }
    cout<<"--------------------------"<<endl;

    return 0;
}