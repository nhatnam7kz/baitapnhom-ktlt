#include "data.h"
#include "luutru.h"
#include "nhapxuat.h"
#include <stdio.h>
#include "xuly.h"
#include <stdlib.h>
#include <string.h>  


int main () {
    int n;
    int chon;

    giaodich *a = NULL;
    do {
        chon = hienthimenu();
        switch (chon) {
            case 1:
            
            printf("So giao dich can nhap: "); scanf("%d",&n);
            a = (giaodich *) malloc (sizeof(giaodich) * n);
            nhapgiaodich(a,n);
            break;

            case 2:
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            indanhsach(n,a); }
            break;

            case 3:
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            printf("Tong thu: %d\n",tinhtongThu(n,a)); }
            break;

            case 4:
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            printf("Tong chi: %d\n",tinhtongChi(n,a)); }
            break;

            case 5:
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            printf("So du: %d\n",tinhsoDu(tinhtongThu(n,a),tinhtongChi(n,a))); }
            break;

            case 6: 
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            int thang,nam;
            printf("Nhap thang/nam: "); scanf("%d%d",&thang,&nam);
            thongketheothang(n,a,thang,nam); }
            break;

            case 7: 
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            char ten[10];
            printf("Nhap ten khoan can tim: ");
            getchar();
            fgets(ten,sizeof(ten),stdin);
            ten[strlen(ten) -1 ] = 0;
            timkiemtheoten(n,a,ten); }
            break;

            case 0:
            printf("Thoat chuong trinh!\n");
            FILE *b;
            b= fopen("output.txt","w");
            luuFile(b,n,a);
            break;

            default:
            printf("Lua chon khong hop le!\n");
        }

        } while (chon !=0);

    return 0;
    
}