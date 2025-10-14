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
     s->top = NULL;   // ✅ fixed
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
void display(stack s){
     if(s.top==NULL){
          printf("Stack is empty\n");
          return;
     }
     sn* curr=s.top;
     printf("Stack elements (top to bottom): ");
     while(curr!=NULL){
          printf("%d ",curr->data);
          curr=curr->next;
     }
     printf("\n");
     printf("INTERNALLY STACK IS:\n");
     sn* temp=s.top;
     while(temp!=NULL){
          printf("%d -> ",temp->data);
          temp=temp->next;
     }
     printf("NULL\n");
}
void del(stack *s,int v){
     int temp;
     if(s->top==NULL) return ;
     pop(s,&temp);
     if(temp==v){
          return;
     } else{
          del(s,v);
          push(s,temp);
     }
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
     display(s);
     int v;
     printf("Enter the value to be deleted:");
     scanf("%d",&v);
     del(&s,v);
     display(s);
     return 0;
}