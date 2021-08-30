#include<stdio.h>
#include<conio.h>

struct node{
    struct node *left,*right;
    int data;
};

struct node * create(){
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    
    
    printf("enter root: ");
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
int getHeight(struct node *root){
        if root==0{
            return -1;
         }
        
        int left_height=self.getHeight(root.left);
        int right_height=self.getHeight(root.right);
        if(left_height>=right_height){
              return left_height+1;
        }
        else{
              return right_height+1;
        }
}

void pre_order(struct node *root){
    struct node *temp;
    temp=root;
    if(temp!=0){
        printf("%d",temp->data);
        pre_order(temp->left);
        pre_order(temp->right);
    }
}

void in_order(struct node *root){
    struct node *temp;
    temp=root;
    if(temp!=0){
        in_order(temp->left);
        printf("%d",temp->data);
        in_order(temp->right);
    }
}

void post_order(struct node *root){
    struct node *temp;
    temp=root;
    if(temp!=0){
        post_order(temp->left);
        post_order(temp->right);
        printf("%d",temp->data);
    }
}

struct node * invert_bt(struct node * root){
    struct node *temp,*t;
    temp=root;
    if(root==0){
        return 0;
    }
    root->left=invert_bt(root->left);
    root->right=invert_bt(root->right);
    t=root->left;
    root->left=root->right;
    root->right=t;
    
    return temp;
}

int main(){
    struct node * root;
    root=0;
    root=create();
    printf("\npost_order traversal is: ");
    post_order(root);
    printf("\npre_order traversal is: ");
    pre_order(root);
    printf("\nin_order traversal is: ");
    in_order(root);
    root=invert_bt(root);
    in_order(root);    
    int height=getHeight(root);
    printf("Height of the tree is: %d",height);

    return 0;
}


