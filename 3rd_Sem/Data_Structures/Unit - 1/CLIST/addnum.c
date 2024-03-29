//program to add two long numbers using circular lists with header node
#include<stdio.h>
#include<stdlib.h>

 struct node
 {
  int data;
  struct node *next;
 };
  void insert_first(int,struct node*);
  void create_head(struct node **);
  void sum(struct node *,struct node *, struct node *);
 void create_list(char*,struct node*);
 void display(struct node *);
 int main()
 {
  struct node *head1,*head2,*head3;
  char a[10],b[10];
  int x,ch,pos;
  head1=head2=head3=NULL;
  create_head(&head1);//creates the header node
  create_head(&head2);
  create_head(&head3);
  printf("Enter the first number\n");
  scanf("%s",a);
  printf("Enter the second number\n");
  scanf("%s",b);
  create_list(a,head1);
  printf("\n");
  display(head1);
  create_list(b,head2);
  printf("\n");
  display(head2);
  sum(head1,head2,head3);
  printf("\nsum=");
  display(head3);
 }
  
  void create_list(char *a, struct node *h)
  {
     int i=0;
     while(a[i]!='\0')
       {
        insert_first(a[i]-'0',h);
         i++;
       }

    }
 
  
  
    void create_head(struct node **h)
    {
      struct node *temp;
      temp=(struct node*)malloc(sizeof(struct node));
      temp->data=0;
      temp->next=temp;
       *h=temp;
     }



   void insert_first(int x, struct node *p)
   {
     struct node *temp;
     //struct node q=p;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=p->next;
     p->next=temp;
    }

    void sum(struct node *h1,struct node *h2, struct node *h3)
    {
      struct node *p,*q;
      int sum,carry;
      sum=carry=0;
      p=h1->next;
      q=h2->next;
   
       while((p!=h1)&&(q!=h2))
       {
         sum=(p->data+q->data+carry)%10;
         carry=(p->data+q->data+carry)/10;
         insert_first(sum,h3);
         p=p->next;
         q=q->next;
        }
       if(p==h1)
       {
         while(q!=h2)
         {
            sum=(q->data+carry)%10;
            carry=(q->data+carry)/10;
            insert_first(sum,h3);
            q=q->next;
           
          }
       }
       else
         {
          while(p!=h1)
          {
           sum=(p->data+carry)%10;
            carry=(p->data+carry)/10;
            insert_first(sum,h3);
            p=p->next;
           }
         }
       if(carry!=0)
          insert_first(carry,h3);
      }
      

    
     
    
