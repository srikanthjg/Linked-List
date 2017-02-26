#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}nodet;

nodet* createNode(int data){
    nodet *tmp=(nodet*)malloc(sizeof(nodet));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void printLL(nodet* head){
    //int i;
    nodet* curr=NULL;
    curr=head;
    
    while(curr!=NULL){
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}

void alternate_swap_sri(nodet **head){
    nodet *c=NULL,*prev=NULL,*cn=NULL;
    prev  = *head;
    c     = (*head)->next;
    *head=c;
    
    while(prev != NULL && c != NULL){
        //swap
        cn          = c->next;
        c->next     = prev;
        
        
        //next loop init
        if(cn == NULL){
            prev->next = cn;
            //c    = cn->next;
        }
        else if(cn!=NULL && cn->next==NULL){
          prev->next = cn;
          prev       = cn;
          c          = cn->next;
        }
        else if(cn!=NULL && cn->next!=NULL){
          prev->next  = cn->next;
          prev=cn;
          c   =cn->next;
        }  
        //printf("Head = %d\n", (*head)->data);
    }
    printLL(*head);
    
}


int main(void)
{
    int i;
    nodet *head,*curr=NULL;
    head = createNode(1);
    curr=head;
    //nodet **headsH = &head;
    
    //create ll
    for(i=2;i<=3;i++)
    {
        nodet *temp = createNode(i);
        curr->next = temp;
        curr=temp;
    }
    
    printLL(head);
    printf("\n\n");
    
    alternate_swap_sri(&head);
    
    //printLL(curr);
    return 0;
}






