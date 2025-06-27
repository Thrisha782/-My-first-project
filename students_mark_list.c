// Header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student details
struct Student_details {
    char roll_no[20];
    char student_name[50];
    int mark1;
    int mark2;
    int mark3;
    int total;
    struct Student_details* next;
};

// Function to create a new student node
struct Student_details* createStudent() {
    struct Student_details* newStudent = (struct Student_details*)malloc(sizeof(struct Student_details));

    printf("Enter Roll No: ");
    scanf("%s", newStudent->roll_no);

    printf("Enter Name: ");
    scanf("%s", newStudent->student_name);

    printf("Enter Mark 1: ");
    scanf("%d", &newStudent->mark1);

    printf("Enter Mark 2: ");
    scanf("%d", &newStudent->mark2);

    printf("Enter Mark 3: ");
    scanf("%d", &newStudent->mark3);

    newStudent->total = newStudent->mark1 + newStudent->mark2 + newStudent->mark3;

    return newStudent;
}

// Function to display all students
void displayStudents(struct Student_details* head) {
    struct Student_details* temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("\nStudent %d Details:\n", i++);
        printf("Roll No: %s\n", temp->roll_no);
        printf("Name: %s\n", temp->student_name);
        printf("Mark 1: %d\n", temp->mark1);
        printf("Mark 2: %d\n", temp->mark2);
        printf("Mark 3: %d\n", temp->mark3);
        printf("Total: %d\n", temp->total);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Student_details *head = NULL, *tail = NULL, *new_node;
    char choice;

    do {
        new_node = createStudent();

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        printf("Do you want to enter another student? (y/n): ");
        scanf(" %c", &choice);  // Space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    printf("\n--- All Student Records ---\n");
    displayStudents(head);

    // Free memory
    struct Student_details* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
