#include <iostream>
using namespace std;

int mySqrt(int n){
    int left = 1;
    int right = n;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(mid<=n/mid){
            if((mid+1)>n/(mid+1))
                return mid;

            left = mid+1;
        }

        else  
            right = mid-1;
    }

    return 0;
}

int main(){
    cout<<mySqrt(0)<<endl;
    cout<<mySqrt(1)<<endl;
    cout<<mySqrt(2)<<endl;
    cout<<mySqrt(3)<<endl;
    cout<<mySqrt(4)<<endl;
    cout<<mySqrt(99999)<<endl;
    return 0;
}