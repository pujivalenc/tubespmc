#include "libtubes.h"
void initas(asis a[12][5][4]){//inisiasi asisten
	int i,j,k;
	for(i=0;i<=11;i++){
		for(j=0;j<=4;j++){
			for(k=0;k<=3;k++){
				a[i][j][k].satu='0';
				a[i][j][k].dua='0';
			}
		}
	}
}
void initjdl(jdl b[12][5][4]){//inisiasi jadwal
	int i,j,k;
	for(i=0;i<=11;i++){
		for(j=0;j<=4;j++){
			for(k=0;k<=3;k++){
				strcpy(b[i][j][k].matkul,"0");
				strcpy(b[i][j][k].rom,"0");
			}
		}
	}
}
void aam(asis a[12][5][4],jdl b[12][5][4]){//memasukan manual jadwal asisten
	char c,d[100],e[100];
	int f,mg,hr,rg;
	do{
			do{//validasi nama
				printf("Pilih Asisten (A-N): ");
				scanf(" %c",&c);
			}while((c<65 || c>78)&&(c!='q' && c!='Q'));
			if(c!='q' && c!='Q'){
					do{//validasi minggu
						printf("Minggu: ");
						scanf(" %d",&f);
						mg=f-3;
					}while(mg<0 || mg>11);
					hr=-1;
					rg=-1;
					do{//validasi hari
						printf("Hari: ");
						scanf(" %s",d);
						if (strcmp(d,"Senin")==0){
							hr=0;}
						if (strcmp(d,"Selasa")==0){
							hr=1;}
						if (strcmp(d,"Rabu")==0){
							hr=2;}
						if (strcmp(d,"Kamis")==0){
							hr=3;}
						if (strcmp(d,"Jumat")==0){
							hr=4;}
					}while(hr<0|| hr>4);//validasi ruang
					do{
						printf("Ruang: ");
						scanf(" %s",e);
						if (strcmp(e,"LAB1")==0){
							rg=0;}
						if (strcmp(e,"LAB2")==0){
							rg=1;}
						if (strcmp(e,"LAB3")==0){
							rg=2;}
						if (strcmp(e,"LSS")==0){
							rg=3;}
					}while(rg<0||rg>3);
					if((a[mg][hr][0].satu==c||a[mg][hr][0].dua==c||a[mg][hr][1].satu==c||a[mg][hr][1].dua==c||a[mg][hr][2].satu==c||a[mg][hr][2].dua==c||a[mg][hr][3].satu==c||a[mg][hr][3].dua==c)){//validasi apakah asisten terdapat disruangan lain di hari itu
						printf("sudah terdapat asisten tersebut disalah satu ruangan\n");
					}else{
					
						if(strcmp(b[mg][hr][rg].matkul,"0")==0){printf("tidak ada jadwal pada hari,minggu,dan ruangan itu\n");}//validasi apakah jadwal ada
						else{
							switch(c){
							case 'a':
							case 'A':
								if((hr!=2) && (strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n\n");
								}else if(hr==2){
									printf("Jadwal Asisten Praktikum Amir tidak sesuai (libur pada hari Rabu)\n");
								}else{printf("Jadwal Asisten Praktikum Amir tidak sesuai (tidak ada Rombongan EL2205)\n");}
							break;
							case 'b':
							case 'B':
								if((hr!=0) && (strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==0){
									printf("Jadwal Asisten Praktikum Budi tidak sesuai (libur pada hari Senin)\n");
								}else{printf("Jadwal Asisten Praktikum Budi tidak sesuai (tidak ada Rombongan EL2205)\n");}
							break;
							case 'c':
							case 'C':
								if((hr!=2)&&(hr!=1) && (strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==2 || hr==1){
									printf("Jadwal Asisten Praktikum Cici tidak sesuai (libur pada hari Selasa dan Rabu)\n");
								}else{printf("Jadwal Asisten Praktikum Cici tidak sesuai (tidak ada Rombongan EL2205)\n");}
							break;
							case 'd':
							case 'D':
								if((hr!=2)&&(hr !=0) && (strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==2||hr==0){
									printf("Jadwal Asisten Praktikum Doni tidak sesuai (libur pada hari Senin) dan Rabu\n");
								}else{printf("Jadwal Asisten Praktikum Doni tidak sesuai (tidak ada Rombongan EL2205)\n");}
							break;
							case 'e':
							case 'E':
								if( (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)||(strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}
								else{printf("Jadwal Asisten Praktikum Endang tidak sesuai (tidak ada Rombongan EL2208,EL2205)\n");}
							break;
							case 'f':
							case 'F':
								if((hr!=1) && (strcmp(b[mg][hr][rg].matkul,"EL2205")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n\n");
								}else if(hr==1){
									printf("Jadwal Asisten Praktikum Fadel tidak sesuai (libur pada hari Selasa)\n");
								}else{printf("Jadwal Asisten Praktikum Fadel tidak sesuai (tidak ada Rombongan EL2205)\n");}
							break;
							case 'g':
							case 'G':
								if((hr!=3) && ((strcmp(b[mg][hr][rg].matkul,"EL2205")==0)|| (strcmp(b[mg][hr][rg].matkul,"EL2200")==0))){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==3){
									printf("Jadwal Asisten Praktikum Gilang tidak sesuai (libur pada hari Kamis)\n");
								}else{printf("Jadwal Asisten Praktikum Gilang tidak sesuai (tidak ada Rombongan EL2205,EL2200)\n");}
							break;
							case 'h':
							case 'H':
								if((hr!=3) && (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								} else if(hr==3){
									printf("Jadwal Asisten Praktikum Hero tidak sesuai (libur pada hari Kamis)\n");
								}else{printf("Jadwal Asisten Praktikum Hero tidak sesuai (tidak ada Rombongan EL2208)\n");}
							break;
							case 'i':
							case 'I':
								if((hr!=2) && ( (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)||(strcmp(b[mg][hr][rg].matkul,"EL2205")==0)||(strcmp(b[mg][hr][rg].matkul,"EB2200")==0))){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==2){
									printf("Jadwal Asisten Praktikum Intan tidak sesuai (libur pada hari Rabu)\n");}
							break;
							case 'j':
							case 'J':
								if((hr!=4) && ( strcmp(b[mg][hr][rg].matkul,"EL2208")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==4){
									printf("Jadwal Asisten Praktikum Joko tidak sesuai (libur pada hari Jumat)\n");
								}else{printf("Jadwal Asisten Praktikum Joko tidak sesuai (tidak ada Rombongan EL2208)\n");}
							break;
							case 'k':
							case 'K':
								if((hr!=4) && ( (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)||(strcmp(b[mg][hr][rg].matkul,"EB2200")==0))){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==4){
									printf("Jadwal Asisten Praktikum Kiki tidak sesuai (libur pada hari Jumat)\n");
								}else{printf("Jadwal Asisten Praktikum Kiki tidak sesuai (tidak ada Rombongan EL2208,EB2200)\n");}
							break;
							case 'l':
							case 'L':
								if((strcmp(b[mg][hr][rg].matkul,"EL2208")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}
								else{printf("Jadwal Asisten Praktikum Luis tidak sesuai (tidak ada Rombongan EL2208)\n");}
							break;
							case 'm':
							case 'M':
								if((hr!=2)&&(hr!=3) && (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==3 || hr==2){
									printf("Jadwal Asisten Praktikum Mini tidak sesuai (libur pada hari Rabu dan Kamis)\n");
								}else{printf("Jadwal Asisten Praktikum Mini tidak sesuai (tidak ada Rombongan EL2208)\n");}
							break;
							case 'n':
							case 'N':
								if((hr!=1) &&  ( (strcmp(b[mg][hr][rg].matkul,"EL2208")==0)||(strcmp(b[mg][hr][rg].matkul,"EB2200")==0))){//validasi kesesuaian karakteristik asisten
									if(a[mg][hr][rg].satu=='0'){//validasi apakah asisten di koordinat itu penuh
										a[mg][hr][rg].satu=c;
									}else if(a[mg][hr][rg].dua=='0'){
										a[mg][hr][rg].dua=c;}
									else printf("sudah penuh\n");
								}else if(hr==1){
									printf("Jadwal Asisten Praktikum Nina tidak sesuai (libur pada hari Selasa)\n");
								}else{printf("Jadwal Asisten Praktikum Nina tidak sesuai (tidak ada Rombongan EL2208,EB2200)\n");}
							  break;
					  }
				  }
			  }
		  }
	}while (c!='q' && c!='Q');
}
void disas(asis a[12][5][4]){//display asisten
	int i,j,k;
	printf("|--------------------------------------------------------------------|\n");
	printf("|Ruang Praktikum |    LAB1    |    LAB2    |    LAB3    |    LSS     |\n");
	printf("|----------------|------------|------------|------------|------------|\n");
	printf("|Minggu |  Hari  |------------|------------|------------|------------|\n");
	printf("|-------|--------|------------|------------|------------|------------|\n");
	for (i=0;i<=11;i++){//iterasi untuk minggu
		for(j=0;j<=4;j++){//iterasi untuk hari
			if (i+3<10){//penyesuaian kolom minggu 1 digit dan 2 digit
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
			for(k=0;k<=3;k++){//validasi dan input isi dari array ke display
					if (a[i][j][k].satu!='0'){
						if(a[i][j][k].dua=='0'){
							printf("     %c      |",a[i][j][k].satu);
						}else{
							printf("    %c,%c     |",a[i][j][k].satu,a[i][j][k].dua);
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

void savefile(jdl romb[12][5][4], asis as[12][5][4], char nama[100])//save file
{
	int i, j, k;
	char temp[500];
	FILE*rombo;
	strcpy(temp,nama);
	strcat(temp,"_rombongan.csv");
	rombo = fopen(temp,"w+");
	printf("\nRombongan disimpan dalam berkas %s\n",temp);
	fprintf(rombo, "Ruang Praktikum,,LAB 1,LAB 2,LAB 3,LSS\nMinggu,Hari,,,,\n");
	for (i = 0; i < 12; i++)//iterasi minggu
	{	
		for (j = 0; j < 5; j++)//iterasi hari
		{
			fprintf(rombo, "%d,", i+3);//print minggu ke file
			switch (j)//case print hari
			{
				case 0:
					fprintf(rombo, "Senin,");
					break;
				case 1:
					fprintf(rombo, "Selasa,");
					break;
				case 2:
					fprintf(rombo, "Rabu,");
					break;
				case 3:
					fprintf(rombo, "Kamis,");
					break;
				case 4:
					fprintf(rombo, "Jumat,");
					break;
			}
			for (k = 0; k < 4; k++)//validasi di koordinat itu terdapat atau tidaknya jadwal
			{
				if (strcmp(romb[i][j][k].matkul,"0") == 0)
				{		
					fprintf(rombo, " ,");
				} else
				{
					fprintf(rombo, " %s-%s,", romb[i][j][k].matkul, romb[i][j][k].rom);
				}
			}
			fprintf(rombo, "\n");
		}
	}
	fclose(rombo);
	FILE*ass;//untuk asisten
	strcpy(temp,nama);
	strcat(temp,"_asisten.csv");
	ass = fopen(temp, "w+");
	printf("Asisten disimpan dalam berkas %s\n",temp);
	fprintf(ass, "Ruang Praktikum,,LAB 1,LAB 2,LAB 3,LSS\nMinggu,Hari,,,,\n");
	for (i = 0; i < 12; i++)//untuk minggu
	{	
		for (j = 0; j < 5; j++)//untuk hari
		{
			fprintf(ass, "%d,", i+3);//display hari
			switch (j)
			{
				case 0:
					fprintf(ass, "Senin,");
					break;
				case 1:
					fprintf(ass, "Selasa,");
					break;
				case 2:
					fprintf(ass, "Rabu,");
					break;
				case 3:
					fprintf(ass, "Kamis,");
					break;
				case 4:
					fprintf(ass, "Jumat,");
					break;
			}
			for (k = 0; k < 4; k++)//display data,dan validasi apakah satu dua atau nol orang
			{
				if (as[i][j][k].satu != '0')
				{
					if (as[i][j][k].dua !='0')
					{
						fprintf(ass, " \"%c,%c\",", as[i][j][k].satu, as[i][j][k].dua);
					} else
					{
						fprintf(ass, " %c,", as[i][j][k].satu);
					}
				} else
				{
					fprintf(ass, " ,");
				}
			}
			fprintf(ass, "\n");
		}
	}
	fclose(ass);
}
void loadfile(jdl romb[12][5][4], asis as[12][5][4], char nama[100]){//load file untuk menu utama 2

	int i, j, k;
	char temp[500];
	FILE*rombo;
	strcpy(temp,nama);
	strcat(temp,"_rombongan.csv");
	rombo = fopen(temp,"r");
	
	for (int i = 0; i < 5; i++) fscanf(rombo, " %s", temp);//menghabiskan pembacaan dari header file
	fscanf(rombo, " %s", temp);
	for (i = 0; i < 12; i++)//iterasi pembacaan minggu
	{	
		for (j = 0; j < 5; j++)//iterasi pembacaan hari
		{
			fscanf(rombo, " %s", temp);//menghabiskan pembacaan hari
			for (k = 0; k < 4; k++)//validasi apakah jadwal kosong apa tidak
			{
				fscanf(rombo, " %s", temp);
				if (strcmp(temp,",") == 0)
				{		
					strcpy(romb[i][j][k].matkul,"0");
					strcpy(romb[i][j][k].rom,"0");
				} else
				{
					//fprintf(rombo, "%s-%s,", romb[i][j][k].matkul, romb[i][j][k].rom); temp: EL2208-A1,
					for (int x = 0; x < 6; x++) {
						romb[i][j][k].matkul[x] = temp[x];
					}
					romb[i][j][k].matkul[6] = '\0';
					
					romb[i][j][k].rom[0] = temp[7];
					if (temp[8] != ',') {
						romb[i][j][k].rom[1] = temp[8];
						romb[i][j][k].rom[2] = '\0';
					} else
						romb[i][j][k].rom[1] = '\0';
						
				}
			}
		}
	}
	fclose(rombo);//baca file asisten
	FILE*ass;
	strcpy(temp,nama);
	strcat(temp,"_asisten.csv");
	ass = fopen(temp, "r");
	for (int i = 0; i < 5; i++) fscanf(rombo, " %s", temp);
	fscanf(rombo, " %s", temp);
	for (i = 0; i < 12; i++)//untuk minggu
	{	
		for (j = 0; j < 5; j++)//untuk hari
		{
			fscanf(rombo, " %s", temp);
			for (k = 0; k < 4; k++)//kasus 1,2 atau 0 asisten
			{
				fscanf(rombo, " %s", temp);
				if(temp[0]==','){ 
					 as[i][j][k].satu='0'; 
					 as[i][j][k].dua='0';
				}else if(temp[0]!='"'){
					as[i][j][k].satu=temp[0]; 
					 as[i][j][k].dua='0';
				}else{
					as[i][j][k].satu=temp[1];
					as[i][j][k].dua=temp[3];
				}
					
			}
		}
	}
	fclose(ass);
}
void cksc (jdl a[12][5][4]){//rule checker
	printf("[DRC]\nMasukkan File DRC (dalam format .txt):");
	char nama[10000];
	scanf(" %s",nama);
	FILE* ck;
	int mg,hr,b,rg,cl,cr;
	ck=fopen(nama,"r");
	cl=0;
	cr=0;
	while (!feof(ck)) { //cek endof file
		fscanf(ck,"%s",nama);
		if (nama[0] != '\0') {//masuk program jika tidak eof
			mg=atoi(nama)-3;//minggu
			fscanf(ck,"%s",nama); //Hari
			if (strcmp(nama,"Senin")==0){hr=0;}//hari
			if (strcmp(nama,"Selasa")==0){hr=1;}
			if (strcmp(nama,"Rabu")==0){hr=2;}
			if (strcmp(nama,"Kamis")==0){hr=3;}
			if (strcmp(nama,"Jumat")==0){hr=4;}
			b=0;
			for(rg=0;rg<=3;rg++){
				if(strcmp(a[mg][hr][rg].matkul,"0")!=0){
					b=1;
				}
			}
			if(b==1){cl++;}//counting bermasalah
			cr++;//counting libur
			nama[0] = '\0';
		}
	}
	printf("%d/%d Rule is checked\n",(cr-cl),cr);
	fclose(ck);
}
