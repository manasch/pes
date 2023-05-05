#include <iostream>
#include <typeinfo>
using namespace std;

void f (int) {cout << "f int\n";}
void f (double) {cout << "f double\n";}
void f (char) {cout << "f char\n";}

int main() {
   // f('a');
   // f(2.5);
   // f(25);

   void f(char);
   f(2.5);
   ::f(25);
   return 0;
}
