//Header file
#include <stdio.h>
#include <stdlib.h>5

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to append node at the end
void append(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to find and return the middle node
int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // 1 step
        fast = fast->next->next;   // 2 steps
    }
    return slow->data; // slow will be at middle
}

// Main
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    int middle = findMiddle(head);
    printf("\nMiddle element: %d\n", middle);
    return 0;
}
