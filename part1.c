#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct process
{
int i,j,n,count,slice;
int x[500],y[500],pr[500],tat[500],wat[500],rem_bt[500];
}obj;
void getdata()
{		
printf("WELCOME TO PREEMTIVE PRIORITY SCHEDULING ALGORITHM\n\n\n\n");
printf("Enter the number of processes you want : ");
scanf("%d",&obj.n);
if(obj.n<=0)
{
printf("Invalid Input try again\n");
getdata();
}
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
printf("\n Enter the Details for Process [%d]:",obj.i);
printf("\nBurst Time : %d : ",obj.i);
scanf("%d",&obj.y[obj.i]);
if(obj.y[obj.i]<=0)
{
printf("Invalid Input try again\n");
getdata();		
}
printf("\nArrival Time : ");
scanf("%d",&obj.x[obj.i]);
if(obj.x[obj.i]<0)
{
printf("Invalid Input try again\n");
getdata();		
}
printf("\nPriority : ");
scanf("%d",&obj.pr[obj.i]);
if(obj.pr[obj.i]<0){
printf("Invalid Input try again\n");
getdata();
}
}
}
void display()
{
printf("Process Number\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",obj.i,obj.y[obj.i],obj.x[obj.i],obj.pr[obj.i]);
}
}
int main()
{
	getdata();
	display();
}
