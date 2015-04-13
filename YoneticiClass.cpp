#include "YoneticiClass.h"

YoneticiClass::YoneticiClass(std::string model_ismi_)
{
	model_ismi = model_ismi_;
	motor_durumu = true;
	aku_durumu = 999;
	hizlaniyor_mu = false;
	YoneticiClass::nesne_tanimla();
	devir_gosterge_cubuk.aci_ayarla(75);
}

void YoneticiClass::nesne_tanimla() {
	day = IkazLambaClass(0, 0, 0, 0, "night.png");
	day.aktif_ayarla(1);

	aku_sarj = IkazLambaClass(205, 390, 0, 0, "aku_sarj.png");

	arka_cam_rezistans = IkazLambaClass(790, 350, 0, 0, "arka_cam_rezistans.png");

	arka_sis_far = IkazLambaClass(890, 390, 0, 0, "arka_sis_far.png");

	dortlu = IkazLambaClass(790, 250, 0, 0, "dortlu.png");

	fren_devresi_ariza = IkazLambaClass(255, 350, 0, 0, "fren_devresi_ariza.png");

	kisa_far = IkazLambaClass(840, 390, 0, 0, "kisa_far.png");

	on_disk_fren_balata = IkazLambaClass(790, 300, 0, 0, "on_disk_fren_balata.png");

	on_sis_far = IkazLambaClass(790, 390, 0, 0, "on_sis_far.png");

	park_lamba_ikaz = IkazLambaClass(255, 390, 0, 0, "park_lamba_ikaz.png");

	uzun_far = IkazLambaClass(790, 150, 0, 0, "uzun_far.png");

	sogutma_suyu_ikaz = IkazLambaClass(925, 225, 0, 0, "sogutma_suyu_ikaz.png");

	yag_ikaz = IkazLambaClass(155, 390, 0, 0, "yag_ikaz.png");

	yakit_ikaz = IkazLambaClass(960, 340, 0, 0, "yakit_ikaz.png");

	sag_sinyal = IkazLambaClass(685, 90, 0, 0, "sag_sinyal.png");

	sol_sinyal = IkazLambaClass(365, 90, 0, 0, "sol_sinyal.png");

	hiz_gosterge_cubuk = GostergeCubukClass(540, 275, 22, 22, 62, 298, "hiz_gosterge_cubuk.png");

	devir_gosterge_cubuk = GostergeCubukClass(245, 292, 22, 22, 60, 170, "devir_gosterge_cubuk.png");
	yakit_gosterge_cubuk = GostergeCubukClass(920, 330, 15, 10, 45, 135, "yakit_gosterge_cubuk.png");
	su_sicaklik_gosterge_cubuk = GostergeCubukClass(920, 203, 15, 10, 45, 135, "su_sicaklik_gosterge_cubuk.png");

	//KmSayacClass km_tmp_nesne = KmSayacClass(520, 365, 0, 0, 18);

	//km_sayac_nesne = &km_tmp_nesne;

	km_sayac_nesne = new KmSayacClass(520, 365, 0, 0, 18);

	yakit_gosterge_cubuk.aci_ayarla(135);
	//su_sicaklik_gosterge_cubuk.aci_ayarla(90);
}

void YoneticiClass::ekrana_ciz() {

	day.ekrana_ciz();
	aku_sarj.ekrana_ciz();
	arka_cam_rezistans.ekrana_ciz();
	arka_sis_far.ekrana_ciz();
	dortlu.ekrana_ciz();
	fren_devresi_ariza.ekrana_ciz();
	kisa_far.ekrana_ciz();
	on_disk_fren_balata.ekrana_ciz();
	on_sis_far.ekrana_ciz();
	park_lamba_ikaz.ekrana_ciz();
	sag_sinyal.ekrana_ciz();
	sogutma_suyu_ikaz.ekrana_ciz();
	sol_sinyal.ekrana_ciz();
	uzun_far.ekrana_ciz();
	yag_ikaz.ekrana_ciz();
	yakit_ikaz.ekrana_ciz();

	hiz_gosterge_cubuk.ekrana_ciz();
	devir_gosterge_cubuk.ekrana_ciz();
	yakit_gosterge_cubuk.ekrana_ciz();
	su_sicaklik_gosterge_cubuk.ekrana_ciz();

	km_sayac_nesne->ekrana_ciz();

}

void YoneticiClass::tus_kontrol_basili(int klavye_tus) {
	if(motor_durumu == true){
		switch (klavye_tus)
		{
		case ALLEGRO_KEY_UP:
			hiz_gosterge_cubuk.aci_artir(1);
			devir_gosterge_cubuk.artma_durumu_hali_ayarla(true);
			hizlaniyor_mu = true;
			break;

		case ALLEGRO_KEY_DOWN:
			hiz_gosterge_cubuk.aci_azalt();
			//devir_gosterge_cubuk.artma_durumu_hali_ayarla(false);
			//devir_gosterge_cubuk.aci_azalt();
			break;

		default:
			break;
		}
	}
}

