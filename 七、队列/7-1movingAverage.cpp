#include <iostream>
#include <queue>

using namespace std;

class MovingAverage{
    private:
        int capacity;
        int sum;
        queue<int> nums;
    
    public:
        MovingAverage() = delete;    

        MovingAverage(int size){
            capacity = size;
            sum = 0;
        }

        double next(int val){
            nums.push(val);
            sum+=val;
            if(nums.size()>capacity){
                sum-=nums.front();
                nums.pop();
            }

            return static_cast<double>(sum)/nums.size();
        }
};

int main(){
    MovingAverage ma(3);
    cout<<ma.next(1)<<endl;
    cout<<ma.next(2)<<endl;
    cout<<ma.next(3)<<endl;
    cout<<ma.next(4)<<endl;
    cout<<ma.next(5)<<endl;
    cout<<ma.next(6)<<endl;
    cout<<ma.next(7)<<endl;
    return 0;
}