#include <stdio.h>

// ✅ Function to read array elements
void readArray(int arr[], int size, const char* arrayName) {
    printf("Enter elements for %s: ", arrayName);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// ✅ Function to print array elements
void printArray(int arr[], int size, const char* message) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ✅ Function to merge two arrays
void mergeArrays(int arr1[], int arr2[], int size, int merged[]) {
    for (int i = 0; i < size; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size; i++) {
        merged[size + i] = arr2[i];
    }
}

// ✅ Function to sort array (Bubble Sort)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                // swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    int arr1[100], arr2[100], merged[200];

    printf("Enter the size of each array: ");
    scanf("%d", &size);

    // Read input arrays
    readArray(arr1, size, "Array 1");
    readArray(arr2, size, "Array 2");

    // Merge the arrays
    mergeArrays(arr1, arr2, size, merged);

    // Sort the merged array
    sortArray(merged, size * 2);

    // Print the final result
    printArray(merged, size * 2, "Sorted Merged Array: ");

    return 0;
}