 //program to represent a directed graph using adjacency list
 #include<stdio.h>
 #include<stdlib.h>
   struct node
 {
 int data;
 struct node *next;
 };
  void creategraph(struct node **, int );
  void insert(struct node **, int ,int );
  void display(struct node **, int );
  int indegree(struct node **, int , int );
  int outdegree(struct node **,  int );
 int main()
 {
   int i,ch,v,n; 
   struct node *a[100];
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph(a,n);
   while(1)
  {
    printf("\n1. Indegree..\n");
    printf("2. Outdgree..\n");
    printf("3.Display..\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter the vertex..\n");
                   scanf("%d",&v);
                   i=indegree(a, n, v);
                   printf("Indegree of a vertex =%d",i);
                   break;
     case 2:   printf("Enter the vertex..\n");
                   scanf("%d",&v);
                   i=outdegree(a,v);
                   printf("out degree of a vertex =%d",i);
                   break;  
      case 3: display(a,n);
                   break;
    }
  }
}
         
void creategraph(struct node **a,int n)
{ 
	int i,j;
   for(i=1;i<=n;i++)
        a[i]=NULL;

    while(1)
   {
       printf("Enter the source and destination of the edge..");
      scanf("%d %d",&i,&j);
      if((i==-9)&&(j==-9))
         break;
      insert(a,i,j);
   }
}

 void insert(struct node **a, int i, int j)
 {
	 
	 struct node *temp;
	 temp=(struct node*)malloc(sizeof(struct node));
	 temp->data=j;
	 
    temp->next=a[i];
	a[i]=temp;
 }

 int outdegree(struct node **a, int v)
 {
	 struct node *temp;
	 int i,j;
	 int count;
	 
	 temp=a[v];
	 count=0;
	 while(temp!=NULL)
	 {
		 count++;
		 temp=temp->next;
	 }
	 return count;
 }
	 
 int indegree(struct node **a, int n, int v)
 {
	 struct node *temp;
	 int i,j,count;
	 count=0;
	 
	 for(i=1;i<=n;i++)
	 {
		 temp=a[i];
		 while(temp!=NULL)
		 {
			 if(temp->data==v)
				 count++;
			 temp=temp->next;
		 }
	 }
	 return count;
 }
	 

	void display(struct node **a , int n)
	{
        int i;
	   struct node *temp;
	   for(i=1;i<=n;i++)
	   {
	   printf("%d ->",i);
	   
	   temp=a[i];
	   
	   while(temp!=NULL)
	   {
		   printf("%d ",temp->data);
		   temp=temp->next;
	   }
	   printf("\n");
	   }
	}
		   
	