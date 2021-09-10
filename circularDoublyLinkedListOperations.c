#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * create(){
    struct node *tail=NULL,*head=NULL,*newnode;
    int x;
    printf("enter node: ");
    scanf("%d",&x);
    while(x!=-1){
        newnode=(struct node *)malloc(sizeof(struct node *));
        newnode->data=x;
        if(head==NULL){
            tail=head=newnode;
            head->next=tail;
            head->prev=tail;
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
            newnode->next=head;
            head->prev=tail;
        }
        printf("enter node: ");
        scanf("%d",&x);
    }
    return tail;
}

struct node * insert_node(struct node *tail){
    int choice,pos,x,i=1;
    struct node *temp=tail->next;
    printf("\nenter position:1.Start 2.Position 3.End: ");
    scanf("%d",&choice);
    printf("enter node: ");
    scanf("%d",&x);
    struct node *newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=x;
    switch(choice){
        case 1:
        newnode->next=tail->next;
        newnode->prev=tail;
        tail->next->prev=newnode;
        tail->next=newnode;
        break;
        case 2:
        printf("enter position: ");
        scanf("%d",&pos);
        pos=pos-2;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        break;
        case 3:
        newnode->prev=tail;
        newnode->next=tail->next;
        tail->next=newnode;
        newnode->next->prev=newnode;
        tail=newnode;
        break;
        default:
        printf("invalid choice");
        break;
    }
    
    return tail;
}

struct node * delete_node(struct node *tail){
    int choice,pos,x,i=1;
    struct node *temp;
    printf("\nenter position:1.Start 2.Position 3.End: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        temp=tail->next;
        temp->next->prev=tail;
        tail->next=temp->next;
        free(temp);
        break;
        case 2:
        temp=tail->next;
        printf("enter position: ");
        scanf("%d",&pos);
        pos=pos-1;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        break;
        case 3:
        temp=tail;
        tail->next->prev=tail->prev;
        tail->prev->next=tail->next;
        tail=tail->prev;
        free(temp);
        break;
        default:
        printf("invalid choice");
        break;
    }
    
    return tail;
}


void display(struct node *tail){
    struct node *temp=tail->next;
    printf("\n");
    while(temp!=tail){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

int main() {
    struct node *tail;
    tail=create();
    display(tail);
    tail=insert_node(tail);
    display(tail);
    tail=insert_node(tail);
    display(tail);
    tail=insert_node(tail);
    display(tail);
    tail=delete_node(tail);
    display(tail);
    tail=delete_node(tail);
    display(tail);
    tail=delete_node(tail);
    display(tail);
    return 0;
}
