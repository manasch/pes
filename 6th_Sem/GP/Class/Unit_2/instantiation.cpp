#include <iostream>

using namespace std;

template<class T> class X {
    public:
        X* p;
        void f() {int i = 0;}
        void g() {int j = 0;}
};

int main() {
    X<int> *p;
    X<int> r;
    X<float> *q;
    // r.f();
    // q->g();
    return 0;
}
