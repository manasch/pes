> 07/02/23

 a constructor for class C

```cpp
#include <iostream>

class C {
	public:
		int x;
		int *y;
};

int main() {
	C c1(10);
	C c2(c1);
	C c3 = c1; // Reference of an object

	std::cout << "c2.x = " << c2.x << std::endl;
	std::cout << "c3.x = " << c3.x << std::endl;

	return 0;
}
```

- By default does it as a shallow copy, but if you implement it it does it as a deep copy.
- Always impement it as a deep copy
```cpp
#include <iostream>
using namespace std;
class C {
    public:
        int x;
        int *X;

        C (int a) {
            X = new int;
            *X = a;
            cout << "Constructor called" << endl;
        }

        C (C &obj) {
        }

        C (const C &obj) {

            x = obj.x;
            cout << "Shallow Copy constructor called" << endl; // even if not done it is a shallow copy
        }
};

int main() {
    C c1(10);
    cout << "c1.x = " << c1.x << endl;
    
    C c2(c1);
    C c3 = c1; // Reference of an object

    cout << "c2.x = " << c2.x << endl;
    cout << "c3.x = " << c3.x << endl;
    
    return 0;
}
```

##  Composition

```cpp
#include <iostream>

using namespace std;

class Engine {
    public:
        void start() {
            cout << "Engine started" << endl;
        }
        ~Engine() {
            cout << "Engine destroyed" << endl;
        }
};

class Car {
    private:
        Engine engine;
    public:
        void start() {
            engine.start();
            cout << "Car started" << endl;
        }
};

int main() {
    Car c;
    c.start();

    return 0;
}
```

- Templatize it

```cpp
template <typename E>
class Engine {
    public:
        void start() {
            cout << "Ending started of type " << typeid(E).name() << endl;
        }
};

template <typename C, typename E>
class Car {
    private:
        Engine<E> engine;
    public:
        void start() {
            engine.start();
            cout << "Car started of type " << typeid.(C).name() << endl;
        }
};

int main() {
    Car<int, float> c;
    c.start();

    return 0;
}
```

- STL templates handle destructors well hence no memory leak, but if done manually could lead to memory leaks
```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    private:
        vector<char> m_data;
    
    public:
        MyString() {} //Empty constructor

        void assign(const char *str) {
            m_data.clear();
            m_data.insert(m_data.end(), str, str + strlen(str));
            m_data.push_back('\0');
        }

        const char *c_str() const {
            return &m_data[0];
        }
};

int main() {
    MyString my_string;
    cout << "Before assignment: " << (my_string.c_str() == nullptr ? "nullptr" : "not nullptr") << endl;

    my_string.assign("Hello World!");

    cout << "After assignment: " << my_string.c_str();

    return 0;
}
```

- Template

```cpp
template <typename Whole, typename Part>
class MyString {
    private:
        vector<Part> m_data;
    
    public:
        MyString() {} //Empty constructor

        void assign(const Whole *str, size_t size) {
            m_data.clear();
            m_data.insert(m_data.end(), str, str + size);
            m_data.push_back('\0');
        }

        const char *c_str() const {
            return &m_data[0];
        }
};
```

## Destructors

- By default if you compose a class with other classes, when you destroy a parent class, the composed classes don't get destroyed automatically, they need to be manually destroyed in the parent class' destructor.
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
    public:
        Person(const string& name) : name(name) {}
        ~Person() {
            cout << name << " died" << endl;
        }
        string name;
};

class House {
    public:
        House(const string& address) : address(address) {}
        ~House() {
            cout  << "House at " << address << " was destroyed" << endl;
        }
        string address;
};

class Town {
    public:
        Town() {
            cout << "Town was created" << endl;
        }

        ~Town() {
            for (auto p: people) {
                delete p;
            }

            for (auto h: houses) {
                delete h;
            }
            
            cout << "Town was destroyed" << endl;
        }

        void add_person(Person* person) {
            people.push_back(person);
        }

        void add_house(House* house) {
            houses.push_back(house);
        }
    private:
        vector<Person*> people;
        vector<House*> houses;
};

int main() {
    cout << "Entering main" << endl;
    Town* town = new Town();
    town->add_person(new Person("John"));
    town->add_house(new House("123 Main St."));

    delete town;
    cout << "Leaving main" << endl;

    return 0;
}
```

###### output
```bash
.\a.exe
Entering main
Town was created
John died
House at 123 Main St. was destroyed
Town was destroyed
Leaving main
```

---
