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
printf("WELCOME TO PREEMTIVE PRIORITY SCHEDULING ALGORITHM\n\n");
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
if(obj.pr[obj.i]<0)
{
printf("Invalid Input try again\n");
getdata();
}
}
}
void display()
{
printf("Process ID\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
printf("    %d\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",obj.i,obj.y[obj.i],obj.x[obj.i],obj.pr[obj.i]);
}
}
void priority()
{
obj.count=0;
if(obj.pr[obj.i]==0)
{
obj.pr[obj.i]+=1;
obj.count++;
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
obj.count=1;
if(obj.pr[obj.i]!=obj.count)
{
obj.pr[obj.i]+=2;
}
}
}
}
void timeslice()
{
obj.slice=1;
int t=0;
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
obj.rem_bt[obj.i]=obj.y[obj.i];
}
while(1)
{
int flag=1;
for(obj.i=1;obj.i<=obj.n;obj.i++)
if(obj.rem_bt[obj.i]>0)
{
flag=0;
if(obj.rem_bt[obj.i]>obj.slice)
{
t+=obj.slice;
obj.rem_bt[obj.i]-=obj.slice;
}
else
{
t=t+obj.rem_bt[obj.i];
obj.wat[obj.i]=t-obj.y[obj.i];
obj.rem_bt[obj.i]=0;
}
}
if(flag==1)
break;
}
}
void turnaround()
{
printf("\nTURNAROUND TIME\n");
for(obj.i=1;obj.i<=obj.n;obj.i++)
{
obj.tat[obj.i]=obj.wat[obj.i]+obj.y[obj.i];
printf("\nProcess ID\t\tBurst Time\t\tArrival Time\t\tPriority\t\t   Turnaround Time\n");
printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\t\n",obj.i,obj.y[obj.i],obj.x[obj.i],obj.pr[obj.i],obj.tat[obj.i]);
}
}
void waiting()
{
printf("\nWAITING TIME \n");
for(obj.i=1;obj.i<=obj.n;obj.i++)  
{
printf("\nProcess ID\t\tBurst Time\t\tArrival Time\t\tPriority\t\t  Waiting Time\n");
printf("    %d\t\t\t    %d\t\t\t     %d\t\t\t    %d\t\t\t     %d\t\n",obj.i,obj.y[obj.i],obj.x[obj.i],obj.pr[obj.i],obj.wat[obj.i]);
}
}
int main()
{
 float k=0,m=0;
 getdata();
 display();
 priority();
 timeslice();
 turnaround();
 waiting();
for(obj.i=1;obj.i<=obj.n;obj.i++)
 {
 k=k+obj.tat[obj.i];
 m=m+obj.wat[obj.i];
 }
 k=k/obj.n;
 m=m/obj.n;
 printf("\nAverage turnaround time : %f\n",k);
 printf("\nAverage waiting time : %f\n",m);
}


