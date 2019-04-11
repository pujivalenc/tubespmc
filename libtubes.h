#ifndef LIBTUBES_H
#define LIBTUBES_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct jadwal{
	char matkul[7];
	char rom[3];
	}jdl;
typedef struct asisten{
	char satu;
	char dua;
}asis;
//deklarasi variabel
jdl jad[12][5][4];//[minggu][hari][ruangan]
asis a[12][5][4];


void schedule  (jdl a[12][5][4]);
void initas(asis a[12][5][4]);
void initjdl(jdl b[12][5][4]);

void aam(asis a[12][5][4],jdl b[12][5][4]);
void disas(asis a[12][5][4]);
void savefile(jdl romb[12][5][4], asis as[12][5][4], char nama[100]);

void tampilkanSchedule();
void scheduleManual();
int hariSalah(char day[], char prak[]);
int intHari(char d[]);
int intRuang(char r[]);
void loadfile(jdl romb[12][5][4], asis as[12][5][4], char nama[100]);




#endif // LIBTUBES_H_INCLUDED
