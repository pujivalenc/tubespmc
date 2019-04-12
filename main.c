#include "libtubes.h"

int main(){

	int menu1;
	int menu;
	do{
		printf("Menu: \n");
		printf("   1. Buat Proyek Baru \n");
		printf("   2. Muat Proyek dari Berkas \n");
		printf("   3. Keluar \n");
		do{
			printf("Masukan: ");
			scanf("%d",&menu);
		}while((menu<1)||(menu>3));
		if(menu==1){
            initjdl(jad);
            initas(a);
			char nmf[100];
			printf("\n");
			printf("====== Membuat Proyek Baru ====== \n");
			printf("Masukkan nama proyek: ");
			scanf("%s",nmf);
			do{
				printf("\n");
				printf("[Menu Utama] ");
				printf("Pilih Mode: \n");
				printf("   1. Tampilkan Schedule\n");
				printf("   2. Schedule Manual\n");
				printf("   3. Tampilkan Status Assignment Asisten\n");
				printf("   4. Assign Asisten Manual\n");
				printf("   5. Schedule Otomatis\n");
				printf("   6. Assign Otomatis\n");
				printf("   7. Rule Checker\n");
				printf("   8. Simpan Proyek dan Keluar\n");
				do{
					printf("Pilih Mode: ");
					scanf("%d",&menu1);
				}while((menu1<1) || (menu1>8));
				switch(menu1){
					case 1 :
                            tampilkanSchedule();
						break;
					case 2 :
                            scheduleManual();
						break;
					case 3 :
                            disas(a);
						break;
					case 4 :
                            aam(a,jad);
						break;
					case 5 :

						break;
					case 6 :

						break;
					case 7 :
							cksc(jad);
						break;
					case 8 :
                            savefile(jad,a,nmf);
						break;
				}
			}while(menu1 != 8);
		}
		else if(menu==2){
			initjdl(jad);
            initas(a);
			char nmf[100];
			printf("\n");
			printf("====== Memuat Proyek ====== \n");
			printf("Masukkan nama proyek yang ingin di-load: ");
			scanf("%s",nmf);
			loadfile(jad, a, nmf);
			do{
				printf("\n");
				printf("[Menu Utama] ");
				printf("Pilih Mode: \n");
				printf("   1. Tampilkan Schedule\n");
				printf("   2. Schedule Manual\n");
				printf("   3. Tampilkan Status Assignment Asisten\n");
				printf("   4. Assign Asisten Manual\n");
				printf("   5. Schedule Otomatis\n");
				printf("   6. Assign Otomatis\n");
				printf("   7. Rule Checker\n");
				printf("   8. Simpan Proyek dan Keluar\n");
				do{
					printf("Pilih Mode: ");
					scanf("%d",&menu1);
				}while((menu1<1) || (menu1>8));
				switch(menu1){
					case 1 :
                            tampilkanSchedule();
						break;
					case 2 :
                            scheduleManual();
						break;
					case 3 :
                            disas(a);
						break;
					case 4 :
                            aam(a,jad);
						break;
					case 5 :

						break;
					case 6 :

						break;
					case 7 :
						cksc(jad);
						break;
					case 8 :
                            savefile(jad,a,nmf);
						break;
				}
			}while(menu1 != 8);
		}
	}while(menu != 3);
return 0;}
