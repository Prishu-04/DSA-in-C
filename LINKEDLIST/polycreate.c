#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int coeff,exp;
     struct node *next;
}sn;
void create(sn **h, sn **t){
     int n;
     printf("Enter the length:");
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          sn *curr=malloc(sizeof(sn));
          scanf("%d %d",&curr->coeff,&curr->exp);
          curr->next=NULL;
          if(*h==NULL){
               *h=*t=curr;
          } else{
               (*t)->next=curr;
               (*t)=curr;
          }
          
     }
}
void display(sn *h){
     while(h!=NULL){
          printf("%dx^%d+",h->coeff,h->exp);
          h=h->next;
     }
     printf("NULL\n");
}
int main(){
     sn *h=NULL;
     sn *t=NULL;
     create(&h,&t);
     display(h);
}