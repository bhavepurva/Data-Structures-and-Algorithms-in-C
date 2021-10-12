#include<stdio.h>
#define size 5
int a[]={10,20,44,58,73};


int linearSearch(int search){
    for(int i=0;i<size;i++){
        if(a[i]==search){
            return i;
        }
    }
    return -1;
}

int binarySearch(int search){
    int l=0,r=size-1,mid,count=0;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==search){
            return mid;
        }
        else if(a[mid]>search){
            r=mid-1;
            count++;
        }
        else{
            l=mid+1;
            count++;
        }
    }
    return -1;
}

int main(){
    int search;
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\nEnter element: ");
    scanf("%d",&search);
    
    printf("Using linear search element found at index %d ",linearSearch(search));
    
    printf("\nUsing binary search element found at index %d ",binarySearch(search));
    return 0;
}
