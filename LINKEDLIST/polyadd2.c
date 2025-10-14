#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int coeff,exp;
     struct node *next;
}sn;
void create(sn **h){
     sn *t;
     int n;
     printf("Enter the length:");
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          sn *curr=malloc(sizeof(sn));
          scanf("%d %d",&curr->coeff,&curr->exp);
          curr->next=NULL;
          if(*h==NULL){
               *h=t=curr;
          } else{
               t->next=curr;
               t=curr;
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
void join(sn *h1, sn *h2){
     sn *ptr=h1;
     while(ptr->next!=NULL){
          ptr=ptr->next;
     }
     ptr->next=h2;
}
void simplify(sn *h1){
     sn *p1=h1,*p2,*prev;
     while(p1!=NULL){
          prev=p1;
          p2=p1->next;
          while(p2!=NULL){
               if(p1->exp!=p2->exp){
                    prev=p2;
                    p2=p2->next;
               } else{
                    p1->coeff=p1->coeff+p2->coeff;
                    prev->next=p2->next;
                    free(p2);
                    p2=prev->next;
               }
          }
          p1=p1->next;
     }
}
int main(){
     sn *h1=NULL;
     sn *h2=NULL;
     create(&h1);
     create(&h2);
     display(h1);
     display(h2);
     join(h1,h2);
     simplify(h1);
     display(h1);
}