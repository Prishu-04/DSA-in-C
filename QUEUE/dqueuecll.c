#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
}sn;
typedef struct{
     sn*f,*r;
}dcqueue;
void init(dcqueue*q){
     q->f=NULL;
     q->r=NULL;
}
sn* insert(dcqueue *q){
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
          curr->next=q->f;
     } else{
          if(side==1){
               curr->next=q->f;
               q->r->next=curr;
               q->r=curr;
          } else{
               curr->next=q->f;
               q->r->next=curr;
               q->f=curr;
          }
     }
     printf("%d inserted at %s.\n", val, side ? "rear" : "front");
     return curr;
}
sn *delete(dcqueue *q){
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
               q->r->next=q->f->next;
               q->f=q->f->next;
          } else{
               ptr=q->f;
               sn *prev=q->f;
               do{
                    prev=prev->next;
               }while(prev->next!=q->r);
               prev->next=q->f;
               q->r=prev;
          }
     }
     printf("Deleted value: %d\n", ptr->data);
     return ptr;
}
void display(dcqueue q){
     if(q.f==NULL){
          printf("Queue is empty\n");
          return;
     }
     printf("Queue elements:\n");
     sn *temp=q.f;
     do{
          printf("| %d->",temp->data);
          temp=temp->next;
     }while(temp!=q.f);
     printf("| %d->\n",q.f->data);
}
int main(){
     dcqueue q;
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