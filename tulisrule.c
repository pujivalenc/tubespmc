#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//fungsi untuk cetak file txt
int main(){
	int a,i,b;
	char nama[10000];
	printf("nama file(txt):");//input nama file
	scanf(" %s",nama);
	FILE* ck;
	printf("banyak rule:");//banyak libur
	scanf(" %d",&a);
	ck=fopen(nama,"w");
	for(i=0;i<a;i++){//iterasi input banyak Libur
		printf("minggu ke(3-14):");
		do{
			scanf(" %d",&b);
		}while(b<3||b>14);
		fprintf(ck,"%d ",b);
		printf("hari(Senin,Selasa,Rabu,Kamis,Jumat):");
		scanf(" %s",nama);
		fprintf(ck," %s\n",nama);
		
	}
	fclose(ck);
	return 0;
}
