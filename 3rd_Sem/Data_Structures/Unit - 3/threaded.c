//program to implement a threaded binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
  bool lthread;
  bool rthread;
};
struct tnode *insert(struct tnode *,int);
void inorder(struct tnode*);
struct tnode *inordersuccessor(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k;
  root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2..Inorder Traversal.");
      printf("\n3.exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 root=insert(root,num);
                 break;
         
         case 2:printf("Inorder traversal..\n");
               inorder(root);
               break;

         case 3:exit(0);
       }
    }
  }    
    
  void inorder(struct tnode *t)
  {
	  struct tnode *curr;
	  
	  curr=t;
	  
	  while(curr->lthread==false)
		  curr=curr->left;
	  while(curr!=NULL)
	  {
		  printf("%d ",curr->data);
		  curr=inordersuccessor(curr);
	  }
  }
  
  
   struct tnode* inordersuccessor(struct tnode *t)
   {
	   if(t->rthread==true)
		   return t->right;
	   t=t->right;
	   while(t->lthread==false)
		   t=t->left;
	   return t;
   }
	   
	struct tnode* insert(struct tnode *t, int key)
   {
	   struct tnode *curr,*temp;
	   
	   curr=t;
	   
	   temp=(struct tnode*)malloc(sizeof(struct tnode));
	   temp->data=key;
	   temp->left=temp->right=NULL;
	   temp->lthread=temp->rthread=true;
	   
	   if(curr==NULL) // first element,
	      return temp;
		  
	  while(1)
	  {
         if(key < curr->data)
		 {
			 if(curr->lthread==false)
				 curr=curr->left;
			 else
				 break;
		 }
		 if(key > curr->data)
		 {
			 if(curr->rthread==false)
				 curr=curr->right;
			 else
				 break;
		 }
	  }
	 if(key <curr->data)
	 {
         temp->left=curr->left;
		 temp->right=curr;
		 curr->left=temp;
		 curr->lthread=false;
	 }
	 else
	 {
		 temp->left=curr;
		 temp->right=curr->right;
		 curr->right=temp;
		 curr->rthread=false;
	 }
	 return t;
   }
		 
	   
	   
	   


































