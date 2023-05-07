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
#include<stdlib.h>

int main()
{
    int initial_head_pos, direction, num_requests,temp,total_seek=0,current_head_pos;
    float avg_seek_time;
    
    printf("Enter initial head position : ");
    scanf("%d",&initial_head_pos);
    
    printf("Enter the direction (0 for left 1 for right) : ");
    scanf("%d",&direction);
    
    printf("Enter the number of disk requests : ");
    scanf("%d",&num_requests);
    
    int request_queue[num_requests];
    
    printf("Enter the disk queue : ");
    for (int i=0;i<num_requests;i++)
    {
         scanf("%d",&request_queue[i]);
    }    
    for (int i=0;i<num_requests-1;i++)
    {
         for (int j=0;j<num_requests-1;j++)
         {
              if (request_queue[j]>request_queue[j+1])
              {
                  temp = request_queue[j];
                  request_queue[j]=request_queue[j+1];
                  request_queue[j+1]=temp;
              }
         }
    }
    
    int i;
    for (i=0;i<num_requests;i++)
    {
         if (request_queue[i]>=initial_head_pos)
             break;
    }
    
    current_head_pos=initial_head_pos;
    
    if (direction==1)
    {
        for (int j=i;j<num_requests;j++)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=i-1;j>=0;j--)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
    }
    else
    {
        for (int j=i-1;j>=0;j--)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=i;j<num_requests;j++)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
    }
    printf("Total seek movement : %d\n",total_seek);
    
    return 0;
}

