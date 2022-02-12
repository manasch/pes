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


int  main()
{
  struct tnode *root;
   
  printf("\nCreating Binary Tree.\n");
  root=create();
  printf("\npreorder traversal of binary  tree....\n");
  preorder(root);
 
}
  
 struct tnode *create()
 {
	 
	 int x;
	 struct tnode *temp;
	 
	 printf("\nEnter the element..");
	 scanf("%d",&x);
    
	 if(x==-1)
		 return NULL;
 
     temp=(struct tnode*)malloc(sizeof(struct tnode));
	 temp->data=x;
	 
	 printf("Creating the left subtree of %d... ",x);
	 
	 temp->left=create();
	 
	 printf("Creating the right subtree of %d ",x);
	 temp->right=create();
	 
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

  