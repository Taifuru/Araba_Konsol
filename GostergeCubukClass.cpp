#include "GostergeCubukClass.h"


GostergeCubukClass::GostergeCubukClass(float x_, float y_, float genislik_, float yukseklik_, float aci_, float aci_sinir_, std::string resim_adi_) : CizimClass(x_, y_, genislik_, yukseklik_, resim_adi_)
{
	aci = aci_;
	aci_baslangic = aci_;
	aci_sinir = aci_sinir_;
	genislik = genislik_;
	yukseklik = yukseklik_;
	artma_durma_hali = true;
}

GostergeCubukClass::GostergeCubukClass(){

}

GostergeCubukClass::~GostergeCubukClass()
{
}

void GostergeCubukClass::ekrana_ciz() {
	if (!image){
		printf("hata var panpa");
	}
	else {
		al_draw_rotated_bitmap(image, genislik, yukseklik, x, y, (aci)*3.141592 / 180, 0);
	}
}

void GostergeCubukClass::aci_artir(int artis_miktari){
	
	if ( (artma_durma_hali == true) && (aci <= aci_sinir)){
		aci += artis_miktari;
	}

	cout << aci << resim_adi << " artti" << endl;

}

void GostergeCubukClass::aci_artir(float artis_miktari){

	if ( (artma_durma_hali == true) && (aci <= aci_sinir)){
		aci += artis_miktari;
	}

	cout << aci << "artti" << endl;

}

void GostergeCubukClass::aci_azalt(){
	
	if (aci >= aci_baslangic){
		aci--;
	}
	
}

void GostergeCubukClass::aci_azalt(float azalis_miktari){

	if (aci >= aci_baslangic){
		aci -= azalis_miktari;
	}
}

void GostergeCubukClass::sifirla() {
	aci = aci_baslangic;
}

float GostergeCubukClass::aci_getir() {
	return aci;
}

float GostergeCubukClass::aci_sinir_getir() {
	return aci_sinir;
}

float GostergeCubukClass::aci_baslangic_getir() {
	return aci_baslangic;
}

void GostergeCubukClass::aci_ayarla(int aci_) {
	aci = aci_;
}

void GostergeCubukClass::artma_durumu_hali_ayarla(bool durum) {
	artma_durma_hali = durum;
}
