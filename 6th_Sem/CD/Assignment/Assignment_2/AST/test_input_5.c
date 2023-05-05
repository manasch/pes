if (a > b) {
    a = a + 1;
    b = b - 1;
}
else {
    a = a - 1;
    b = b + 1;

    if (b > a) {
        a = 10;
    }
    else {
        b = 10;
    }
}
