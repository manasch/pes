#include<stdio.h>
int input_prec(char);
int stack_prec(char);
char peep(char *,int);
void convert_postfix(char*,char*);
void push(char *, int *, char);
char pop(char *, int *);
int main()
{
  char infix[10],postfix[10];
  printf("\nEnter valid Infix Expression\n");
  scanf("%s",infix);
  convert_postfix(infix,postfix);
  printf("\nThe postfix equivalent=%s\n",postfix);
}

void convert_postfix(char *infix, char *postfix)
{
	char s[10]; //stack of characters
	int top,i,j;
	char ch;
	top=-1;
	i=0;
	j=0;
	push(s,&top,'#'); //push # on to stack
	
	while(infix[i]!='\0')
	{
		ch=infix[i];
		//pop from the stack as long as the 
		//stack precedence of the top of the stack
		//is greater than the input precedence of input symbol
		while(stack_prec(peep(s,top))>input_prec(ch))
			postfix[j++]=pop(s,&top);
		//otherwise
		if(input_prec(ch) > stack_prec(peep(s,top)))
			push(s,&top,ch);
		else
			pop(s,&top); //happens when you compare '(' with ')'
		i++;
  }//end while
  while(peep(s,top)!='#') // pop remaining from the stack
	  postfix[j++]=pop(s,&top);
  postfix[j]='\0';
  }
		 
 
 //function to return the input precedence

  int input_prec(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':return 1;
      case '*':
      case '/':return 3;
      case '$':return 6;
      case '(':return 9;
      case ')':return 0;
      default:return 7;
    }
 }
  //function to return the stack precedence
  int stack_prec(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':return 2;
      case '*':
      case '/':return 4;
      case '$':return 5;
      case '(':return 0;
      case '#':return -1;
      default:return 8;
    }
 }

  char peep(char * s, int t)
  {
    return s[t];
  }
    
  void push(char *s, int *t, char x)
  {
    ++*t;
    s[*t]=x;
  }
  
   char pop(char *s, int *t)
   {
     char x;
      x=s[*t];
     --*t;
    return x;
  }

  
/*void convert_postfix(char *infix,char*postfix)
 {
    char s[10];//stack
    int top=-1,i,j;
    i=0;
    char ch;
    j=0;
    push(s,&top,'#');
	
	//scan infix expressipon from left to right
    while(infix[i]!='\0')
    {
      ch=infix[i];
	  //compare the stack precedence of top of the stack
	 // with the input precedence of symbol scanned
	 //while stack precedence of top of stack is greater 
	 //than the input symbol, keep popping and store
	 //in postfix
	 while(stack_prec(peep(s,top))>input_prec(ch))
          postfix[j++]=pop(s,&top);
	  //if input precednce of input symbol is greater than
	  //stack precednce of top of the stack
      if(input_prec(ch)>stack_prec(peep(s,top)))
         push(s,&top,ch);
       else
		   //if input precedence of symbol is equal to the stack precedence of top of stack 
	     //happens when you compare '(' with ')'
         pop(s,&top); 
     i++;
    }
	
	//pop remaining contents of stack and store in postfix
    while(peep(s,top)!='#')
      postfix[j++]=pop(s,&top);
    postfix[j]='\0';
  } 
  */       









  
