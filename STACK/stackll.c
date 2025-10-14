#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node *next;
}sn;
typedef struct{
     sn *top;
}stack;
void init(stack *s){
     s->top=NULL;
}
int push(stack *s){
     int val;
     printf("Enter value to be pushed:");
     scanf("%d",&val);
     sn* curr=malloc(sizeof(sn));
     if(curr==NULL){
          printf("Stack Overflow\n");
          return 1;
     }
     curr->data=val;
     curr->next=s->top;
     s->top=curr;
     return 0;
}
int pop(stack *s){
     if(s->top==NULL){
          printf("Stack Underflow\n");
          return 1;
     }
     sn* v=s->top;
     s->top=s->top->next;
     printf("Popped element is %d\n",v->data);
     free(v);
     return 0;
}
void display(stack s){
     if(s.top==NULL){
          printf("Stack is empty\n");
          return;
     }
     sn* curr=s.top;
     printf("Stack elements (top to bottom):\n");
     while(curr!=NULL){
          printf("-> | %d->|\n",curr->data);
          curr=curr->next;
     }
     printf("\n");
}
int main(){
     stack s;
     init(&s);
     int d,add;
     int choice;
     do{
          printf("1.Push\n2.Pop\n3.display\nEnter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1: add=push(&s);
                       break;
               case 2: d=pop(&s);
                       break;
               case 3: display(s);
                       break;
               default: printf("Invalid choice\n");
          }
     }while(choice<4);
     return 0;
}