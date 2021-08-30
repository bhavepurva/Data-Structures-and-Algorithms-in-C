#include<stdio.h>
#include<conio.h>

int stack[5];
int top=-1;

void push(){
    int x;
    printf("element to be pushed: ");
    scanf("%d",&x);
    if(top==4){
        printf("stack is full\n");
    }
    else{
        top=top+1;
        stack[top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("stack is empty");
        
    }
    else{
        int popped=stack[top];
        top=top-1;
        printf("popped element is: %d ",popped);
    }
}

void isempty(){
    if(top==-1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

void isfull(){
    if(top==4){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

void peek(){
    printf("%d",stack[top]);
}

void display(){
    int temp=top;
    if(temp==-1){
        printf("\nstack is empty");
    }
    else{
        printf("\nstack elements are: ");
        while(temp!=-1){
        printf("%d ",stack[temp]);
        temp=temp-1;
        }
    }    
}

void main(){
    push();
    pop();
    display();
    isempty();
    isfull();
     peek();
}