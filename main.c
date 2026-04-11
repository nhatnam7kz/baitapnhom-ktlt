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
            int chon1;
            printf("\n1. Nhap truc tiep\n2. Nhap qua file\n\nNhap lua chon: ");
            scanf("%d",&chon1);

            if (chon1 == 1) {
                printf("So giao dich can nhap: "); scanf("%d",&n);
                a = (giaodich *) malloc (sizeof(giaodich) * n);
                nhapgiaodich(a,n);
                break;
            } else if (chon1 == 2) {
                FILE *c;
                c= fopen("input.txt","r");
                if (c == NULL) {
                    printf("Khong tim thay file input.txt!\n");
                    break;
                }
                fscanf(c,"%d",&n);
                fgetc(c);
                a = (giaodich *) malloc (sizeof(giaodich) * n);
                docFile(c,n,a);
                printf("Nhap du lieu tu file thanh cong!\n");
                fclose(c);
            } else {
                printf("Lua chon khong hop le!\n");
            }

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
            inbaocao(n,a); }
            break;

            case 4: 
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            int thang,nam;
            printf("Nhap thang/nam: "); scanf("%d%d",&thang,&nam);
            thongketheothang(n,a,thang,nam); }
            break;

            case 5: 
            if (a == NULL) {
                printf("Chua co khoan giao dich duoc ghi\n");
            } else {
            char ten[100];
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
            fclose (b);
            break;

            default:
            printf("Lua chon khong hop le!\n");
        }

        } while (chon !=0);
    
    free(a);
    return 0;
    
}