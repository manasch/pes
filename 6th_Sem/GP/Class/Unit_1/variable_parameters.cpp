#include <iostream>
#include <cstdarg>

using namespace std;

// No type checking for pointer, no type checking for variable number of arugements

void print_numbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        cout << va_arg(args, int) << endl;
    }

    va_end(args);
}

int main() {
    print_numbers(3, 1, "hello", 3);
    return 0;
}
