#include <stdio.h>
#include <stdlib.h>

// Allocate memory for a matrix of size rows x cols
double* allocMatrix(int rows, int cols) {
    return (double *)malloc(rows * cols * sizeof(double));
}

// Function to get matrix elements from user
double* inputMatrix(double *matrix, int rows, int cols) {
    printf("Enter the matrix elements row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d,%d): ", i, j);
            scanf("%lf", (matrix + i * cols + j));
        }
    }
    return matrix;
}

// Display the matrix
void displayMatrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Add 2 matrices
double* addMatrices(double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Cannot add: matrices must have the same dimensions.\n");
        return NULL;
    }

    int rows = rows1, cols = cols1;
    double *result = allocMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }
    return result;
}

// Multiply a matrix by a scalar
double* scalarMultiply(double *matrix, int rows, int cols, double scalar) {
    double *result = allocMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix + i * cols + j) * scalar;
        }
    }
    return result;
}

// Multiply two matrices
double* multiplyMatrices(double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Cannot multiply: number of columns in A must be equal to number of rows in B.\n");
        return NULL;
    }
    double *result = allocMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *(result + i * cols2 + j) = 0;
            for (int k = 0; k < cols1; k++) {
                *(result + i * cols2 + j) += *(matrix1 + i * cols1 + k) * *(matrix2 + k * cols2 + j);
            }
        }
    }
    return result;
}

