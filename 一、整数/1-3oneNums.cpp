#include <iostream>
using namespace std;

void countBits1(unsigned int n, int*p){
    for(unsigned int i=0; i<n+1; i++){
        int j = i;
        while(j!=0){
            p[i]++;
            j=j&(j-1);
        }
    }
}

void countBits2(unsigned int n, int*p){
    p[0] = 0;
    for(unsigned int i=1; i<n+1; i++){
        p[i] = p[i&(i-1)]+1;
    }
}

void countBits3(unsigned int n, int*p){
    p[0] = 0;
    for(unsigned int i=1; i<n+1; i++){
        p[i] = p[i/2]+(i&1);
    }
}

void cal(unsigned int n){
    int *result1 = new int[n+1];
    int *result2 = new int[n+1];
    int *result3 = new int[n+1];

    countBits1(n, result1);
    countBits2(n, result2);
    countBits3(n, result3);

    for(unsigned int i=0; i<n+1; i++){
        cout<<i<<"："<<result1[i]<<endl;
    }
    cout<<"--------------------"<<endl;
    for(unsigned int i=0; i<n+1; i++){
        cout<<i<<"："<<result2[i]<<endl;
    }
    cout<<"--------------------"<<endl;
    for(unsigned int i=0; i<n+1; i++){
        cout<<i<<"："<<result3[i]<<endl;
    }
    cout<<"--------------------"<<endl;
}

int main(){
    unsigned int n;
    cin>>n;
    cal(n);
    return 0;
}