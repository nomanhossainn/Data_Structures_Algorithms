#include<iostream>
using namespace std;
string processString(string s){
    if(s.length()==0){
        return "";
    }

    char lastCharacter = s[s.length()-1];
    //cout<<"last Character: "<<lastCharacter<<endl;

    string substring = s.substr(0,s.length()-1);
    //cout<<"substring: "<<substring<<endl;

    string obtainedString = processString(substring);
    //cout<<"obtainedString: "<<obtainedString<<endl;


    if(lastCharacter==' '){
        return obtainedString;
    }

    if(lastCharacter>='A' && lastCharacter<='Z'){
        lastCharacter=tolower(lastCharacter);
        return obtainedString+lastCharacter;
    }

    return obtainedString+lastCharacter;



}

int main(){
    string x = processString("Bruce Wayne $$ AA");
    cout<<"The processed string is "<<x<<endl;
}





