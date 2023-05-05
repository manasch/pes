#include <iostream>

using namespace std;

template<typename T>
class MyClass {
    public:
        static int counter;
        MyClass() {
            ++counter;
        }
};

template<typename T>
int MyClass<T>::counter = 0; // Doesn't get instantiated here, it's kept somewhere.

int main() {
    MyClass<int> x;
    MyClass<double> y;

    cout << MyClass<int>::counter << endl;
    cout << MyClass<double>::counter << endl;

    return 0;
}
