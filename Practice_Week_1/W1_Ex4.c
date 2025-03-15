#include <stdio.h>

void menu_program (int n) {//Assuming we have n>0 already
    int selection;
    do {
        printf("Nhap lua chon: "); scanf("%d", &selection);

        if ((selection >= 1) && (selection <= n)) {
            printf("Đã chọn %d\n", selection);
            printf("Quay lại menu\n");
        } else {
            printf("Chương trình sẽ kết thúc");
        }
    } while ((selection >= 1) && (selection <= n));
}

int main() {
    int n;
    do {
        printf("Nhap so lua chon: "); scanf("%d", &n);
        if (n <= 0) {
            printf("Gia tri chua hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0);

    menu_program (n);

    return 0;
}