#include <iostream>

using namespace std;

// class Engine {
//     public:
//         void start() {
//             cout << "Engine started" << endl;
//         }
//         ~Engine() {
//             cout << "Engine destroyed" << endl;
//         }
// };

// class Car {
//     private:
//         Engine engine;
//     public:
//         void start() {
//             engine.start();
//             cout << "Car started" << endl;
//         }
// };

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
