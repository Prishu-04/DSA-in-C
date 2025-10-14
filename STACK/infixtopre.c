#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

// Node for stack
typedef struct node {
    char data;
    struct node *next;
} sn;

typedef struct {
    sn *top;
} stack;

void init(stack *s) {
    s->top = NULL;
}

int push(stack *s, char val) {
    sn *curr = (sn*)malloc(sizeof(sn));
    if (curr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    curr->data = val;
    curr->next = s->top;
    s->top = curr;
    return 0;
}

int pop(stack *s, char *d) {
    if (s->top == NULL) {
        return 1;
    }
    sn *temp = s->top;
    *d = temp->data;
    s->top = s->top->next;
    free(temp);
    return 0;
}

// Reverse string
void reverse(char *infix) {
    char swap;
    int i = 0;
    int j = strlen(infix) - 1;
    while (i < j) {   // ✅ fixed
        swap = infix[i];
        infix[i] = infix[j];
        infix[j] = swap;
        i++;
        j--;
    }
}
int precedence(char op){
     if(op=='^') return 3;
     if(op=='*' || op=='/') return 2;
     if(op=='+' || op=='-') return 1;
     return -1; 
}
void infixtopre(char *infix,stack *s){
     char prefix[100];
     int k=0,i=0;
     char temp;
     while(infix[i]!='\0'){
          if(isalnum(infix[i])){
               prefix[k++]=infix[i];
          } else if(infix[i]=='('){
               push(s,infix[i]);
          } else if(infix[i]==')'){
               while(s->top!=NULL){
                    pop(s,&temp);
                    if(temp=='(') break;
                    prefix[k++]=temp;
               }
          } else{
               if(s->top==NULL){
                    push(s,infix[i]);
               } else {
                    pop(s,&temp);
                    if(temp=='('){
                         push(s,temp);
                         push(s,infix[i]);
                    } else if(precedence(temp)>= precedence(infix[i])){
                         push(s,temp);
                         push(s,infix[i]);
                    } else{
                         prefix[k++]=temp;
                    }
               }
          }
          i++;
     }
     while(s->top!=NULL){
          pop(s,&temp);
          prefix[k++]=temp;
     }
     prefix[k]='\0';
     reverse(prefix);
     printf("Prefix Expression:%s\n",prefix);
}
int main() {
    stack s;
    init(&s);
    char infix[100];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    reverse(infix);
    infixtopre(infix,&s);
    return 0;
}