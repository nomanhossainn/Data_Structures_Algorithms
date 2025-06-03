#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> myMap;
    myMap.insert(make_pair(2,"TWO"));
    myMap.insert(make_pair(3,"XYZ"));
    myMap.insert(make_pair(4,"ABCDF"));

    for(pair<int,string> x : myMap){
        cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }
    myMap[3]="THREE";
    for(pair<int,string> x : myMap){
        cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }
    myMap.erase(3);
        for(pair<int,string> x : myMap){
        cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }
    return 0;
}



