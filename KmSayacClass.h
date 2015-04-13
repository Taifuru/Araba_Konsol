#pragma once

#define _CRT_SECURE_NO_DEPRECATE

#include "CizimClass.h"
#include <iostream>

using namespace std;

class KmSayacClass: public CizimClass {
private:
	//float gunluk_km;
	//float toplam_km;
	ALLEGRO_FONT *font;

public:
	float gunluk_km;
	float toplam_km;

	 void dosya_yaz() ;
	void dosya_oku();

	 void km_artir(float aci);

	 void ekrana_ciz();

	 void gunluk_km_sifirla();

	KmSayacClass(float x, float y, float genislik, float yukseklik, float yazi_boyutu);
	KmSayacClass();
	~KmSayacClass();
};
