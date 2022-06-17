linked_list.exe: linked_lists_client.o linked_lists_server_2.o
	gcc -Wall linked_lists_client.o linked_lists_server_2.o -o linked_list.exe

linked_lists_client.o: linked_lists_client.c list_1.h
	gcc -Wall -c linked_lists_client.c

linked_lists_server.o: linked_lists_server_2.c list_1.h
	gcc -Wall -c linked_lists_server_2.c

clean:
	rm -f linked_lists_client.o linked_lists_server_2.o