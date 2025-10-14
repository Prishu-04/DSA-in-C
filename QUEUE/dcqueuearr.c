#include<stdio.h>
#include<stdlib.h>

#define MAX 5
typedef struct {
     int data[MAX],f,r;
}dcqueue;
void init(dcqueue *q)
{
     q->f=q->r=-1;
}
int insert(dcqueue *q){
     int val,side;
     printf("Enter the value to be inserted:");
     scanf("%d",&val);
     printf("Enter side (0: Front, 1: Rear): ");
     scanf("%d",&side);
     if(q->f==(q->r+1)%MAX){
          printf("Queue is full\n");
          return -1;
     } else if(q->f==-1){
          q->f=q->r=0;
          q->data[q->r]=val;
     } else{
          if(side==0){
               q->f=(q->f+MAX-1)%MAX;
               q->data[q->f]=val;
          } else{
               q->r=(q->r+1)%MAX;
               q->data[q->r]=val;
          }
     }
     printf("Inserted %d at %s\n", val, side == 0 ? "front" : "rear");
     return val;
}
int delete(dcqueue *q){
     int side;
     printf("Enter side (0: Front, 1: Rear): ");
     scanf("%d",&side);
     if(q->f==-1){
          printf("Queue is empty\n");
          return -1;
     }
     int val=q->data[side==0?q->f:q->r];
     if(q->f==q->r){
          q->f=q->r=-1;
     } else{
          if(side==0){
               q->f=(q->f+1)%MAX;
          } else{
               q->r=(q->r+MAX-1)%MAX;
          }
     }
     printf("Deleted %d from %s\n", val, side == 0 ? "front" : "rear");
     return val;
}
void display(dcqueue q){
     if(q.f==-1){
          printf("Queue is empty\n");
          return;
     }
     printf("Queue elements: ");
     for (int i = 0; i < MAX; i++) {
          if (q.f == -1) {
               printf("|   ");
          } else {
               int pos = q.f;
               int found = 0;
               while (1) {
                    if (pos == i) {
                    printf("| %d ", q.data[i]);
                    found = 1;
                    break;
                    }
                    if (pos == q.r) break;
                    pos = (pos + 1) % MAX;
               }
               if (!found) printf("|   ");
          }
     }
     printf("|\n");
}
int main(){
     dcqueue q;
     init(&q);
     int choice,x;
     do{
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
          case 1: x=insert(&q);
                    break;
          case 2: x=delete(&q);
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