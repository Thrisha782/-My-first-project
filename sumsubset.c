#include <stdio.h>
#include <stdbool.h>

int main() {
    // Getting input
    int array_size;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    int array[100]; // Static array to hold elements

    // Input array elements
    printf("Enter the elements: ");
    for (int input_counter = 0; input_counter < array_size; input_counter++) {
        scanf("%d", &array[input_counter]);
    }

    // Input target value to find subset sum
    int target_value;
    printf("Enter the target value: ");
    scanf("%d", &target_value);

    bool is_found = false; // Flag to check if any valid pair found

    // Loop through the array to find pairs
    for (int start_counter = 0; start_counter < array_size; start_counter++) {
        for (int end_counter = start_counter + 1; end_counter < array_size; end_counter++) {
            // Check if the sum of two elements equals the target
            if (array[start_counter] + array[end_counter] == target_value) {
                printf("The indexes are: [%d, %d]\n", start_counter, end_counter);
                is_found = true;
            }
        }
    }

    // If no matching pairs found
    if (!is_found) {
        printf("No subsets of the target value found.\n");
    }

    return 0;
}
