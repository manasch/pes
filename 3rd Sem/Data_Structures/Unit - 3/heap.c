 #include<stdio.h>
 //implement heap by using bottom up technique
  void bot_heap(int*,int);
  void top_heap(int *, int);
  
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
   bot_heap(h,n-1);//pass index of last element
   
   printf("After creating heap..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
   
  }


 void bot_heap(int *h, int n)//n is the index of the last element
 {
	 int i,j,k,key;
	 for(k=(n-1)/2; k>=0 ;k--)
	 {
		 j=k;
		 key=h[j];
		 i=2*j+1;//find the left child
		 while(i<=n) //until the left child exits
		 {
			 if((i+1)<=n) //check if the right child exists
			 {
				 if(h[i+1]>h[i]) 
					 i++; // index of the largest child
			 }
			 if(key < h[i])//compare the key with the largest child
			 {
				h[j]=h[i];//move the child up
			   j=i;
              i=2*j+1	;
			 }
			 else
				 break;
		 }			 
		h[j]=key;  //insert key at its proper place	 
	 }		 
 }		 
			 
			 
		 
		 
		 
		 
		 
	 
	 
	 
	 



































      






















