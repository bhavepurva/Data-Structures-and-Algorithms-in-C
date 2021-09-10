#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node *prev;
    }; 
    
struct node *head,*temp,*newnode,*tail;

struct node *create(struct node *head){
    int choice=1;
    while(choice){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=0;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
        
    }
    printf("want to continue? ");
    scanf("%d",&choice);
    }
    return head;
}

struct node * display(struct node *head){
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct node * insert(struct node *head){
    int pos,choice;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=0;
    printf("1.beginning 2.position 3.end: ");
    scanf("%d",&choice);
    temp=head;
    switch(choice){
        case 1:
        newnode->next=temp;
        head=newnode;
        temp->prev=newnode;
        break;
        case 2:
        printf("\nwhich position? ");
        scanf("%d",&pos);
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        
        
        break;
        case 3:
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        
        break;
        default:
        printf("invalid choice");
        break;
    }
    return head;
}

struct node * delete(struct node *head){
    int pos,choice;
    printf("1.beginning 2.position 3.end: ");
    scanf("%d",&choice);
    temp=head;
    switch(choice){
        case 1:
        head=head->next;
        head->next->prev=0;
        free(temp);
        break;
        case 2:
        printf("\nwhich position? ");
        scanf("%d",&pos);
        int i=1;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        break;
        case 3:
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->prev->next=0;
        free(temp);
        
        break;
        default:
        printf("invalid choice");
        break;
    }
    return head;
}



struct node *search(struct node * head){
    int search,index;
    index=1;
    temp=head;
    printf("\nwhat to search? ");
    scanf("%d",&search);
    while(temp!=0){
        if(search==temp->data){
            printf("%d found at position %d",search,index);
            break;
        }
        else{
            temp=temp->next;
            index++;
        }
    }
}


void main(){
    head=0;
    int choice;
    head=create(head);
    display(head);
    printf("\ndo you want to insert? ");
    scanf("%d",&choice);
    if(choice==1){
    head=insert(head);
    display(head);
    
    }
    printf("\n");
    
     printf("\ndo you want to delete? ");
    scanf("%d",&choice);
    if(choice==1){
    head=delete(head);
    display(head);
    
    }
    search(head);
}
