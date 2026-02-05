#include<stdio.h>

void insertionSort(int a[],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    
    int a[5] = {5,4,3,2,1};
    int n = sizeof(a) / sizeof(a[0]);
    insertionSort(a,5);
    printf("Sorted Array is ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
