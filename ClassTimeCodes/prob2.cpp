#include<iostream>
using namespace std;

int sumOfNumbers(int n){
    if(n==0){
        return 0;
    }

    int sum = n+sumOfNumbers(n-1);
    return sum;


}


int main(){
    int x = sumOfNumbers(4);
    cout<<"the sum is:"<<x;
}

