#include "libtubes.h"
struct cek
{
    char minggu[50];
    char hari[50];
};


int konvhari (char hari[]){


    int isSenin = strcmp(hari, "Senin");
    int isSelasa = strcmp(hari, "Selasa");
    int isRabu = strcmp(hari, "Rabu");
    int isKamis = strcmp(hari, "Kamis");
    int isJumat = strcmp(hari, "Jumat");

    if (isSenin == 0) {
        return 0;
    }
    else if (isSelasa == 0) {
        return 1;
    }
    else if (isRabu == 0) {
        return 2;
    }
    else if (isKamis == 0) {
        return 3;
    }
    else  if(isJumat==0){
        return 4;}

}

int konvminggu (char minggu[]){

    int val = atoi(minggu) - 3;
    return val;


}


void cari(int count, int ming, int har, jdl a[12][5][4])
{
    /**int o, oo, ooo;
    for (o = 0; o < 12; o++) {
        for (oo = 0; oo < 5; oo++) {
            for (ooo = 0; ooo < 4; ooo++) {
                printf("Minggu: %d, Hari: %d, dan Lab %d: | matkul: %s, rombongan: %s\n", o, oo, ooo, a[o][oo][ooo].matkul, a[o][oo][ooo].rom);
            }
        }
    }**/
    int ii;
    int hitung = 0;
    for (ii=0; ii< count; ii++){
        int i = ming;
        int j = har;
        int k;
        int checkSalah = 0;
        int isMatkulNotEmpty;
        for (k = 0; k<=3; k++){
            printf("Minggu: %d, Hari: %d, dan Lab %d: | matkul: %s, rombongan: %s\n", i, j, k, a[i][j][k].matkul, a[i][j][k].rom);
            isMatkulNotEmpty = strcmp(a[i][j][k].matkul, "0");
            printf ("%d", isMatkulNotEmpty);
            checkSalah = checkSalah ||isMatkulNotEmpty;
        }
        if (checkSalah !=0){
            printf ("Tidak bisa ada praktikum minggu %d hari %d \n", i, j);
        }else {
            hitung++;

        }
    }
    printf ("Sesuai dengan jadwal libur %d / %d \n", hitung, count);

}



void schedule  (jdl a[12][5][4])
{
    //create an array of structures
    struct cek arr[100];

    /** initjdl(a);
    strcpy(a[0][1][0].matkul, "ELKA");
    strcpy(a[0][1][0].rom, "A2"); **/


    FILE *po;
    char s, array[50][20];
    int count=0, c=0, d=0;

    po = fopen("C:\\Users\\User\\Documents\\AKADEMIK\\PMC\\TUBES\\chalila\\Schedule_rule.txt", "r");
    s=fgetc(po);
    while (s!=EOF){
        if((s==' ')||(s=='\n')){
            array[c][d]='\0';
            count++;
            c++;
            d=0;
            }
        else {
        array[c][d]=s;
        d++;
        }

        s=fgetc(po);
    }
    fclose(po);

    int x;
    int ming, har;
    for (x=0; x<=count; x++){
        if (x%2 == 0){
        printf ("Minggu %s \n", array[x]);
        strcpy(arr[x].minggu, array[x]);
        ming = konvminggu (arr[x].minggu);
        printf ("arrMinggu: %d \n", ming);
        }
        else{
        printf ("Hari %s \n", array[x]);
        strcpy(arr[x].hari, array[x]);
        har = konvhari (arr[x].hari);
        printf ("arrHari: %d \n", har);
        cari (count, ming, har, a);
        }


        }
    printf ("\n");

}
