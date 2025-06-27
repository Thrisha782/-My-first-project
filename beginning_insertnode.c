#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display the list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main program
int main() {
    int n, value, choice;

    printf("How many nodes do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter value: ");
        scanf("%d", &value);
        printf("Where to insert?\n1. Beginning\n2. End\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            insertBeginning(value);
        else if (choice == 2)
            insertEnd(value);
        else
            printf("❌ Invalid choice! Skipping this value.\n");
    }

    printf("\n✅ Final Linked List:\n");
    display();

    return 0;
}
