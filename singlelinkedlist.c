// Program to implement  singly linked list with ADT(Abstract Data Type) operations

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int n;
    struct node *next;
};

// Global pointers
struct node *first = NULL;
struct node *last = NULL;
struct node *current = NULL;
struct node *before = NULL;
struct node *after = NULL;

int count = 0;

// Function prototypes
void create();// Creates a new node
void display();//prints all the nodes in the  list
void beforeInsert();// inserts a new node before a specific value
void afterInsert();// inserts a new node after a specific value
void delet();// deletes a node by value
void search();// searches for a value in the list
void insertAtPosition();// inserts a node at specific position
void deleteAtPosition();// deletes a node at specific position
void reverseList();// Reverses the whole list and prints it
void freeAll();//Frees all nodes before existing

// Main menu
int main() {
    int option;
    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Display\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete by Value\n");
        printf("6. Search\n");
        printf("7. Insert at Specific Position\n");
        printf("8. Delete at Specific Position\n");
        printf("9. Reverse List\n");
        printf("10. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: beforeInsert(); break;
            case 4: afterInsert(); break;
            case 5: delet(); break;
            case 6: search(); break;
            case 7: insertAtPosition(); break;
            case 8: deleteAtPosition(); break;
            case 9: reverseList(); break;
            case 10:
                freeAll();
                printf("\nExiting program. All memory freed.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to create node
void create() {
    current = (struct node*)malloc(sizeof(struct node));//creatning a node dynamically using  malloc
    if (current == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &current->n);
    current->next = NULL;

    if (first == NULL) {
        first = last = current;
    } else {
        last->next = current;
        last = current;
    }
    count++;
    printf("Node created successfully.\n");
}

// Function to display nodes
void display() {
    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }
    printf("\nLinked List Elements:\n");
    current = first;
    while (current != NULL) {
        printf("%d  ", current->n);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert before a specific value
void beforeInsert() {
    int n1;
    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }

    printf("Enter node value before which to insert: ");
    scanf("%d", &n1);

    if (first->n == n1) {
        current = (struct node*)malloc(sizeof(struct node));
        printf("Enter new value: ");
        scanf("%d", &current->n);
        current->next = first;
        first = current;
        count++;
        printf("Node inserted successfully.\n");
        return;
    }

    before = first;
    after = before->next;
    while (after != NULL) {
        if (after->n == n1) {
            current = (struct node*)malloc(sizeof(struct node));
            printf("Enter new value: ");
            scanf("%d", &current->n);
            before->next = current;
            current->next = after;
            count++;
            printf("Node inserted successfully.\n");
            return;
        }
        before = after;
        after = after->next;
    }
    printf("Value %d not found in list.\n", n1);
}

// Function to insert after a specific value
void afterInsert() {
    int n1;
    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }

    printf("Enter node value after which to insert: ");
    scanf("%d", &n1);

    after = first;
    while (after != NULL) {
        if (after->n == n1) {
            current = (struct node*)malloc(sizeof(struct node));
            printf("Enter new value: ");
            scanf("%d", &current->n);
            current->next = after->next;
            after->next = current;
            if (after == last)
                last = current;
            count++;
            printf("Node inserted successfully.\n");
            return;
        }
        after = after->next;
    }
    printf("Value %d not found in list.\n", n1);
}

// Function to delete a node by value
void delet() {
    int n1;
    struct node *temp;

    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }

    printf("Enter node value to delete: ");
    scanf("%d", &n1);

    if (first->n == n1) {
        temp = first;
        first = first->next;
        free(temp);
        count--;
        if (first == NULL) last = NULL;
        printf("Node deleted successfully.\n");
        return;
    }

    before = first;
    after = before->next;
    while (after != NULL) {
        if (after->n == n1) {
            before->next = after->next;
            if (after == last)
                last = before;
            free(after);
            count--;
            printf("Node deleted successfully.\n");
            return;
        }
        before = after;
        after = after->next;
    }

    printf("Value %d not found in list.\n", n1);
}

// Function to search a value
void search() {
    int val, pos = 1, found = 0;

    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    current = first;
    while (current != NULL) {
        if (current->n == val) {
            printf("Value %d found at position %d.\n", val, pos);
            found = 1;
            break;
        }
        current = current->next;
        pos++;
    }
    if (!found)
        printf("Value %d not found in list.\n", val);
}

// Function to insert at a specific position
void insertAtPosition() {
    int pos, i;
    printf("Enter position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    current = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &current->n);

    if (pos == 1) {
        current->next = first;
        first = current;
        if (last == NULL)
            last = current;
    } else {
        before = first;
        for (i = 1; i < pos - 1; i++)
            before = before->next;
        current->next = before->next;
        before->next = current;
        if (current->next == NULL)
            last = current;
    }
    count++;
    printf("Node inserted successfully.\n");
}

// Function to delete at a specific position
void deleteAtPosition() {
    int pos, i;
    struct node *temp;

    if (first == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        temp = first;
        first = first->next;
        free(temp);
        if (first == NULL)
            last = NULL;
    } else {
        before = first;
        for (i = 1; i < pos - 1; i++)
            before = before->next;
        temp = before->next;
        before->next = temp->next;
        if (temp == last)
            last = before;
        free(temp);
    }
    count--;
    printf("Node deleted successfully.\n");
}

// Function to reverse the linked list
void reverseList() {
    struct node *prev = NULL, *nextNode = NULL;
    current = first;

    if (first == NULL) {
        printf("\nNo nodes are created.\n");
        return;
    }

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    last = first;
    first = prev;

    printf("\nLinked list reversed successfully.\n");
    display();
}

// Function to free all nodes before exiting
void freeAll() {
    struct node *temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }
    last = NULL;
    count = 0;
}


// END OF SINGLY LINKED LIST IMPLEMENTATION