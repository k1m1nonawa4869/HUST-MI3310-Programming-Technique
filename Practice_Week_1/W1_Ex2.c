#include <stdio.h>
#include <math.h>

int check_prime (int num) {
    int prime_code = 1;

    if (num <= 1) {//0 & 1 are not prime
        prime_code = 0;
        return prime_code;
    } 

    int stopper = (int) sqrt(num); //no divisor of a number exceed its square-root
    for (int i = 2; i <= stopper; i++) {
        if (num % i == 0) {
            prime_code = 0; //a prime number cant have any divisors outside 1 and itself
            return prime_code;
        }
    }

    return prime_code;
}

int main() {
    int n;
    printf("Nhap so nguyen n: "); scanf("%d", &n);

    if (n <= 1) {
        printf("Khong co so nguyen to nao <= %d", n);
    }
    else {
        printf("Danh sach cac so nguyen to <= %d la: \n", n);
        for (int i=0; i<=n; i++) {
            if (check_prime (i) == 1) {
                printf("%d ", i);
        }
        }
    }

    return 0;
}