// Menu for user to choose operations
void menu(int choice, double *matrix1, double *matrix2, int rows1, int cols1, int rows2, int cols2) {
    switch (choice) {
        case 1:
        {// Input matrix A and B
            printf("\nEnter matrix A:\n");
            inputMatrix(matrix1, rows1, cols1);  

            printf("\nEnter matrix B:\n");
            inputMatrix(matrix2, rows2, cols2);

            printf("Matrices A and B have been entered successfully.\n");
            break;
        }
        case 2:
        {// Display matrix A and B
            printf("\nMatrix A:\n");
            displayMatrix(matrix1, rows1, cols1);  

            printf("\nMatrix B:\n");
            displayMatrix(matrix2, rows2, cols2);

            break;
        }
        case 3:
        {//Add matrices A and B
            double *result = addMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

            if (result == NULL) {
                printf("Addition failed due to dimension mismatch.\n");
                break;
            }

            printf("\nResult of A + B:\n");
            displayMatrix(result, rows1, cols1);
                
            free(result);
            break;
        }
        case 4:
        {// Multiply matrices A and B
            double *multResult = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

            if (multResult == NULL) {
                printf("Multiplication failed due to dimension mismatch.\n");
                break;
            }
            
            printf("\nResult of A * B:\n");
            displayMatrix(multResult, rows1, cols2);
                
            free(multResult);
            break;
        }
        case 5:
        {// Multiply matrix by a scalar
            printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
            int matrixChoice; scanf("%d", &matrixChoice);

            while (matrixChoice != 1 && matrixChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
                scanf("%d", &matrixChoice);
            }

            double scalar;
            printf("Enter scalar value: ");
            scanf("%lf", &scalar);

            if (matrixChoice == 1) {
                double *scaledMatrix = scalarMultiply(matrix1, rows1, cols1, scalar);

                printf("\nResult of A * %lf:\n", scalar);
                displayMatrix(scaledMatrix, rows1, cols1);

                free(scaledMatrix);
            } 
            else if (matrixChoice == 2) {
                double *scaledMatrix = scalarMultiply(matrix2, rows2, cols2, scalar);

                printf("\nResult of B * %lf:\n", scalar);
                displayMatrix(scaledMatrix, rows2, cols2);

                free(scaledMatrix);
            } 
                
            break;
        }
        case 6:
        {// Swap rows in matrix
            printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
            int matrixChoice; scanf("%d", &matrixChoice);

            while (matrixChoice != 1 && matrixChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
                scanf("%d", &matrixChoice);
            }

            int row1, row2;
            printf("Enter two rows to swap (1-based index): ");
            scanf("%d %d", &row1, &row2);

            while (row1 < 1 || row1 > rows1 || row2 < 1 || row2 > rows2 || row1 == row2) {
                printf("Invalid row indices.\n");
                printf("Enter two rows to swap (1-based index): ");
                scanf("%d %d", &row1, &row2);
            }
            row1--; row2--; // Convert to 0-based index

            if (matrixChoice == 1) {
                double temp;
                for (int j = 0; j < cols1; j++) {
                    temp = *(matrix1 + row1 * cols1 + j);
                    *(matrix1 + row1 * cols1 + j) = *(matrix1 + row2 * cols1 + j);
                    *(matrix1 + row2 * cols1 + j) = temp;
                }
                printf("\nMatrix A after swapping rows %d and %d:\n", row1, row2);
                displayMatrix(matrix1, rows1, cols1);
            } 
            else if (matrixChoice == 2) {
                double temp;
                for (int j = 0; j < cols2; j++) {
                    temp = *(matrix2 + row1 * cols2 + j);
                    *(matrix2 + row1 * cols2 + j) = *(matrix2 + row2 * cols2 + j);
                    *(matrix2 + row2 * cols2 + j) = temp;
                }
                printf("\nMatrix B after swapping rows %d and %d:\n", row1, row2);
                displayMatrix(matrix2, rows2, cols2);
            } 
                
            break;
        }
        case 7:
        {// Multiply a row in matrix by a scalar
            printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
            int matrixChoice; scanf("%d", &matrixChoice);

            while (matrixChoice != 1 && matrixChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
                scanf("%d", &matrixChoice);
            }

            int row;
            double scalar;
            printf("Enter row index (1-based) and scalar value: ");
            scanf("%d %lf", &row, &scalar);

            while (row < 1 || row > rows1) {
                printf("Invalid row index.\n");
                printf("Enter row index (1-based) and scalar value: ");
                scanf("%d %lf", &row, &scalar);
            }
            row--; // Convert to 0-based index

            if (matrixChoice == 1) {
                for (int j = 0; j < cols1; j++) {
                    *(matrix1 + row * cols1 + j) *= scalar;
                }
                printf("\nMatrix A after multiplying row %d by %lf:\n", row, scalar);
                displayMatrix(matrix1, rows1, cols1);
            } 
            else if (matrixChoice == 2) {
                for (int j = 0; j < cols2; j++) {
                    *(matrix2 + row * cols2 + j) *= scalar;
                }
                printf("\nMatrix B after multiplying row %d by %lf:\n", row, scalar);
                displayMatrix(matrix2, rows2, cols2);
            } 
                
            break;
        }
        case 8:
        {// Add scalar of one row (row1) to another row (row2) in matrix
            printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
            int matrixChoice; scanf("%d", &matrixChoice);

            while (matrixChoice != 1 && matrixChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
                scanf("%d", &matrixChoice);
            }

            int row1, row2;
            double scalar;
            printf("Enter two rows (1-based index) and scalar value: ");
            scanf("%d %d %lf", &row1, &row2, &scalar);

            while (row1 < 1 || row1 > rows1 || row2 < 1 || row2 > rows2 || row1 == row2) {
                printf("Invalid row indices.\n");
                printf("Enter two rows (1-based index) and scalar value: ");
                scanf("%d %d %lf", &row1, &row2, &scalar);
            }
            row1--; row2--; // Convert to 0-based index

            if (matrixChoice == 1) {
                for (int j = 0; j < cols1; j++) {
                    *(matrix1 + row2 * cols1 + j) += *(matrix1 + row1 * cols1 + j) * scalar;
                }
                printf("\nMatrix A after adding %lf times row %d to row %d:\n", scalar, row1, row2);
                displayMatrix(matrix1, rows1, cols1);
            } 
            else if (matrixChoice == 2) {
                for (int j = 0; j < cols2; j++) {
                    *(matrix2 + row2 * cols2 + j) += *(matrix2 + row1 * cols2 + j) * scalar;
                }
                printf("\nMatrix B after adding %lf times row %d to row %d:\n", scalar, row1, row2);
                displayMatrix(matrix2, rows2, cols2);
            } 
                
            break;
        }
        case 9:
        {// Transpose matrix
            printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
            int matrixChoice; scanf("%d", &matrixChoice);

            while (matrixChoice != 1 && matrixChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose matrix to multiply by scalar (1 for A, 2 for B): ");
                scanf("%d", &matrixChoice);
            }

            if (matrixChoice == 1) {
                double *transposedMatrix = allocMatrix(cols1, rows1);
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols1; j++) {
                        *(transposedMatrix + j * rows1 + i) = *(matrix1 + i * cols1 + j);
                    }
                }
                printf("\nTransposed Matrix A:\n");
            }

            else if (matrixChoice == 2) {
                double *transposedMatrix = allocMatrix(cols2, rows2);
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        *(transposedMatrix + j * rows2 + i) = *(matrix2 + i * cols2 + j);
                    }
                }
                printf("\nTransposed Matrix B:\n");
            }
        }
        case 0:
        {// Exit the program
            printf("Exiting...\n");
            free(matrix1); free(matrix2);
            exit(0);
            break;
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    printf("MatrixA\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns: ");
    scanf("%d", &colsA);
    
    printf("MatrixB\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowsB);
    printf("Enter number of columns: ");
    scanf("%d", &colsB);    

    while (rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0) {
        printf("Invalid matrix dimensions.\n");
        printf("MatrixA\n");
        printf("Enter number of rows: ");
        scanf("%d", &rowsA);
        printf("Enter number of columns: ");
        scanf("%d", &colsA);
        
        printf("MatrixB\n");
        printf("Enter number of rows: ");
        scanf("%d", &rowsB);
        printf("Enter number of columns: ");
        scanf("%d", &colsB);    
    }

    // Allocate memory for matrices
    double* A = allocMatrix(rowsA, colsA);
    double* B = allocMatrix(rowsB, colsB);
    
    //Menu options
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Input matrices A and B\n");
        printf("2. Display matrices A and B\n");
        printf("3. Add matrices A and B\n");
        printf("4. Multiply matrices A and B\n");
        printf("5. Multiply matrix by a scalar\n");
        printf("6. Swap rows in matrix\n");
        printf("7. Multiply a row in matrix by a scalar\n");
        printf("8. Add scalar of one row to another row in matrix\n");
        printf("9. Transpose matrix\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        menu(choice, A, B, rowsA, colsA, rowsB, colsB);
    } while (choice != 0);
}