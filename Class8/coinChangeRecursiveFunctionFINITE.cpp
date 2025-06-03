#include<iostream>
using namespace std;

int coins[5]={-1,2,1, 3,4};

int coinChangeFinite(int N, int i){
    // base cases:
    if(N==0) return 0;
    if(i==0) return 9999;
    if(N<0) return 9999;
    int call1,call2;
    call1=0+coinChangeFinite(N,i-1);
    call2=1+coinChangeFinite(N-coins[i],i-1);

    if(call1<=call2){
        return call1;
    }else{
        return call2;
    }
}

int main(){
    int result = coinChangeFinite(6,4);
    cout<<"min number of coins "<<result<<endl;
}
