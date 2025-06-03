#include<iostream>
using namespace std;

template <typename t1>
class MyClass{
    public:
    t1 x;
    t1 y;
    int id;

    MyClass(t1 x, t1 y){
        this->x=x;
        this->y=y;
    }

    t1 additionResult(){
        t1 sum = this->x+this->y;
        return sum;
    }

};


int main(){
    MyClass<int> myobj1(1,2);
    int result1 = myobj1.additionResult();
    cout<<"result1 "<<result1<<endl;

    MyClass<string> myobj2("Hello ","World");
    string result2 = myobj2.additionResult();
    cout<<"result2 "<<result2<<endl;

    return 0;
}

