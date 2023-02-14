#include <iostream>

using namespace std;

class C {
    public:
        int x;
        int *X;

        C (int a) {
            X = new int;
            *X = a;
            cout << "Constructor called" << endl;
        }

        C (C &obj) {

        }

        C (const C &obj) {
            x = obj.x;
            cout << "Shallow Copy constructor called" << endl; // even if not done it is a shallow copy
        }
};

int main() {
    C c1(10);
    cout << "c1.x = " << c1.x << endl;
    C c2(c1);
    C c3 = c1; // Reference of an object

    cout << "c2.x = " << c2.x << endl;
    cout << "c3.x = " << c3.x << endl;

    return 0;
}