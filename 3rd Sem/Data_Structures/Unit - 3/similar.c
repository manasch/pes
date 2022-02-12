//program to check if two trees are identical
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
struct tnode* create();
void preorder(struct tnode *);

int identical(struct tnode*, struct tnode*);
int  main()
{
  struct tnode *root1,*root2;
  int ch,num,k,n,result;
  root1=NULL;
  root2=NULL;
 
  printf("\nCreating first tree..\n");
  root1=create();
  printf("\nTraversal in preorder of first tree");
  preorder(root1);

  printf("\nCreating second  tree..\n");
  root2=create();
  printf("\nTraversal in preorder of second tree");
  preorder(root2);
    
  result=identical(root1,root2);
  if(result)
   printf("trees identical..\n");
 else
  printf("Not Identical\n");
}
  
  int identical(struct tnode *t1, struct tnode *t2)
  {
	  int l,r;
	  if((t1==NULL) && (t2==NULL))
	      return 1;
	  if((t1!=NULL)&&(t2!=NULL))
	  {
		  if(t1->data==t2->data) // compare the roots
		  {
			   l=identical(t1->left,t2->left); //compare the left subtree
			    if(l==0)
                    return 0;
			   r=identical(t1->right,t2->right);// compare right subtree
		      return(l&&r);
		  }
		  return 0;
	  }
	  return 0;
  }
	  
  
  
  struct tnode *create()
  {
	  
	  int x;
	  
	  struct tnode *temp;
	  
	  printf("Enter the element ..");
	  scanf("%d",&x);
	  
	  if(x==-1)
		  return NULL;
	  temp=(struct tnode *)malloc(sizeof(struct tnode));
	  temp->data = x;
	  
	  printf("Creating left subtree of %d...\n ",x);
	  temp->left=create();
		 
	  printf("Creating the right subtree of %d...\n",x);
      temp->right =create();	
	   	 	 
      return temp;
   }
  
	     
 
	 
	 
	 
 void preorder(struct tnode *t)
   {
     if(t!=NULL)
     {
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
     }
  }






 
