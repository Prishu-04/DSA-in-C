#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node* next;
}sn;
typedef struct {
     sn*f,*r;
}cqueue;
void init(cqueue *q){
     q->f=q->r=NULL;
}
sn* insert(cqueue *q){
     int val;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     sn *curr=malloc(sizeof(sn));
     curr->data=val;
     curr->next=NULL;
     if(q->f==NULL){
          q->f=q->r=curr;
          curr->next=q->f;
     } else{
          curr->next=q->f;
          q->r->next=curr;
          q->r=curr;
     }
     return curr;
}
sn* delete(cqueue *q){
     if(q->f==NULL){
          printf("Queue Underflow\n");
          return NULL;
     }
     sn *ptr=q->f;
     int val=ptr->data;
     if(q->f==q->r){
          q->f=q->r=NULL;
     } else{
          q->r->next=q->f->next;
          q->f=q->r->next;
     }    
     return ptr;
}
void display(cqueue q){
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
     cqueue q;
     init(&q);
     int choice;
     sn *d;
     do{
          printf("1.Insertion\n2.Deletion\n3.Display\nEnter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1: d=insert(&q);
                       break;
               case 2: d=delete(&q);
                       break;
               case 3: display(q);
                       break;
               default: printf("Invalid choice\n");
          }
     }while(choice<=3);
     return 0;
}