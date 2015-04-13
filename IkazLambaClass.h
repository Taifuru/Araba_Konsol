#pragma once
#include "CizimClass.h"
class IkazLambaClass : public CizimClass
{
private:
	bool aktif;
public:
	IkazLambaClass(float x, float y, float genislik, float yukseklik, std::string resim_adi);

	IkazLambaClass();

	//Polimorfizim de kullan�lacak
	//Saydaml�k netlik olay�
	
	void ekrana_ciz();

	void aktif_ayarla(int deger);

	bool aktif_getir();

	void durum_degistir();

	~IkazLambaClass();
};
