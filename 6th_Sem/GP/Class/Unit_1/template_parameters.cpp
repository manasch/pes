#include <iostream>

using namespace std;

template<typename T>
void print(T value, int num) {
    for (int i = 0; i < num; ++i) {
        cout << value << endl;
    }
}

// template<typename T>
// T Max(T lhs, T rhs) {
//     return (lhs > rhs) ? lhs : rhs;
// }

// int main() {
//     // print("apple", 11);
//     ::Max(10.5f, 5.5);
//     return 0;
// }

/*
#include <iostream>

using namespace std;

template<typename T, int N>
class Array {
  public:
  	int getSize() const {
      return N;
    }
  private:
  	T elem[N];
};

Doesn't initialize and throws an error for x as it is not const, otherwise it would instantiate 2 times one for 5 and one for 10
also the function isn't concrete unless it is explicitly called in the main function.

int main()
{
  	int x{5};
    Array<int, 5> MyArr1;
    Array<int, 10> MyArr2;
    Array<int, 5> MyArr3;
  	Array<int, x> MyArr4;
    // MyArr3.getSize();
  	return 0;
}
*/


