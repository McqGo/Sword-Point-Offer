#include <iostream>
#include <vector>
#include <utility>
#include <random>
using namespace std;

int getRandomVal(int start, int end){
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> intDist(start, end);
    return intDist(engine);
}

int partition(vector<int>& nums, int start, int end){
    int random = getRandomVal(start, end);
    swap(nums[random], nums[end]);

    int back = start - 1;
    for(int front = start; start<end; start++){
        if(nums[front]<nums[end]){
            back++;
            swap(nums[back], nums[front]);
        }
    }

    back++;
    swap(nums[back], nums[end]);
    return back;
}


int findKthLargest(vector<int>& nums, int k){
    int target = nums.size()-k;
    int start = 0;
    int end = nums.size()-1;
    int index = partition(nums, start, end);
    while(index!=target){
        if(index>target)
            end = index-1;
        else    
            start = index+1;

        index = partition(nums, start, end);
    }

    return nums[index];
}

int main(){
    vector<int> nums = {3, 1, 2, 4, 5, 5, 6};
    cout<<findKthLargest(nums, 3)<<endl;
    return 0;
}