#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Append function
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

// Print list (optional)
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 🔹 Function to find the Nth node from the end
int getNthFromEnd(struct Node* head, int N) {
    struct Node* first = head;
    struct Node* second = head;

    // Move first pointer N steps ahead
    for (int i = 0; i < N; i++) {
        if (first == NULL)
            return -1;  // N is greater than the number of nodes
        first = first->next;
    }

    // Move both until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second->data;
}

// Main
int main() {
    struct Node* head = NULL;
    int n, N, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter N (position from end): ");
    scanf("%d", &N);

    int result = getNthFromEnd(head, N);
    if (result != -1)
        printf("Nth node from end: %d\n", result);
    else
        printf("No such node exists (N is too big).\n");

    return 0;
}
