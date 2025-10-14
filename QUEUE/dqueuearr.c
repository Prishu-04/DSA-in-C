#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
    int data[MAX],f,r;
}dqueue;

void init(dqueue *q){
    q->f=-1;
    q->r=-1;
}

int insert(dqueue *q){
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d",&val);
    int side;
    printf("Enter the side to insert\n(0.Front 1.Rear):");
    scanf("%d",&side);
    
    if(q->r==-1){
        q->f=q->r=0;
        q->data[q->r]=val;
    } else if((side==1 && q->r==MAX-1) || (side==0 && q->f==0)){
        printf("Queue is full\n");
        return -1;
    } else{
        if(side==0){
            q->f--;
            q->data[q->f]=val;
        } else{
            q->r++;
            q->data[q->r]=val;
        }
    }
    return 0;
}

int delete(dqueue *q){
    int side;
    printf("Enter the side to delete\n(0.Front 1.Rear):");
    scanf("%d",&side);
    
    if(q->r==-1){
        printf("Queue is empty\n");
        return -1;
    }
    
    int val=q->data[side==0?q->f:q->r];
    
    if(q->f==q->r){
        q->f=q->r=-1;
    } else{
        if(side==0){
            q->f++;
        } else{
            q->r--;
        }
    }
    
    printf("Deleted value: %d\n", val);
    return val;
}

void display(dqueue q){
    if(q.f==-1)
        printf("Queue is empty\n");
    else{
        int i;
        for(i=0;i<MAX;i++){
            if(q.f==-1 || i<q.f || i>q.r)
                printf("|   ");
            else{
                printf("| %d ",q.data[i]);
            }
        }
        printf("|\n");
    }
}

int main(){
    dqueue q;
    init(&q);
    int choice,d;
    
    do{
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
