#include <iostream>
// TODO create a dynamic array 
// TODO using new operator
// TODO btw can 'new' be overloaded
// TODO delete the array used delete x[]
// TODO twice and then access
// TODO x[0]
// * what should we use instead
int main() {
    //TODO  Dynamically allocate an array of integers
    int *x = new int(5);

    //TODO Initialize the array with some values
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;

    //TODO Delete the array twice (mistake!)
    delete[] x;
    delete[] x;

    //TODO  Access the array 
    std::cout << x[0] << std::endl;

    return 0;
}
