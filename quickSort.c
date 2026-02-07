#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int lb,int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start<=end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void quickSort(int a[],int lb,int ub){
    int loc;
    if(lb<=ub){
        loc = partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}
int main(){
    int n;
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    n = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    printf("sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    
    return 0;
}
