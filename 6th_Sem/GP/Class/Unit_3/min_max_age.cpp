#include<bits/stdc++.h>

using namespace std;

class Person {
    public:
        string name;
        int age;

        Person(string n, int a) : name(n), age(a) {}
};

int main() {
    vector<Person> arr;

    arr.push_back(Person("Test", 25));
    arr.push_back(Person("Best", 35));
    arr.push_back(Person("Lest", 21));
    arr.push_back(Person("Cest", 5));
    arr.push_back(Person("Pest", 26));
    arr.push_back(Person("Kest", 95));

    // auto [minm, maxm] = minmax_element(arr);
    return 0;
}
