#include<stdio.h>

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int reverse_number (int n) {
    int reversed = 0;
    while (n != 0) {// Take the last digit and push to the end of previous last digit
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int coprime_reverse (int n) {
    int g = gcd (n, reverse_number(n));
    
    int status_code;
    if (n <= 1) {
        status_code = -1;
    } else if (g == 1) {
        status_code = 1;
    } else {
        status_code = 0;
    }

    return status_code;
}

int main() {
    //Coprime of number and its reverse
    //Finding 2-digit numbers
    printf("Cac so co 2 chu so ma dao thu tu là nguyen to cung nhau la:\n");

    for (int i = 10; i <= 99; i++) {
        if ( coprime_reverse (i) == 1 ) {
            printf("%d ", i);
        }
    }

    return 0;
}