#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
} sn;

typedef struct{
     sn *top;
} stack;

void init(stack *s){
     s->top = NULL;
}

int push(stack *s, int val){
     sn *curr = (sn*)malloc(sizeof(sn));
     if(curr == NULL){
          return 1;
     }
     curr->data = val;
     curr->next = s->top;
     s->top = curr;
     return 0;
}

int pop(stack *s, int *d){
     if(s->top == NULL){
          return 1;
     }
     sn *temp = s->top;
     *d = temp->data;
     s->top = s->top->next;
     free(temp);
     return 0;
}

void push_end(stack *s, int temp){
     int k;
     if(s->top == NULL){
          push(s,temp);
          return;   // ✅ base case return
     }
     pop(s,&k);
     push_end(s,temp);
     push(s,k);
}

void rev(stack *s){
     int temp;
     if(s->top == NULL){
          return;
     }
     pop(&s,&temp);
     rev(s);
     push_end(s,temp);
}

void display(stack s){
     sn* curr = s.top;
     printf("Stack (top to bottom): ");
     while(curr != NULL){
          printf("%d ", curr->data);
          curr = curr->next;
     }
     printf("\n");
}

int main(){
     stack s;
     init(&s);

     int n, val;
     printf("Enter number of elements: ");
     scanf("%d",&n);

     for(int i=0; i<n; i++){
          printf("Enter value: ");
          scanf("%d",&val);
          push(&s,val);
     }

     printf("Original stack:\n");
     display(s);

     rev(&s);

     printf("Reversed stack:\n");
     display(s);

     return 0;
}