#include <stdio.h>

int main() {
    int array_size, chunk_size, counter;

    // Getting input for array size
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    int arr[array_size]; // Declaring the array

    // Getting input for array elements
    printf("Enter the elements of the array: ");
    for (counter = 0; counter < array_size; counter++) {
        scanf("%d", &arr[counter]);
    }

    // Getting the chunk size
    printf("Enter a chunk size: ");
    scanf("%d", &chunk_size);

    // Reversing in chunks
    for (counter = 0; counter < array_size; counter += chunk_size) {
        int start_index = counter;
        int end_index = counter + chunk_size - 1;

        // Adjust end_index if it exceeds array size
        if (end_index >= array_size) {
            end_index = array_size - 1;
        }

        // Swapping within chunk using temporary variable
        while (start_index < end_index) {
            int temp = arr[start_index];
            arr[start_index] = arr[end_index];
            arr[end_index] = temp;
            start_index++;
            end_index--;
        }
    }

    // Output the modified array
    printf("Reversed array in chunks: ");
    for (counter = 0; counter < array_size; counter++) {
        printf("%d ", arr[counter]);
    }

    return 0;
}
