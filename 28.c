#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 1000

int main(int argc, char** argv)
{
     int rank,size;
     int array[ARRAY_SIZE];
     int sum=0;
     int local_sum=0;
     
     MPI_Init(NULL,NULL);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);
     MPI_Comm_size(MPI_COMM_WORLD,&size);
     
     srand(time(NULL)+rank);
     for (int i=0;i<ARRAY_SIZE;i++)
     {
          array[i]=rand()%100;
     }
     
     for (int i=rank;i<ARRAY_SIZE;i+=size)
     {
          local_sum+=array[i];
     }
     
     MPI_REDUCE(&local_sum,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
     
     if (rank==0)
     {
         printf("Sum of %d random numbers : %d\n",ARRAY_SIZE,sum);
     }
     MPI_Finalize();
     return 0;
}



#include<stdio.h>
#include<stdlib.h>

int main()
{
    int initial_head_pos, direction, num_requests,temp,total_seek=0,current_head_pos,n=0;
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
         {
             n=i;
             break;

         }
    }
    
    current_head_pos=initial_head_pos;
    
    if (direction==1)
    {
        printf("Initial Head Position : %d\n",current_head_pos);
        for (int j=i;j<num_requests;j++)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        current_head_pos = request_queue[0];
        
        for (int j=1;j<n;j++)
        {
             printf("Head Moving towards %d\n",current_head_pos);
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             
        }
        printf("Head Moving towards %d\n",current_head_pos);
    }
    else
    {
        printf("Initial Head Position : %d\n",current_head_pos);
        for (int j=i-1;j>=0;j--) 
        {
             printf("Head Moving towards %d\n",current_head_pos);
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             
        }
        current_head_pos = request_queue[num_requests-1];
        for (int j=num_requests-1;j>=n;j--)
        {
             printf("Head Moving towards %d\n",current_head_pos);
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             
        }
        printf("Head Moving towards %d\n",current_head_pos);
        
    }
    printf("Total seek movement : %d\n",total_seek);
    
    return 0;
}


