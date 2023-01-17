#include <iostream>
using namespace std;

void print_int(int* ptr) {
    cout << *ptr << endl;
}

int main() {
    double d = 3.14;
    print_int((int*) &d);
    return 0;
}
