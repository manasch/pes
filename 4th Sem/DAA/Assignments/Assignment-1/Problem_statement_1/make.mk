heap_test.exe: test.o SRN_heap.o
	gcc -Wall test.o SRN_heap.o -o heap_test.exe

test.o: test.c heap.h
	gcc -Wall -c test.c


heap.exe: heap_client.o SRN_heap.o
	gcc -Wall heap_client.o SRN_heap.o -o heap.exe

heap_client.o: heap_client.c heap.h
	gcc -Wall -c heap_client.c

heap_server.o: SRN_heap.c heap.h
	gcc -Wall -c SRN_heap.c

debug:
	gcc -Wall -g SRN_heap.c test.c heap.h -o debug.exe

clean:
	rm -f test.o *.o *.o *.exe
