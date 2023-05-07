#include<stdio.h> 
#include<stdlib.h>

int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the Number of Requests : ");
    scanf("%d",&n);
    printf("Enter the request sequence : ");
    for (i=0;i<n;i++)
         scanf("%d",&RQ[i]);
    printf("Enter initial head position : ");
    scanf("%d",&initial);
    printf("Enter total disk size : ");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0 : ");
    scanf("%d",&move);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (RQ[j]>RQ[j+1])
            {
               int temp;
               temp=RQ[j];
               RQ[j]=RQ[j+1];
               RQ[j+1]=temp;
            }
        }
    }
  
    int index;
    for (i=0;i<n;i++)
    {
        if (initial<RQ[i])
        {
           index=i;
           break;
        }
    }
  
    if (move==1)
    {
        for (i=index;i<n;i++)
        {
            printf("Servicing request : %d\n",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        printf("Servicing request : %d\n",size);
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;  
        for (i=0;i<index;i++)
        {
            printf("Servicing request : %d\n",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
    else
    {
        for (i=index-1;i>=0;i--)
        {
             printf("Servicing request : %d\n",RQ[i]);
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
             TotalHeadMoment+=abs(size-1-0);
             initial=size-1;
        }
       
        for (i=n-1;i>=0;i--)
        {
             printf("Servicing request : %d\n",RQ[i]);
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
        }
    }
  
    printf("\nTotal head movement is %d\n",TotalHeadMoment);
    return 0;
}    



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