void YoneticiClass::tus_kontrol(int klavye_tus) {
	switch (klavye_tus)
	{
	case ALLEGRO_KEY_M:
		motor_durumu_degistir();
		cout << "m ye bastik" << endl;
		break;
	case ALLEGRO_KEY_A:
		//eğer tuşa basıldıysa onun değerini değiştiriyor aktif ya da değil diye ctrl m1
		aku_sarj.durum_degistir(); // bisn kanka
		break;

	case ALLEGRO_KEY_R:
		arka_cam_rezistans.durum_degistir();
		break;

	case ALLEGRO_KEY_G:
		arka_sis_far.durum_degistir();
		break;

	case ALLEGRO_KEY_D:
		dortlu.durum_degistir();
		sol_sinyal.aktif_ayarla(0);
		sag_sinyal.aktif_ayarla(0);
		break;

	case ALLEGRO_KEY_F:
		fren_devresi_ariza.durum_degistir();
		break;

	case ALLEGRO_KEY_L:
		kisa_far.durum_degistir();
		break;

	case ALLEGRO_KEY_B:
		on_disk_fren_balata.durum_degistir();
		break;

	case ALLEGRO_KEY_S:
		on_sis_far.durum_degistir();
		break;

	case ALLEGRO_KEY_P:
		park_lamba_ikaz.durum_degistir();
		break;

	case ALLEGRO_KEY_RIGHT:
		if(!dortlu_getir()->aktif_getir()) {
			sag_sinyal.durum_degistir();
		}
		break;

	case ALLEGRO_KEY_Z:
		sogutma_suyu_ikaz.durum_degistir();
		break;

	case ALLEGRO_KEY_LEFT:
		if(!dortlu_getir()->aktif_getir()) {
			sol_sinyal.durum_degistir();
		}
		break;

	case ALLEGRO_KEY_U:
		uzun_far.durum_degistir();
		break;

	case ALLEGRO_KEY_Y:
		yag_ikaz.durum_degistir();
		break;

	case ALLEGRO_KEY_H:
		yakit_ikaz.durum_degistir();
		break;

	case ALLEGRO_KEY_Q:
		km_sayac_nesne->gunluk_km_sifirla();
		break;

	case ALLEGRO_KEY_X:
		yakit_ekle();
		break;
	default:
		break;
	}

}

IkazLambaClass *YoneticiClass::aku_sarj_getir(){
	return &aku_sarj;
}

IkazLambaClass *YoneticiClass::day_getir(){
	return &day;
}

IkazLambaClass *YoneticiClass::arka_cam_rezistans_getir(){
	return &arka_cam_rezistans;
}

IkazLambaClass *YoneticiClass::arka_sis_far_getir(){
	return &arka_sis_far;
}

IkazLambaClass *YoneticiClass::dortlu_getir(){
	return &dortlu;
}

IkazLambaClass *YoneticiClass::fren_devresi_ariza_getir(){
	return &fren_devresi_ariza;
}

IkazLambaClass *YoneticiClass::kisa_far_getir(){
	return &kisa_far;
}

IkazLambaClass *YoneticiClass::on_disk_fren_balata_getir(){
	return &on_disk_fren_balata;
}

IkazLambaClass *YoneticiClass::on_sis_far_getir(){
	return &on_sis_far;
}

IkazLambaClass *YoneticiClass::park_lamba_ikaz_getir(){
	return &park_lamba_ikaz;
}

IkazLambaClass *YoneticiClass::sag_sinyal_getir(){
	return &sag_sinyal;
}

IkazLambaClass *YoneticiClass::sogutma_suyu_ikaz_getir(){
	return &sogutma_suyu_ikaz;
}

IkazLambaClass *YoneticiClass::sol_sinyal_getir(){
	return &sol_sinyal;
}

IkazLambaClass *YoneticiClass::uzun_far_getir(){
	return &uzun_far;
}

IkazLambaClass *YoneticiClass::yag_ikaz_getir(){
	return &yag_ikaz;
}

IkazLambaClass *YoneticiClass::yakit_ikaz_getir(){
	return &yakit_ikaz;
}

GostergeCubukClass *YoneticiClass::hiz_gosterge_cubuk_getir() {
	return &hiz_gosterge_cubuk;
}

GostergeCubukClass *YoneticiClass::devir_gosterge_cubuk_getir() {
	return &devir_gosterge_cubuk;
}

GostergeCubukClass *YoneticiClass::yakit_gosterge_cubuk_getir() {
	return &yakit_gosterge_cubuk;
}

GostergeCubukClass *YoneticiClass::su_sicaklik_gosterge_cubuk_getir() {
	return &su_sicaklik_gosterge_cubuk;
}

void YoneticiClass::motor_durumu_degistir() {

	motor_durumu = !motor_durumu;
}

void YoneticiClass::hizlan() {

};

