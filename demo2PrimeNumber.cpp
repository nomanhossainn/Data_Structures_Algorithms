
#include<iostream>
#include<math.h>
using namespace std;

bool P[101];

void printThePrimeNumberArray(int n){
    cout<<"*************************"<<endl;
    for(int i=1;i<=n;i++){
        cout<<P[i]<<" ";
    }
    cout<<endl<<"*************************"<<endl;
}

void sieveOfEratosthenes(int n){
    // mark all the numbers as prime except 1
    for(int i=2;i<=n;i++){
        P[i]=true;
    }
    // for i =2 to sqrt (n)
    for(int i=2;i<=sqrt(n);i++){
        // checking if the number is true
        if(P[i]==true){
            // setting all the multiples of P[i] as False
            int j=2;
            int index= i*j;
            while(index<=n){
                P[index]=false;
                j++;
                index=i*j;
            }
        }
    }

    //printThePrimeNumberArray(n);

}

int countPrimeNumbers(int A[], int start, int end){
    if(start==end){
        int number=A[start];
        if(P[number]==true){
            return 1;
        }else{
            return 0;
        }
    }
    int mid = (start+end)/2;

    int count1 = countPrimeNumbers(A, start,mid);
    int count2 = countPrimeNumbers(A, mid+1,end);

    return count1+count2;


}

int main(){
    int A [] = {2,5,4,10,2,2,1,2};
    int start = 0;
    int end = 7;
    sieveOfEratosthenes(50);
    int result = countPrimeNumbers(A,start,end);
    cout<<"Total number of prime numbers = "<<result<<endl;
    return 0;
}
