#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maNV[20];
    char hoTen[50];
    float luong;
} NhanVien;

// Nhap danh sach 
void nhapDanhSach(NhanVien* ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap nhan vien thu %d ---\n", i + 1);
        printf("Ma so nhan vien: ");
        scanf("%s", ds[i].maNV);

        printf("Ho ten: ");
        getchar();
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = '\0';
        
        printf("Luong: ");
        scanf("%f", &ds[i].luong);
    }
}

// In danh sach 
void inDanhSach(NhanVien* ds, int n) {
    printf("\n%-5s %-15s %-30s %-10s\n", "STT", "Ma NV", "Ho ten", "Luong");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-15s %-30s %-10.2f\n", i + 1, ds[i].maNV, ds[i].hoTen, ds[i].luong);
    }
}

// trung binh luong 
float tinhLuongTB(NhanVien* ds, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ds[i].luong;
    }
    return (n == 0) ? 0 : sum / n;
}

// nhan vien luong cao nhat  
NhanVien timLuongMax(NhanVien* ds, int n) {
    NhanVien max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].luong > max.luong) {
            max = ds[i];
        }
    }
    return max;
}


int main() {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    NhanVien* ds = (NhanVien*)malloc(n * sizeof(NhanVien));
    nhapDanhSach(ds, n);

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In danh sach nhan vien\n");
        printf("2. Tinh trung binh luong\n");
        printf("3. Tim nhan vien co luong cao nhat\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                inDanhSach(ds, n);
                break;
            }
            case 2: {
                float avg = tinhLuongTB(ds, n);
                printf("Luong trung binh cua %d nhan vien la: %.2f\n", n, avg);
                break;
            }
            case 3: {
                NhanVien max = timLuongMax(ds, n);
                printf("Nhan vien co luong cao nhat:\n");
                printf("Ma NV: %s\nHo ten: %s\nLuong: %.2f\n", max.maNV, max.hoTen, max.luong);
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default:{
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
            }
        }
    } while (choice != 0);

    free(ds);
    return 0;
}

