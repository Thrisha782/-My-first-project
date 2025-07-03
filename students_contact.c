#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact
struct Contact {
    char name[100];             // character array for name
    int phone_number;           // integer for phone number
    struct Contact* next;       // pointer to next contact
};

// Head of the contact list
struct Contact* head = NULL;

// Function to add contact at the end
void add_contact(char name[], int phone_number) {
    struct Contact* new_node = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(new_node->name, name);
    new_node->phone_number = phone_number;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;  // First contact
    } else {
        struct Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;  // Append at end
    }
}

// Function to display contacts
void display_contacts() {
    if (head == NULL) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nStored Contacts:\n");
    struct Contact* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Phone Number: %d\n", temp->name, temp->phone_number);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n;
    char name[100];
    int phone;

    printf("How many contacts do you want to store? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter name for contact %d: ", i + 1);
        scanf("%s", name);  // Note: no spaces in names unless you use fgets()

        printf("Enter phone number for contact %d: ", i + 1);
        scanf("%d", &phone);

        add_contact(name, phone);
    }

    display_contacts();

    return 0;
}
