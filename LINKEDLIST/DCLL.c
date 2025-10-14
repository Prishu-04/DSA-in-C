#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node *prev,*next;
}sn;
void create(sn **h){
     int n;
     printf("Enter number of nodes:");
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          sn *curr=malloc(sizeof(sn));
          scanf("%d",&curr->data);
          curr->next=curr->prev=NULL;
          if(*h==NULL){
               (*h)=curr;
               (*h)->next=curr;
               (*h)->prev=curr;
          }else {
               curr->prev=(*h)->prev;
               curr->next=(*h);
               (*h)->prev=curr;
               (*h)->prev->next=curr;
          }
     }
}
void insert(sn **h, int val,int pos){
     sn *curr=malloc(sizeof(sn));
     curr->data=val;
     curr->prev=curr->next=NULL;
     if(*h==NULL){
          (*h)=curr->prev=curr->next=curr;
     } else{
          if(pos==0){
              curr->prev=(*h)->prev;
              curr->next=*h;
              (*h)->prev=curr;
              (*h)->prev->next=curr;
              (*h)=curr; 
          } else{
               sn *ptr=*h;
               int i=0;
               while(i<pos-1 && ptr->next!=*h){
                    ptr=ptr->next;
               }
               curr->prev=ptr;
               curr->next=ptr->next;
               ptr->next=curr;
               ptr->next->prev=curr;
          }
     }
}
void delete(sn **h,int val){
     sn *ptr;
     if(*h==NULL){
          printf("List is empty\n");
     } else{
          for(ptr=*h;ptr->next!=*h;ptr=ptr->next){
               if(ptr->data==val){
                    break;
               }
          }
          if(ptr->data!=val){
               printf("Value not found");
          } else if(ptr==*h && ptr->next==*h){
               free(ptr);
               *h=NULL;
          } else if(ptr==*h){
              ptr->next->prev=ptr->prev;
              ptr->prev->next=ptr->next;
              *h=ptr->next;
              free(ptr);
          } else{
               ptr->prev->next=ptr->next;
               ptr->next->prev=ptr->prev;
               free(ptr);
          }
     }
}
void display(sn *h){
     sn *ptr=h;
     do{
          printf("%d->",ptr->data);
          ptr=ptr->next;
     }while(ptr!=h);
     printf("%d->",h->data);
}
int main(){
     sn *head=NULL;
     int val,pos;
     int choice;
     do{
          printf("Enter your choice:");
          scanf("%d",&choice);
          switch(choice){
               case 1:
               create(&head);
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