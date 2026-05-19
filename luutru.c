#include "data.h"
#include <stdio.h>
#include <string.h>
void docFile (FILE *a ,int n,giaodich *t) {
    int i;
    for (i=0;i<n;i++) {
        fgets(t[i].tenkhoan,sizeof(t[i].tenkhoan),a);
        t[i].tenkhoan[strcspn(t[i].tenkhoan,"\n") ] = 0;
        fscanf(a,"%d",&t[i].sotien);
        fgetc(a);
        fgets(t[i].loai,sizeof(t[i].loai),a);
        t[i].loai[strcspn(t[i].loai,"\n")] = 0;
        fscanf(a,"%d %d %d",&t[i].ngay,&t[i].thang,&t[i].nam);
        fgetc(a);
    }
}

void xuatBaoCaoFile(FILE *a, int n, giaodich *t) {
    if (a == NULL) return;
    int i;
    fprintf(a, "\n%-5s %-20s %-10s %-12s %-10s\n",
            "STT", "Ten khoan", "Loai", "So tien", "Ngay");
    for (i = 0; i < n; i++) {
        fprintf(a, "%-5d %-20s %-10s %-12d %02d/%02d/%04d\n",
                i + 1,
                t[i].tenkhoan,
                t[i].loai,
                t[i].sotien,
                t[i].ngay,
                t[i].thang,
                t[i].nam);
    }
}