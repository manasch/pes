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
