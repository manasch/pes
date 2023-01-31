#include <iostream>

using namespace std;

class classy {
public:
    void printHello() {
        cout << "Hello" << endl;
    }
};

template <typename T = classy, typename U = int>
void func() {
    T i; U p;
    cout << typeid(i).name() << " ";
    cout << typeid(p).name() << endl;
}

template <typename T = classy>
struct laxyclass {
    int i;
    T obj;
};

template <typename T, typename U = double> struct multiTemplate;
template <typename T = int, typename U> struct multiTemplate; // Here you can mention the default first
template <typename T, typename U>
struct multiTemplate {
    T a;
    U b;
};

template <typename T, int size>
void print_array(T (&arr)[size]) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    func<int, int>();
    func<char, char>();
    func<>();
    func<char>();

    laxyclass<> notClass;
    notClass.obj.printHello();

    multiTemplate<> f1;
    cout << typeid(f1.a).name() << endl;
    cout << typeid(f1.b).name() << endl;

    int arr[] = {1, 2, 3, 4, 5};
    print_array(arr);
    double arr2[] = {1.1, 2.2, 3.3};
    print_array<double, 3>(arr2);
    
    return 0;
}
