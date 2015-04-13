#include "IkazLambaClass.h"

IkazLambaClass::IkazLambaClass(float x_, float y_, float genislik_, float yukseklik_, std::string resim_adi_) : CizimClass(x_, y_, genislik_, yukseklik_, resim_adi_)
{
	aktif_ayarla(0);
}

IkazLambaClass::IkazLambaClass() {
	aktif_ayarla(0);
}

IkazLambaClass::~IkazLambaClass()
{
}

void IkazLambaClass::ekrana_ciz() {
	if (!aktif) {//aktif değilse bir şey yapmıyor
		
	}
	else {
		if (!image){
				printf("resim yuklenemedi");
			}
			else {
				al_draw_bitmap(image, x, y, 0);//(resim adi, x, y, bayrak) // bir üst sınıf burası
			}
	}
}

void IkazLambaClass::aktif_ayarla(int deger) {
	aktif = deger ? true : false;
}

bool IkazLambaClass::aktif_getir() {
	return aktif;
}

void IkazLambaClass::durum_degistir() {
	aktif = !aktif;
}
