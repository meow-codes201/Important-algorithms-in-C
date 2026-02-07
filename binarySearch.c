#include<stdio.h>

int binaryIterative(int a[],int n,int key){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key){
            high = mid-1;
        }
        else{
            low = mid +1;
        }
        
    }

return -1;
    
}

int binaryRecursive(int a[],int l,int h, int key){
    while(l <= h){
        int mid = (l+h)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            return binaryRecursive(a,l,mid-1,key);
        }
        else{
            return binaryRecursive(a,mid+1,h,key);
        }
    }
    return -1;
}

int main(){
    int n;
    int a[] = {1,5,8,10,14,15};
    int key = 14;
     n = sizeof(a)/sizeof(a[0]);
    // int loc = binaryIterative(a,n,key);
    int pos = binaryRecursive(a,0,n-1,key);
    printf("key = %d is at index = %d\n",key,pos);
    return 0;
    
}
