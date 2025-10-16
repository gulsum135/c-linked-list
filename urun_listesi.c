
#include <stdio.h>
#include <stdlib.h>

/*1. int verilerden oluşan bir bağlı liste oluşturunuz. -1 girilene kadar veri girişini sağlayınız. 
Örnek: 1, 10, 20, 50, 90, 12, 9*/
typedef struct Dugum{
	int veri ;
	struct Dugum *sonraki;
	
}Dugum;


Dugum *Bagli_liste_olustur(){
	Dugum *ilkdugum=NULL;
	Dugum *sondugum=NULL;
	int sayi;
    printf("sayi girin:");
	
	while( scanf("%d",&sayi),sayi != -1){
		
		Dugum *yeni=(Dugum*)malloc(sizeof(Dugum));
		yeni->veri=sayi;
		yeni->sonraki=NULL;	
	
		if(ilkdugum==NULL){
			ilkdugum=yeni;
			sondugum=yeni;
		}
		else{
			sondugum->sonraki=yeni;
			sondugum=yeni;
		}
   }
   return ilkdugum;
}


float Ortalama_bul(Dugum *ilkdugum){
	int toplam=0,adet=0;
	float ortalama;
	Dugum *gecici=ilkdugum;
	while(gecici != NULL){
		toplam+=gecici->veri;
		gecici=gecici->sonraki;
		adet++;
	}
	ortalama=(float)toplam/adet;
	printf("\nOrtalama: %.2f\n",ortalama);
	return ortalama;
}
Dugum * Ortalamadan_buyuk_olan_yeni_liste(Dugum *ilkdugum ,float ortalama){
	Dugum *yeni_ilkdugum=NULL;
	Dugum *yeni_sondugum=NULL;

	while(ilkdugum!= NULL ){
		if( ilkdugum->veri>ortalama){
			Dugum *yenidugum=(Dugum*)malloc(sizeof(Dugum));
		yenidugum->veri=ilkdugum ->veri;
		yenidugum->sonraki=NULL;
		
		if(yeni_ilkdugum ==NULL){
		yeni_ilkdugum=yenidugum;
		yeni_sondugum=yenidugum	;
		}
		else{
		yeni_sondugum->sonraki=yenidugum;
			yeni_sondugum=yenidugum;
	    }
	}
    ilkdugum=ilkdugum->sonraki;
	}
	return yeni_ilkdugum;	
}
void Tersten_Yaz(Dugum *gecici){

	if(gecici==NULL){
		return ;
	}
	Tersten_Yaz(gecici ->sonraki);
	printf("%d ", gecici->veri);
}
/*Kullanıcının istediği sıradaki elemanı ekrana yazdırınız. 
Örnek : 2. Eleman ise 10 yazdırınız. */

void Siradaki_eleman_bul(Dugum *ilkdugum,int sira){
	Dugum *gecici=ilkdugum;
	int i=1;
	while(gecici != NULL && i<=sira){
    if(i==sira){
    	printf("Siradaki_eleman_bul:");
		printf("%d. sirada %d elemani vardir\n",sira,gecici->veri);
	}
	
	gecici=gecici->sonraki;
	i++;
}

}
 /*Kullanıcının istediği sayının kaçıncı sırada olduğunu yazdırınız. 
Örnek : 10 sayısı ise 2 sıradadır şeklinde yazdırınız.*/

void Eleman_ile_sira_bul(Dugum *ilkdugum,int aranan_sayi){
	Dugum *gecici=ilkdugum;
	int sirasi=1;
		while(gecici != NULL ){
		if(aranan_sayi== gecici->veri){
			printf("Eleman_ile_sira_bul: %d sayisi %d. siradadir\n",aranan_sayi,sirasi);
	}
		sirasi++;
		gecici=gecici->sonraki;
		}

} 

