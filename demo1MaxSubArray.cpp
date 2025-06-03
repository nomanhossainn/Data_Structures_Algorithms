#include<iostream>
using namespace std;

struct ReturnValues{
    int sum;
    int start;
    int end;

};

struct ReturnValues maxCrossingSubArray(int A[],int start, int end){
    int middle = (start+end)/2;

    int sum=0;
    int leftSum = INT_MIN;
    int leftIndex=-1;

    for(int i=middle;i>=start;i--){
        sum = sum+A[i];
        if(leftSum<sum){
            leftSum=sum;
            leftIndex=i;
        }
    }
    sum=0;
    int rightSum=INT_MIN;
    int rightIndex=-1;

    for(int i=middle+1;i<=end;i++){
        sum=sum+A[i];
        if(sum>rightSum){
            rightSum=sum;
            rightIndex=i;
        }
    }

    ReturnValues returnValues;
    returnValues.sum=leftSum+rightSum;
    returnValues.start=leftIndex;
    returnValues.end=rightIndex;

    return returnValues;
}

ReturnValues maximumSubArray(int A[], int start, int end){
    if(start==end){
        ReturnValues returnValues;
        returnValues.sum=A[start];
        returnValues.start=start;
        returnValues.end=end;
        return returnValues;
    }

    int middle =  (start+end)/2;

    ReturnValues left= maximumSubArray(A,start,middle);
    ReturnValues right=maximumSubArray(A,middle+1,end);
    ReturnValues cross=maxCrossingSubArray(A, start,end);

    if(left.sum>right.sum && left.sum>cross.sum){
        return left;
    }else if(right.sum>left.sum && right.sum>cross.sum){
        return right;
    }else{
        return cross;
    }

}



int main(){
    int A[]={16,23,18,20,7,12,5};
    int start = 0;
    int end = 6;
    struct ReturnValues test=maximumSubArray(A,start,end) ;

    cout<<"test.sum="<<test.sum<<endl;
    cout<<"test.start="<<test.start<<endl;
    cout<<"test.end="<<test.end<<endl;

    return 0;
}
