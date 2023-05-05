if (a > b) {
	a = a * 10;
	b = a;
}
else {
	a = b + 10;
	if (b == a) {
		b = b * 10;
		a = a / 10;
	}
	else {
		a = b + a;
	}
	b = a - 10;
}
c = a * b;
