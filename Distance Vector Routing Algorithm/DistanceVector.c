
// Distance Vector Algorithm implementation to find the shortest path in a Network 

#include<stdio.h>

//Defining the Router Table
 
struct node
{
    unsigned cost[100];
    unsigned to[100];
    unsigned next[100];
}Router[100];

int main()
 {
    int iterations = 0;
    int cost_mat[200][200];
    int int_mat[200][200];
    int user_input;
    int dt,sc,n,i,j,k,count=0,w,nodes,fnodes;
    char filename[200];
    printf("\nEnter the number of Routers in the Topology : ");
    scanf("%d",&nodes);
    printf("\nEnter the name of file:");
    scanf("%s",filename);
    printf("\n\nEnter the router to be failed(Enter 0 if no router failure):");
    scanf("%d",&fnodes);
    int fmat[nodes][nodes];
    printf("\n");

//Getting the intial matrix as a File input

FILE *file_input = fopen(filename, "r");

//Creating the inital Cost matrix to compute the shortest path
	

if(fnodes > 0 && fnodes <= nodes) //Initial matrix computation if a router failure is stimulated
 { 
   for(i=1;i<=nodes;i++)
    {
     for(j=1;j<=nodes;j++)
        {   	
	  fscanf(file_input, "%d", &w);
	  cost_mat[i][j] = w;
	  int_mat[i][j] =w ;
	  cost_mat[fnodes][j] = 999;
	  int_mat[fnodes][j] =w ;
          Router[i].cost[j]=cost_mat[i][j];
          Router[i].to[j]=j;
        }
	cost_mat[i][fnodes] = 999;	
	int_mat[i][fnodes] =999 ;
	Router[i].cost[fnodes]=999;
	//printf("\n%d",cost_mat[i][fnodes]);
	}
	}

      else //Initial matrix computation if no router failure is stimulated
        {
        for(i=1;i<=nodes;i++)
	{
         for(j=1;j<=nodes;j++)
        {       
	  fscanf(file_input, "%d", &w);
          cost_mat[i][j] = w;
          int_mat[i][j] =w ;
          cost_mat[i][i]=0;
	  int_mat[i][i] = 0;
          Router[i].cost[j]=cost_mat[i][j];
          Router[i].to[j]=j;
        }

}
}

//Printing the Intial Matrix

printf("\nInitial Matrix \n");

for(i=1;i<=nodes;i++)
 {
	printf("\n");
        for(j=1;j<=nodes;j++)
	{
		printf("\t%d",cost_mat[i][j]);
	}
}
printf("\n");

//Distance Vector algorithm to calculate the distance Vector between Routers

count = 1;
while(count!=0)       
 {   
   count = 0;
		
            for(i=1;i<=nodes;i++)
	     {
              for(j=1;j<=nodes;j++) 
               {
            	 for(k=1;k<=nodes;k++)
		 { 
                  if(int_mat[i][k] != 999)
                  {
                  if(Router[i].cost[j]>cost_mat[i][k]+cost_mat[k][j])
                    {
                     Router[i].cost[j]=cost_mat[i][k]+cost_mat[k][j];
                     Router[i].to[j]=j;
		     Router[i].next[j]=k; 
                     count++;
                 }
                }
	       }
              }
             }

//Updated cost matrix 

for(i=1;i<=nodes;i++)
 {
            for(j=1;j<=nodes;j++)
                {
			cost_mat[i][j] = Router[i].cost[j];
                }
 }

//Calculating the number of iterations n to get the final matrix

if(count !=0)
 {
	iterations++;
 }
}

printf("\nThe required number of iterations %d\n",iterations);

//Final matrix

printf("\n\n Final Matrix \n\n");

for(i=1;i<=nodes;i++)
 {
	    printf("\n");
            for(j=1;j<=nodes;j++)
             {
			printf("\t%d",cost_mat[i][j]);
             }	
 }
printf("\n");

//Finding the shortest path with the final matrix and router tables

do
{
printf("\nenter source and destination to find the shortest path\n");
printf("enter the source:\n");
scanf("%d",&sc);
printf("enter the destination:\n");
scanf("%d",&dt);
int temp=0,inter_nodes[10];
int z=0;
temp = sc;
int iter = 0,cnt;

do
 {
	cnt = 0;
	if (Router[temp].next[dt] != 0)
	 {
		inter_nodes[z] = Router[temp].next[dt];
		temp = inter_nodes[z];	
		z++;
		cnt++;
		iter++;
	}
 }while(cnt !=0);
if (iter == 0)
 {
	printf("the shortest path to router-%d to router-%d is:%d->%d\n",sc,dt,sc,dt);
	printf("The length of this path is:%d\n",iter);
 }
else
 { 
	printf("the shortest path to router%d to router%d is\n",sc,dt);
	printf("%d->",sc);
	for(i=0;i<iter;i++)
        	
 	 {
		printf("%d->",inter_nodes[i]);
         }
	printf("%d\n",dt);
	printf("The length of this path is:%d\n",iter);
 }

printf("\nTo continue finding another shortest path enter 1 , to exit the program enter 0:");
scanf("%d",&user_input);
printf("\n");
}while(user_input != 0);
printf("\n\n");
}

