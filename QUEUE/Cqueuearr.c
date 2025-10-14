#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
     int data[MAX],f,r;
}cqueue;
void init(cqueue *q){
     q->f=-1;
     q->r=-1;
}
int insert(cqueue *q){
     int val;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     if(q->f==((q->r)+1)%MAX){
          printf("Queue Overflow\n");
          return -1;
     } else if(q->r==-1){
          q->f=q->r=0;
     } else{
          q->r=(q->r+1)%MAX;
     }
     q->data[q->r]=val;
     return val;
}
int delete(cqueue *q){
     if(q->f==-1){
          printf("Queue Underflow\n");
          return -1;
     }
     int val=q->data[q->f];
     if(q->f==q->r){
          q->f=q->r=-1;
     } else{
          q->f=(q->f+1)%MAX;
     }
     return val;
}
void display(cqueue q){
     if(q.f==-1){
          printf("Queue is empty\n");
          return;
     }
     int i = q.f;
    printf("Queue elements: ");
    while(1){
        printf("| %d ", q.data[i]);
        if(i == q.r) break;
        i = (i + 1) % MAX;
    }
    printf("|\n");
}
int main(){
     cqueue q;
     init(&q);
     int choice;
     int d;
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