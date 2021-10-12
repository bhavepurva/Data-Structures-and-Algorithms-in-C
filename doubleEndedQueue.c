#include<stdio.h>
#define n 5
int deq[n];
int front=-1,rear=-1;


void insertFromRear(int data){
    if(front==-1 && rear ==-1){
        front++;
        rear++;
        deq[rear]=data;
    }
    else if((rear+1)%n==front){
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%n;
        deq[rear]=data;
    }
}

void insertFromFront(int data){
    if(front==-1 && rear ==-1){
        front++;
        rear++;
        deq[front]=data;
    }
    else if((rear+1)%n==front){
        printf("Queue is full\n");
    }
    else if(front==0){
        front=n-1;
        deq[front]=data;
    }
    else{
        front--;
        deq[front]=data;
    }
}

void deleteFromFront(){
    if(front==-1 && rear==-1){
        printf("\nQueue is empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%n;
    }
}

void deleteFromRear(){
    if(front==-1 && rear==-1){
        printf("\nQueue is empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=n-1;
    }
    else{
        rear--;
    }
    
}
void display(){
    int temp=front;
    printf("\n");
    if(front==-1 && rear==-1){
        printf("Queue is empty, nothing to print\n");
        return;
    }
    while(temp!=rear){
        printf("%d ",deq[temp]);
        temp=(temp+1)%n;
    }
    printf("%d ",deq[temp]);
}

void getFront(){
    printf("\n%d ",deq[front]);
}
void getRear(){
    printf("\n%d ",deq[rear]);
}

int main(){
    insertFromRear(5);  // Queue-> 5
    insertFromRear(4);  // Queue-> 5 4
    insertFromRear(3);  // Queue-> 5 4 3
    insertFromFront(2); // Queue-> 2 5 4 3
    insertFromFront(1); // Queue-> 1 2 5 4 3
    insertFromFront(0); // Queue is full
    getFront();         // 1
    display();          // Queue-> 1 2 5 4 3
    deleteFromFront();  // Queue-> 2 5 4 3
    deleteFromFront();  // Queue-> 5 4 3
    getRear();          // 3
    display();          // Queue-> 5 4 3
    deleteFromRear();   // Queue-> 5 4 
    deleteFromRear();   // Queue-> 5 
    deleteFromRear();   // Queue->
    deleteFromRear();   // Queue is empty
    display();          // Queue is empty, nothing to print
    
    
    return 0;
}
