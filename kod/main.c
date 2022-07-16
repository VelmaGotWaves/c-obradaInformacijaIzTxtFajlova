#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct igraci{
	char ime[30], prezime[30];
	float br_utakmica,pbr_poena, pbr_skokova, pbr_asistencija, pbr_ukradenih, pbr_izgubljenih, indekskorisnosti;
} IG;
IG igrac[300];
int i=0;
	
int unosigraca(FILE *f, IG *ig)//kod specificnog tima
{		
	fscanf(f,"%s%s%f%f%f%f%f%f%f", &(ig->ime), &(ig->prezime), &(ig->br_utakmica), &(ig->pbr_poena), &(ig->pbr_skokova), &(ig->pbr_asistencija), &(ig->pbr_ukradenih),
	&(ig->pbr_izgubljenih), &(ig->indekskorisnosti));
	if(feof(f)) return 0;
	return 1;
}
void najvecibrojpoena( IG *igrac, int d)//kod specificnog tima
{
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_poena>igrac[j].pbr_poena)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise prosecnih poena u ovom timu je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_poena);
}

void najvecibrojskokova( IG *igrac, int d)//kod specificnog tima
{
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_skokova>igrac[j].pbr_skokova)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvisim prosecnim skoku u ovom timu je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_skokova);
}
void najvecibrojasistencija( IG *igrac, int d)//kod specificnog tima
{
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_asistencija>igrac[j].pbr_asistencija)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvisim prosecnim asistencijama u ovom timu je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_asistencija);
}
void najvecibrojukradenihlopti( IG *igrac, int d)//kod specificnog tima
{
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_ukradenih>igrac[j].pbr_ukradenih)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise ukradenih lopti u ovom timu je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_ukradenih);
}
void mvp( IG *igrac, int d)//kod specificnog tima
{
	
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].indekskorisnosti>igrac[j].indekskorisnosti)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nMVP igrac u ovom timu je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].indekskorisnosti);
}
//mogu jos vise da skratim ako prvo napisem funkciju koja procita sve izbroji kolko ih ima i stavi ih sve na svoje mesto, a onda samo funkcije koje sortiraju odredjene kategorije
int ukupanbroj(char timovi[18][40], IG igrac[300]){
	int k=0,i;
	for(i=0;i<18;i++){
		FILE *f1=fopen(timovi[i],"r");
		if(f1==NULL){
			printf("\nNisi uneo validno ime kluba");	
		}		
		while(!feof(f1))
		{
			fscanf(f1,"%s%s%f%f%f%f%f%f%f", &(igrac[k].ime), &(igrac[k].prezime), &(igrac[k].br_utakmica), &(igrac[k].pbr_poena), &(igrac[k].pbr_skokova), &(igrac[k].pbr_asistencija), &(igrac[k].pbr_ukradenih),
			&(igrac[k].pbr_izgubljenih), &(igrac[k].indekskorisnosti));
	
			k++;
		}
		fclose(f1);
	}
	return k;
}
void mvpliga(int d, IG igrac[300]){
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].indekskorisnosti>igrac[j].indekskorisnosti)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nMVP igrac u ligi je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].indekskorisnosti);
}
void najpoena(int d, IG igrac[300]){
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_poena>igrac[j].pbr_poena)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise prosecnih poena u ligi je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_poena);
}
void najskokova(int d, IG igrac[300]){
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_skokova>igrac[j].pbr_skokova)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise prosecnih skokova u ligi je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_skokova);
}
void najasistencija(int d, IG igrac[300]){
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_asistencija>igrac[j].pbr_asistencija)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise prosecnih asistencija u ligi je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_asistencija);
}
void ukradenih(int d, IG igrac[300]){
	IG pom;
	int j,i;
	for(i=0;i<d-1;i++)
	{
		for(j=i+1;j<d;j++)
		{
			if(igrac[i].pbr_ukradenih>igrac[j].pbr_ukradenih)
			{
				pom=igrac[i];
				igrac[i]=igrac[j];
				igrac[j]=pom;
			}
		}
	}
	printf("\nIgrac sa najvise prosecnih ukradenih lopti u ligi je: %s %s %f", igrac[i].ime,igrac[i].prezime,igrac[i].pbr_ukradenih);
}
main() {
	char timovi[18][40]={
		"ALBABerlin.txt","AnadoluEfesIstanbul.txt","AXArmaniExchangeMilan.txt","CrvenaZvezda.txt","CSKAMoscow.txt","Barcelona.txt","BayernMunich.txt","FenerbacheBekoIstanbul.txt","KhimkiMoscowRegion.txt",
		"KIROLBETBaskoniaVitoriaGasteiz.txt","LDLCASVELVilleurbanne.txt","MaccabiFOXTelAviv.txt","OlympiacosPiraeus.txt","PanathinaikosOPAPAthens.txt","RealMadrid.txt","ValenciaBasket.txt","ZalgirisKaunas.txt","ZenitStPetersburg.txt"
	};

	IG pom;
	int n,d;
	char imekluba[30], ime[30], prezime[30];
	printf("Izaberi zeljenu opciju:");
	printf("\n1 -Ako zelis izvestaj za odredjenog igraca\n2 -Ako zelis izvestaj za odredjeni klub\n3 -Ako zelis izvestaj za celu ligu pritisni\n");
	scanf("%d", &n);
	if(n==1){//igrac
		printf("\nNavedi Ime kluba:");
		scanf("%s", &imekluba);
		printf("\nNavedi Ime igraca:");
		scanf("%s", &ime);
		printf("\nNavedi Prezime igraca:");
		scanf("%s", &prezime);
		strcat(imekluba,".txt");
		FILE *f1=fopen(imekluba,"r");
		if(f1==NULL){
			printf("\nNisi uneo validno ime kluba");
			return 0;
		}
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			i=0;
			int j=1000;
			for(i=0;i<d;i++)
			{
				if(strcmp(ime,igrac[i].ime)==0 && strcmp(prezime,igrac[i].prezime)==0)
				j=i;
			}
			if(j==1000){
				printf("\nNisi uneo dobro ime ili prezime za igraca ");
				return 0;
			} 
		printf("\nIzabrao si igraca, sad izaberi neku od sledecih opcija: ");
		printf("\n1 -Prosecan broj poena\n2 -Prosecan broj skokova\n3 -prosecan broj asistencija\n4 -Broj odigranih utakmica\n");
		scanf("%d", &n);
	
		if(n==1){
			printf("\nProsecan broj njegovih poena je: %f", igrac[j].pbr_poena);
		}
		else if(n==2){
			printf("\nProsecan broj njegovih skokova je: %f", igrac[j].pbr_skokova);
		}
		else if(n==3){
			printf("\nProsecan broj njegovih asistencija je: %f", igrac[j].pbr_asistencija);
		}
		else if(n==4){
			printf("\nBroj odigranih utakmica je: %f", igrac[j].br_utakmica);
		}
		else{
			printf("\nNisi izabrao validnu opciju");
			return;
		}
		}
	else if(n==2)
	{//klub
		printf("\nUnesi ime kluba: ");
		scanf("%s", &imekluba);
		strcat(imekluba,".txt");
		FILE *f1=fopen(imekluba,"r");
		if(f1==NULL){
			printf("\nNisi uneo validno ime kluba");
			return 0;
		}
		printf("\nUneo si klub, sad izaberi neku od sledecih opcija: ");
		printf("\n1 -Spisak igraca kluba\n2 -Igrac sa najvecim brojem poena\n3 -Igrac sa najvecim brojem skokova\n4 -Igrac sa najvecim brojem asistencija\n5 -Igrac sa najvecim brojem ukradenih lopti\n6 -MVP Igrac\n");
		scanf("%d", &n);
		if(n==1){
			while(unosigraca(f1, &igrac[i])){
				i++;	
			}
			d=i;
			for(i=0;i<d;i++)
			{
				printf("\n%s %s", igrac[i].ime, igrac[i].prezime);
			}
		}
		else if(n==2){
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			najvecibrojpoena(igrac, d);
		}
		else if(n==3){
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			najvecibrojskokova(igrac, d);
		}
		else if(n==4){
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			najvecibrojasistencija(igrac, d);
		}
		else if(n==5){
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			najvecibrojukradenihlopti(igrac, d);
		}
		else if(n==6){
			while(unosigraca(f1, &igrac[i])){
				i++;
			}
			d=i;
			mvp(igrac, d);
		}
		else{
			printf("\nNisi izabrao validnu opciju klub");
			return;
		}
	}
	else if(n==3)
	{//liga
		printf("\nIzabrao si ligu, sad izaberi neku od sledecih opcija: ");
		printf("\n1 -Ukupan broj igraca\n2 -MVP Igrac\n3 -Igrac sa najvecim brojem poena\n4 -Igrac sa najvecim brojem skokova\n5 -Igrac sa najvecim brojem asistencija\n6 -Igrac sa najvecim brojem ukradenih lopti\n");
		scanf("%d", &n);
		ukupanbroj(timovi,igrac);
		if(n==1){
			printf("\nUkupan broj igraca je: %d", ukupanbroj(timovi,igrac));
		}
		else if(n==2){
			mvpliga(ukupanbroj(timovi,igrac), igrac);
		}
		else if(n==3){
			najpoena(ukupanbroj(timovi,igrac), igrac);
		}
		else if(n==4){
			najskokova(ukupanbroj(timovi,igrac), igrac);
		}
		else if(n==5){
			najasistencija(ukupanbroj(timovi,igrac), igrac);
		}
		else if(n==6){
			ukradenih(ukupanbroj(timovi,igrac), igrac);
		}
		else{
			printf("\nNisi izabrao validnu opciju");
			return;
		}
		
	}
	else {// ako nista nije dobro
	
		printf("\nNisi izabrao validnu opciju");
		return;
	}
	return 0;
}
