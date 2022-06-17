// write a program to validate the paranthesis using stack, note that opening bracket should be closed by same closing bracket in the same order
// without creating a new stack, the program seemed the work, when time figure out how it works


#include <stdio.h>
#include <stdlib.h>

void push(char *, int *, char);
void pop(char *, int *);
char peep(char *, int);
int check(char *);


int main()
{

	while (1)
	{
		char exp[20];
		printf("\nEnter the expression: ");
		scanf("%s", exp);
	
		int res = check(exp);
	
		if (res == 1)
			printf("\nValid use of brackets..\n");
		else
			printf("\nInvalid use of brackets..\n");
	}
}
	

void push(char *s, int *t, char ch)
{
	++*t;
	s[*t] = ch;
}

char peep(char *s, int t)
{
	return s[t];
}

void pop(char *s, int *t)
{	
	--*t;
}

int check(char *s)
{
	int i = 0;
	int top = -1;
	char ch;
	char s1[10];
	while(s[i] != '\0')
	{
		ch = s[i];
		
		switch (ch)
		{
			case '(':
				push(s1, &top, ch);
				break;
			
			case '{':
				push(s1, &top, ch);
				break;
			
			case '[':
				push(s1, &top, ch);
				break;
			
			case ')':
				if (peep(s1, top) != '(')
					return 0;
				pop(s1, &top);
				break;
			
			case '}':
				if (peep(s1, top) != '{')
					return 0;
				pop(s1, &top);
				break;
			
			case ']':
				if (peep(s1, top) != '[')
					return 0;
				pop(s1, &top);
				break;
		
			default:
				break;
		}
		i++;
	}
	if (top >= 0)
		return 0;
	return 1;
}
