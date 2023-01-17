#include <iostream>
using namespace std;

class Time {
    int hour;
    int mins;
    public:
        Time(int t) {
            hour = t / 60;
            mins = t % 60;
        }

        void Display() {
            cout << "Hour: " << hour << " " << "Mins: " << mins << endl;
        }
};

int main() {
    // Object of Time class
    int dur = 95;
    Time T1(dur);
    
    // conversion of int type to class type
    T1.Display();
    return 0;
}
