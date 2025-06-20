#include <stdio.h>
#include <stdbool.h>

// Function to find max of two integers
int get_max(int value1, int value2) {
    return (value1 > value2) ? value1 : value2;
}

// Function to find min of two integers
int get_min(int value1, int value2) {
    return (value1 < value2) ? value1 : value2;
}

int main() {
    int slot_size1, slot_size2;
    int timeSlot1[100][2], timeSlot2[100][2];
    int duration;

    // Input for person 1
    printf("Enter number of slots for person 1: ");
    scanf("%d", &slot_size1);
    printf("Enter the slots as start and end time:\n");
    for (int start_counter1 = 0; start_counter1 < slot_size1; start_counter1++) {
        scanf("%d %d", &timeSlot1[start_counter1][0], &timeSlot1[start_counter1][1]);
    }

    // Input for person 2
    printf("Enter number of slots for person 2: ");
    scanf("%d", &slot_size2);
    printf("Enter the slots as start and end time:\n");
    for (int start_counter2 = 0; start_counter2 < slot_size2; start_counter2++) {
        scanf("%d %d", &timeSlot2[start_counter2][0], &timeSlot2[start_counter2][1]);
    }

    // Input for required duration
    printf("Enter the duration: ");
    scanf("%d", &duration);

    // Two-pointer approach to find earliest common slot
    int pointer_counter1 = 0;
    int pointer_counter2 = 0;
    bool slot_found = false;

    while (pointer_counter1 < slot_size1 && pointer_counter2 < slot_size2) {
        int start_time = get_max(timeSlot1[pointer_counter1][0], timeSlot2[pointer_counter2][0]);
        int end_time = get_min(timeSlot1[pointer_counter1][1], timeSlot2[pointer_counter2][1]);

        if (end_time - start_time >= duration) {
            printf("Earliest common available slot: [%d, %d]\n", start_time, start_time + duration);
            slot_found = true;
            break;
        }

        if (timeSlot1[pointer_counter1][1] < timeSlot2[pointer_counter2][1]) {
            pointer_counter1++;
        } else {
            pointer_counter2++;
        }
    }

    if (!slot_found) {
        printf("No common slot available for the required duration.\n");
    }

    return 0;
}
