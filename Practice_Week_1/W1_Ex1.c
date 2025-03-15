#include <stdio.h>

int gcd(int a, int b) {
    a = (a < 0) ? -a : a; // Use absolute values for GCD calculation
    b = (b < 0) ? -b : b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

void normalize_fraction(int *nume, int *deno) {
    int nume_copy = *nume, deno_copy = *deno;
    int g = gcd(nume_copy, deno_copy);
    
    if (deno_copy < 0) { // Make sure the denominator is positive
        nume_copy = -nume_copy;
        deno_copy = -deno_copy;
    }

    if (g == 1) { // Fraction is already in normalized form
        printf("Phan so %d / %d da toi gian.\n", nume_copy, deno_copy);
    } 
    else { // Normalize the fraction
        nume_copy = nume_copy / g;
        deno_copy = deno_copy / g;

        printf("Phan so toi gian la: %d / %d\n", nume_copy, deno_copy);
    }
}

int main() {
    // Normalize integer fractions
    int a, b;
    do {
        printf("Nhap tu so: "); scanf("%d", &a);
        printf("Nhap mau so: "); scanf("%d", &b);

        if (b == 0) {
            printf("Ban nhap sai quy tac phan so. Vui long nhap lai\n");
        }
    } while (b == 0);

    normalize_fraction(&a, &b);
    return 0;
}