#include <stdio.h>
#include <stdlib.h>


struct node {
    int n;
    struct node *next;
};

struct node *first = NULL;
struct node *last;
struct node *current;
struct node *next;
struct node *after;
struct node *before;
int count=0;


int main() {
    int option;
    do{
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Display\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete\n");
        printf("6. Search\n");
        printf("7. Insert at Specific Position\n");
        printf("8. Delete at Specific Position\n");
        printf("9. Reverse\n");
        printf("10. Exit\n");
        printf("\nEnter your option:\n ");
        scanf("%d",&option);
        switch(option) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: beforeInsert(); break;
            case 4: afterInsert(); break;
            case 5: delet(); break;
            case 6: search(); break;
            case 7: insertAtPosition(); break;
            case 8: deleteAtPosition(); break;
            case 9: reverseList(); break;
            case 10: exit(0);
            default: printf("Invalid option!\n");
        }
    }while(1);
    return 0;
}



void create() {
     count++;
    current = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value:\n ");
    scanf("%d", &current->n);
    if (first == NULL) {
        first = last = current;
        last->next=NULL;
    } else {
        last->next = current;
        last = current;
        last->next=first;
    }
}



void display()
{
     if(first==NULL)
     {
        printf("\n no nodes are created\n");
     }
     else
     {
         current=first;
         do
         {
            printf("\n%d\n",current->n);
            current=current->next;
         }while(current!=first);
         
     }
}



            
void beforeInsert()
{
    int n1;
    if (first == NULL) {
        printf("\nNo nodes are created\n");
    }
    else {
        printf("\nEnter n1 value: ");
        scanf("%d", &n1);

        before = last;         // start with last (since circular)
        after = first;         // start traversal from first

        // Case 1: inserting before first node
        if (first->n == n1) {
            count++;
            current = (struct node*)malloc(sizeof(struct node));
            printf("Enter n value: ");
            scanf("%d", &current->n);

            current->next = first;
            first = current;
            last->next = first;   // maintain circular link
        }
        else {
            int found = 0;
            // traverse until we reach back to 'first'
            do {
                if (after->n == n1) {
                    count++;
                    current = (struct node*)malloc(sizeof(struct node));
                    printf("Enter n value: ");
                    scanf("%d", &current->n);

                    before->next = current;
                    current->next = after;
                    found = 1;
                    break;
                }
                before = after;
                after = after->next;
            } while (after != first);

            if (!found) {
                printf("\nNo such node is created\n");
            }
        }
    }

}

void afterInsert()
{
    int n1;
    if(first==NULL){
        printf("\nno nodes are created\n");
    }
    else{
        before=first;
        after=before->next;
        printf("\nenter n1 value :\n ");
        scanf("%d",&n1);
        if(first->n==n1){
            count++;
            current=(struct node*)malloc(sizeof(struct node));
            printf("enter n value");
            scanf("%d",&current->n);
            before->next=current;
            current->next=after;
        }
        else{
            while(after!=NULL){
                if(after->n==n1){
                    count++;
                    current=(struct node*)malloc(sizeof(struct node));
                    printf("enter n value : ");
                    scanf("%d",&current->n);
                    current->next=after->next;
                    after->next=current;
                    break;
                }
                else{
                    before=after;
                    after=before->next;
                }
            }
            if(after==NULL){
                printf("\nno such node is created\n");
            }
        }
    }
}



void delet()
{
    int n1;
    if(first==NULL){
        printf("\nno nodes are created\n");
    }
    else{
        before=first;
        after=before->next;
        printf("\nenter n1 value :\n ");
        scanf("%d",&n1);
        if(first->n==n1){
            count--;
            first=first->next;
        }
        else{
            while(after!=NULL){
                if(after->n==n1){
                    count--;
                    before->next=after->next;

                    break;
                }
                else{
                    before=after;
                    after=before->next;
                }
            }
            if(after==NULL){
                printf("\nno such node is created\n");
            }
        }
    }
}




void search()
{
    int val, pos=1, found=0;
    if(first==NULL){
        printf("\nNo nodes are created\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d",&val);
    current=first;
    while(current!=NULL){
        if(current->n==val){
            printf("Value %d found at position %d\n",val,pos);
            found=1;
            break;
        }
        current=current->next;
        pos++;
    }
    if(!found)
        printf("Value %d not found in list\n",val);
    }



void insertAtPosition(){
    int pos, i;
    if(first==NULL && count==0){
        printf("\nList is empty, use Create Node option first.\n");
        return;
    }
    printf("Enter position to insert (1 to %d): ",count+1);
    scanf("%d",&pos);
    if(pos<1 || pos>count+1){
        printf("Invalid position!\n");
        return;
    }
    current=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&current->n);
    if(pos==1){
        current->next=first;
        first=current;
    } else {
        before=first;
        for(i=1;i<pos-1;i++){
            before=before->next;
        }
        current->next=before->next;
        before->next=current;
    }
    count++;
}


void deleteAtPosition(){
     int pos, i;
    if(first==NULL && count==0){
        printf("\nList is empty, use Create Node option first.\n");
        return;
    }
    printf("Enter position to insert (1 to %d): ",count+1);
    scanf("%d",&pos);
    if(pos<1 || pos>count+1){
        printf("Invalid position!\n");
        return;
    }
    current=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&current->n);
    if(pos==1){
        current->next=first;
        first=current;
    } else {
        before=first;
        for(i=1;i<pos-1;i++){
            before=before->next;
        }
        current->next=before->next;
        before->next=current;
    }
    count++;
}

void reverseList() {
    struct node *temp = NULL, *temp1 = NULL;
    current = first;

    if (first == NULL) {
        printf("\nNo nodes are created\n");
        return;
    }

    while (current != NULL) {
        temp1 = current->next;   
        current->next = temp;   
        temp = current;         
        current = temp1;         
    }

    first = temp; 
    display();
    printf("\nLinked list reversed successfully.\n");
}



