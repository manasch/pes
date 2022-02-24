heap.exe: test.o SRN_heap.o
	gcc -Wall test.o SRN_heap.o -o heap.exe

test.o: test.c heap.h
	gcc -Wall -c test.c

heap_server.o: SRN_heap.c heap.h
	gcc -Wall -c SRN_heap.c

debug:
	gcc -Wall -g SRN_heap.c test.c heap.h -o debug.exe

clean:
	rm -f test.o SRN_heap.o