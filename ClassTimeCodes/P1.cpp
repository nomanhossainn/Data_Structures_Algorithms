#include<iostream>
using namespace std;

void printNumbers(int n){
    if(n==1){
        printf("1 ");
        //cout << 1<<" ";
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
    //cout << n<<" ";
}
int main(){
    int n;
    cout << "Enter the value: ";
    cin >> n;
    printNumbers(n);
}