#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
     sn *curr=malloc(sizeof(sn));
     if(curr==NULL){
          return 1;
     }
     curr->data=val;
     curr->next=s->top;
     s->top=curr;
     return 0;
}
int pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    sn *d = s->top;
    int val = d->data;
    s->top = s->top->next;
    free(d);
    return val;
}
int evalutepost(stack *s, char *postfix){
     int j=strlen(postfix);
     for(int i=0;i<j;i++){
          if(isdigit(postfix[i])){
               push(s,postfix[i]-'0');
          } else{
               int right = pop(s);
               int left = pop(s);
               int res;

               switch (postfix[i]) {
               case '+': res = left + right; break;
               case '-': res = left - right; break;
               case '*': res = left * right; break;
               case '/': res = left / right; break;
               default:
               printf("Invalid operator %c\n", postfix[i]);
               exit(1);
               }
               push(s,res);
          }
     }
     return pop(s);
}
int main(){
     stack s;
     init(&s);
     char postfix[100];
     printf("Enter the expression:");
     scanf("%s",postfix);
     int res = evalutepost(&s, postfix);
     printf("Result = %d\n", res);
}