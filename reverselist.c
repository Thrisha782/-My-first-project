#include <stdio.h>
#include <stdlib.h>

// 🔸 Node structure
struct Node {
    int data;
    struct Node* next;
};

// 🔸 Function to append node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
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

// 🔸 Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 🔁 Reverse the linked list with step-by-step comments
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;        // 🔹 'prev' initially points to NULL
    struct Node* current = head;     // 🔹 'current' starts from head
    struct Node* next = NULL;        // 🔹 'next' used to store next node temporarily

    while (current != NULL) {
        next = current->next;        // 🔸 Step 1: Store next node address
        current->next = prev;        // 🔸 Step 2: Reverse the link direction
        prev = current;              // 🔸 Step 3: Move 'prev' to current node
        current = next;              // 🔸 Step 4: Move 'current' to next node
    }

    return prev;                     // 🔚 Return new head (prev becomes new head)
}

// 🔸 Function to build linked list using -999 as stop input
void inputLinkedList(struct Node** head_ref) {
    int value;
    printf("Enter node values (enter -999 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == -999)
            break;                   // 🛑 Stop input when -999 is entered
        append(head_ref, value);
    }
}

// 🔸 Main function
int main() {
    struct Node* head = NULL;

    inputLinkedList(&head);           // 🔹 Get input from user
    printf("\nOriginal List:\n");
    printList(head);                  // 🔹 Display original list

    head = reverseList(head);        // 🔁 Reverse the list

    printf("\nReversed List:\n");
    printList(head);                 // 🔹 Display reversed list

    return 0;
}
