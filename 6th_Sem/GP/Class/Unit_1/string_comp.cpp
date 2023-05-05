#include <iostream>

using namespace std;

void string_comp(string a, string b) {
    return *a = *b;
}

int main() {
    string s1 = "hello";
    string s2 = "bello";
    string_comp(s1, s2);
    return 0;
}
