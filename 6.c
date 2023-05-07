#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct dir
{
      char fname[20];
      int start;
      struct dir *next;
}NODE;

NODE *head,*last,*temp,*prev,*dell,*tmp;
int n,bit[MAX],fb=0;

void init()
{
      int i;
      printf("Enter total no. of disk blocks : ");
      scanf("%d",&n);
      for (i=0;i<n;i++)
      {
           bit[i]=rand()%2;
      }
}

void show_bitvector()
{
     int i;
     for (i=0;i<n;i++)
          printf("%d ",bit[i]);
     printf("\n");
}

void show_dir()
{
     NODE *temp;
     int i;
     printf("\nDirectory : ");
     printf("\nFile Name   Allocated Block Number");
     for (temp=head;temp!=NULL;temp=temp->next)
     {
          printf("\n %s",temp->fname);
          printf("      %d",temp->start);
     }
     printf("\n\nAllocated Blocks : ");
     for (temp=head;temp!=NULL;temp=temp->next)
     {
          printf("%d->",temp->start);
     }
     printf("NULL\n\n");
}

void create()
{
     NODE *p;
     char fname[20];
     int i,j,nob;
     int fb=0;
     printf("Enter file name : ");
     scanf("%s",&fname);
     printf("Enter the no of blocks : ");
     scanf("%d",&nob);
     for (i=0;i<n;i++)
     {
          if (bit[i]==0)
              fb++;
     }
     if (nob>fb)
     {
         printf("Failed to create file %s\n",fname);
         return;
     }
     else
     {
         for (i=0;i<n;i++)
         {
              if (bit[i]==0 && nob!=0)
              {
                  p=(NODE*)malloc(sizeof(NODE));
                  strcpy(p->fname,fname);
                  nob--;
                  bit[i]=1;
                  p->start=i;
                  p->next=NULL;
                  if (head==NULL)
                      head=p;
                  else
                      last->next=p;
                  last=p;
              }
         }
         printf("File %s created successfully \n",fname);
     }
}

void delete()
{
     int i=0;
     NODE *p,*q;
     char fname[20];
     
     temp=head;
     printf("Enter file to be deleted : ");
     scanf("%s",fname);
     
     while (temp!=NULL)
     {
            p=q=head;
            while (p!=NULL)
            {
                   if (strcmp(p->fname,fname)==0)
                       break;
                       
                   q=p;
                   p=p->next;
            }
            
            if (p==NULL)
            {
                return;
            }
            
            if (p==head)
                head=head->next;
            else if (p==last)
            {
                last=q;
                last->next=NULL;
            }
            else
            {
                 q->next=p->next;
            }
            bit[p->start]=0;
            free(p);
            temp=temp->next;
     }
     printf("File %s deleted successfully\n",fname);
}

int main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n*******Menu*******\n");
        printf("\n1.Show bit Vector");
        printf("\n2.Create New File");
        printf("\n3.Show Directory");
        printf("\n4.Delete File");
        printf("\n5.Exit\n");
        printf("\nEnter Your Choice : \n");
        scanf("%d",&ch);
        
        switch (ch)
        {
                case 1: show_bitvector();
                        break;
                case 2: create();
                        break;
                case 3: show_dir();
                        break;
                case 4: delete();
                        break;
                case 5: exit(0);
        }
    }
}






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

