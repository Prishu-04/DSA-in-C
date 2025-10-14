#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
     int data[MAX];
     int f,r;
}queue;
void init(queue *q){
     q->f=q->r=-1;
}
int insert(queue *q){
     int val;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     if(q->r==MAX-1){
          printf("Queue overflow\n");
          return -1;
     } else if(q->f==-1 && q->r==-1){
          q->f=q->r=0;
     } else{
          q->r++;
     }
     q->data[q->r]=val;
     return val;
}
int delete(queue *q){
     if(q->f==-1){
          printf("Queue underflow\n");
          return -1;
     }
     int val=q->data[q->f];
     if(q->f==q->r){
          q->f=q->r=-1;
     } else {
          q->f++;
     }
     return val;
}
void display(queue q){
     if(q.f==-1){
          printf("Queue is empty\n");
          return;
     }
     for(int i=q.f;i<=q.r;i++){
          printf("| %d ",q.data[i]);
     }
     printf("|\n");
}
int main(){
     queue q;
     init(&q);
     int d;
     int choice;
     do{
          printf("1.Insertion\n2.Deletion\n3.Display\nEnter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1:d=insert(&q);
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