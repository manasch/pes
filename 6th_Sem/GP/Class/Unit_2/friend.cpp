#include <iostream>

using namespace std;

class Container {
    private:
        int a;
    public:
        Container(int val) : a(val) {}
        friend void func();
};

void func() {
    cout << a << endl;
}

int main() {
    Container c(10);
    func();

    return 0;
}
