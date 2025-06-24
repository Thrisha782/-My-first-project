//Header file
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to append a new node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;   // First node becomes head
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;      // Add at end
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;        // 🔸 Store next node
        current->next = prev;        // 🔸 Reverse the link
        prev = current;              // 🔸 Move prev forward
        current = next;              // 🔸 Move to next node
    }

    return prev;                     // 🔸 Return new head of reversed list
}

// Function to take input and build the list
void inputLinkedList(struct Node** head_ref, int n) {
    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(head_ref, value);    // Add value to the list
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    inputLinkedList(&head, n);       // Input values
    printf("\nOriginal List:\n");
    printList(head);                 // Before reverse

    head = reverseList(head);        // Reverse the list

    printf("\nReversed List:\n");
    printList(head);                 // After reverse

    return 0;
}