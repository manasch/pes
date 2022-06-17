3.exe: 3_server.o 3_client.o
	gcc 3_server.o 3_client.o -o 3.exe
3_server.o: 3_server.c 3_header.h
	gcc -c 3_server.c
3_client.o: 3_client.c 3_header.h
	gcc -c 3_client.c
