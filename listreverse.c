#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node {
    int data;
    struct node* link;
};

// Global head pointer
struct node* head = NULL;

// Insert at end
void insert(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;  // ✅ Linking node here
    }
}


// Print list
void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Reverse list
void reverseList() {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next =curr->link ;

    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Main function
int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &val);
        insert(val);
    }

    printf("Original linked list:\n");
    printList();

    reverseList();

    printf("Reverse linked list:\n");
    printList();

    return 0;
}
