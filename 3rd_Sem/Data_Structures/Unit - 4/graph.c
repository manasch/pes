 //program to represent a directed graph using adjacency matrix
 #include<stdio.h>
  void creategraph(int (*)[],int);
  int indegree(int (*)[], int , int);
 int outdegree(int (*)[],int,int);
 void display(int (*)[], int);
 int main()
 {
   int i,ch,v; 
   int a[100][100],n;
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
                   i=outdegree(a,n,v);
                   printf("out degree of a vertex =%d",i);
                   break;     
      case 3: display(a,n);
                   break;
    }
  }
}
       
void display(int (*a)[100], int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	   for(j=1;j<=n;j++)
	      printf("%d ",a[i][j]);

                    printf("\n");
	}
}
  
	 	   
		 
 void creategraph(int (*a)[100],int n)
  {
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          a[i][j]=0;
		
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=1; //a[i][j]=a[j][i]=1// for indirected graph
     }
  }

  int indegree(int (*a)[100], int n, int v)
  {
     int i,count=0;
   
     for(i=1;i<=n;i++)
     {
        if(a[i][v]==1)
           count++;
    }
   return count;
}

    int outdegree(int (*a)[100], int n, int v)
  {
     int i,count=0;
   
     for(i=1;i<=n;i++)
     {
        if(a[v][i]==1)
           count++;
    }
   return count;
}


  
   

  
   

      

     



