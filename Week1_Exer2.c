// Name: Vu Quang Vinh
// Student ID: 20237408
// Dtae: 3 March, 2025

//Viết chương trình nhập vào ba số nguyên, kiểm tra xem ba số đó có thể tạo thành một tam giác hay không.


#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Ban nhap sai gia tri canh");
    } else if (a + b <= c || a + c <= b || b + c <= a){
        printf("Ba so tren khong tao thanh mot tam giac");
    } else{
        printf("Ba so tren tao thanh mot tam giac");
    }

    return 0;
}