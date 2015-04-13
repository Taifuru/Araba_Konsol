#pragma once
#include "CizimClass.h"
#include <iostream>
using namespace std;

class GostergeCubukClass : public CizimClass
{
private:
	float aci;
	float aci_baslangic;
	float aci_sinir;

	bool artma_durma_hali;

public:

	GostergeCubukClass(float x, float y, float genislik, float yukseklik, float aci, float aci_sinir,  std::string resim_adi);
	
	GostergeCubukClass();

	void ekrana_ciz();

	void aci_artir(int artis_miktari);

	void aci_artir(float artis_miktari);

	void aci_azalt();

	void aci_azalt(float azalis_miktari);

	void sifirla();

	float aci_getir();

	float aci_sinir_getir();

	float aci_baslangic_getir();

	void aci_ayarla(int aci_);

	void artma_durumu_hali_ayarla(bool durum);

	~GostergeCubukClass();
};