/*Çift sayı ikililerini ekrana yazdırınız. 
10-20, 50-90 şeklinde. İlk bulduğu ikiliyi yazdırınız. 20-50 ekran çıktısı olarak 
yazdırmayınız.
DOĞRU ÇALIŞMAYAN KOD
void cift_ikili_Yazdir(Dugum *ilkdugum){
	Dugum *gecici=ilkdugum;
	int a = gecici->veri;
    int b = gecici->sonraki->veri;
	while(gecici !=NULL && gecici->sonraki!=NULL && gecici->sonraki ->sonraki!=NULL){
		if(gecici->veri == gecici->sonraki->veri && a%2==0 &&b%2==0 ){
			printf("Cift ikililer : %d - %d ",a,b );
			gecici=gecici->sonraki->sonraki;
			return;
		}else{
				gecici=gecici->sonraki;
		}
	
	}
	 printf("Cift ikili bulunamadi.\n");
}
*/
/*Kullanıcı tarafından girilen artış miktarına göre ekrana yazdırınız. 
Örnek: 3 ise , 3 ve 3’ün katında yer alan sayıları yazdıralım. Bu durumda 20 ve 12 
yazdırılacaktır.*/
void artis_miktarina_gore_artir(Dugum *ilkdugum, int artis_miktari){
	Dugum *gecici=ilkdugum;
	int i=1;
	printf("%d nin katlarindaki sayilar:",artis_miktari);
	while(gecici!=NULL){
		if(i%artis_miktari==0){
			printf(" %d",gecici->veri);
		}
		i++;
		gecici=gecici->sonraki;
		
	}
	
}/*Bir sonraki sayı kendinden küçük olduğu sürece sayıları ekrana yazdırınız. Varsa diğer sayı 
dizileri de yazdırılacaktır. Bu örnekte tek bir sayı dizisi bulunmaktadır. 
Sonuç: 1, 10, 20, 50, 90 olacaktır. Çünkü 1<10, 10<20, 20<50, 50<90*/ 

void kurala_gore_yazdir(Dugum *ilkdugum){
	Dugum *gecici=ilkdugum;
	while(gecici !=NULL){
		if(gecici->veri< gecici->sonraki->veri){
			printf("%d < %d  ",gecici->veri,gecici->sonraki->veri);
		}
		gecici=gecici->sonraki;
}
}

/*0. Girilen sayıya en yakın sayının kaçıncı sırada ve hangi sayı olduğunu ekrana yazdırınız. 
Örnek: 22 sayısı 20 sayısına en yakındır ve bu sayı 3. sıradadır.*/
void Girilen_sayiya_en_yakin_sayi(Dugum *ilkdugum,int girilen_sayi){
	Dugum *gecici=ilkdugum;
	int en_az_fark=100,fark;
	while(gecici !=NULL){
	fark=abs(gecici->veri - girilen_sayi);
	if(fark < en_az_fark){
		printf(" %d sayisina en yakin sayi %d dir.",girilen_sayi,gecici->veri);
	}
	gecici=gecici->sonraki;
	}
	
}



void Liste_yazdir(Dugum *ilkdugum){
		Dugum *gecici=ilkdugum;
	while(gecici !=NULL){
		printf("%d, ",gecici->veri);
		gecici=gecici->sonraki;
}}


int main(){
	int sayi,artis_miktari;
	int sira,aranan_sayi,girilen_sayi;
	Dugum *ilkdugum= Bagli_liste_olustur();
	
	float ortalama = Ortalama_bul(ilkdugum);
    Liste_yazdir(ilkdugum);
	printf("\n");
	printf("Listenin yeni hali:");
	Dugum *yeni_liste=Ortalamadan_buyuk_olan_yeni_liste(ilkdugum ,ortalama);
	Liste_yazdir(yeni_liste);
	printf("\n");
	printf("Listenin ters hali:");
	Tersten_Yaz(ilkdugum);
	printf("\n");
	printf("sira no girin:");
	scanf("%d",&sira);
	Siradaki_eleman_bul(ilkdugum, sira);
	printf("bulmak istediginiz sayiyi girin");
	scanf("%d",&aranan_sayi);
	Eleman_ile_sira_bul(ilkdugum, aranan_sayi);
    printf("artis miktarini girin");
    scanf("%d",&artis_miktari);
    artis_miktarina_gore_artir(ilkdugum, artis_miktari);
    printf("\n");
    kurala_gore_yazdir(ilkdugum);
    printf("\n");
    printf("yakin olmasini istedigin sayiyi gir:");
    scanf("%d",&girilen_sayi);
    Girilen_sayiya_en_yakin_sayi(ilkdugum,girilen_sayi);
	return 0;
}

                                         








