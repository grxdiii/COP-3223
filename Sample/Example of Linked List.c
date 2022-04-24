#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {

  char name[30];

  struct node *next;
};

struct node  *insertatfrontinlist(struct node *l, struct node node1);
struct node  *insertatbackinlist(struct node *l, struct node node1);
void printlis(struct node *l);

int main (void) {

  int i;
  struct node nodeA, *head;
  head=NULL;


  for(i=0;i<4;i++) {
    scanf( "%s", &nodeA.name);
    head= insertatbackinlist(head, nodeA);
  }
  printlis(head);
}

struct node  *insertatfrontinlist(struct node *l, struct node node1)
{
  struct node *temp;
  temp= (struct node *) malloc (       sizeof (struct node));

  strcpy(temp->name,node1.name);

  temp->next = l;
  return (temp);
}


struct node   *insertatbackinlist(struct node *l, struct node node1)
{
  struct node *temp, *temp2, *temp3;
  temp= (struct node *) malloc (       sizeof (struct node));

  strcpy(temp->name,node1.name);

  temp->next = NULL;


  temp2 = l;
  if (l==NULL)
    l=temp;

  else
  {
  while (temp2 != NULL){

    temp3= temp2;
    temp2 = temp2->next;
  }

  temp3->next = temp;
  }

  return (l);
}

void printlis(struct node *l)
{
  if (l==NULL) printf("Empty\n");
  while (l != NULL) { 
    printf("Name=%s \n", l->name);
    l = l->next;
  }
}
