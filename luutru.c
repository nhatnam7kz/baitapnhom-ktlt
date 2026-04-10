#include "data.h"
#include <stdio.h>
#include <string.h>
void luuFile (FILE *a,int n, giaodich *t) {
    
    int i;
    fprintf(a,"\n%-5s %-25s %-10s %-10s %-12s\n", "STT", "Ten khoan", "Loai", "So tien", "Ngay");
    fprintf(a,"-----------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        fprintf(a,"%-5d %-25s %-10s %-10d %02d/%02d/%04d\n",
        i + 1,
        t[i].tenkhoan,
        t[i].loai,
        t[i].sotien,
        t[i].ngay,
        t[i].thang,
        t[i].nam );
    }
}

void docFile (FILE *a ,int n,giaodich *t) {
    int i;
    for (i=0;i<n;i++) {
        fgets(t[i].tenkhoan,sizeof(t[i].tenkhoan),a);
        t[i].tenkhoan[strlen(t[i].tenkhoan) -1 ] = 0;
        fscanf(a,"%d",&t[i].sotien);
        fgetc(a);
        fgets(t[i].loai,sizeof(t[i].loai),a);
        t[i].loai[strlen(t[i].loai) -1 ] = 0;
        fscanf(a,"%d %d %d",&t[i].ngay,&t[i].thang,&t[i].nam);
        fgetc(a);
    }
}