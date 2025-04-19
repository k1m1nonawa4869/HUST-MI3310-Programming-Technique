//Vector math opearations
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* allocVector (int size) {
    // Function to allocate memory for a vector of size n
    return (double *)malloc(size * sizeof(double));
}

double* inputVector (double *vector, int size) {
    // Function to input vector elements
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%lf", (vector+i));
    }
    return vector;
}

double* displayVector (double *vector, int size) {
    // Function to output vector elements
    for (int i = 0; i < size; i++) {
        printf("%lf ", *(vector+i));
    }
    printf("\n");
    return 0;
}

double lengthVector (double *vector, int size) {
    // Function to calculate the length of a vector
    double length = 0;
    for (int i = 0; i < size; i++) {
        length += *(vector+i) * *(vector+i);
    }
    return sqrt(length);
}

double dotProductVector (double *vectorA, double *vectorB, int size) {
    // Function to calculate the dot product of two vectors
    double dotProduct = 0;
    for (int i = 0; i < size; i++) {
        dotProduct += *(vectorA+i) * *(vectorB+i);
    }
    return dotProduct;
}

double angleBetweenVectors (double *vectorA, double *vectorB, int size) {
    // Function to calculate the angle between two vectors
    double dotProduct = dotProductVector(vectorA, vectorB, size);
    double lengthA = lengthVector(vectorA, size);
    double lengthB = lengthVector(vectorB, size);
    return acos(dotProduct / (lengthA * lengthB));
}

void menu(int choice, double *vectorA, double *vectorB, int sizeA, int sizeB) {
    //Menu for vector operations
    switch (choice) {
        case 1:
        {// Input vector A and B
            printf("\nEnter vector A:\n");
            inputVector(vectorA, sizeA);  
            
            printf("\nEnter vector B:\n");
            inputVector(vectorB, sizeB);
            
            printf("Vectors A and B have been entered successfully.\n");
            break;
        }
        case 2:
        {// Display vector A and B
            printf("\nVector A:\n");
            displayVector(vectorA, sizeA);  
            
            printf("\nVector B:\n");
            displayVector(vectorB, sizeB);
            
            break;
        }
        case 3:
        {// Length of a vector
            printf("Choose vector (1 for A, 2 for B): ");
            int vectorChoice; scanf("%d", &vectorChoice);

            while (vectorChoice != 1 && vectorChoice != 2) {
                printf("Invalid choice.\n");
                printf("Choose vector (1 for A, 2 for B): ");
                scanf("%d", &vectorChoice);
            }

            if (vectorChoice == 1) {
                double lengthA = lengthVector(vectorA, sizeA);
                printf("Length of vector A: %lf\n", sqrt(lengthA));
            } else if (vectorChoice == 2) {
                double lengthB = lengthVector(vectorB, sizeB);
                printf("Length of vector B: %lf\n", sqrt(lengthB));
            }

            break;
        }
        case 4:
        {//Dot product of two same-size vectors
            if (sizeA != sizeB) {
                printf("Vectors must be of the same size for dot product.\n");
                break;
            }

            double dotProduct = dotProductVector(vectorA, vectorB, sizeA);
            printf("Dot product of A and B: %lf\n", dotProduct);
            break;
        }
        case 5:
        {//Angle of 2 same-size vectors
            if (sizeA != sizeB) {
                printf("Vectors must be of the same size for angle calculation.\n");
                break;
            }

            double angle = angleBetweenVectors(vectorA, vectorB, sizeA);
            printf("Angle between A and B: %lf radians\n", angle);
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
    int sizeA, sizeB;
    printf("Size of Vector A: "); scanf("%d", &sizeA);
    printf("Size of Vector B: "); scanf("%d", &sizeB);

    while (sizeA <= 0 || sizeB <= 0) {
        printf("Invalid vector size.\n");
        printf("size of Vector A: "); scanf("%d", &sizeA);
        printf("size of Vector B: "); scanf("%d", &sizeB);
    }

    //Allocate memory for vectors
    double* A = allocVector(sizeA);
    double* B = allocVector(sizeB);
    
    //Menu options
    int choice;
    do {
        printf("\nMenu:\n");

        printf("1. Input Vector\n");
        printf("2. Display Vector\n");
        printf("3. Length of Vector\n");
        printf("4. Dot Product of Vectors\n");
        printf("5. Angle Between Vectors\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        menu(choice, A, B, sizeA, sizeB);
    } while (choice != 0);
}