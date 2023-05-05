#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swap(T* a, T* b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    swap(x, y);
    cout << x << " " << y << endl;

    double a = 2.3;
    double b = 3.4;
    swap(a, b);
    cout << a << " " << b << endl;

    float f = 3.4;
    float g = 4.3;
    swap(f, g);
    cout << f << " " << g << endl;

    string s1 = "hello";
    string s2 = "world";
    swap(s1, s2);
    cout << s1 << " " << s2 << endl;
}
