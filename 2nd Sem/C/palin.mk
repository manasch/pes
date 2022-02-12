a.exe: palin_c.o palin_s.o palin_s1.o
	gcc palin_c.o palin_s.o palin_s1.o
palin_c.o: palin_c.c palin.h
	gcc -c palin_c.c
palin_s.o: palin_s.c palin.h
	gcc -c palin_s.c
palin_s1.o: palin_s1.c palin.h
	gcc -c palin_s1.c