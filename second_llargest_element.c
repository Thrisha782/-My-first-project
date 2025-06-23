#include <stdio.h>

// ✅ Function: Reads sorted array input
void readArray(int arr[], int *size, char arrayName) {
    printf("Enter number of elements in array %c: ", arrayName);
    scanf("%d", size);
    printf("Enter %d sorted elements in array %c:\n", *size, arrayName);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

// ✅ Function: Finds the second largest common element in two sorted arrays
int findSecondLargestCommonElement(int a[], int b[], int aSize, int bSize) {
    int i = 0, j = 0, k = 0;
    int common[100];

    while (i < aSize && j < bSize) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            // Avoid duplicates
            if (k == 0 || a[i] != common[k - 1]) {
                common[k++] = a[i];
            }
            i++;
            j++;
        }
    }

    if (k >= 2)
        return common[k - 2];  // Second largest
    else
        return -1;  // Less than 2 common elements
}

// ✅ Function: Displays the result
void displayResult(int result) {
    if (result != -1)
        printf("✅ Second Largest Common Element: %d\n", result);
    else
        printf("❌ Less than 2 Common Elements Found.\n");
}

// ✅ Main driver
int main() {
    int a[100], b[100];
    int aCount, bCount;

    // Input Phase
    readArray(a, &aCount, 'A');
    readArray(b, &bCount, 'B');

    // Process Phase
    int result = findSecondLargestCommonElement(a, b, aCount, bCount);

    // Output Phase
    displayResult(result);

    return 0;
}