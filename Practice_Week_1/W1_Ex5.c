#include <stdio.h>

void fraction_io(int *nume, int *deno) {
    do {
        printf("Nhap tu so: "); scanf("%d", nume);
        printf("Nhap mau so: "); scanf("%d", deno);

        if (*deno == 0) {
            printf("Ban nhap sai quy tac phan so. Vui long nhap lai\n");
        }
    } while (*deno == 0);
}

int gcd(int a, int b) {
    a = (a < 0) ? -a : a; // Use absolute values for GCD calculation
    b = (b < 0) ? -b : b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

void normalize_fraction(int *nume, int *deno) {
    int nume_copy = *nume;
    int deno_copy = *deno;
    
    if (deno_copy < 0) {// Handle the case where denominator is negative
        nume_copy = -nume_copy;
        deno_copy = -deno_copy;
    }
    
    int g = gcd(nume_copy, deno_copy);
    
    if (g > 1) {//Normalize the function
        nume_copy = nume_copy / g;
        deno_copy = deno_copy / g;
    }
    
    *nume = nume_copy;
    *deno = deno_copy;
}

void addition_fraction(int *nume1, int *deno1, int *nume2, int *deno2, int subtraction_code) {
    int nume1_copy = *nume1; int deno1_copy = *deno1;
    int nume2_copy = *nume2; int deno2_copy = *deno2;
    if (subtraction_code == 0) { // 0 is subtraction, // 1 is addition
        nume2_copy = -nume2_copy;
    } 

    int result_nume, result_deno;
    result_nume = nume1_copy * deno2_copy + nume2_copy * deno1_copy;
    result_deno = deno1_copy * deno2_copy;

    normalize_fraction(&result_nume, &result_deno);
    printf("Ket qua cua phep tinh: %d / %d\n", result_nume, result_deno);
}

void multiplication_fraction(int *nume1, int *deno1, int *nume2, int *deno2, int division_code) {
    int nume1_copy = *nume1; int deno1_copy = *deno1;
    int nume2_copy, deno2_copy;
    if (division_code == 0) { // 0 is division, // 1 is subtraction
        nume2_copy = *deno2; deno2_copy = *nume2;
    } else {
        nume2_copy = *nume2; deno2_copy = *deno2;
    }
    
    int result_nume, result_deno;
    if (deno2_copy == 0) {
        printf("Khong the thuc hien phep tinh\n");
        return;
    } else {
        result_nume = nume1_copy * nume2_copy;
        result_deno = deno1_copy * deno2_copy;
    }

    normalize_fraction(&result_nume, &result_deno);
    printf("Ket qua cua phep tinh: %d / %d\n", result_nume, result_deno);
}

int main() {
    int a1, b1, a2, b2;

    printf("Phan so thu nhat\n");
    fraction_io(&a1, &b1);
    printf("Phan so thu nhat: %d/%d\n", a1, b1);

    printf("Phan so thu hai\n");
    fraction_io(&a2, &b2);
    printf("Phan so thu hai: %d/%d\n", a2, b2);

    printf("Cong hai phan so: ");
    addition_fraction(&a1, &b1, &a2, &b2, 1);

    printf("Tru hai phan so: ");
    addition_fraction(&a1, &b1, &a2, &b2, 0);

    printf("Nhan hai phan so: ");
    multiplication_fraction(&a1, &b1, &a2, &b2, 1);

    printf("Chia hai phan so: ");
    multiplication_fraction(&a1, &b1, &a2, &b2, 0);

    return 0;
}