#include <stdio.h>

int main() {
    int matrix_size;
    int matrix_elements[100][100];

    // Getting matrix size
    printf("Enter the size of the matrix: ");
    scanf("%d", &matrix_size);

    // Getting matrix elements
    printf("Enter the elements in the matrix:\n");
    for (int row_counter = 0; row_counter < matrix_size; row_counter++) {
        for (int column_counter = 0; column_counter < matrix_size; column_counter++) {
            scanf("%d", &matrix_elements[row_counter][column_counter]);
        }
    }

    // Transpose the matrix
    for (int row_counter = 0; row_counter < matrix_size; row_counter++) {
        for (int column_counter = row_counter + 1; column_counter < matrix_size; column_counter++) {
            int temp_counter = matrix_elements[row_counter][column_counter];
            matrix_elements[row_counter][column_counter] = matrix_elements[column_counter][row_counter];
            matrix_elements[column_counter][row_counter] = temp_counter;
        }
    }

    // Reverse each row
    for (int row_counter = 0; row_counter < matrix_size; row_counter++) {
        for (int column_counter = 0; column_counter < matrix_size / 2; column_counter++) {
            int temp_counter = matrix_elements[row_counter][column_counter];
            matrix_elements[row_counter][column_counter] = matrix_elements[row_counter][matrix_size - 1 - column_counter];
            matrix_elements[row_counter][matrix_size - 1 - column_counter] = temp_counter;
        }
    }

    // Print rotated matrix
    printf("The rotated matrix:\n");
    for (int row_counter = 0; row_counter < matrix_size; row_counter++) {
        for (int column_counter = 0; column_counter < matrix_size; column_counter++) {
            printf("%d ", matrix_elements[row_counter][column_counter]);
        }
        printf("\n");
    }

    return 0;
}