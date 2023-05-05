#include <iostream>

using namespace std;

class X {
    public:
        int a;
        void foo() {
            cout << "My a is " << a << endl;
            boo();
        }
    
    private:
        int boo() {
            cout << "Boo !" << endl;
        }
};

int main() {
    X a;
    return 0;
}

// Convert to C

/*
#include <stdio.h>

struct X {
    int a;
    void foo() {
        printf("My a is %d\n", a);
        boo();
    }

    int boo() {
        printf("Boo !\n");
    }
};

int main() {
    struct X a;
    return 0;
}

struct X {
    int a;
}

void foo(struct X* x) {
    printf("My a is %d\n", x->a);
}

int boo(struct X* x) {
    printf("Boo !");
}

*/

