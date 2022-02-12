typedef struct measure{
    int feet;
    float inch;
}unit;

void read(unit *m);
unit addm(unit *m1, unit *m2);
void display(unit *m);