#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node* link;
};

// Global head pointer
struct node* head = NULL;

// Function to insert a node at a given position
int insert(int data, int count) {
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->link = NULL;

    if (count == 1) {
        temp1->link = head;
        head = temp1;
        return 0;
    }

    struct node* temp2 = head;
    for (int count1 = 0; count1 < count - 2; count1++) {
        if (temp2 == NULL) {
            printf("Position out of bounds!\n");
            return 0;
        }
        temp2 = temp2->link;
    }

    temp1->link = temp2->link;
    temp2->link = temp1;
    return 0;
}

// Function to reverse the linked list
int reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return 0;
}

// Function to get the value at a specific position
int value_at_position(int position) {
    struct node* temp = head;
    int index = 1;

    while (temp != NULL && index < position) {
        temp = temp->link;
        index++;
    }

    if (temp != NULL) {
        return temp->data;
    } else {
        printf("Invalid position!\n");
        return -1;
    }
}

// Function to print the linked list (optional helper)
void print_list() {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Main function
int main() {
    int size, elements, position;

    printf("Enter no. of elements: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int counter = 0; counter < size; counter++) {
        scanf("%d", &elements);
        insert(elements, counter + 1);
    }

    printf("Enter a position: ");
    scanf("%d", &position);

    reverse();

    int value = value_at_position(position);
    if (value != -1)
        printf("Value at position %d is: %d\n", position, value);

    return 0;
}
