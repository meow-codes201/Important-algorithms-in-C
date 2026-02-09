#include<stdio.h>
#include<stdbool.h>
#define N 4

bool isSafe(char board[N][N],int row,int col)
{
    int c,r;
    //horizontal
    for(c=0;c<N;c++){
        if(board[row][c]=='Q'){
            return false;
        }
    }
    //vertical
    for(r=0;r<row;r++){
        if(board[r][col]=='Q'){
            return false;
        }
    }
    //left upper diagonal
    for(c=col-1 , r=row-1; c>=0 && r>=0; c--,r--){
        if(board[r][c]=='Q'){
            return false;
        }
    }
    //right upper diagonal
    for(c=col+1 , r=row-1; c<N && r>=0; c++,r--){
        if(board[r][c]=='Q'){
            
            return false;
        }
    }
    return true;
}
void printBoard(char board[N][N])
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void nQueens(char board[N][N],int row)
{int col;
    if(row == N)
    {
        printBoard(board);
        return;
    }
    for(col=0;col<N;col++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]='Q';
            nQueens(board,row+1);
            board[row][col]='.';
        }
    }
        
}
int main()
{
    int i,j;
    char board[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]='.';
        }
    }
    nQueens(board,0);
    return 0;
}
