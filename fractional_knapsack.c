#include<stdio.h>
// sample wts and profits
// 4 20
// 8 40
// 5 30
// 2 60
// 6 60
// enter the capacity : 15

// vectors: 1.000000	1.000000	1.000000	0.250000	0.000000	
// Max profit: 160.00
void knapsack(int n,float weight[],float profit[],float capacity){
    float x[20],tp = 0;
    int i;
    float u = capacity;
    for(i=0;i<n;i++){
        x[i] = 0.0;
    }
    for(i=0;i<n;i++){
        if(u < weight[i])
         break;   
            else{
                x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if(i < n){
        x[i] = u/weight[i];
        tp = tp + (x[i] * profit[i]);
    }
    printf("\nvectors: ");
    for(i=0;i<n;i++){
        printf("%f\t",x[i]);
    }
    printf("\nMax profit: %.2f",tp);
    
}
    


int main(){
    float weight[20],profit[20],capacity;
    int num,i,j;
    float ratio[20],temp;
    printf("\nnumber of objects: ");
    scanf("%d",&num);
    printf("\nenter wts and profits: ");
    for(i=0;i<num;i++){
        scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("\nenter the capacity : ");
    scanf("%f",&capacity);
    
    for(i=0;i<num;i++){
        ratio[i] = profit[i]/weight[i];
    }
    
    
    //sort
    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num,weight,profit,capacity);
    return 0;
}

