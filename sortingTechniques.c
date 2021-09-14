#include <stdio.h>
#include <conio.h>

void bubble_sort(int a[],int n){
    int temp;
    
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swapped=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        if(swapped==0){
            break;
        }
        }
    }
    printf("bubblesort: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}

void insertion_sort(int a[],int n){
    // time complexity-> worst-case->O(n^2) ->array is in descending order
    // time complexity-> best-case->O(n) ->array is in ascending order(already sorted)

    int temp;
    for(int i=1;i<n;i++){
        int j=i-1;
        temp=a[i];
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("insertion_sort: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void selection_sort(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min!=i){
            temp=a[min];
            a[min]=a[i];
            a[i]=a[min];
        }
    }
    printf("selection_sort: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    
}

int partition(int a[],int start,int end){
    int pivot=start;
    while(start<end){
        while(a[start]<=a[pivot]){
            start++;
        }
        while(a[end]>a[pivot]){
            end--;
        }
        if(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    int temp=a[end];
    a[end]=a[pivot];
    a[pivot]=temp;
    return end;
}


void quicksort(int a[],int start,int end){
    if(start<end){
        int loc=partition(a,start,end);
        quicksort(a,start,loc-1);
        quicksort(a,loc+1,end);
    }  
    
}

int main()
{
    int n=5;
    int a[]={90,23,1,7,15};
    bubble_sort(a,n);
    printf("\n");
    insertion_sort(a,n);
    printf("\n");
    selection_sort(a,n);
    printf("\n");
    quicksort(a,0,5);
    printf("\n");
    printf("quicksort: ");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
