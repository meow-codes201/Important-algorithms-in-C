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
    int loc1 = binaryIterative(a,n,1);
    int pos1 = binaryRecursive(a,0,n-1,15);
    int loc2 = binaryIterative(a,n,15);
    int pos2 = binaryRecursive(a,0,n-1,1);
    int loc3 = binaryIterative(a,n,8);
    int pos3 = binaryRecursive(a,0,n-1,10);
    printf("key = %d is at index = %d\n",1,loc1);
    printf("key = %d is at index = %d\n",15,pos1);
    printf("key = %d is at index = %d\n",1,pos2);
    printf("key = %d is at index = %d\n",15,loc2);
    printf("key = %d is at index = %d\n",8,loc3);
    printf("key = %d is at index = %d\n",10,pos3);
    //OUTPUTS:
        // key = 1 is at index = 0
        // key = 15 is at index = 5
        // key = 1 is at index = 0
        // key = 15 is at index = 5
        // key = 8 is at index = 2
        // key = 10 is at index = 3
    return 0;
    
}

