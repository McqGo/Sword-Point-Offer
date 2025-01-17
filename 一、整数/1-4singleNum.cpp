#include <iostream>
#include <vector>
using namespace std;

int getSingleNumber(vector<int>* a){
    vector<int> bits(32,0);
    for(const auto &num: *a){
        for(int i=0; i<32; i++){
            bits[i]+=(num>>(31-i))&1;
        }
    }

    int result = 0;
    for(int i=0; i<32; i++){
        result = (result<<1)+bits[i]%3;
    }

    return result;
}

int main(){
    vector<int> a = {1,3,2,2,1,5,5,5,1,2};
    cout<<getSingleNumber(&a)<<endl;
    return 0;
}