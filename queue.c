//wap for queue using arrays
#include<stdio.h>

#include<conio.h>
#define max 5

int queue[max];
int front=-1, rear=-1, size=0, e, i;

void insertion(void);
void deletion(void);
void traverse(void);



void main(void)
{
int choice;
char ans;

do
{

printf("\nqueue using arrays\n");
printf("\n\t1. insertion \n\t2.deletion \n\t3.traverse \n\t0.exit\n");
printf("\nenter ur choice:");
scanf("%d",&choice);
	switch(choice)
	{
	case 1: insertion(); break;
	case 2: deletion(); break;
	case 3: traverse(); break;
	case 0: exit(0);
	default: printf("\n\tinvalid choice!!!! try again....\n"); break;
	}//switch
printf("\ndo u want to continue from queue menu onwards... press (y/Y):");
ans=getche();
}while(ans=='y' || ans=='Y');
}//main

void insertion(void)
{
if(rear==(max-1))
{
printf("\nqueue is full/overflow");
}//if
else
{
printf("\nenter the element to be insertioned into the queue:");
scanf("%d",&e);
rear=rear+1;
queue[rear]=e;
size++;
printf("\n\t%d element is insertioned into the queue\n",e);
printf("\n\t\trear=%d\tfront=%d\tsize=%d\n",rear,front,size);
}//else
}//insertion

void deletion(void)
{
if(front==rear)
{
printf("\nqueue is empty/underflow\n");
}//if
else
{
front=front+1;
size--;
printf("\n\t%d element is deletioned from the queue\n",queue[front]);
printf("\n\t\trear=%d\tfront=%d\tsize=%d\n",rear,front,size);
}//else
}//deletion

void traverse(void)
{
if(front==rear)
{
printf("\nqueue is empty/underflow\n");
}//if
else
{
printf("\n\n\tthe size of the queue is %d\n",size);
printf("\n\t\trear=%d\tfront=%d\tsize=%d\n",rear,front,size);
printf("\ntraversing the queue\n");
for(i=front;i<rear;i++)
{
printf("\t%d",queue[i+1]);
}//for
}//else
}//traverse