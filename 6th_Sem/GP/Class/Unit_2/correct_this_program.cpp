#include<iostream>
using namespace std;

template<typename T>
class Wrap;

template<typename T>
void friendFunc(Wrap<T>); // doesn't work

template<typename T>
class Wrap {
    private:
     int data;
    public:
    void set() { this->data = 10;}
    friend void friendFunc<>(Wrap<T> &wrap);
};

template<typename T>
void friendFunc(Wrap<T> &wrap) {
    cout << wrap.data << endl;
}

int main() {
    Wrap<int> wrap;
    wrap.set();
    friendFunc(wrap);
    return 0;
}

