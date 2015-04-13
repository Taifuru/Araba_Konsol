#pragma once
#include "IkazLambaClass.h"
#include "GostergeCubukClass.h"
#include "KmSayacClass.h"

#include <string>

class YoneticiClass
{
private:
	IkazLambaClass aku_sarj;
	IkazLambaClass day;
	IkazLambaClass arka_cam_rezistans;
	IkazLambaClass arka_sis_far;
	IkazLambaClass dortlu;
	IkazLambaClass fren_devresi_ariza;
	IkazLambaClass kisa_far;
	IkazLambaClass on_disk_fren_balata;
	IkazLambaClass on_sis_far;
	IkazLambaClass park_lamba_ikaz;
	IkazLambaClass sag_sinyal;
	IkazLambaClass sogutma_suyu_ikaz;
	IkazLambaClass sol_sinyal;
	IkazLambaClass uzun_far;
	IkazLambaClass yag_ikaz;
	IkazLambaClass yakit_ikaz;

	GostergeCubukClass hiz_gosterge_cubuk;
	GostergeCubukClass devir_gosterge_cubuk;
	GostergeCubukClass yakit_gosterge_cubuk;
	GostergeCubukClass su_sicaklik_gosterge_cubuk;

	//Polimorfizm
	//KmSayacClass km_sayac_nesne;
	CizimClass *km_sayac_nesne;


	int vites;
	int hiz;
	int devir;
	int yakit_miktari;
	int su_sicakligi;

	int aku_durumu;

	bool motor_durumu;

	std::string model_ismi;

	//############################
	//Fonksiyonlar
	void nesne_tanimla();
public:
	YoneticiClass(std::string model_ismi_);

	void tus_kontrol(int klavye_tus);

	void tus_kontrol_basili(int klavye_tus);
	
	void ekrana_ciz();

	bool hizlaniyor_mu;

	IkazLambaClass *aku_sarj_getir();
	IkazLambaClass *day_getir();
	IkazLambaClass *arka_cam_rezistans_getir();
	IkazLambaClass *arka_sis_far_getir();
	IkazLambaClass *dortlu_getir();
	IkazLambaClass *fren_devresi_ariza_getir();
	IkazLambaClass *kisa_far_getir();
	IkazLambaClass *on_disk_fren_balata_getir();
	IkazLambaClass *on_sis_far_getir();
	IkazLambaClass *park_lamba_ikaz_getir();
	IkazLambaClass *sag_sinyal_getir();
	IkazLambaClass *sogutma_suyu_ikaz_getir();
	IkazLambaClass *sol_sinyal_getir();
	IkazLambaClass *uzun_far_getir();
	IkazLambaClass *yag_ikaz_getir();
	IkazLambaClass *yakit_ikaz_getir();

	GostergeCubukClass *hiz_gosterge_cubuk_getir();
	GostergeCubukClass *devir_gosterge_cubuk_getir();
	GostergeCubukClass *yakit_gosterge_cubuk_getir();
	GostergeCubukClass *su_sicaklik_gosterge_cubuk_getir();

	void vites_artir();
	void vites_azalt();
	void hizlan();
	void yavasla();

	void yakit_ekle();

	void araba_calisma_hali();

	void motor_durumu_degistir();

	~YoneticiClass();
};

