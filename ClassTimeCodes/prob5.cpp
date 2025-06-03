#include<iostream>
using namespace std;

bool firstCall=false;
int countTheDigits(int n){
    if(n==0){
        if(firstCall==false){
            return 1;
        }else{
            return 0;
        }
    }
    // if(firstCall==true){
    //     firstCall=true;
    // }

    //int lastDigit = n%10; // will not be used here
    int remainingDigits = n/10;

    int count=1+countTheDigits(remainingDigits);

    return count;
}
int main(){
    int x;
    //x = countTheDigits(0);
    x = countTheDigits(01230670);
    cout<<"the factorial value is: "<<x;
}




