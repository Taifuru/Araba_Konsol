#include "CizimClass.h"

CizimClass::CizimClass(float x_, float y_, float genislik_, float yukseklik_, std::string resim_adi_)
{
	dosya_yolu = "resimler/";
	resim_adi = resim_adi_;
	x = x_;
	y = y_;
	genislik = genislik_;
	yukseklik = yukseklik_;

	image = al_load_bitmap((dosya_yolu.append(resim_adi)).c_str());
}

CizimClass::CizimClass() {
	x = 0;
	y = 0;
	genislik = 0;
	yukseklik = 0;
	dosya_yolu = "";
	resim_adi = "";

	image = NULL;
}

void CizimClass::ekrana_ciz() {}

//Polimorfizm

void CizimClass::dosya_yaz() {}
void CizimClass::km_artir(float tmp) {}
void CizimClass::gunluk_km_sifirla()  {}
void CizimClass::ekrana_ciz1(){};

float CizimClass::x_getir() {
	return this->x;
}

float CizimClass::y_getir() {
	return this->y;
}

CizimClass::~CizimClass()
{
}
