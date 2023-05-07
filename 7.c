#include<stdio.h>
#include<stdlib.h>

int main()
{
	  int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
	  
	  printf("Enter the number of requests: ");
	  scanf("%d",&n);
	  
	  printf("Enter the request sequence: ");
	  for(i=0;i<n;i++)
		scanf("%d",&RQ[i]);
	  
	  printf("Enter initial head position: ");
	  scanf("%d",&initial);
	  
	  printf("Enter total disk size: ");
	  scanf("%d",&size);
	  
	  printf("Enter the head movement direction for high 1 and for low 0: ");
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
			   printf("Serving Request: %d\n",RQ[i]);
			   TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
			   initial=RQ[i];
		  }
		 
		  TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
		  initial=size-1;  
		  for (i=index-1;i>=0;i--)
		  {
		      printf("Serving Request: %d\n",RQ[i]);
		      TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
		      initial=RQ[i];
		  }
	  }
	  
	  else
	  {
		  for (i=index-1;i>=0;i--)
		  {
		       printf("Serving Request: %d\n",RQ[i]);
		       TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
		       initial=RQ[i];
		  }
		
		  TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
		  initial=0;
		  for (i=index;i<n;i++)
		  {
		      printf("Serving Request: %d\n",RQ[i]);
		      TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
		      initial=RQ[i];
		  }
	  }
	  
	  printf("Total head movement is %d",TotalHeadMoment);
	  return 0;
}    
                         
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
