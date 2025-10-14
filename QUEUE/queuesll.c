#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
}sn;
typedef struct {
     sn *f,*r;
}queue;
void init(queue *q){
     q->f=q->r=NULL;
}
sn* insert(queue *q){
     int val;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     sn *curr=malloc(sizeof(sn));
     curr->data=val;
     curr->next=NULL;
     if(q->r==NULL){
          q->f=q->r=curr;

     } else {
          q->r->next=curr;
          q->r=curr;
          
     } 
     return curr;    
}
sn* delete(queue *q){
     if(q->f==NULL){
          printf("Queue underflow\n");
          return NULL;
     } 
     sn *ptr=q->f;
     int val=ptr->data;
     q->f=q->f->next;
     if(q->f==NULL){
          q->r=NULL;
     }
     return ptr;
}
void display(queue q){
     if (q.f == NULL) {
          printf("Queue is empty.\n");
          return;
     }

     printf("Queue elements:\n");
     sn *temp = q.f;
     while (temp != NULL) {
          printf("| %d->", temp->data);
          temp = temp->next;
     }
     printf("|\n");
}
int main(){
     queue q;
     init(&q);
     int choice;
     sn *val;
     do{
          printf("1.Insertion\n2.Deletion\n3.Display\nEnter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1: val=insert(&q);
                       break;
               case 2: val=delete(&q);
                       break;
               case 3: display(q);
                       break;
               default: printf("Invalid choice\n");
          }
     }while(choice<=3);
     return 0;
}