#include <iostream>

using namespace std;

class Base{
public:
    Base(){
        cout << "Base" << endl;
    }
    ~Base(){
        cout << "~Base" << endl;
    }
};

class A{
public:
    A(){
        cout << "A" << endl;
        Base base;
    }
    ~A(){
        cout << "~A" << endl;
    }
};

int main () {

    A a;

    return 0;
}