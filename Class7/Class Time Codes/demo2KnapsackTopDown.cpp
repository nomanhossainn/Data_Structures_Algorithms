#include<iostream>
using namespace std;

int P[] = {-1,3,4,5,6};
int W[] = {-1,2,3,4,5};
// int P[] = {200,150,100,50,300};
// int W[] = {3,2,1,2,5};

int memo [50][50];

void printMemo(int C,int i){
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            cout<<memo[r][c]<<"\t";
        }
        cout<<endl;
    }
}

void initializaMemo(int C,int i){


    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            memo[r][c]=-1;
        }
    }

    for(int r=0;r<=C;r++){
            memo[r][0]=0;
    }

    for(int c=0;c<=i;c++){
            memo[0][c]=0;
    }

}

int knapsack01(int C, int i){
    if (C==0||i==0){
        return 0;
    }

    if(memo[C][i]!=-1) return memo [C][i];

    int value1=0,value2=0;
    value1=0+knapsack01(C,i-1);
    if(C>=W[i]){
        value2=P[i]+knapsack01(C-W[i],i-1);
    }else{
        value2=0;
    }
    if(value1>=value2){
        memo [C][i]=value1;
        return value1;
    }else{
        memo [C][i]=value2;
        return value2;
    }
}


int main(){
    initializaMemo(5,4);
    int profit=knapsack01(5,4);
    // initializaMemo(7,5);
    // int profit=knapsack01(7,5);
    cout<<"Total profit "<<profit<<endl;
    printMemo(5,4);
    return 0;
}

