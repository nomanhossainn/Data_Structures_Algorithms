#include<iostream>
using namespace std;

int digitSum(int n){
    if(n==0){
        return 0;
    }
    int lastDigit = n%10;
    int remainingDigits = n/10;
    int sum =lastDigit+digitSum(remainingDigits);
    return sum;

}


int main(){
    int x = digitSum(43219);
    cout<<"the factorial value is:"<<x;
}