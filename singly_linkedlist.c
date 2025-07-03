#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer (global)
struct Node* head = NULL;

// Insert at end
void insert_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Insert at beginning
void insert_at_beginning(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

// Insert at specific position (0-based)
void insert_at_position(int position, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Node* temp = head;
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete node at specific position
void delete_node(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}

// Display the linked list
void display_list() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the operations
int main() {
    insert_node(10);
    insert_node(20);
    insert_node(30);
    display_list();  // Output: 10 -> 20 -> 30 -> NULL

    insert_at_beginning(5);
    display_list();  // Output: 5 -> 10 -> 20 -> 30 -> NULL

    insert_at_position(2, 15);
    display_list();  // Output: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    delete_node(3);
    display_list();  // Output: 5 -> 10 -> 15 -> 30 -> NULL

    return 0;
}