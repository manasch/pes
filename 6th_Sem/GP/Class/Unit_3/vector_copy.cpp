//* Using this stub code change the 
//* age of persons in the objects 
//* put in the vector and see 
//* if they have changed the objects
//* themselves
#include <iostream>
#include <vector>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    void printInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create some Person objects
    Person p1 = Person("Apple", 20);
    Person p2 = Person("Ball", 22);
    Person p3 = Person("Cat", 25);
    

    // Add them to a vector
    std::vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    

    // Print the original info
    for (auto x: v) {
        x.printInfo();
    }
   

    // Modify the objects in the vector
    for (auto& p : v) {
        p.age += 1;
    }

    // Print the modified info
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();

    return 0;
}
