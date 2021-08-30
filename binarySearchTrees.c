#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int count=0;

struct node{
    struct node *left,*right;
    int data;
};

struct node * create(){
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    
    
    printf("enter data: ");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    else{
        newnode->data=x;
        printf("enter left child of  %d: ",x);
        newnode->left=create();
        printf("enter right child of  %d: ",x);
        newnode->right=create();
        
    }
    return newnode;
    
}


void in_order(struct node *root){
    struct node *temp;
    temp=root;
    if(temp!=0){
        in_order(temp->left);
        printf("%d ",temp->data);
        in_order(temp->right);
    }
}

void search_recursive(struct node *root,int key){
    if(root==0){
        printf("\n%d not found",key);
    }
    else if(root->data==key){
        printf("\n%d found in %d steps",key,count);
        count=0;
    }
    else if(root->data>key){
        count++;
        search_recursive(root->left,key);
    }
    else{
        count++;
        search_recursive(root->right,key);
    }
}

int search_iterative(struct node * root,int key){
    while(root!=0){
        if(root->data==key){
            return root->data;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}



struct node * insert(struct node * root,int x){
    struct node *newnode,*prev,*temp;
    temp=root;
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=x;
    newnode->left=0;
    newnode->right=0;
    while(root!=0){
        prev=root;
        if(root->data==x){
            printf("no duplicates");
            return temp;
            
        }
        else if(root->data>x){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    if(prev->data>x){
        prev->left=newnode;
    }
    else{
        prev->right=newnode;
    }
    return temp;
}

struct node * in_order_predecessor(struct node *root){
    root=root->left;
    while(root->right!=0){
        root=root->right;
    }
    return root;
}

struct node * delete(struct node *root,int x){
    struct node *temp;
    temp=root;
    struct node *in_pred;
    if(root->left==0 && root->right==0){
        free(root);
        return 0;
    }
    if(root==0){
        return 0;
    }
    if(root->data>x){
        root->left=delete(root->left,x);
    }
    else if(root->data<x){
        root->right=delete(root->right,x);
    }
    else{
        in_pred=in_order_predecessor(root);
        root->data=in_pred->data;
        root->left=delete(root->left,in_pred->data);
    }
    
    return root;
    
}


int main(){
    struct node * root;
    root=0;
    int x;
    root=create();
    
    // search_recursive(root,4);
    // search_recursive(root,3);
    
    
    // printf("\n%d found iteratively",search_iterative(root,5));
    // printf("\n%d found iteratively",search_iterative(root,10));
    
    printf("what to insert? ");
    scanf("%d",&x);
    
    root=insert(root,x);
    root=insert(root,x);
    root=insert(root,15);
    
    root=delete(root,4);
    root=delete(root,13);
    
    printf("\nin_order traversal is: ");
    
    in_order(root);
    return 0;
}


