#include <stdio.h>
#include <stdbool.h>

int main() {
    int size1, size2;
    int set1[100], set2[100], intersection[100];
    int counter1, counter2, counter3, counter4;
    int intersection_size = 0;

    // Input for Set 1
    printf("Enter number of elements in Set 1: ");
    scanf("%d", &size1);
    printf("Enter elements of Set 1:\n");
    for (counter1 = 0; counter1 < size1; counter1++) {
        scanf("%d", &set1[counter1]);
    }

    // Input for Set 2
    printf("Enter number of elements in Set 2: ");
    scanf("%d", &size2);
    printf("Enter elements of Set 2:\n");
    for (counter2 = 0; counter2 < size2; counter2++) {
        scanf("%d", &set2[counter2]);
    }

    // Finding intersection
    for (counter1 = 0; counter1 < size1; counter1++) {
        for (counter2 = 0; counter2 < size2; counter2++) {
            if (set1[counter1] == set2[counter2]) {
                bool already_exists = false;
                for (counter3 = 0; counter3 < intersection_size; counter3++) {
                    if (intersection[counter3] == set1[counter1]) {
                        already_exists = true;
                        break;
                    }
                }
                if (!already_exists) {
                    intersection[intersection_size] = set1[counter1];
                    intersection_size++;
                }
            }
        }
    }

    // Output
    if (intersection_size == 0) {
        printf("No intersection found.\n");
    } else {
        printf("Intersection of the two sets: ");
        for (counter4 = 0; counter4 < intersection_size; counter4++) {
            printf("%d ", intersection[counter4]);
        }
        printf("\n");
    }

    return 0;
}
