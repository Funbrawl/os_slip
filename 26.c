#include<stdio.h>
#include<string.h>

int n,m,i,j,k,flag;
int a[50][50],av[15],max[50][50],need[50][50];

void get_data()
{
     printf("\nEnter number of processes : ");
     scanf("%d",&n);
     printf("\nEnter the number of resources : ");
     scanf("%d",&m);
     printf("\nEnter allocation matrix : \n");
     
     for (i=0;i<n;i++)
     {
          for (j=0;j<m;j++)
          {
              scanf("%d",&a[i][j]);
          }
     }
     printf("\nEnter MAX matrix : \n");
     for (i=0;i<n;i++)
     {
          for (j=0;j<m;j++)
          {
               scanf("%d",&max[i][j]);
          }
     }
     printf("\nEnter Available Array : \n");
     for (i=0;i<m;i++)
          scanf("%d",&av[i]);
}

void put_data()
{
     printf("\nAllocation matrix is....\n");
     for (i=0;i<n;i++)
     {
          for (j=0;j<m;j++)
          {
               printf("%d\t",a[i][j]);
          }
          printf("\n");
     }
     printf("\nMax Matrix is......\n");
     for (i=0;i<n;i++)
     {
         for (j=0;j<m;j++)
         {
              printf("%d\t",max[i][j]);
         }
         printf("\n");
     }
     printf("\nAvailable Array is.....\n");
     for (i=0;i<m;i++)
         printf("%d\t",av[i]);
}

void calc_need()
{
     for (i=0;i<n;i++)
     {
          for (j=0;j<m;j++)
          {
               need[i][j] = max[i][j]-a[i][j];
          }
     }
     printf("\nNeed Array is.....\n");
     for (i=0;i<n;i++)
     {
          for (j=0;j<m;j++)
          {
               printf("%d\t",need[i][j]);
          }
          printf("\n");
     }
}

void main()
{
     get_data();
     put_data();
     calc_need();
}




#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int queue[20],n,head,i,j,k,seek=0,max,diff;
    printf("\nEnter the max range of disk : ");
    scanf("%d",&max);
    printf("Enter the size of queue request : ");
    scanf("%d",&n);
    printf("Enter the queue of disk positions to be read : ");
    for (i=1;i<=n;i++)
        scanf("%d",&queue[i]);
    printf("Enter the initial head position : ");
    scanf("%d",&head);
    queue[0]=head;
    for (j=0;j<=n-1;j++)
    {
         diff = abs(queue[j+1]-queue[j]);
         seek+=diff;
         printf("\nDisk head moves from %d to %d with head movement of %d",queue[j],queue[j+1],diff);
    }
    printf("\n\nTotal Head Movement is %d\n",seek);
    return 0;
}


