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
int push(stack *s,int val){
     sn *curr=(sn *)malloc(sizeof(sn));
     if(curr==NULL){
          return 1;
     }
     curr->data=val;
     curr->next=s->top;
     s->top=curr;
     return 0;
}
int pop(stack *s, int *d){
     if(s->top==NULL){
          return 1;
     }
     sn *temp=s->top;
     *d=temp->data;
     s->top=s->top->next;
     free(temp);
     return 0;
}
void rev(stack *s,stack *ns){
     int temp;
     while(s->top!=NULL){
          pop(s,&temp);
          push(ns,temp);
     }
}
void display(stack ns){
     if(ns.top==NULL){
          printf("Stack is empty\n");
          return;
     }
     sn* curr=ns.top;
     printf("Stack elements (top to bottom): ");
     while(curr!=NULL){
          printf("%d ",curr->data);
          curr=curr->next;
     }
     printf("\n");
}
int main(){
     stack s,ns;
     init(&s);
     init(&ns);
     int n;
     printf("Enter the number of nodes to be entered:");
     scanf("%d",&n);
     int val;
     for(int i=0;i<n;i++){
          printf("Enter value to be pushed:");
          scanf("%d",&val);
          push(&s,val);
     }
     display(s);
     rev(&s,&ns);
     display(ns);
     return 0;
}