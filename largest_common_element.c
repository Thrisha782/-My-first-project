// Header file
#include <stdio.h>

// ✅ Function to find the largest common element in two sorted arrays
int findLargestCommonElement(int a[], int b[], int aSize, int bSize) {
    int i = 0, j = 0, k = -1;  // i → index for a[], j → index for b[], k → stores largest common

    while (i < aSize && j < bSize) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            if (a[i] > k)  // Update only if current common element is larger
                k = a[i];
            i++;
            j++;
        }
    }

    return k;
}

// ✅ Function to input array
void readArray(int arr[], int *size, char arrayName) {
    printf("Enter number of elements in array %c: ", arrayName);
    scanf("%d", size);
    printf("Enter %d sorted elements in array %c:\n", *size, arrayName);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int a[100], b[100];
    int aCount, bCount;
    char choice;  // ✅ Needed for repeat

    do {
        // Input
        readArray(a, &aCount, 'A');
        readArray(b, &bCount, 'B');

        // Processing
        int k = findLargestCommonElement(a, b, aCount, bCount);

        // Output
        if (k != -1)
            printf("✅ Largest Common Element: %d\n", k);
        else
            printf("❌ No Common Elements Found.\n");

        // Ask for repeat
        printf("\nDo you want to enter another array? (y/n): ");
        while ((getchar()) != '\n');       // Clear buffer
        scanf(" %c", &choice);             // Accept choice



    } while (choice == 'y' || choice == 'Y');

    return 0;
}

