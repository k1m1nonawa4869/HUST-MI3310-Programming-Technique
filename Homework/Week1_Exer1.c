// Name: Vu Quang Vinh
// Student ID: 20237408
// Dtae: 3 March, 2025

//Viết chương trình C: nhập một mảng n số nguyên, tìm số lớn thứ hai trong mảng

#include <stdio.h>
#include <limits.h>

int main(){
    int n; scanf("%d", &n);
    int a[n]; int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        if (a[i] > max1){
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2 && a[i] != max1){
            max2 = a[i];
        }
    }
    
    if (max2 != INT_MIN){
        printf("%d", max2);
    } else{
        printf("Khong co so lon thu hai");
    }

    return 0;
}