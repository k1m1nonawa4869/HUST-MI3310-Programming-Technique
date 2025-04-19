// Normalized a string
#include <stdio.h>
#include <ctype.h>
#include <string.h>
const int MAX=257;

int normalizeString (char* str) {
    //NAME CLEANING
    int length=strlen(str)-1; //strlen also count \0 so minus that 
    char name[MAX][MAX]; int name_idx=0; //storing the name split

    for (int i=0; i<length; i++){
        if (str[i] != ' ') {
            int start=i, end=i;
            while (i<length && str[i] != ' ') {++end; ++i;} //this one serves for splliting word out of space

            int c=0;
            for (int k=start; k<=end; k++){
                if (isalpha(str[k]) || isdigit(str[k])) {//remove non-character & non-number
                    if (c==0) {name[name_idx][c] = toupper(str[k]);}
                    else {name[name_idx][c] = tolower(str[k]);} //and stylize in correct form
                    c++;
                }
            }
            name_idx++;
        }
    }

    //MERGE BACK
    char clean_name[MAX];
    for (int i=0; i<name_idx; i++){
        strcat(clean_name, name[i]);
        if (i<name_idx-1) {strcat(clean_name, " ");}
    }
    
    printf("Cleaned string: %s", clean_name);
    return name_idx;
}

int main(){
    char str[MAX]; 
    printf("Type your string: "); fgets(str, MAX, stdin); //input
    size_t len = strlen(str);     
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    int word_count = normalizeString(str);
    printf("\nNumber of words: %d", word_count); //output
    return 0;
}