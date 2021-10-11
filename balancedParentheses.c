#include<stdio.h>
#include<string.h>
char stack[10];
int top=-1;

char pop(){
    char val=stack[top];
    top--;
    return val;
}

void push(char a){
    top++;
    stack[top]=a;
}

void display(){
    int temp=top;
    while(temp!=-1){
        printf("%c",stack[temp]);
        temp--;
    }
}

int main(){
    char s[]="([{()}{()}]())";
    int flag=1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(s[i]);
        }
        else{
            char val=pop();
            if(s[i]==')' && val=='('|| s[i]==']' && val=='[' || s[i]=='}' && val=='{'){
                continue;
            }
            else{
                printf("unbalanced");
                flag=0;
                break;
            }
            
        }
        
    }
    if(flag==1){
        printf("balanced");
    }
    // display();
    return 0;
}
