#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sum = 0;

	printf("The numbers given are: \n");	
	for (int i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
		sum += atoi(argv[i]);
	}

	printf("\nSum of the entered numbers is: %d\n", sum);
	return 0;
}
