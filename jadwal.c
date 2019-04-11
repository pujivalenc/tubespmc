#include "libtubes.h"

int crom[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//EL2205A1, EL2205A2, El2205B1, EL2205B2, EL2205C1, EL2205C2, EL2208A1, EL2208A2, EL2208A3, EL2208B1, EL2208B2, EL2208B3, EL2208C, EB2200A, EB2200B
int i,j,k;//pencacah

int hariSalah(char day[],char prak[]){//mengecek apakah hari sesuai
    if(strcmp(prak,"EB2200")==0){
        return(strcmp(day,"Selasa") && strcmp(day,"Kamis"));
    }else {//prak ELKA atau PPMC
        return(strcmp(day,"Senin") && strcmp(day,"Selasa")&& strcmp(day,"Rabu")&&strcmp(day,"Kamis")&& strcmp(day,"Jumat"));
    }
}

int intHari(char d[]){
    if (strcmp(d,"Senin")==0){
        return(0);
    }else if (strcmp(d,"Selasa")==0){
        return(1);
    }else if (strcmp(d,"Rabu")==0){
        return(2);
    }else if (strcmp(d,"Kamis")==0){
        return(3);
    }else if (strcmp(d,"Jumat")==0){
        return(4);
    }else {
        return(-1);
    }
}

int intRuang(char r[]){
    if (strcmp(r,"LAB1")==0){
        return(0);
    }else if (strcmp(r,"LAB2")==0){
        return(1);
    }else if (strcmp(r,"LAB3")==0){
        return(2);
    }else if (strcmp(r,"LSS")==0){
        return(3);
    }else {
        return(-1);
    }
}


void tampilkanSchedule(){

	printf("|--------------------------------------------------------------------|\n");
	printf("|Ruang Praktikum |    LAB1    |    LAB2    |    LAB3    |    LSS     |\n");
	printf("|----------------|------------|------------|------------|------------|\n");
	printf("|Minggu |  Hari  |------------|------------|------------|------------|\n");
	printf("|-------|--------|------------|------------|------------|------------|\n");
	for (i=0;i<12;i++){
		for(j=0;j<5;j++){
			if (i+3<10){
				switch(j){
					case 0 :printf("|   %d   | Senin  |",i+3);
					break;
					case 1 :printf("|   %d   | Selasa |",i+3);
					break;
					case 2 :printf("|   %d   | Rabu   |",i+3);
					break;
					case 3 :printf("|   %d   | Kamis  |",i+3);
					break;
					case 4 :printf("|   %d   | Jumat  |",i+3);
					break;
				}
			}else{
				switch(j){
					case 0 :printf("|  %d   | Senin  |",i+3);
					break;
					case 1 :printf("|  %d   | Selasa |",i+3);
					break;
					case 2 :printf("|  %d   | Rabu   |",i+3);
					break;
					case 3 :printf("|  %d   | Kamis  |",i+3);
					break;
					case 4 :printf("|  %d   | Jumat  |",i+3);
					break;
				}
			}
			for(k=0;k<4;k++){
					if (strcmp(jad[i][j][k].matkul,"0")!=0){
                        if ((strcmp(jad[i][j][k].rom,"A")==0)||(strcmp(jad[i][j][k].rom,"B")==0)||(strcmp(jad[i][j][k].rom,"C")==0)){
                            printf(" %s-%s   |", jad[i][j][k].matkul , jad[i][j][k].rom);
                        }else {
                            printf(" %s-%s  |",jad[i][j][k].matkul,jad[i][j][k].rom);
                        }

					}else{
						printf("            |");
					}
				}
			printf("\n");
		}
		printf("|--------------------------------------------------------------------|\n");
	}
}

void scheduleManual(){
    char matkul [7];
    char romb[3];
    int nWeek;
    char hari[10];
    char ruang[5];
    int hr=-1;
    int rg=-1;
    int kemb = 0; //boolean untuk kembali ke menu utama

    // inisiasi input
    printf("[Mode Schedule]\n");
    printf("Isi `q` atau `Q` untuk kembali ke menu\n");
    do {
         //PILIHAN SALAH
           // pengulangan hingga masukan benar
            do {
                printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
                scanf("%s", matkul);
            }while (strcmp(matkul,"EL2205") && strcmp(matkul,"EL2208")&& strcmp(matkul,"EB2200")&&strcmp(matkul,"Q")&& strcmp(matkul,"q" ));

        // PILIHAN BENAR
        // MATKUL PELKA
        if (strcmp(matkul,"EL2205")==0){
            // pengulangan hingga masukan benar
                do {
                    printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
                    scanf("%s", romb);
                }while (strcmp(romb,"A") && strcmp(romb,"B") && strcmp(romb,"C") && strcmp(romb,"A1")
                          && strcmp(romb,"A2") && strcmp(romb,"B1") && strcmp(romb,"B2") && strcmp(romb,"C1") && strcmp(romb,"C2" ));

            // input benar
            if (strcmp(romb,"A")==0){
                // cek jumlah modul
                if ((crom[0]<7)&&(crom[1]<7)){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));

                    //hari benar
                    hr = intHari(hari);

                    for (i=0;i<2;i++){
                        do {
                            printf("Ruangan %d: ",i+1);
                            scanf("%s",ruang);
                            rg=intRuang(ruang);
                        }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                        strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                            if (i==0){
                                strcpy(jad[nWeek-3][hr][rg].rom, "A1");
                                crom[0]++;
                            }else if (i==1){
                                strcpy(jad[nWeek-3][hr][rg].rom, "A2");
                                crom[1]++;}
                    }


                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s \n",romb,matkul);
                }

            //ROMBONGAN B
            }else if (strcmp(romb,"B")==0){
                 // cek jumlah modul
                if ((crom[2]<7)&&(crom[3]<7)){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                    //hari benar
                    hr = intHari(hari);

                    for (i=0;i<2;i++){
                        do {
                            printf("Ruangan %d: ",i+1);
                            scanf("%s",ruang);
                            rg=intRuang(ruang);
                        }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                        strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                            if (i==0){
                                strcpy(jad[nWeek-3][hr][rg].rom, "B1");
                                crom[2]++;
                            }else if (i==1){
                                strcpy(jad[nWeek-3][hr][rg].rom, "B2");
                                crom[3]++;}
                    }

                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s \n",romb,matkul);
                }

            }else if (strcmp(romb,"C")==0){
                 // cek jumlah modul
                if ((crom[4]<7)&&(crom[5]<7)){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                //hari benar
                    hr = intHari(hari);

                    for (i=0;i<2;i++){
                        do {
                            printf("Ruangan %d: ",i+1);
                            scanf("%s",ruang);
                            rg=intRuang(ruang);
                        }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                        strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                            if (i==0){
                                strcpy(jad[nWeek-3][hr][rg].rom, "C1");
                                crom[4]++;
                            }else if (i==1){
                                strcpy(jad[nWeek-3][hr][rg].rom, "C2");
                                crom[5]++;}
                        }

                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s \n",romb,matkul);
                }

            }else if (strcmp(romb,"A1")==0){
                // cek jumlah modul
                if (crom[0]<7){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                    //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A1");
                    crom[0]++;


                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s \n",romb,matkul);
                }

            }else if (strcmp(romb,"A2")==0){
                 // cek jumlah modul
                if (crom[1]<7){
                    printf("A\n");
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1)|| (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A2");
                    crom[1]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B1")==0){
                 // cek jumlah modul
                if (crom[2]<7){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B1");
                    crom[2]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }


            }else if (strcmp(romb,"B2")==0){
                 // cek jumlah modul
                if (crom[3]<7){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B2");
                    crom[3]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"C1")==0){
                 // cek jumlah modul
                if (crom[4]<7){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "C1");
                    crom[4]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"C2")==0){
                 // cek jumlah modul
                if (crom[5]<7){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2205");
                    strcpy(jad[nWeek-3][hr][rg].rom, "C2");
                    crom[5]++;
            }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }
            }

        // MATKUL PPMC
        } else if (!strcmp(matkul,"EL2208")){
             // pengulangan hingga masukan benar
                do {
                    printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
                    scanf("%s", romb);
                }while (strcmp(romb,"A") && strcmp(romb,"B") && strcmp(romb,"C") && strcmp(romb,"A1") && strcmp(romb,"A2")
                        &&strcmp(romb, "A3") && strcmp(romb,"B1") && strcmp(romb,"B2") && strcmp(romb,"B3" ));

            // input sudah benar
            if (strcmp(romb,"A")==0){
                    printf("%s",matkul);
                 // cek jumlah modul
                if ((crom[6]<9)&&(crom[7]<9)&&(crom[8]<9)){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                    //hari benar
                    hr = intHari(hari);

                    for (i=0;i<3;i++){
                        do {
                            printf("Ruangan %d: ",i+1);
                            scanf("%s",ruang);
                            rg=intRuang(ruang);
                        }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                        strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                            if (i==0){
                                strcpy(jad[nWeek-3][hr][rg].rom, "A1");
                                crom[6]++;
                            }else if (i==1){
                                strcpy(jad[nWeek-3][hr][rg].rom, "A2");
                                crom[7]++;
                            }else if (i==2){
                                strcpy(jad[nWeek-3][hr][rg].rom, "A3");
                                crom[8]++;}
                        }
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B")==0){
                 // cek jumlah modul
                if ((crom[9]<9)&&(crom[10]<9)&&(crom[11]<9)){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                    //hari benar
                    hr = intHari(hari);

                    for (i=0;i<3;i++){
                        do {
                            printf("Ruangan %d: ",i+1);
                            scanf("%s",ruang);
                            rg=intRuang(ruang);
                        }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                        strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                            if (i==0){
                                strcpy(jad[nWeek-3][hr][rg].rom, "B1");
                                crom[9]++;
                            }else if (i==1){
                                strcpy(jad[nWeek-3][hr][rg].rom, "B2");
                                crom[10]++;
                            }else if (i==2){
                                strcpy(jad[nWeek-3][hr][rg].rom, "B3");
                                crom[11]++;}
                        }
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"C")==0){
                 // cek jumlah modul
                if (crom[12]<9){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (strcmp(hari,"Rabu")!=0);
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "C");
                    crom[12]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"A1")==0){
                 // cek jumlah modul
                if (crom[6]<9){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A1");
                    crom[6]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"A2")==0){
                 // cek jumlah modul
                if (crom[7]<9){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A2");
                    crom[7]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"A3")==0){
                 // cek jumlah modul
                if (crom[8]<9){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A3");
                    crom[8]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B1")==0){
                 // cek jumlah modul
                if (crom[9]<9){
                    printf("A\n");
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B1");
                    crom[9]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B2")==0){
                 // cek jumlah modul
                if (crom[10]<9){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B2");
                    crom[10]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B3")==0){
                 // cek jumlah modul
                if (crom[11]<9){
                    printf("A\n");
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));//input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EL2208");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B3");
                    crom[11]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }


        // MATKUL PELKAB
        } else if (!strcmp(matkul,"EB2200")){
            // pengulangan hingga masukan benar
                do {
                    printf("Rombongan (A atau B): ");
                    scanf("%s", romb);
                }while (strcmp(romb,"A") && strcmp(romb,"B"));

            // input benar
            if (strcmp(romb,"A")==0){
             // cek jumlah modul
                if (crom[13]<5){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                     //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EB2200");
                    strcpy(jad[nWeek-3][hr][rg].rom, "A");
                    crom[13]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }

            }else if (strcmp(romb,"B")==0){
             // cek jumlah modul
                if (crom[14]<5){
                    do {
                        printf("Minggu ke: ");
                        scanf("%d", &nWeek);
                    }while ((nWeek<3) || (nWeek>14));
                    //input minggu benar
                    do {
                        printf("Hari: ");
                        scanf("%s", hari);
                    }while (hariSalah(hari,matkul));
                    //hari benar
                    hr = intHari(hari);
                    do {
                        printf("Ruangan: ");
                        scanf("%s",ruang);
                        rg=intRuang(ruang);
                    }while ((rg==-1) || (strcmp(jad[nWeek-3][hr][rg].matkul,"0")!=0));
                    strcpy(jad[nWeek-3][hr][rg].matkul, "EB2200");
                    strcpy(jad[nWeek-3][hr][rg].rom, "B");
                    crom[14]++;
                }else {
                    printf("Rombongan %s telah menyelesaikan praktikum %s\n",romb,matkul);
                }
            }

        // KEMBALI KE MENU UTAMA
        } else if ((!strcmp(matkul,"Q")) || (!strcmp(matkul,"q"))){
            kemb = 1;


        }

    } while (!kemb); //memasukan jadwal hingga pengguna ingin kembali ke menu utama


}

