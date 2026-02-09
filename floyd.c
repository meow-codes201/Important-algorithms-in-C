#include<stdio.h>
#define INF 999

int main()
{   int i,j,k;
    char word[]={'I','N','F','\0'};
    int graph[4][4]= {
        {0,3,INF,INF},
        {4,0,INF,3},
        {5,2,0,INF},
        {INF,4,INF,0}
    };
    int dist[4][4];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    
    for(k=0;k<4;k++){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    
for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(dist[i][j]==INF){
                printf("%s ",word);
            }
            else{
            printf("%d ",dist[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
     
    
    return 0;
}
