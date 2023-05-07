#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int queue[100],i,n,seek=0,head,count=0;
    printf("Enter the number of request : ");
    scanf("%d",&n);
    printf("Enter the request sequence : \n");
    for (i=0;i<n;i++)
         scanf("%d",&queue[i]);
    printf("Enter the head position : \n");
    scanf("%d",&head);
    
    while (count!=n)
    {
           int min=1000,d,index;
           for (i=0;i<n;i++)
           {
                d = abs(queue[i]-head);
                if (min>d)
                {
                    min = d;
                    index = i;
                }
           }
           seek = seek+min;
           printf("\nDisk head moves from %d to %d with head movement of %d",head,queue[index],min);
           head=queue[index];
           queue[index]=1000;
           count++;
    }
    printf("\n\nTotal head movement is %d\n",seek);
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bv[50],i,st,j,len,c,k;
char name[10][30];
int start[10],length[10],num=0;

void displayBitVector()
{
     printf("\nBit Vector contents : \n");
     for (i=0;i<50;i++)
          printf("%d ",bv[i]);
}

void createFile()
{
     char temp[30];
     printf("Enter the name of file : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
          if (strcmp(name[i],temp)==0)
          {
              printf("\nFilename already exists");
              return;
          }
     strcpy(name[num],temp);
     printf("Enter the start block of the file : ");
     scanf("%d",&start[num]);
     printf("Enter the length of the file : ");
     scanf("%d",&length[num]);
     
     for (j=start[num];j<(start[num]+length[num]);j++)
          if (bv[j]==1)
          {
              printf("File cannot be allocated.... block already allocated");
              strcpy(name[j],"-");
              start[j]=0;
              length[j]=0;
              return;
          }
     for (j=start[num];j<(start[num]+length[num]);j++)
     {
          bv[j]=1;
          printf("\n%d->%d",j,bv[j]);
     }
     num++;
}

void showDirectory()
{
      printf("Directory contents\n");
      printf("%s%40s%40s\n","File Name","Start Block","Length");
      int i;
      for (i=0;i<num;i++)
      {
           if (strcmp(name[i],"-")!=0)
           {
               printf("%s%40d%40d\n",name[i],start[i],length[i]);
           }
      }
}

void deleteFile()
{
     char temp[10];
     printf("\nEnter the filename : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
     {
          if (strcmp(name[i],temp)==0)
          {
             
                   for (j=start[i];j<(start[i]+length[i]);j++)
                   {
                        bv[j]=0;
                        printf("\n%d->%d",j,bv[j]);
                   }
                   printf("\nFile successfully deleted...");
                   strcpy(name[i],"-");
                   start[i]=0;
                   length[i]=0;
                   return;
              
          }
     }
}

int main()
{
    int ch=0;
    for (i=0;i<50;i++)
         bv[i]=0;
         
    do 
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
                case 1: displayBitVector();
                        break;
                case 2: createFile();
                        break;
                case 3: showDirectory();
                        break;
                case 4: deleteFile();
                        break;
        }
    }while(ch!=5);
}


