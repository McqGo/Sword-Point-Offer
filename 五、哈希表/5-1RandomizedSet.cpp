#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;

class RandomizedSet{
    private:
        vector<int> nums;
        unordered_map<int, int> num2location;

    public:
        bool insert(int val){
            if(num2location.count(val)==1){
                return false;
            }

            num2location[val] = nums.size();
            nums.emplace_back(val);
            return true;
        }

        bool remove(int val){
            if(num2location.count(val)==0){
                return false;
            }

            int val_loc = num2location[val];
            int swap_val = nums[nums.size()-1];

            num2location[swap_val] = val_loc;
            nums[val_loc] = swap_val;
           
            num2location.erase(val);
            nums.pop_back();
            return true;
        }

        int getRandomVal(){
            //下面三行只是在生成随机数
            random_device rd;
            mt19937 engine(rd());
            uniform_int_distribution<int> intDist(0, nums.size()-1);

            return nums[intDist(engine)];
        }
};

int main(){
    RandomizedSet rs;
    rs.insert(100);
    rs.insert(12);
    rs.insert(23);
    rs.insert(34);
    rs.insert(45);
    rs.insert(5);
    rs.insert(5);
    rs.insert(100);
    rs.insert(23);

    rs.remove(100);

    cout<<rs.getRandomVal()<<endl;
    return 0;
}