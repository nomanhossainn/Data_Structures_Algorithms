#include<iostream>
using namespace std;

int P[] = {-1,3,4,5,6};
int W[] = {-1,2,3,4,5};

int memo [50][50]; // needs to be initialized
char printTable[50][50]; // no need to initialize

void printMemo(int C,int i){
    cout<<"*************Memo********************"<<endl;
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            cout<<memo[r][c]<<"\t";
        }
        cout<<endl;
    }
    cout<<"*************************************"<<endl;
}

void printPrintTable(int C,int i){
    cout<<"*************Print Table ***********"<<endl;
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            cout<<printTable[r][c]<<"\t";
        }
        cout<<endl;
    }
    cout<<"*************************************"<<endl;
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
        printTable[C][i]='N';
        return value1;
    }else{
        memo [C][i]=value2;
        printTable[C][i]='T';
        return value2;
    }
}

int knapsack01BottomUp(int C, int i){
    initializaMemo(C,i);

    for(int r=1;r<=C;r++){
        for(int c=1;c<=i;c++){
            knapsack01(r,c);
        }
    }
    return memo[C][i];
}

void printTheItems(int C,int i){
    if(C==0||i==0) return;

    if(printTable[C][i]=='N'){
        printTheItems(C,i-1);
        cout<<"Item "<<i<<" was not taken"<<endl;
    }else{
        printTheItems(C-W[i],i-1);
        cout<<"Item "<<i<<" was  taken"<<endl;
    }

}

int main(){
    knapsack01BottomUp(5,4);
    printMemo(5,4);
    printPrintTable(5,4);
    printTheItems(5,4);
    return 0;
}


