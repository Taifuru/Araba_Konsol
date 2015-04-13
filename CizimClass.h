#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string>
#include <iostream>
#include <stdio.h>

class CizimClass
{
//Alt siniftan erisimi olsun diye protected kullanildi
protected:
	//Ekrandaki konumlari
	float x;
	float y;
	float yukseklik;
	float genislik;

	//resim dosya yolu
	std::string dosya_yolu;

	//Gosterilecek png resmi
	ALLEGRO_BITMAP *image;
	//png nin adi
	std::string resim_adi;

public:
	//Kurucu fonksiyon
	CizimClass(float x, float y, float genislik, float yukseklik, std::string resim_adi);

	//Bos kurucu fonksiyon
	CizimClass();

	//Nesnelerin ekrana cizilmesi icin kodlarin yazilacagi fonksiyon
	virtual void ekrana_ciz();
	virtual void ekrana_ciz1();

	//
	void yukseklik_ayarla(int yukseklik);

	void genislilk_ayarla(int genislik);

	float x_getir();
	float y_getir();

	//Polimorfizm
	virtual void dosya_yaz() ;
	virtual void km_artir(float) ;
	virtual void gunluk_km_sifirla();

	~CizimClass();
};
