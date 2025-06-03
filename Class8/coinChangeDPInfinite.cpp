#include<iostream>
using namespace std;

int N = 6;
int numOfCoins =3;
int coins[100]={-1,2,1,3};
int memo[100][100];
char printTable [100][100];


void initializeMemo(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=numOfCoins;j++){
            memo[i][j]= -1;
        }
    }
    for(int i=0;i<=numOfCoins;i++){
        memo[0][i]= 0;
    }

    for(int i=0;i<=N;i++){
        memo[i][0]= 9999;
    }

}

void printMemo(){
    cout<<"***************The Memo***************"<<endl;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=numOfCoins;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The Memo***************"<<endl;

    cout<<"***************The PrintTable***************"<<endl;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=numOfCoins;j++){
            cout<<printTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The PrintTable***************"<<endl;


}

int coinChangeInFinite(int N, int i){ // change needed
    // base cases:
    if(N==0) return 0;
    if(i==0) return 9999;
    if(N<0) return 9999;

    // checking the memo
    if(memo[N][i]!=-1) return memo[N][i];

    int call1,call2;
    call1=0+coinChangeInFinite(N,i-1);
    call2=1+coinChangeInFinite(N-coins[i],i);

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
            coinChangeInFinite(r,c);
        }
    }
    return memo[N][i];

}

void printTheCoins(int N,int i){ // change needed
    if(N==0 || i==0) return;

    if(printTable[N][i]=='T'){
        printTheCoins(N-coins[i],i);
        cout<<"Coin "<<i<<" has been taken, coin value:"<<coins[i]<<endl;
    }else{ // 'N'
        printTheCoins(N,i-1);
    }

}


int main(){
        int result = coinChangeFiniteBottomUp(N,numOfCoins);
        if(result==9999){
            cout<<"it is not possible to make the given amount"<<endl;
        }else{
            cout<<"min number of coins "<<result<<endl;
        }

        printMemo();
        printTheCoins(N,numOfCoins);
}

