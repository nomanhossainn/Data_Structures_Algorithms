#include<iostream>
using namespace std;
void pallindromeChecker(string s){
    if(s.length()==1){
        cout<<"Palindrome"<<endl;
        return;
    }

    if(s.length()==2){
        char firstCharacter=s[0];
        char lastCharacter=s[1];

        if(firstCharacter==lastCharacter){
            cout<<"Palindrome"<<endl;
        }else{
            cout<<"Not Palindrome"<<endl;
        }

        return;
    }
    int length = s.length();
    char firstCharacter=s[0];
    char lastCharacter=s[length-1];

    if(firstCharacter==lastCharacter){
        // recursive call
        string substring = s.substr(1,length-2);
        pallindromeChecker(substring);

    }else{
        cout<<"Not Palindrome"<<endl;
        return;
    }


}

int main(){
//    string s = "abcd";
//    cout<<"length function "<<s.length()<<endl;
//
//    // substring function
//    cout<<"substring function "<<s.substr(1,3)<<endl;
    pallindromeChecker("ab");
}




