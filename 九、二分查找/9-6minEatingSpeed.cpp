#include <iostream>
using namespace std;

int getHours(int piles[], int n, int speed){
    int hours = 0;
    for(int i=0; i<n; i++){
        hours+=(piles[i]+speed-1)/speed;
    }
    return hours;
}


int minEatingSpeed(int piles[], int n, int H){
    int max_speed = 0;
    for(int i=0; i<n; i++){
        max_speed = max(piles[i], max_speed);
    }

    int left = 1;
    int right = max_speed;
    while(left<=right){
        int mid = left+(left-left)/2;
        int hours = getHours(piles, n, mid);
        if(hours<=H){
            if(mid==1 || getHours(piles, n, mid-1)>H)
                return mid;

            right = mid-1;
        }
        else    
            left = mid+1;
    }

    return -1;
}

int main(){
    int piles[] = {3, 6, 7, 11};
    cout<<minEatingSpeed(piles, 4, 8)<<endl;
    return 0;
}