void YoneticiClass::araba_calisma_hali() {

	if (motor_durumu == true) {

		int tmp_aci = hiz_gosterge_cubuk_getir()->aci_getir();

		if (hizlaniyor_mu == true){	//Birinci Vites
			if (64 < tmp_aci && tmp_aci <= 88) {
				if (tmp_aci == 88) {
					devir_gosterge_cubuk_getir()->aci_ayarla(80);
				}

				yakit_gosterge_cubuk.aci_azalt(0.05);
				devir_gosterge_cubuk_getir()->aci_artir(2);
			}
			//ikinci vites
			else if (88 < tmp_aci && tmp_aci <= 111) {
				if (tmp_aci == 111) {
					devir_gosterge_cubuk_getir()->aci_ayarla(80);
				}

				yakit_gosterge_cubuk.aci_azalt(0.07);
				devir_gosterge_cubuk_getir()->aci_artir(2);
			}
			//ucuncu vites
			else if (111 < tmp_aci && tmp_aci <= 135) {
				if (tmp_aci == 135) {
					devir_gosterge_cubuk_getir()->aci_ayarla(80);
				}

				yakit_gosterge_cubuk.aci_azalt(0.09);
				devir_gosterge_cubuk_getir()->aci_artir(2);
			}
			//dorduncu vites
			else if (135 < tmp_aci && tmp_aci <= 158) {
				if (tmp_aci == 158) {
					devir_gosterge_cubuk_getir()->aci_ayarla(80);
				}

				yakit_gosterge_cubuk.aci_azalt(0.11);
				devir_gosterge_cubuk_getir()->aci_artir(2);
			}
			else if (158 < tmp_aci) {
				yakit_gosterge_cubuk.aci_azalt(0.13);
				devir_gosterge_cubuk_getir()->aci_artir((float)0.5);

			}
			else {
				devir_gosterge_cubuk_getir()->aci_azalt();
			}

			if( devir_gosterge_cubuk_getir()->aci_getir() >= 170 ){
				devir_gosterge_cubuk_getir()->aci_ayarla(devir_gosterge_cubuk.aci_getir() - 1);
			}

			if( hiz_gosterge_cubuk_getir()->aci_getir() >= 298 ){
				hiz_gosterge_cubuk_getir()->aci_ayarla(hiz_gosterge_cubuk.aci_getir() - 2);
			}

			if (tmp_aci > 270){
				su_sicaklik_gosterge_cubuk.aci_artir(float (0.2));
			}
		}

		//Km sayaci ayarlari
		if (64 < tmp_aci && tmp_aci <= 88) {
			km_sayac_nesne->km_artir(0.1);
		}
		//ikinci vites
		else if (88 < tmp_aci && tmp_aci <= 111) {
			km_sayac_nesne->km_artir(0.2);
		}
		//ucuncu vites
		else if (111 < tmp_aci && tmp_aci <= 135) {
			km_sayac_nesne->km_artir(0.3);
		}
		//dorduncu vites
		else if (135 < tmp_aci && tmp_aci <= 158) {
			km_sayac_nesne->km_artir(0.4);
		}
		else if (158 < tmp_aci) {
			km_sayac_nesne->km_artir(0.5);
		}

		//Led işlemleri

		if(60 < yakit_gosterge_cubuk.aci_getir() && yakit_gosterge_cubuk.aci_getir() < 65) {
			yakit_ikaz.aktif_ayarla(true);
		}

		if(100 < su_sicaklik_gosterge_cubuk.aci_getir()) {
			sogutma_suyu_ikaz.aktif_ayarla(true);
		}

		if(yakit_gosterge_cubuk.aci_getir() <= yakit_gosterge_cubuk.aci_baslangic_getir()) {
			motor_durumu = false;
		}

		if(aku_durumu > 0) {
			aku_durumu -= 1;
			cout << aku_durumu << endl;
		} else {
			aku_sarj.aktif_ayarla(true);
		}

	}
	else {
		devir = 0;
		hiz = 0;
		su_sicakligi = 0;
		yakit_miktari = 0;
		vites = 0;

		aku_sarj_getir()->aktif_ayarla(0);
		arka_cam_rezistans_getir()->aktif_ayarla(0);
		arka_sis_far_getir()->aktif_ayarla(0);
		dortlu_getir()->aktif_ayarla(0);
		fren_devresi_ariza_getir()->aktif_ayarla(0);
		kisa_far_getir()->aktif_ayarla(0);
		on_disk_fren_balata_getir()->aktif_ayarla(0);
		on_sis_far_getir()->aktif_ayarla(0);
		park_lamba_ikaz_getir()->aktif_ayarla(0);
		sag_sinyal_getir()->aktif_ayarla(0);
		sogutma_suyu_ikaz_getir()->aktif_ayarla(0);
		sol_sinyal_getir()->aktif_ayarla(0);
		uzun_far_getir()->aktif_ayarla(0);
		yag_ikaz_getir()->aktif_ayarla(0);
		yakit_ikaz_getir()->aktif_ayarla(0);

		hiz_gosterge_cubuk_getir()->sifirla();
		devir_gosterge_cubuk_getir()->sifirla();
	}
}

void YoneticiClass::yakit_ekle() {
	yakit_gosterge_cubuk.aci_ayarla( yakit_gosterge_cubuk.aci_sinir_getir() );
	yakit_ikaz.aktif_ayarla(false);
}

YoneticiClass::~YoneticiClass()
{
	km_sayac_nesne->dosya_yaz();
}
