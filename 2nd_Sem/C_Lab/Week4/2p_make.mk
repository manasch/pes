2p.exe: 2p_client.o 2p_server.o
	gcc 2p_client.o 2p_server.o -o 2p.exe
2p_client.o: 2p_client.c 2p_header.h
	gcc -c 2p_client.c
2p_server.o: 2p_server.c 2p_header.h
	gcc -c 2p_server.c
