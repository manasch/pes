#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *next;
  struct node *prev;
  };
  
  typedef struct node node_t;
  
  struct dlist
  {
	  node_t* head;
  };
  
  typedef struct dlist dlist_t;
  
  void init_list(dlist_t*);
  void insert_head(dlist_t*,int);
  void display(dlist_t*);
  void insert_tail(dlist_t*,int);
 void delete_first(dlist_t*);
 void delete_last(dlist_t*);
  void delete_node(dlist_t*,int);
  void delete_pos(dlist_t*,int);
  void insert_pos(dlist_t*,int,int);
 /*void display_reverse_nodes(node_t *);
  void display_reverse(list_t *);
  int count_nodes(list_t*);
  int count_nodes_recur(node_t *);
  void reverse_list(list_t*);*/
  
  
  
  
  
  