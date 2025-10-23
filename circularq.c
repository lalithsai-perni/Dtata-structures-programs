#include<stdio.h>
#define max_size 5
int queue[max_size];
int front = -1;
int rear = -1;
void enqueue(int ele){
    if((rear+1)%max_size==front){
        printf("queue is overflow");
        return;
    }
    if(front == -1){
        front = 0;
        rear=(rear+1)%max_size;
        queue[rear]=ele;
    }
}
void dequeue(){
    if(front == -1){
        printf("queue is empty");
        return;
    }
    printf("the element deleted is %d",queue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front+1)%max_size;
  
    }
}
void display(){
    int i = front;
    while(i!= rear){
        printf("%d",queue[i]);
        i=(i+1)%max_size;
    }
    printf("%d\n",queue[rear]);
}
void main(){
    int choice;
    do{
        
        printf("1.enqueue\n2.dequeue\n3.display\n");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        int ele;
        switch(choice){
            case 1: 
            printf("\nenter the element :");
            scanf("%d",&ele);
            enqueue(ele);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;


        }

    }while(1);
}