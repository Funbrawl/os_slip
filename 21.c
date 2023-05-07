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



