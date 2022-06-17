p2.exe: p2_client.o p2_server.o
	gcc p2_client.o p2_server.o -o p2.exe
p2_client.o: p2_client.c p2_header.h
	gcc -c p2_client.c
p2_server.o: p2_server.c p2_header.h
	gcc -c p2_server.c 