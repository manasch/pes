// A parking garage contains a single lane and hold 8 cars. Garage has only one entry and one exit. If a person arrives and takes his/her
// car that is not nearest to exit, all cars blocking its path are moved out then the person's car is driven out and other cars are 
// restored in same order as they were originally. WAP that process a group of inputs.
// Each input line contains an A - arrival & D - Departure and a lisence plate no. cars are assumed to arrive and depart in the order
// specified by the input. The program should print a message whenever car arrives / departs. When car arrives, the message should specify
// whether / not there is a room for the car in the garage. If there is no room the car leaves without entering garage. When a car departs,
// the message should include the no. of times that the car was moved out of the garage to allow other cars to depart.

#include <stdio.h>
#include <stdlib.h>

typedef struct car
{
	int license_plate;
	int move_count;
} car;

typedef struct garage
{
	car *c;
	int size;
	int top;
} garage;


int push(garage *, int);
int pop(garage *);
void display(garage *);
void init(garage *);
void insert(garage *, int);
int peep(garage *);
void delete(garage *, int);


int main()
{
	garage gar;
	init(&gar);

	char ch;
	int lp; // License plate number

	while(1)
	{
		printf("\n\nA) Arrival Car");
		printf("\nD) Departure Car");
		printf("\nG) Display Garage");
		printf("\nQ) Exit");
		printf("\nChoice: ");
		scanf("%c", &ch);
		switch (ch)
		{
			case 'A':
				printf("\n%d parking slots available", gar.size - (gar.top + 1));
				printf("\nEnter License Plate No.: ");
				scanf("%d", &lp);
				insert(&gar, lp);
				break;

			case 'D':
				printf("\nEnter the License Plate No.: ");
				scanf("%d", &lp);
				delete(&gar, lp);
				break;

			case 'G':
				display(&gar);
				break;

			case 'Q':
				exit(0);

			default:
				printf("\nInvalid Choice");
				break;
		}
		fflush(stdin);
	}
}

void init(garage *gar_ptr)
{
	gar_ptr->top = -1;
	// printf("\nEnter the number of cars in the garage: ");
	// scanf("%d", &(gar_ptr->size));
	gar_ptr->size = 8;
	gar_ptr->c = (car *)malloc(gar_ptr->size * sizeof(car));

	for (int i = 0; i < gar_ptr->size; i++)
	{
		gar_ptr->c[i].move_count = 0;
	}
}

int peep(garage *gar_ptr)
{
	return gar_ptr->c[gar_ptr->top].license_plate;
}

int push(garage *gar_ptr, int lp)
{
	if (gar_ptr->top == (gar_ptr->size) - 1)
		return 0;

	++(gar_ptr->top);
	gar_ptr->c[gar_ptr->top].license_plate = lp;
	gar_ptr->c[gar_ptr->top].move_count = 0;
	return 1;
}

void insert(garage *gar_ptr, int lp)
{
	printf("\nCar %d has arrived", lp);

	if (push(gar_ptr, lp) == 0)
	{
		printf("\nGarage is full");
		printf("\nCar %d has departed, it was moved 0 times", lp);
	}
}

int pop(garage *gar_ptr)
{
	if (gar_ptr->top == -1)
		return -1;
	
	int temp;
	temp = gar_ptr->c[gar_ptr->top].license_plate;
	
	// gar_ptr->c[gar_ptr->top].license_plate = -1;
	--(gar_ptr->top);
	return temp;
}

void delete(garage *gar_ptr, int lp)
{
	int *temp = (int *)malloc(gar_ptr->size * sizeof(int)); // temporary array of integers to store license plate numbers
	int lp_temp;
	int i = 0;

	while (lp != peep(gar_ptr))
	{
		lp_temp = pop(gar_ptr);

		if (lp_temp == -1)
			break;

		temp[i] = lp_temp;
		gar_ptr->c[(gar_ptr->top) + 1].move_count++;
		i++;
	}

	if (lp_temp == -1)
	{
		printf("\nCar with License No. %d does not exist in the garage.", lp);
	}
	else
	{
		lp_temp = pop(gar_ptr);
		printf("\nCar %d has departed, it was moved %d times(from stack)", lp_temp, gar_ptr->c[gar_ptr->top + 1].move_count);
	}
	
	while (--i >= 0)
	{
		push(gar_ptr, temp[i]);
		gar_ptr->c[gar_ptr->top].move_count = gar_ptr->c[(gar_ptr->top) + 1].move_count;
		gar_ptr->c[(gar_ptr->top) + 1].move_count = 0;
	}

	free(temp);
}

void display(garage *gar_ptr)
{
	if (gar_ptr->top == -1)
	{
		printf("\nEmpty Garage");
		return;
	}

	int i = gar_ptr->top;
	while (i >= 0)
	{
		printf("\n|\t%2d\t|", gar_ptr->c[i].license_plate);
		i--;
	}
}