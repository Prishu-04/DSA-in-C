#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node *next;
}sn;
void create(sn **h,sn **t){
     int n;
     printf("Enter  number of nodes:");
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          sn *curr=malloc(sizeof(sn));
          scanf("%d",&curr->data);
          curr->next=NULL;
          if((*h)==NULL){
               (*h)=(*t)=curr;
          } else{
               (*t)->next=curr;
               (*t)=curr;
          }
     }
}
void insert(sn **h,int val,int pos){
     sn *curr=malloc(sizeof(sn));
     curr->data=val;
     curr->next=NULL;
     if((*h)==NULL){
          (*h)=curr;
     } else{
          if(pos==0){
               curr->next=(*h);
               (*h)=curr;
          } else{
               sn *ptr=*h;
               int i=0;
               while(i<pos-1 && ptr->next==NULL){
                    ptr=ptr->next;
                    i++;
               }
               curr->next=ptr->next;
               ptr->next=curr;
          }
     }
}
void delete(sn **h, int val){
     sn *ptr;
     sn *prev;
     if(*h==NULL){
          free(*h);
     } else{
          for(ptr=*h;ptr->next!=NULL;ptr=ptr->next){
               if(ptr->data==val){
                    break;
               }
               prev=ptr;
          }
          if(ptr->data!=val){
               printf("Not Found");
          } else if(ptr==*h && ptr->next){
               free(ptr);
          } else if(ptr==*h){
               *h=(*h)->next;
               free(ptr);
          } else{
               prev->next=ptr->next;
               free(ptr);
          }
     }
}
void display(sn *h){
     while(h!=NULL){
          printf("%d->",h->data);
          h=h->next;
     }
     printf("NULL\n");
}
int main(){
     sn *head=NULL;
     sn *tail=NULL;
     int val,pos;
     int choice;
     do{
          printf("Enter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1:
               create(&head,&tail);
               break;
               case 2:
               printf("Enter the value to be inserted:");
               scanf("%d",&val);
               printf("Enter the position to be inserted:");
               scanf("%d",&pos);
               insert(&head,val,pos);
               break;
               case 3:
               printf("Enter the value to be deleted:");
               scanf("%d",&val);
               delete(&head,val);
               break;
               case 4:
               display(head);
               break;
               default: printf("Invalid choice:");
          }
     }while(choice<=4);
     return 0;
}