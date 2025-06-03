#include<iostream>
using namespace std;

struct MaxMinValues{
    int max;
    int min;
};

struct MaxMinValues MaxMin(int *A, int i, int j){
    if(i==j){
        struct MaxMinValues mmv;
        mmv.max=A[i];
        mmv.min=A[i];
        return mmv;
    }

    int mid = (i+j)/2;
    struct MaxMinValues mmv1 = MaxMin(A,i,mid);
    struct MaxMinValues mmv2 = MaxMin(A,mid+1,j);

    struct MaxMinValues fmmv;

    if(mmv1.max>=mmv2.max){
        fmmv.max=mmv1.max;
    }else{
        fmmv.max=mmv2.max;
    }

    if(mmv1.min<=mmv2.min){
        fmmv.min=mmv1.min;
    }else{
        fmmv.min=mmv2.min;
    }

    return fmmv;

}



int main(){
    int A[] = {-1000,20,30,-2,-100,56,12,99,1};
    int length =  9;

    struct MaxMinValues resultmmv = MaxMin(&A[0],0,8);

    cout<<"max val in the array "<<resultmmv.max<<endl;
    cout<<"min val in the array "<<resultmmv.min<<endl;
}
