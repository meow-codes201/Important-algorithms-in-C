#include<stdio.h>

int binaryIterative(int a[],int n,int key){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] == key){
            printf("FOUND IT!\n");
            return mid;
        }
        else if(a[mid] > key){
            printf("searching first half....\n");
            high = mid-1;
        }
        else{
            printf("searching 2nd half....\n");
            
            low = mid +1;
        }
        
    }

return -1;
    
}

int binaryRecursive(int a[],int l,int h, int key){
    while(l <= h){
        int mid = (l+h)/2;
        if(a[mid]==key){
            printf("FOUND IT!\n");
            return mid;
        }
        else if(a[mid]>key){
            printf("searching first half....\n");
            return binaryRecursive(a,l,mid-1,key);
        }
        else{
            printf("searching 2nd half....\n");
            return binaryRecursive(a,mid+1,h,key);
        }
    }
    return -1;
}

int main(){
    int n;
    int a[] = {1,5,8,10,15};
    int key = 14;
     n = sizeof(a)/sizeof(a[0]);
    int loc1 = binaryIterative(a,n,1);
    printf("key = %d is at index = %d\n\n",1,loc1);

    int pos1 = binaryRecursive(a,0,n-1,15);
    printf("key = %d is at index = %d\n\n",15,pos1);

    int loc2 = binaryIterative(a,n,15);
    printf("key = %d is at index = %d\n\n",15,loc2);

    int pos2 = binaryRecursive(a,0,n-1,1);
    printf("key = %d is at index = %d\n\n",1,pos2);

    int loc3 = binaryIterative(a,n,8);
    printf("key = %d is at index = %d\n\n",8,loc3);

    int pos3 = binaryRecursive(a,0,n-1,10);
    printf("key = %d is at index = %d\n\n",10,pos3);

    int pos4 = binaryRecursive(a,0,n-1,100);
    if (pos4 == -1){
        printf("Key does not exist\n\n");
    }
    //OUTPUTS:
        /*searching first half....
        FOUND IT!
        key = 1 is at index = 0
        
        searching 2nd half....
        searching 2nd half....
        FOUND IT!
        key = 15 is at index = 4
        
        searching 2nd half....
        searching 2nd half....
        FOUND IT!
        key = 15 is at index = 4
        
        searching first half....
        FOUND IT!
        key = 1 is at index = 0
        
        FOUND IT!
        key = 8 is at index = 2
        
        searching 2nd half....
        FOUND IT!
        key = 10 is at index = 3
        
        searching 2nd half....
        searching 2nd half....
        searching 2nd half....
        Key does not exist
*/
    return 0;
    
}

