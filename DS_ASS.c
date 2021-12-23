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
   int k;
    for(k=0;k<vertices;k++)  
  {
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<2;j++)
        {if(A[i][j]==k)
        {
         if(j==1)
         {
           neighbours[array_size++]=A[i][0];
           continue;
         }
         if(j==0)
         {
             neighbours[array_size++]=A[i][1];
             continue;
         }         
          
        }
      }
    } 
   neighbours[array_size++]=-1;
   for(int j=0;j<array_size;j++)
   matrix[k][j]=neighbours[j];

    array_size=0;


 }
 printf("\nmatrix\n");

 for(int i=0;i<vertices;i++)
   {
     for(int j=0;j<25;j++)
     {
       if(matrix[i][j]!=-1)
        {
          printf("%d ",matrix[i][j]);
        }
        else break;
    
     }
     printf("\n");
  }

  printf("\nmatrix\n");
  int j;
  struct node_colour node[vertices][10000];
  for(int i=0;i<vertices;i++)
   {
     for(j=0;matrix[i][j]!=-1;j++)
      node[i][j].num=matrix[i][j];

      node[i][j].num=matrix[i][j];   
  }
  printf("\nstruct\n");
  for(int i=0;i<vertices;i++)
   {
     for(int j=0;;j++)
     {
       if(node[i][j].num!=-1)
        {
          printf("%d ",node[i][j].num);
        }
        else break;
    
     }
     printf("\n");
   }

    printf("\nstruct\n");

   int* colour;
   colour=(int*)malloc(vertices*sizeof(int));

   for(int k=0;k<vertices;k++)
   colour[k]=-1;

   int p=0;
   colour[p]=0;
  
     for(int j=0;;j++)
     {
       if(node[0][j].num!=-1)
        {
          node[0][j].colour=1;
          colour[node[0][j].num]=1;
        }
        else break;
    
     }

     int main_check=-1;
     int check_2=-1;
     for(int i=1;i<vertices;i++)
     {
        if(colour[i]!=-1)
        {
         for(int j=0;node[i][j].num!=-1;j++)
         {   if(colour[i]==1){
             if(node[i][j].colour!=1 && node[i][j].num!=-1) 
             node[i][j].colour=0;

             if(colour[node[i][j].num]==1)
             {
                 main_check=i;
                 check_2=j;
                 break;
             }
             else colour[node[i][j].num]=0;
            }
             else
             {
                 if(node[i][j].colour!=0 && node[i][j].num!=-1)
                 node[i][j].colour=1;
                 if(colour[node[i][j].num]==0)
                 {
                 main_check=i;
                 check_2=j;
                 break;
                 }
                else  
                 colour[node[i][j].num]=1;
             }
             
         }
       }
     }

     

     printf("\ncolour\n");
     for(int i=0;i<vertices;i++){
       printf("%d   ",colour[i]);
     }
      printf("\ncolour\n");



     if(main_check==-1){
      
     int set_u[vertices];
     int set_v[vertices];
     int i_1=0;
     int i_2=0;
      for(int i=0;i<vertices;i++){
      if(colour[i]==0)
      set_u[i_1++]=i;
      else
      set_v[i_2++]=i;
      }
      for(int u=0;u<i_1;u++)
      printf("%d ",set_u[u]);
      printf("\n");
      for(int v=0;v<i_2;v++)
      printf("%d ",set_v[v]);
    }
    else
     { 
        int main_check_array[1000];
        int check_2_array[1000];
        int main_check_count=0;
        int check_2_count=0;
        int i;
    for(i=0;node[main_check][i].num!=-1;i++){
      main_check_array[main_check_count++]=node[main_check][i].num;
    }
    main_check_array[main_check_count++]=node[main_check][i].num;
     

   for(i=0;node[check_2][i].num!=-1;i++){
      check_2_array[check_2_count++]=node[check_2][i].num;
     }
     check_2_array[check_2_count++]=node[check_2][i].num;
     
    int j;
     int wanted=-99;
    for(int j=0;j<check_2_count;j++)
    {
     for(int i=0;i<main_check_count;i++)
     {
      if(main_check_array[i]==check_2_array[j])
            wanted=check_2_array[j];
            break;
     }
   }
   if(wanted!=-99)
   printf("%d %d %d",main_check,wanted,check_2);
   }

    
return 0;
   
}