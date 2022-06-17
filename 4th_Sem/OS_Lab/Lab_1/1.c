#include <stdio.h>
#include <unistd.h>

int main() {
	int pid = getpid(); // id
	int ppid = getppid(); // parent id

	printf("Process ID: %d\n", pid);
	printf("Process Parent ID: %d\n", ppid);

	return 0;
}
