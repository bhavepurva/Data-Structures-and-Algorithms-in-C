#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
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
        }
        else{
            tail->next=newnode;
            tail=newnode;
            newnode->next=head;
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
        newnode->next=temp->next;
        temp->next=newnode;
        break;
        case 3:
        newnode->next=tail->next;
        tail->next=newnode;
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
    struct node *temp=tail->next;
    printf("\nenter position:1.Start 2.Position 3.End: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        tail->next=temp->next;
        free(temp);
        break;
        case 2:
        printf("enter position: ");
        scanf("%d",&pos);
        pos=pos-2;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        struct node * nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
        break;
        case 3:
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        free(tail);
        tail=temp;
        break;
        default:
        printf("invalid choice");
        break;
    }
    
    return tail;
}

struct node *reverse(struct node *tail){
    struct node *temp,*prevnode,*nextnode;
    temp=prevnode=nextnode=tail->next;
    temp=temp->next;
    while(temp!=tail){
        nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    tail=tail->next;
    tail->next=temp;
    temp->next=prevnode;
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
    tail=reverse(tail);
    display(tail);
    return 0;
}
