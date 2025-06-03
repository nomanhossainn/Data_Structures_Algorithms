#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> vec;

    // create some data
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // read the data for each loop
    for(int x: vec){
        cout<<x<<" ";
    }
    cout<<endl;

    // inserting 40 at index 1
    vec.insert(vec.begin()+1,40);
    // read the data using indexing
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    // UPDATE
    vec[2]=200;

    // read the data using iterator

    for(auto it = vec.begin();it!=vec.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // Deletion
    vec.pop_back(); // deletes the last element
    vec.erase(vec.begin()+1); // deletes the element at index 1
        for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
