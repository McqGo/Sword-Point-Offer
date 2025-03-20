#include <iostream>
#include <vector>
#include <limits>
#include <random>
using namespace std;

vector<int> countingSort(vector<int>& nums){
    vector<int> res(nums.size());

    int min_num = numeric_limits<int>::max();
    int max_num = numeric_limits<int>::min();
    for(int num: nums){
        min_num = min(min_num, num);
        max_num = max(max_num, num);
    }

    int counts[max_num-min_num+1] = {};
    for(int num: nums)
        counts[num-min_num]++;

    for(int i=0, num=min_num; num<=max_num; num++){
        while(counts[num-min_num]>0){
            res[i++] = num;
            counts[num-min_num]--;
        }
    }

    return res;
}

vector<int> mergeSortIteration(vector<int>& nums){
    int len = nums.size();
    vector<int> res(len);
    vector<int> temp = nums;

    for(int seg=1; seg<len; seg+=seg){
        for(int start=0; start<len; start+=seg*2){
            int first_end = min(start+seg, len);
            int second_end = min(start+seg*2, len);
            int i=start, j=first_end, k=start;
            while(i<first_end || j<second_end){
                if(j==second_end || (i<first_end && temp[i]<temp[j]))
                    res[k++] = temp[i++];
                else    
                    res[k++] = temp[j++];
            }
        }

        temp = res;
    }

    return res;
}

void mergeSort(vector<int>& nums, int start, int end){
    if(start+1>=end)
        return;
    
    int mid = (start+end)/2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid, end);

    int i=start, j=mid, k=start;
    vector<int> temp = nums;
    while(i<mid || j<end){
        if(j==end || (i<mid && temp[i]<temp[j]))
            nums[k++] = temp[i++];
        else    
            nums[k++] = temp[j++];
    }
}

vector<int> mergeSortRecursion(vector<int>& nums){
    vector<int> res = nums;
    mergeSort(res, 0, res.size());
    return res;
}

int getRandomVal(int min_val, int max_val){
    //下面三行只是在生成随机数
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> intDist(min_val, max_val);

    return intDist(engine);
}

void swap(vector<int>& nums, int p1, int p2){
    int temp = nums[p1];
    nums[p1] = nums[p2];
    nums[p2] = temp;
}

int partition(vector<int>& nums, int start, int end){
    int random = getRandomVal(start, end);
    swap(nums, random, end);

    int back = start-1;
    for(int front=start; front<end; front++){
        if(nums[front]<nums[end]){
            back++;
            swap(nums, front, back);
        }
    }

    back++;
    swap(nums, back, end);
    return back;
}

void helper(vector<int>& nums, int start, int end){
    if(end>start){
        int pivot = partition(nums, start, end);
        helper(nums, start, pivot-1);
        helper(nums, pivot+1, end);
    }
}

vector<int> quickSort(vector<int>& nums){
    vector<int> res = nums;
    helper(res, 0, res.size()-1);
    return res;    
}

int main(){
    vector<int> nums = {10, 1, 9, 8, 7, 8, 6, 5, 10, 4, 3, 2, 1};
    for(auto num: nums)
        cout<<num<<" "<<flush;
    cout<<endl;

    vector<int> res;

    res = countingSort(nums);
    for(auto num: res)
        cout<<num<<" "<<flush;
    cout<<endl;

    res = mergeSortIteration(nums);
    for(auto num: res)
        cout<<num<<" "<<flush;
    cout<<endl;

    res = mergeSortRecursion(nums);
    for(auto num: res)
        cout<<num<<" "<<flush;
    cout<<endl;

    res = quickSort(nums);
    for(auto num: res)
        cout<<num<<" "<<flush;
    cout<<endl;

    return 0;
}