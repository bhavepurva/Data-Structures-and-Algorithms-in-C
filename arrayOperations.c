#include<stdio.h>
#include<conio.h>
void main(){
    int a[10],n,i,pos,insert,delete,data,choice;
    printf("enter limit of array: ");
    scanf("%d",&n);
    printf("enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("elements are: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    printf("\ndo you want to 1.insert 2.delete 3.exit? ");
    scanf("%d",&choice);
    switch(choice){
        //insert
        case 1:
        printf("enter data to be inserted: ");
        scanf("%d",&data);
        printf("1.begining 2.position 3.end ");
        scanf("%d",&insert);
        switch(insert){
            //begining
            case 1:
            for(i=n-1;i>=0;i--){
                a[i+1]=a[i];
            }
            a[0]=data;
            n++;
            break;
            
            //position
            case 2:
            printf("position: ");
            scanf("%d",&pos);
            for(i=n-1;i>=pos-1;i--){
                a[i+1]=a[i];
            }
            a[pos-1]=data;
            n++;
            break;
            
            //end
            case 3:
            a[n]=data;
            n++;
            break;
            default:
            printf("invalid choice");
            break;
        }
        break;
        
        //delete
        case 2:
        printf("1.begining 2.position 3.end ");
        scanf("%d",&delete);
        switch(delete){
            //begining
            case 1:
            for(i=0;i<n;i++){
                a[i]=a[i+1];
            }
            n--;
            break;
            
            //position
            case 2:
            printf("position: ");
            scanf("%d",&pos);
            for(i=pos-1;i<n-1;i++){
                a[i]=a[i+1];
            }
            n--;
            break;
            
            //end
            case 3:
            n--;
            break;
            default:
            printf("invalid choice");
            break;
        }        
        
        break;
        
        //exit
        case 3:
        break;
        
        default:
        printf("invalid choice");
        break;
    }
    printf("elements are: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}