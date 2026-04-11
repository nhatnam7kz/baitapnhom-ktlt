#include "data.h"
#include <stdio.h>
#include <string.h>
#include "xuly.h"

int hienthimenu () {
    int chon;

    printf("\n========== QUAN LY THU CHI ==========\n");
    printf("1. Nhap giao dich\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Bao cao tai chinh\n");
    printf("4. Thong ke theo thang\n");
    printf("5. Tim kiem theo ten\n");
    printf("0. Thoat\n");
    printf("=====================================\n");
    printf("Nhap lua chon: ");
    
    scanf("%d", &chon);

    return chon;
}

void nhapgiaodich (giaodich *t, int n) {
    int i;
    getchar();
    for (i=0;i<n;i++) {
        printf("STT: %d\n",i+1);
        printf("Nhap ten khoan: "); fgets(t[i].tenkhoan,sizeof(t[i].tenkhoan),stdin);
        t[i].tenkhoan[strlen(t[i].tenkhoan) -1 ] = 0;

        printf("Nhap so tien: "); scanf("%d",&t[i].sotien); getchar();
        
        printf("Loai(thu/chi): ");   fgets(t[i].loai,sizeof(t[i].loai),stdin);
        t[i].loai[strlen(t[i].loai) -1 ] = 0;
        
        printf("Nhap ngay/thang/nam: "); scanf("%d%d%d",&t[i].ngay,&t[i].thang,&t[i].nam);
        getchar();
        printf("\n");
        
    }
}


void indanhsach(int n, giaodich *t) {
    int i;

    printf("\n===== DANH SACH GIAO DICH =====\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "STT", "Ten khoan", "So tien", "Loai", "Ngay");

    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-10d %-10s %02d/%02d/%04d\n",
               i + 1,
               t[i].tenkhoan,
               t[i].sotien,
               t[i].loai,
               t[i].ngay,
               t[i].thang,
               t[i].nam);
    }

    printf("================================\n");
}


void inbaocao(int n, giaodich *t) {
    int thu = tinhtongThu(n, t);
    int chi = tinhtongChi(n, t);
    int sodu = thu - chi;

    printf("\n===== BAO CAO TAI CHINH =====\n");
    printf("Tong thu : %d\n", thu);
    printf("Tong chi : %d\n", chi);
    printf("So du    : %d\n", sodu);
    printf("================================\n");
}