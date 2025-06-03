#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    int id;
    // default constructor
    Person(){
        cout<<"The person with name "<<this->name <<" has been created"<<endl;
    }
    // parameterized constructor
    Person(string name,int id){
        this->name=name;
        this->id=id;
        cout<<"The person with name "<<this->name <<" has been created"<<endl;
    }
    // copy constructor
    Person(Person &person){
        this->name=person.name;
        this->id=person.id;
        cout<<"The copy constructor has been called"<<endl;
    }

    // destructor
    ~Person(){
        cout<<"The person with name "<<this->name <<" has been destroyed"<<endl;
    }
};

void nameChanger1(Person personX){ // pass by value // COPY CONSTRUCTOR WILL BE CALLED
    personX.name="Mr. "+personX.name;
    return; // DESTRUCTOR WILL BE CALLED FOR THE COPIED OBJECT
}

void nameChanger2(Person* personX){ // pass using pointer //NO COPY CONSTRUCTOR
    personX->name="Mr. "+personX->name;
    return; // NO DESTRUCTOR
}

void nameChanger3(Person &personX){ // pass by reference
    personX.name="Mr. "+personX.name;
    return; // NO DESTRUCTOR
}

void increment(int &z){
    z++;
}

int main(){
    int x=10;
//    int &ptr=x;;

//    //namceChanger1(person1);
//    //nameChanger2(&person1);
    Person person1("Clark Kent",10);


    nameChanger3(person1);
    cout<<"Changed name: "<<person1.name<<endl;

    Person person2("Bruce Wayne",12);

    return 0;
}
