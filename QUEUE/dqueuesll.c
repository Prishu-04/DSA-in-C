#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
}sn;
typedef struct{
     sn*f,*r;
}dqueue;
void init(dqueue*q){
     q->f=NULL;
     q->r=NULL;
}
sn* insert(dqueue *q){
     int val,side;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     printf("Enter the side to insert\n(0.Front 1.Rear):");
     scanf("%d",&side);
     sn *curr=malloc(sizeof(sn));
     curr->data=val;
     curr->next=NULL;
     if(q->f==NULL){
          q->f=q->r=curr;
     } else{
          if(side==1){
               q->r->next=curr;
               q->r=curr;
          } else{
               curr->next=q->f;
               q->f=curr;
          }
     }
     printf("%d inserted at %s.\n", val, side ? "rear" : "front");
     return curr;
}
sn *delete(dqueue *q){
     int side;
     printf("Enter the side to delete\n(0.Front 1.Rear):");
     scanf("%d",&side);
     if(q->f==NULL){
          printf("Queue is empty\n");
          return NULL;
     }
     sn *ptr=NULL;
     if(q->f==q->r){
          ptr=q->f;
          q->f=q->r=NULL;
     }
     else {
          if(side==0){
               ptr=q->f;
               q->f=q->f->next;
          } else{
               sn *prev=q->f;
               while(prev->next!=q->r){
                    prev=prev->next;
               }
               ptr=q->r;
               prev->next=NULL;
               q->r=prev;
          }
     }
     printf("Deleted value: %d\n", ptr->data);
     return ptr;
}
void display(dqueue q){
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
     dqueue q;
     init(&q);
     int choice;
     sn *d;
     do {
          printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice:");
          scanf("%d",&choice);          
          switch(choice){
               case 1: d=insert(&q);
                    break;
               case 2: d=delete(&q);
                    break;
               case 3: display(q);
                    break;
               case 4: printf("Exiting...\n");
                    break;
               default: printf("Invalid choice\n");
          }
     }while(choice!=4);
     return 0;
}