#include <iostream>
using namespace std;

int add(int, int);

void foo(int x) {
    cout << "foo int" << endl;
}

void foo(double x) {
    cout << "foo double" << endl;
}

int main() {
    cout << "res : " << add(3, 4) << endl;
    // cout << "res : " << add(3, 4, 5) << endl;
    cout << "res : " << add(3.5, 4.6) << endl;
    foo(20);
    foo(2.0);
}

int add(int x, int y) {
    return x + y;
}
