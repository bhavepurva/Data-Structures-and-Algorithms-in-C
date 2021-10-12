#include<stdio.h>
#define n 5
int q[n];
int front=-1,rear=-1;

void enqueue(int data){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        q[rear]=data;
    }
    else if((rear+1)%n==front){
        printf("\nqueue is full\n");
    }
    else{
        rear=(rear+1)%n;
        q[rear]=data;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("queue is empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%n;
    }
}

void display(){
    int temp=front;
    printf("\n");
    while(temp!=rear){
        printf("%d ",q[temp]);
        temp=(temp+1)%n;
    }
    printf("%d ",q[temp]);
}
int main(){
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();  //5 4 3 2 1
    enqueue(0); // queue is full
    dequeue();
    display();  // 4 3 2 1
    enqueue(5);
    display();  // 4 3 2 1 5
    return 0;
}
