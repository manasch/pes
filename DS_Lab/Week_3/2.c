#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Department
{
    char *name;
    int number;
} Department;

typedef struct Node
{
    char *ssn;
    char *name;
    Department *department;
    char *designations;
    int salary;
    int phone_number;
    int age;
    struct Node *next, *prev;
} Node;

typedef struct Employees
{
    Node *head;
} Employees;


void init(Employees *);
void insert(Employees *, char *, char *, char *, int, char *, int, int, int);
void display(Employees *);
void display2(Employees *, char *);
void delete(Employees *, int);


int main()
{
    Employees emp;
    init(&emp);    
    
    int ch;
    char name[100], ssn[20], dname[20], designation[20];
    int dnum, sal, ph, age;
    char dept[20];
    int age1;
    
    while(1)
    {
        printf("\n1) Insert");
        printf("\n2) Display");
        printf("\n3) Display by dept");
        printf("\n4) Delete");
        printf("\n5) Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                printf("\nEnter ssn, name, department name, department number, designations, salary, phone number, age: \n");
                scanf("%s %s %s %d %s %d %d %d", ssn, name, dname, &dnum, designation, &sal, &ph, &age);
                insert(&emp, ssn, name, dname, dnum, designation, sal, ph, age);
                break;
            case 2:
                display(&emp);
                break;
            case 3:
            	printf("\nEnter department: ");
            	scanf("%s", dept);
                display2(&emp, dept);
                break;
            case 4:
            	printf("\nEnter the age after which records are to be deleted: ");
            	scanf("%d", &age1);
                delete(&emp, age1);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input");
                break;
        }
    }
}


void init(Employees *emp)
{
    emp->head = NULL;
}

void insert(Employees *emp, char *ssn, char *name, char *dname, int dnum, char *designation, int sal, int ph, int age)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->department = (Department *)malloc(sizeof(Department));
    
    temp->next = temp->prev = NULL;
    
    temp->ssn = (char *)malloc(sizeof(ssn));
    strcpy(temp->ssn, ssn);
    
    temp->name = (char *)malloc(sizeof(name));
    strcpy(temp->name, name);
    
    temp->department->name = (char *)malloc(sizeof(dname));
    strcpy(temp->department->name, dname);
    
    temp->designations = (char *)malloc(sizeof(designation));
    strcpy(temp->designations, designation);
    
    temp->department->number = dnum;
    temp->salary = sal;
    temp->phone_number = ph;
    temp->age = age;
    
    Node *pres;
    
    if (emp->head == NULL)
    	emp->head = temp;
   	else
   	{	
   		pres = emp->head;
   		
   		while(pres->next != NULL)
   			pres = pres->next;
   		
   		pres->next = temp;
   		temp->prev = pres;
   	}   
}

void display(Employees *emp)
{
	Node *pres;
	
	pres = emp->head;
	while (pres != NULL)
	{
		printf("(%s, %s, %s, %d, %s, %d, %d, %d) <=> ", pres->ssn, pres->name, pres->department->name, 
		pres->department->number, pres->designations, pres->salary, pres->phone_number, pres->age);
		pres = pres->next;
	}
}

void display2(Employees *emp, char *dept)
{
	Node *pres;
	
	pres = emp->head;
	while(pres != NULL)
	{
		if (strcmp(dept, pres->department->name) == 0)
			printf("(%s, %s, %s, %d, %s, %d, %d, %d) <=> ", pres->ssn, pres->name, pres->department->name, 
			pres->department->number, pres->designations, pres->salary, pres->phone_number, pres->age);
		pres = pres->next;	
	}
}

void delete(Employees *emp, int age)
{
	Node *pres;
	
	pres = emp->head;
	while(pres != NULL)
	{
		if(pres->age > age)
		{
			if(pres->prev == NULL)
			{
				emp->head = pres->next;
				pres->next->prev = NULL;
			}
			
			else if(pres->next == NULL)
			{
				pres->prev->next = NULL;
			}
			
			else
			{
				pres->prev->next = pres->next;
				pres->next->prev = pres->prev;
			}
		}
		
		pres = pres->next;
	}
}
