#include <iostream>

using namespace std;

int main() {
    // int a = 5;
    // int &b = a;
    // int &c = b;

    // int d = 5;
    // int *e = &d;
    // int **f = &e;


    // cout << a << " " << b << " " << c << endl;
    // cout << d << " " << e << " " << f << endl;

    int a = 5;
    int *p = &a;
    int* (&c) = p; // ?>>>>???>?>

    cout << p << " " << c << endl;
    return 0;
}