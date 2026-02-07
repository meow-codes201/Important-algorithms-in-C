#include<stdio.h>
#define INF 999

int main(){
    int n,i,j,a,b,u,v,min;
    int cost[10][10];
    int visited[10]= {0};
    int mincost=0;
    int ne=1;
    
    printf("enter number of VERTEX: ");
    scanf("%d",&n);
    
    printf("\nEnter COST\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j] = INF;
            }
        }
    }
    
    visited[0] = 1;
    while(ne < n){
        min = INF;
        for(i=0;i<n;i++){
            if(visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        printf("edge %d : (%d,%d) cost = %d\n",ne,a,b, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INF;
        ne++;
    }
    printf("\nMinimum cost = %d",mincost);
    
    
    return 0;
}
