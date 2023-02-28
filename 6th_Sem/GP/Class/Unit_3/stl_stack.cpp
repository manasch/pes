#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyStack {
    private:
        vector<T> stk;
    public:

        void push(T val) {
            stk.push_back(val);
        }

        T pop() {
            T temp = stk.back();
            stk.pop_back();
            return temp;
        }

        T peek() {
            return stk.back();
        }

        bool empty() {
            if (stk.size() == 0)
                return true;
            else
                return false;
        }

};

int main() {
    MyStack<int> s;
    s.push(10);
    s.push(20);

    cout << s.pop();
}