
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;

}*front=NULL,*rear=NULL;
void enqueue(int x)
{
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
 printf("OVERFLOW\n");
 else
 {
 t->data=x;
 t->next=NULL;
 if(front==NULL)
 front=rear=t;
 else
 {
 rear->next=t;
 rear=t;
 }
 }

}
int dequeue()
{
 int x=-1;
 struct Node* t;

 if(front==NULL)
 printf("UNDERFLOW\n");
 else
 {
 x=front->data;
 t=front;
 front=front->next;
 free(t);
 }
 return x;
}
void Display()
{
 struct Node *p=front;
 while(p)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}
int main()
{ int choice,x;
while(choice!=3)
{ printf("Enter the choice:\n1.Insert\n2.Delete\n3.Exit\n");
scanf("%d",&choice);
  if(choice==1)
  {
    printf("Enter value :");
    scanf("%d",&x);
    enqueue(x);
     Display();
  }
   if(choice==2)
  {
    
    dequeue();
     Display();
  }
}

 return 0;
}