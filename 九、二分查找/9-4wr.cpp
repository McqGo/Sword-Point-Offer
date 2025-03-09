#include <iostream>
#include <vector>
#include <random>
using namespace std;

int getRandomVal(int max_val){
    //下面三行只是在生成随机数
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> intDist(0, max_val);

    return intDist(engine);
}

int wr(vector<int>& nums) {
    vector<int> sums(nums.size());
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        sums[i] = sum;
    }

    int random_val = getRandomVal(sum);

    int left = 0;
    int right = sums.size();
    while(left<=right){
        int mid = (left+right)/2;
        if(sums[mid]>random_val){
            if(mid==0 || sums[mid-1]<=random_val){
                return mid;
            }

            right = mid-1;
        }

        else    
            left = mid+1;
    }

    return -1;

}

int main(){
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {100, 102, 200, 201};
    vector<int> nums3 = {1, 1, 100, 1, 1, 1};
    cout<<wr(nums1)<<endl;
    cout<<wr(nums2)<<endl;
    cout<<wr(nums3)<<endl;
    return 0;
}