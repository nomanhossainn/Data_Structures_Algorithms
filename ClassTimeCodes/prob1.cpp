#include<iostream>
using namespace std;

void printNumbers(int n){
    if(n==1){
        cout<<1;
        return;
    }
    printNumbers(n-1);
    cout<<n<<" ";
}


int main(){
    printNumbers(1);
}
