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
sn* mul(sn *h1, sn *h2){
    sn *h3=NULL, *t=NULL;
    for (sn *p1 = h1; p1 != NULL; p1 = p1->next) {
        for (sn *p2 = h2; p2 != NULL; p2 = p2->next) {
            sn *curr = malloc(sizeof(sn));
            curr->coeff = p1->coeff * p2->coeff;
            curr->exp = p1->exp + p2->exp;
            curr->next = NULL;
            if (h3 == NULL) {
                h3 = t = curr;
            } else {
                t->next = curr;
                t = curr;
            }
        }
    }
    return h3;
}

void simplify(sn *h3){
     sn *p1=h3,*p2,*prev;
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
     sn *h3=NULL;
     create(&h1);
     create(&h2);
     display(h1);
     display(h2);
     h3=mul(h1,h2);
     simplify(h3);
     display(h3);
}