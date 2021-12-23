#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node_colour{
  int num;
  int colour;
};
/*int* find_neighbours(int A[][2],int ver,int edges,int vertices){
   int neighbours[1000];
   int array_size=0;
   for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        if(A[i][j]==ver)
        {
         if(j==1){
           neighbours[array_size++]=A[i][0];
           continue;
         }
         if(j==0){
             neighbours[array_size++]=A[i][1];
             continue;
         }         
          
        }
    }

    for(int i=0;i<array_size;i++){
        printf("%d",neighbours[i]);
    }

  return neighbours;
}*/

int main(){
    int A[10000][2];
    int vertices;
    scanf("%d",&vertices);
    int edges;
    scanf("%d",&edges);
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        scanf("%d",&A[i][j]);
    }

    
    int neighbours[1000];
   int array_size=0;
   int matrix[vertices][1000];

    for(int k=0;k<vertices;k++)  
  {
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        if(A[i][j]==k)
        {
         if(j==1){
           neighbours[array_size++]=A[i][0];
           continue;
         }
         if(j==0){
             neighbours[array_size++]=A[i][1];
             continue;
         }         
          
        }
    } 
    neighbours[array_size++]=-1;
   for(int j=0;j<array_size;j++)
    matrix[k][j]=neighbours[j];

    array_size=0;


 }

 for(int i=0;i<vertices;i++)
   {
     for(int j=0;j<25;j++)
     {
       if(A[i][j]!=-1)
        {
          printf("%d ",matrix[i][j]);
        }
       if(A[i][j]==-1){
           printf("fk u");
           break;
       }
     }
     printf("\n");
  }

  return 0;
   
}