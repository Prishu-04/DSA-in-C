#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>   // for isalnum()

// Node for stack
typedef struct node{
     char data;
     struct node *next;
} sn;

// Stack structure
typedef struct{
     sn *top;
} stack;

// Initialize stack
void init(stack *s){
     s->top=NULL;
}

// Push function
int push(stack *s, char val){
     sn *newnode=(sn*)malloc(sizeof(sn));
     if(newnode==NULL){
          printf("Memory allocation failed\n");
          return 1;
     }
     newnode->data=val;
     newnode->next=s->top;
     s->top=newnode;
     return 0;
}

// Pop function
int pop(stack *s, char *d){   
     if(s->top==NULL){
          return 1;   // underflow
     }
     sn *temp=s->top;
     *d=temp->data;
     s->top=s->top->next;
     free(temp);
     return 0;
}

// Precedence of operators
int precedence(char op){
     if(op=='^') return 3;
     if(op=='*' || op=='/') return 2;
     if(op=='+' || op=='-') return 1;
     return -1;
}

// Infix to Postfix conversion
void infixtopost(char *infix, stack *s){
     char postfix[100];
     int k=0,i=0;
     char temp;

     while(infix[i]!='\0'){
          if(isalnum(infix[i])){                 // Operand
               postfix[k++]=infix[i];
          } 
          else if(infix[i]=='('){                // Opening bracket
               push(s,infix[i]);
          } 
          else if(infix[i]==')'){                // Closing bracket
               while(s->top!=NULL){
                    pop(s,&temp);
                    if(temp=='(') break;
                    postfix[k++]=temp;
               }
          } 
          else {                                // Operator cases
               if(s->top==NULL){  
                    // Case 1: stack empty
                    push(s,infix[i]);
               } 
               else {  
                    pop(s,&temp);
                    if(temp=='('){
                        // Case 2: top is '('
                        push(s,temp);         // put back '('
                        push(s,infix[i]);     // push operator
                    }
                    else if(precedence(temp) < precedence(infix[i])){
                        // Case 3: new operator has higher precedence
                        push(s,temp);         // keep old operator
                        push(s,infix[i]);     // push new operator
                    }
                    else {
                        // Case 4: old operator >= new operator
                        postfix[k++]=temp;    // output old operator
                        continue;             // recheck with same infix[i]
                    }
               }
          }
          i++;
     }

     // Pop remaining operators
     while(s->top!=NULL){
          pop(s,&temp);
          postfix[k++]=temp;
     }

     postfix[k]='\0';
     printf("Postfix Expression: %s\n",postfix);
}

int main(){
     stack s;
     init(&s);
     char infix[100];
     printf("Enter infix expression: ");
     scanf("%s", infix);
     infixtopost(infix, &s);
     return 0;
}