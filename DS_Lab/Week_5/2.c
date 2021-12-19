// Write a program using priority queue to implement the record of covid vacccines such that priority is as follows:
//senior citizens greater than 65 age, person with health issues, person greater than 45 and finally 18+

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient
{
	char name[15];
	int age;
	int health_issues;
	int priority;
	struct patient *next;
} patient;

typedef struct queue
{
	patient *head;
} queue;

void init(queue *);
int enqueue(queue *);
int dequeue(queue *, char *);
void display(queue *);
void getpriority(patient *);

int main()
{
	int ch, res;
	char name[20];
	queue q;
	init(&q);
	
	while(1)
	{
		printf("\n1) Enqueue");
		printf("\n2) Dequeue");
		printf("\n3) Display");
		printf("\n4) Exit");
		printf("\nChoice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter the patient details:\n");
				res = enqueue(&q);
				if(res == 1)
					printf("\nPatient added to queue");
				else
					printf("\nPatient not added to queue");
				break;
			
			case 2:
				res = dequeue(&q, name);
				if(res)
					printf("\nPatient %s has exited the queue", name);
				else
					printf("\nQueue is empty");
				break;
			
			case 3:
				display(&q);
				break;
			
			case 4:
				exit(0);
			
			default:
				printf("\nInvalid Choice");
				break;
		}
	}
}

void init(queue *q)
{
	q->head = NULL;
}

void getpriority(patient *p1)
{
	if((p1->age < 45) && (p1->health_issues == 0))
		p1->priority = 1;
	
	else if((p1->age < 45) && (p1->health_issues == 1))
		p1->priority = 2;
	
	else if(((p1->age >= 45) && (p1->age < 65)) && (p1->health_issues == 0))
		p1->priority = 3;
	
	else if(((p1->age >= 45) && (p1->age < 65)) && (p1->health_issues == 1))
		p1->priority = 4;
	
	else if((p1->age >= 65) && (p1->health_issues == 0))
		p1->priority = 5;
	
	else if((p1->age >= 65) && (p1->health_issues == 1))
		p1->priority = 6;
}

int enqueue(queue *q)
{
	patient *pres, *prev;
	patient *temp = (patient *)malloc(sizeof(patient));
	temp->priority = 0;
	temp->next = NULL;
	
	printf("\nEnter the patient's name: ");
	scanf("%s", temp->name);
	
	printf("\nEnter the patient's age: ");
	scanf("%d", &(temp->age));
	
	printf("\nDoes the patient have health issue (1 or 0): ");
	scanf("%d", &(temp->health_issues));

	getpriority(temp);
	
	if(temp->age < 18)
	{
		return 0;
	}
	else
	{
		if(q->head == NULL)
			q->head = temp;
		else
		{
			pres = q->head;
			prev = NULL;
		
			while((pres->next != NULL) && (temp->priority <= pres->priority))
			{
				prev = pres;
				pres = pres->next;
			}
		
			if(prev == NULL) // inserting at first
			{
				q->head = temp;
				temp->next = pres;
			}
			else
			{
				prev->next = temp;
				temp->next = pres;
			}
		}
		return 1;
	}
}

int dequeue(queue *q, char *temp_name)
{
	patient *temp;
	if(q->head != NULL)
	{
		temp = q->head;
		q->head = temp->next;
		strcpy(temp_name, temp->name);
		free(temp);
		return 1;
	}
	else
		return 0;
}

void display(queue *q)
{
	patient *pres;
	int i = 0;
	char HI;
	
	if(q->head == NULL)
		printf("\nQueue is empty");
	else
	{
		pres = q->head;
		while(pres != NULL)
		{
			if(pres->health_issues == 1)
				HI = 'Y';
			else
				HI = 'N';
			printf("\n%d) Name: %s\n   Age: %d\n   Health Issues: %c\n", ++i, pres->name, pres->age, HI);
			pres = pres->next;
		}
	}
}