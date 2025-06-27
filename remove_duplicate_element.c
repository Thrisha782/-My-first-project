//Header file

#include <stdio.h>

// ✅ Function 1: To input array elements
void readSortedArray(int arr[], int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);

    printf("Enter sorted elements:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

// ✅ Function 2: To remove duplicates from sorted array
int removeDuplicatesFromSortedArray(int arr[], int size) {
    if (size == 0) return 0;

    int k = 1; // next unique index

    for (int j = 1; j < size; j++) {
        if (arr[j] != arr[k - 1]) {
            arr[k] = arr[j];
            k++;
        }
    }

    return k;
}

// ✅ Function 3: To print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ✅ MAIN Function
int main() {
    int arr[100];
    int size;
    char choice;  // ✅ Declare this!

    do {  // ✅ Start of the loop

        // Read input
        readSortedArray(arr, &size);

        // Process: Remove duplicates
        int uniqueCount = removeDuplicatesFromSortedArray(arr, size);

        // Output
        printf("Number of unique elements: %d\n", uniqueCount);
        printf("Array after removing duplicates: ");
        printArray(arr, uniqueCount);

        // Ask user if they want to continue
        printf("\nDo you want to enter another array? (y/n): ");
        scanf(" %c", &choice); // ✅ with space before %c

    } while (choice == 'y' || choice == 'Y');  // ✅ Loop end

    return 0;
}
