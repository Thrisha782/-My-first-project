#include <stdio.h>
#include <stdlib.h>

// Structure definition for each node
struct Node {
    int data;                  // Stores the value
    struct Node* next;         // Points to the next node
    struct Node* prev;         // Points to the previous node
};

struct Node* head = NULL;      // Head pointer to the first node

// Function to create a new node with the given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = value;     // Assign value to the node
    newNode->next = NULL;      // Initially no next
    newNode->prev = NULL;      // Initially no previous
    return newNode;            // Return the created node
}

// Function to print the doubly linked list
void printList() {
    struct Node* temp = head;  // Start from head
    printf("📄 Linked List: ");
    while (temp != NULL) {     // Traverse until the end
        printf("%d <-> ", temp->data);  // Print each node's data
        temp = temp->next;     // Move to next node
    }
    printf("NULL\n");          // End of list
}

// Function to add node at the end
void addAtEnd(int value) {
    struct Node* newNode = createNode(value);  // Create new node
    if (head == NULL) {         // If list is empty
        head = newNode;         // Make new node as head
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)  // Go to last node
        temp = temp->next;

        temp->next = newNode;       // Link last node to new node
    newNode->prev = temp;       // Link back from new node
}

// Function to add node at the beginning
void addAtBeginning(int value) {
    struct Node* newNode = createNode(value); // Create new node
    newNode->next = head;          // New node points to current head
    if (head != NULL)
        head->prev = newNode;      // Head points back to new node
    head = newNode;                // Head becomes the new node
}

// Function to add a node at a specific position
void addAtPosition(int value, int pos) {
    if (pos <= 1) {                // If position is 1 or less
        addAtBeginning(value);     // Insert at beginning
        return;
    }

    struct Node* newNode = createNode(value); // Create new node
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;         // Traverse to (pos-1)th node

    if (temp == NULL) {            // If position is invalid
        printf("❌ Invalid position\n");
        return;
    }

    newNode->next = temp->next;        // Link new node to next
    if (temp->next != NULL)
        temp->next->prev = newNode;    // Link next to new node
    newNode->prev = temp;              // Link new node to previous
    temp->next = newNode;              // Link previous node to new node
}

// Function to delete a node by value
void deleteByValue(int value) {
    struct Node* temp = head;

    // Traverse to find the node
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {                 // Value not found
        printf("❌ %d not found\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next; // Bypass the node
    else
        head = temp->next;             // If head is deleted, update head

    if (temp->next != NULL)
        temp->next->prev = temp->prev; // Adjust backward link

    free(temp);                        // Free memory
    printf("✅ %d deleted\n", value);
}

// Function to reverse the doubly linked list
void reverseList() {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (originally prev)
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;     // Update head to new front

    printf("✅ List Reversed\n");
}

// Main function with menu interface
int main() {
    int choice, value, pos;
    int firstTime = 1;   // To print menu only once

    while (1) {
        if (firstTime) {
            // Display menu
            printf("\n--- MENU ---\n");
            printf("1. Create a new node list\n");
            printf("2. Add node at end\n");
            printf("3. Add node at beginning\n");
            printf("4. Add node at position\n");
            printf("5. Delete node by value\n");
            printf("6. Reverse the list\n");
            printf("7. Print the linked list\n");
            printf("0. Exit\n");
            firstTime = 0;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter values (end with -999): ");
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
                addAtBeginning(value);
                printList();
                break;

            case 4:
                printf("Enter value and position: ");
 
 
 
 
 
 
                scanf("%d %d", &value, &pos);
                addAtPosition(value, pos);
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

            case 0:
                printf("👋 Exit program.\n");
                return 0;

            default:
                printf("❗ Invalid choice\n");
        }
    }
}
