#include<stdio.h>
int queue[5],front=-1,rear=-1;
void enqueue(int data){
    if(rear==4){
        printf("\n");
        printf("Queue is full");
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1 && rear==-1 || front>rear){
        printf("\n");
        printf("Queue is empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}

void peek(){
    printf("\n");
    printf("Front: %d ",queue[front]);
    printf("\n");
    printf("Rear: %d ",queue[rear]);
}



void display(){
    printf("\n");
    if(front==-1 && rear==-1 || front>rear){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }    
    }
    
}

int main(){
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    peek();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
