#include<iostream>
using namespace std;

string encrypt(string input, int key){
    if(input.length()==0){
        return "";
    }

    char firstCharacter=input[0];
    int length=input.length();
    string remainingString = input.substr(1,length-1);

    char firstCharacterEncrypted = firstCharacter+key;
    string remainingStringEncrypted = encrypt(remainingString,key+1);

    string combinedString = firstCharacterEncrypted+remainingStringEncrypted;

    return combinedString;
}


int main(){
    string input;
    int key;

    cin>>input;
    cin>>key;
    cout<<endl;
    cout<<encrypt(input,key)<<endl;
    return 0;
}
