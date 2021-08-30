#include <stdio.h>
#include <conio.h>

void bubble_sort(int a[],int n){
    int temp,no_of_swaps=0;
    
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swapped=1;
                no_of_swaps+=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        if(swapped==0){
            break;
        }
        }
    }
    printf("bubblesort in %d swaps: ",no_of_swaps);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}

void insertion_sort(int a[],int n){
    // time complexity-> worst-case->O(n^2) ->array is in descending order
    // time complexity-> best-case->O(n) ->array is in ascending order(already sorted)

    int temp,no_of_swaps=0;
    for(int i=1;i<n;i++){
        int j=i-1;
        temp=a[i];
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
            no_of_swaps+=1;
        }
        a[j+1]=temp;
    }
    printf("insertion_sort in %d swaps: ",no_of_swaps);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void selection_sort(int a[],int n){
    int temp,no_of_swaps;
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
    printf("selection_sort in %d swaps: ",no_of_swaps);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    
}

int main()
{
    int n=5;
    int a[]={90,23,1,7,15};
    // bubble_sort(a,n);
    // insertion_sort(a,n);
    selection_sort(a,n);
    return 0;
}
