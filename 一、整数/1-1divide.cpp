#include <iostream>
using namespace std;

long divide1(int dividend, int divisor){
    if(dividend==0x80000000 && divisor==-1)
        return 0x80000000;

    int negative = 2;
    if(dividend>0){
        negative--;
        dividend=-dividend;
    }
    if(divisor>0){
        negative--;
        divisor=-divisor;
    }

    int result = 0;
    while(dividend<=divisor){
        dividend-=divisor;
        result++;
    }

    return negative==1? -result:result;
}

long divide2(int dividend, int divisor){
    if(dividend==0x80000000 && divisor==-1)
        return 0x80000000;

    int negative = 2;
    if(dividend>0){
        negative--;
        dividend=-dividend;
    }
    if(divisor>0){
        negative--;
        divisor=-divisor;
    }

    int result = 0;
    while(dividend<=divisor){
        int value = divisor;
        int quotient = 1;
        while(value>=0xc0000000 && dividend<=value+value){
            quotient+=quotient;
            value+=value;
        }

        dividend-=value;
        result+=quotient;
    }

    return negative==1? -result:result;
}
int main(){

    int a, b;
    cin>>a>>b;
    cout<<divide1(a,b)<<endl;
    cout<<divide2(a,b)<<endl;
    return 0;
}