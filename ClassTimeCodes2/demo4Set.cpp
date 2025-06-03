#include<iostream>
#include<set>

using namespace std;
int main(){
    set<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(10);
    mySet.insert(10);
    mySet.insert(10);

    // read the data for each loop
    for(int x: mySet){
        cout<<x<<" ";
    }
    cout<<endl;

    mySet.erase(10);
    // read the data for each loop
    for(int x: mySet){
        cout<<x<<" ";
    }


    cout<<endl;
    return 0;
}


