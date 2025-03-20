#include <iostream>
#include <vector>
using namespace std;

vector<int> relativeSortArray(vector<int>& nums, vector<int>& arr){
    vector<int> res(nums.size());
    int counts[1001] = {};
    for(auto num: nums)
        counts[num]++;

    int i = 0;

    for(auto num: arr){
        while(counts[num]>0){
            res[i++] = num;
            counts[num]--;
        }
    }

    for(int j=0; j<1001; j++){
        while(counts[j]>0){
            res[i++] = j;
            counts[j]--;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {2, 3, 3, 7, 3, 9, 2, 1, 7, 2};
    vector<int> arr = {3, 2, 1};
    vector<int> res = relativeSortArray(nums, arr);
    for(auto num: res)
        cout<<num<<" "<<flush;
    cout<<endl;
    return 0;
}