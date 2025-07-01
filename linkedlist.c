#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList() {
    struct Node* temp = head;
    printf("📃 Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void addAtFirst(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void addAtMiddle(int value, int position) {
    if (position <= 1) {
        addAtFirst(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("❌ Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteByValue(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ %d not found\n", value);
        return;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("✅ %d deleted\n", value);
}
void reverseList() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("✅ List Reversed\n");
}

int main() {
    int choice, value, pos;

    // Show menu only once
    printf("\n--- MENU ---\n");
    printf("1. Create a new node\n");
    printf("2. Add node at end\n");
    printf("3. Add node at beginning\n");
    printf("4. Add node at middle\n");
    printf("5. Delete node by value\n");
    printf("6. Reverse the list\n");
    printf("7. Print the linked list\n");
    printf("8. Exit\n");  // ✅ Modified from 0 to 8

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter values to create (end with -999): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -999) break;
                    addAtEnd(value);
                }
                printList();
                break;

            case 2:
                printf("Enter value to add at end: ");
                scanf("%d", &value);
                addAtEnd(value);
                printList();
                break;

            case 3:
                printf("Enter value to add at beginning: ");
                scanf("%d", &value);
                addAtFirst(value);
                printList();
                break;

            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                addAtMiddle(value, pos);
                printList();
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                printList();
                break;

            case 6:
                reverseList();
                printList();
                break;

            case 7:
                printList();
                break;

            case 8:
                printf("👋 Exiting...\n");
                return 0;

            default:
                printf("❌ Invalid choice\n");
        }
    }

    return 0;
}