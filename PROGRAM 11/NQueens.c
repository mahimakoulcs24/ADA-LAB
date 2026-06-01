#include<stdio.h>

int n,board[20][20],count=0;

void printSolution(){
    count++;
    printf("Solution %d:\n",count);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row,int col){
    for(int i=0;i<col;i++)
        if(board[row][i])
            return 0;

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return 0;

    for(int i=row,j=col;i<n&&j>=0;i++,j--)
        if(board[i][j])
            return 0;

    return 1;
}

void solveNQUtil(int col){
    if(col>=n){
        printSolution();
        return;
    }

    for(int i=0;i<n;i++){
        if(isSafe(i,col)){
            board[i][col]=1;
            solveNQUtil(col+1);
            board[i][col]=0;
        }
    }
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=0;

    solveNQUtil(0);

    if(count==0)
        printf("Solution does not exist");

    return 0;
}
