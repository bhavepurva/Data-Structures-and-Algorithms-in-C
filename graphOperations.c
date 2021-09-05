#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct Graph{
    int v;
    int *visited;
    struct adjlist *arr;
};

struct adjlist{
    struct node *head;
};
struct node{
    int data;
    struct node *next;
};

struct Graph * create_graph(int v){
    struct Graph *graph;
    graph=(struct Graph *)malloc(sizeof(struct Graph *));
    graph->v=v;
    graph->arr=(struct adjlist *)malloc(v * sizeof(struct adjlist *));
    graph->visited=malloc(v*sizeof(int));
    for(int i=0;i<v;i++){
        graph->arr[i].head=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

struct node *create_new_node(int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}

void add_edge(struct Graph * graph,int src,int dest){
    struct node *newnode;
    newnode=create_new_node(src);
    newnode->next=graph->arr[dest].head;
    graph->arr[dest].head=newnode;
    
    newnode=create_new_node(dest);
    newnode->next=graph->arr[src].head;
    graph->arr[src].head=newnode;
}

void print_graph(struct Graph * graph,int v){
    for(int i=0;i<v;i++){
        struct node *crawl;
        crawl=graph->arr[i].head;
        printf("on node %d: ",i);
        while(crawl!=NULL){
            printf("-> %d ",crawl->data);
            crawl=crawl->next;
        }
        printf("\n");
    }
    
}

void print_dfs(struct Graph *graph,int src,int v){
    int stack[v],top=-1;
    top++;
    stack[top]=src;
    printf("\ndfs: ");
    while(top!=-1){
        int val=stack[top];
        graph->visited[val]=1;
        top--;
        printf("%d ",val);
        struct node *temp=graph->arr[val].head;
        while(temp!=NULL){
            if(graph->visited[temp->data]==0){
                top++;
                stack[top]=temp->data;
                
            }
            temp=temp->next;
        }
    }
}


void print_bfs(struct Graph *graph,int src,int v){
    int queue[v],front=-1,rear=-1;
    rear++,front++;
    queue[rear]=src;
    printf("\nbfs: ");
    while(front<=rear){
        int val=queue[front];
        front++;
        graph->visited[val]=1;
        printf("%d ",val);
        struct node *temp=graph->arr[val].head;
        while(temp!=NULL){
            if(graph->visited[temp->data]==0){
                rear++;
                queue[rear]=temp->data;
                
            }
            temp=temp->next;
        }
    }
}
int main() {
    struct Graph *graph;
    int v=5;
    graph=create_graph(v);
    add_edge(graph,0,1);
    add_edge(graph,1,2);
    add_edge(graph,1,3);
    add_edge(graph,2,4);
    print_graph(graph,v);
    print_dfs(graph,0,v);
    print_bfs(graph,0,v);
    return 0;
}