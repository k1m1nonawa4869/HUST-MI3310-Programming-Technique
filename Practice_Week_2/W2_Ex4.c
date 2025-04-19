//find string in list of strings
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
const int MAX=257;

char* inputString(char *str, int n) {
    //Receive a string from the user and remove the newline character if present
    fgets(str, n, stdin);
    size_t len = strlen(str);     
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

void findPatternInString(char *str, char *pattern) {
    // Find all occurrences of the pattern in the string and print their indices
    char *found = str;
    int patternLen = strlen(pattern);
    int count = 0;

    while ((found = strstr(found, pattern)) != NULL) {
        printf("Pattern found at index: %ld\n", found - str); // Print the index
        found += patternLen; // Move past the current match to find the next one
        count++;
    }

    if (count == 0) {
        printf("Pattern not found\n");
    } else {
        printf("Total occurrences found: %d\n", count);
    }

    printf("------------------\n");
}

void findPatternInList(char **list, int size, char *pattern) {
    // Find all occurrences of the item in the string list and print their indices
    for (int i = 0; i < size; i++) {
        printf("Searching in string %d: \"%s\"\n", i, list[i]);
        findPatternInString(list[i], pattern); // Find the pattern in each string
    }
}

int main() {
    int size;
    printf("Enter the number of strings: "); scanf("%d", &size);
    while (getchar() != '\n'); // Clear the input buffer

    char **stringList = (char**)malloc(size * sizeof(char*));
    if (stringList == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < size; i++) {
        stringList[i] = (char*)malloc(MAX * sizeof(char));
        if (stringList[i] == NULL) {
            printf("Memory allocation failed!\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(stringList[j]);
            }
            free(stringList);
            return 1;
        }
        printf("Enter string %d: ", i + 1);
        inputString(stringList[i], MAX);
    }

    printf("Your strings are:\n");
    for (int i=0; i < size; i++) {
        printf("%s\n", stringList[i]);
    }

    // Allocate memory for pattern
    char pattern[MAX];
    printf("Enter your finding: "); 
    inputString(pattern, MAX);

    findPatternInList(stringList, size, pattern); // Find the pattern in the string list
    
    // Free memory for each string
    for (int i = 0; i < size; i++) {
        free(stringList[i]);
    }
    free(stringList);
    
    return 0;
}