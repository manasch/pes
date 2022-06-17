bst_test.exe: bst_test.o SRN_bst.o
	gcc -Wall bst_test.o SRN_bst.o -o bst_test.exe

bst_test.o: bst_test.c bst.h
	gcc -Wall -c bst_test.c


bst.exe: bst_client.o SRN_bst.o
	gcc -Wall bst_client.o SRN_bst.o -o bst.exe	

bst_client.o: bst_client.c bst.h
	gcc -Wall -c bst_client.c

bst_server.o: SRN_bst.c bst.h
	gcc -Wall -c SRN_bst.c

debug:
	gcc -Wall -g SRN_bst.c bst_client.c bst.h -o debug.exe

clean:
	rm -f test.o *.o *.o *.exe
