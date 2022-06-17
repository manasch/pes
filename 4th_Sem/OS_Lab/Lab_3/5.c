#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main()
{
	int fd;
	char buff[BUFFER_SIZE] = "";

	// FIFO file path
	char myfifo[BUFFER_SIZE] = "/tmp/myfifo";

	printf("Enter the message to be passed\n");
	read(0, buff, BUFFER_SIZE);
	// Creating a named file(FIFOI
	mkfifo(myfifo, 0666);
	fd = open (myfifo, o_WRONLY);
	// write the input to FIF0 and close it
	write(fd, buff, strlen(buff)+1);
	close(fd);
	sleep(100);
	return 0;
}
