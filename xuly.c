#include "data.h"
#include <string.h>
#include <stdio.h>

int  tinhtongThu (int n ,giaodich *t) {
    int i;
    int tongThu = 0;
    for (i=0;i<n;i++) {
        if (strcmp(t[i].loai, "thu") == 0) {
            tongThu += t[i].sotien;
        }
    }

    return tongThu;
}

int tinhtongChi (int n, giaodich *t) {
    int i;
    int tongChi = 0;
    for (i=0;i<n;i++) {
        if (strcmp (t[i].loai,"chi") == 0) {
            tongChi += t[i].sotien;
        }
    }

    return tongChi;
}

int tinhsoDu (int thu, int chi) {
    return thu-chi;
}

void thongketheothang (int n, giaodich *t, int thang, int nam) {
    int i;
    int j = 0;
    int check = 0;

    for (i=0;i<n;i++) {
        if (t[i].nam == nam && t[i].thang == thang ){
            j++;
            if (check == 0) {
                printf("\n===== DANH SACH GIAO DICH =====\n");
                printf("%-5s %-20s %-10s %-10s %-10s\n", "STT", "Ten khoan", "So tien", "Loai", "Ngay");
                check = 1;
            }
            
            printf("%-5d %-20s %-10d %-10s %02d/%02d/%04d\n",
               j,
               t[i].tenkhoan,
               t[i].sotien,
               t[i].loai,
               t[i].ngay,
               t[i].thang,
               t[i].nam);   
        }
    }

    if (check == 0) {
        printf("Khong tim thay giao dich trong %d/%d\n",thang,nam);
    }

    printf("================================\n");
}

void timkiemtheoten (int n, giaodich *t, char key[]) {
    int i;
    int j = 0;
    int check = 0;
    int tong = 0;
    for (i=0;i<n;i++) {
        if (strcmp (t[i].tenkhoan, key) == 0) {
            j++;
            tong += t[i].sotien;
            if (check == 0) {
                printf("\n===== DANH SACH GIAO DICH =====\n");
                printf("%-5s %-20s %-10s %-10s %-10s\n", "STT", "Ten khoan", "So tien", "Loai", "Ngay");
                check = 1;
            }
            
            printf("%-5d %-20s %-10d %-10s %02d/%02d/%04d\n",
               j,
               t[i].tenkhoan,
               t[i].sotien,
               t[i].loai,
               t[i].ngay,
               t[i].thang,
               t[i].nam); 
            
        }
    }

    if (check == 0) {
        printf("Khong tim thay ten khoan\n");
    } else {
        printf("%-5s %-20s %-10d\n", "Tong", "", tong);
    }

    printf("================================\n");
}