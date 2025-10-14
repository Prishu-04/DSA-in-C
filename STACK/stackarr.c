#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
     int data[MAX];
     int top;
}stack;
void init(stack *s){
     s->top=-1;
}
int push(stack *s){
     int val;
     printf("Enter value to be pushed:");
     scanf("%d",&val);
     if(s->top==MAX-1){
          printf("Stack is Overflow\n");
          return 1;
     }
     s->top++;
     s->data[s->top]=val;
     return 0;
}
void display(stack s) {
    if (s.top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = s.top; i >= 0; i--) {
            printf("->| %d |\n", s.data[i]);
        }
        printf("\n");
    }
}
int pop(stack *s, int *d){
     if(s->top==-1){
          printf("Stack is Underflow\n");
          return 1;
     }
     *d=s->data[s->top];
     s->top--;
     printf("Popped element is %d\n",*d);
     return 0;
}
int main(){
     stack s;
     init(&s);
     int d;
     int choice;
     do{
          printf("1.Push\n2.Display\n3.Pop\nEnter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1: int add=push(&s);
                       break;
               case 2: int d=pop(&s,&d);
                       break;
               case 3: display(s);  
                       break;
               default: printf("Invalid choice\n");
          }
     }while(choice<4);
     return 0;
}