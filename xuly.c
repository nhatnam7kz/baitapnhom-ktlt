#include "data.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define VALUE(y, m, d) ((y) * 10000 + (m) * 100 + (d))

void sapxep (int n, giaodich *t) {
    int i,j;
    for (i=0;i<n-1;i++) {
        for (j=i+1;j<n;j++) {
            if ( VALUE( t[i].nam, t[i].thang, t[i].ngay) < VALUE( t[j].nam, t[j].thang, t[j].ngay ) ) {
                giaodich temp;
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}



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

void thongketheothang(int n, giaodich *t, int thang, int nam) {
    int i, j = 0, check = 0;
    for (i = 0; i < n; i++) {
        if (t[i].nam == nam && t[i].thang == thang) {
            j++;
            if (check == 0) {
                printf("\n========== THONG KE THANG %02d/%04d ==========\n", thang, nam);
                printf("%-5s %-20s %-10s %-12s %-10s\n", "STT", "Ten khoan", "Loai", "So tien", "Ngay");
                check = 1;
            }
            printf("%-5d %-20s %-10s %-12d %02d/%02d/%04d\n",
                   j, t[i].tenkhoan, t[i].loai, t[i].sotien,
                   t[i].ngay, t[i].thang, t[i].nam);
        }
    }
    if (check == 0) {
        printf("\nKhong co giao dich nao trong thang %02d/%04d\n", thang, nam);
    }
    printf("==================================================\n");
}

void timkiemtheoten(int n, giaodich *t, char key[]) {
    int i, j = 0, check = 0;
    int tongThu = 0; // tách thành 2 biến 
    int tongChi = 0;
    
    char temp1[strlen(key)+1];
    strcpy(temp1,key);

    for (i = 0; temp1[i] != '\0';i++) {
        temp1[i] = tolower(temp1[i]);
    }
    for (i = 0; i < n; i++) {
       char temp2[strlen(t[i].tenkhoan)+1];
       strcpy(temp2,t[i].tenkhoan);
       int z;
       for (z = 0; temp2[z] != '\0';z++) temp2[z] = tolower(temp2[z]);
       if (strstr(temp2,temp1) != NULL) {
            j++;  
            if (strcmp(t[i].loai, "thu") == 0) { // kiểm tra các giao dịch trước khi cộng dồn
                tongThu += t[i].sotien;
            } else if (strcmp(t[i].loai, "chi") == 0) {
                tongChi += t[i].sotien;
            } 
            if (check == 0) {
                printf("\n========== KET QUA TIM KIEM: \"%s\" ==========\n", key);
                printf("%-5s %-20s %-10s %-12s %-10s\n", "STT", "Ten khoan", "Loai", "So tien", "Ngay");
                check = 1;
            }
            printf("%-5d %-20s %-10s %-12d %02d/%02d/%04d\n",
                   j, t[i].tenkhoan, t[i].loai, t[i].sotien,
                   t[i].ngay, t[i].thang, t[i].nam);
       }
    }
    if (check == 0) {
        printf("\nKhong tim thay ten khoan \"%s\"\n", key);
    } else {
        printf("--------------------------------------------------\n"); // thêm in ra tổng thu và chi 
        printf("Tong Thu: %d\n", tongThu);
        printf("Tong Chi: %d\n", tongChi);
        printf("So du con lai: %d\n", tongThu - tongChi);
    }
    printf("==================================================\n");
}