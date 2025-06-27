#include <stdio.h>

// ✅ Function to sort array in ascending order
void sortArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// ✅ Function to print a subset
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// ✅ Recursive function to find valid subsets
void findSubsets(int arr[], int size, int target, int index, int currentSum, int subset[], int subsetSize) {
    if (currentSum == target && subsetSize >= 2) {
        printSubset(subset, subsetSize);
        return;
    }

    if (index >= size || currentSum > target) {
        return;
    }

    // Include current element
    subset[subsetSize] = arr[index];
    findSubsets(arr, size, target, index + 1, currentSum + arr[index], subset, subsetSize + 1);

    // Exclude current element
    findSubsets(arr, size, target, index + 1, currentSum, subset, subsetSize);
}

// ✅ Driver function for subset finding
void generateTargetSubsets(int arr[], int size, int target) {
    int subset[100];
    findSubsets(arr, size, target, 0, 0, subset, 0);
}

// ✅ Function to read array input
void readArray(int arr[], int size) {
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// ✅ Main function
int main() {
    int arr[100], size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    readArray(arr, size);

    printf("Enter the target value: ");
    scanf("%d", &target);

    sortArray(arr, size);
    generateTargetSubsets(arr, size, target);

    return 0;
}