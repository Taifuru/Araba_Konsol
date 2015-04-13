#include "KmSayacClass.h"

KmSayacClass::KmSayacClass(float x, float y, float genislik, float yukseklik, float yazi_boyutu) //
				:CizimClass(x, y, genislik, yukseklik, "day.png")
{
	/*
	this->x = x;
	this->y = y;
	this->genislik = genislik;
	this->yukseklik = yukseklik;
	this->resim_adi = "day.png";
	*/
	font = al_load_font("pirulen.ttf", yazi_boyutu, 0);
	gunluk_km = 0;
	dosya_oku();
}

KmSayacClass::KmSayacClass(){

}

void KmSayacClass::dosya_yaz() {
	FILE *di;

	int tmp = (int) toplam_km;

	di = fopen("cokgizliacma.txt", "w");

	if( di != NULL) {
		fprintf(di, "%d\n", tmp);
		fclose(di);
	}else {
		cout << "Dosya Acilamadi" << endl;
	}
}

void KmSayacClass::dosya_oku() {
	FILE *di;

	int tmp;

	di = fopen("cokgizliacma.txt", "r");

	if( di != NULL) {
		fscanf(di, "%d\n", &tmp);

		toplam_km = (int) (tmp);

		fclose(di);
	}else {
		toplam_km = 0;
		cout << "Dosya Acilamadi" << endl;
	}
}

void KmSayacClass::km_artir(float aci) {
	gunluk_km += aci;
	toplam_km += aci;
}

void KmSayacClass::ekrana_ciz() {
	char tmp[32];
	char tmp2[32];

	int tmp3 = (int) gunluk_km;
	int tmp4 = (int) toplam_km;

	sprintf(tmp, "%d", tmp3);
	sprintf(tmp2, "%d", tmp4);

	al_draw_text(font, al_map_rgb(90, 239, 8), x, y, 0, tmp);
	al_draw_text(font, al_map_rgb(90, 239, 8), x, y+30, 0, tmp2);
}

void KmSayacClass::gunluk_km_sifirla(){
	gunluk_km = 0;
}

KmSayacClass::~KmSayacClass() {
	// TODO Auto-generated destructor stub
}
