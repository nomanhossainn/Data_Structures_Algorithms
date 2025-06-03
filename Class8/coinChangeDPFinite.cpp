#include<iostream>
using namespace std;

int coins[5]={-1,5,10, 1,2};
int memo[6+1][4+1];
char printTable [6+1][4+1];

void initializeMemo(){
    for(int i=0;i<=6;i++){
        for(int j=0;j<=4;j++){
            memo[i][j]= -1;
        }
    }
    for(int i=0;i<=4;i++){
        memo[0][i]= 0;
    }

    for(int i=0;i<=6;i++){
        memo[i][0]= 9999;
    }

}

void printMemo(){
    cout<<"***************The Memo***************"<<endl;
    for(int i=0;i<=6;i++){
        for(int j=0;j<=4;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The Memo***************"<<endl;

    cout<<"***************The PrintTable***************"<<endl;
    for(int i=0;i<=6;i++){
        for(int j=0;j<=4;j++){
            cout<<printTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The PrintTable***************"<<endl;


}

int coinChangeFinite(int N, int i){
    // base cases:
    if(N==0) return 0;
    if(i==0) return 9999;
    if(N<0) return 9999;

    // checking the memo
    if(memo[N][i]!=-1) return memo[N][i];

    int call1,call2;
    call1=0+coinChangeFinite(N,i-1);
    call2=1+coinChangeFinite(N-coins[i],i-1);

    if(call1>9999) call1=9999;
    if(call2>9999) call2=9999;

    if(call1<=call2){
        memo[N][i]=call1;
        printTable[N][i]='N';
        return call1;
    }else{
        memo[N][i]=call2;
        printTable[N][i]='T';
        return call2;
    }
}


int coinChangeFiniteBottomUp(int N,int i){
    initializeMemo();
    for(int r=0;r<=N;r++){
        for(int c=0;c<=i;c++){
            coinChangeFinite(r,c);
        }
    }
    return memo[N][i];

}

void printTheCoins(int N,int i){
    if(N==0 || i==0) return;

    if(printTable[N][i]=='T'){
        printTheCoins(N-coins[i],i-1);
        cout<<"Coin "<<i<<" has been taken, coin value:"<<coins[i]<<endl;
    }else{ // 'N'
        printTheCoins(N,i-1);
    }

}


int main(){
        int result = coinChangeFiniteBottomUp(6,4);
        if(result==9999){
            cout<<"it is not possible to make the given amount"<<endl;
        }else{
            cout<<"min number of coins "<<result<<endl;
        }

        printMemo();
        printTheCoins(6,4);
}

