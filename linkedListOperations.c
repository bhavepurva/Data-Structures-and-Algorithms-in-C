#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
    }; 
struct node * newnode,* temp,* head,* nextnode,* prevnode;

struct node * create(int n){
    head=0;
    
    for(int i=0;i<n;i++){
    newnode=  (struct node * )malloc(sizeof(struct node *));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;

    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=temp->next;
    }
    }
    return head;
}

int print(struct node * head){
    temp=head;
    while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->next;
}   
}

struct node *removeDuplicates(struct node *head){
  //Write your code here
  struct node *temp,*nextnode,*prevnode;
  temp=prevnode=head;
  if(temp->next!=NULL){
      temp=temp->next;
  }
  
  while(temp->next!=NULL){
      
      nextnode=temp->next;
      if(prevnode->data==temp->data){
        prevnode->next=nextnode;
        free(temp);
        
      }
      else{
          prevnode=temp;
      }  
      temp=nextnode;  
  }
  if(prevnode->data==temp->data && prevnode!=temp){
      prevnode->next=NULL;
      free(temp);
  }
  
  
  return head;
}


struct node * insert(struct node * head){
    int choice,pos;
    newnode=  (struct node * )malloc(sizeof(struct node *));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    printf("1.begining 2.position 3.end ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            newnode->next=head;
            head=newnode;
        break;
        case 2:
        printf("enter position: ");
        scanf("%d",&pos);
        int count=1;
        temp=nextnode=head;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        nextnode=temp->next;
        temp->next=newnode;
        newnode->next=nextnode;
        
        
        break;
        case 3:
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        break;
        default:
        printf("invalid choice");
        break;
    }
    return head;
}

struct node * delete(struct node * head){
    int choice,pos;
    printf("1.begining 2.position 3.end ");
    scanf("%d",&choice);
    temp=prevnode=head;
    int count=0;
    switch(choice){
        case 1:
        head=head->next;
        free(temp);
        break;
        
        case 2:
        printf("position: ");
        scanf("%d",&pos);
        while(pos!=2){
            prevnode=prevnode->next;
            pos--;
        }
        temp=prevnode->next;
        prevnode->next=temp->next;
        free(temp);
        break;
        
        case 3:
        
        while(temp->next!=0){
            temp=temp->next;
            count++;
        }
        while(count!=1){
            prevnode=prevnode->next;
            count--;
        }
        prevnode->next=0;
        free(temp);
        break;
        default:
        printf("invalid choice");
        break;
    }
    return head;
}

struct node * reverse(struct node * head){
    temp=nextnode=prevnode=head;
    temp=temp->next;
    while(temp->next!=0){
        nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    temp->next=prevnode;
    head->next=0;
    head=temp;
    return head;
}

void main(){
    int choice,del,pos;
    int i,n;
    printf("enter length of linked list: ");
    scanf("%d",&n);
    
    head=create(n);
    print(head);
    printf("\n1.insert 2.delete ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        head=insert(head);
        print(head);
        break;
        case 2:
        head=delete(head);
        print(head);
        break;
        default:
        printf("invalid choice");
        break;
    }
    head=reverse(head);
    head=removeDuplicates(head);
    print(head);

    
    
}