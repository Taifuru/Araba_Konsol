#include "YoneticiClass.h"
#include <iostream>
using namespace std;

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_TIMER *timer_dortlu = NULL;

	if (!al_init()) {
		fprintf(stderr, "allegro baslatilirken hata olustu!\n");
		return -1;
	}
	
	if (!al_install_keyboard()) {
		fprintf(stderr, "keyboard modulu baslatilirken hata!\n");
		return -1;
	}
	
	timer = al_create_timer(1.0 / 20);
	timer_dortlu = al_create_timer(1.0/2);

	if (!timer) {
		fprintf(stderr, "timer baslatilirken hata!\n");
		return -1;
	}

	if(!timer_dortlu) {
		fprintf(stderr, "timer_dortlu baslatilirken hata!\n");
		return -1;
	}

	al_init_image_addon();

	al_init_font_addon();// Font addon başlatılıyor

	al_init_ttf_addon();// ttf addon başlatılıyor

	display = al_create_display(1100, 460);

	if (!display) {
		fprintf(stderr, "display olusturulamadi!\n");
		return -1;
	}

	//Event sirasi olusturduk
	event_queue = al_create_event_queue();
	if (!event_queue) {
		printf("Event olusturma hatasi");
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(timer_dortlu));

	//YoneticiClass yonetici_nesne = YoneticiClass();
	YoneticiClass araba_nesne = YoneticiClass("Kia Cerato");

	bool tus_basili = false;

	al_start_timer(timer);
	al_start_timer(timer_dortlu);

	while (1) {

		ALLEGRO_EVENT event_r;
		al_wait_for_event(event_queue, &event_r);
		
		if (event_r.type == ALLEGRO_EVENT_KEY_DOWN) {

			if (event_r.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				break;
			}
			else if(event_r.keyboard.keycode == ALLEGRO_KEY_UP) {
				tus_basili = true;
			}

			araba_nesne.tus_kontrol(event_r.keyboard.keycode);

		}
		else if (event_r.type == ALLEGRO_EVENT_KEY_UP) {
			tus_basili = false;

			if(event_r.keyboard.keycode == ALLEGRO_KEY_UP) {
				araba_nesne.hizlaniyor_mu = false;
			}

		}
		else if (event_r.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if(event_r.timer.source == timer_dortlu) {
			if( araba_nesne.dortlu_getir()->aktif_getir() == true ) {
				araba_nesne.sag_sinyal_getir()->durum_degistir();
				araba_nesne.sol_sinyal_getir()->durum_degistir();
			}
		}

		if (tus_basili) {
			araba_nesne.tus_kontrol_basili(event_r.keyboard.keycode);
		}else {
			if (event_r.timer.source == timer /*ALLEGRO_EVENT_TIMER*/) {
				araba_nesne.tus_kontrol_basili(ALLEGRO_KEY_DOWN);
				araba_nesne.devir_gosterge_cubuk_getir()->aci_azalt();
				araba_nesne.su_sicaklik_gosterge_cubuk_getir()->aci_azalt(0.1);
			}
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		araba_nesne.araba_calisma_hali();
		araba_nesne.ekrana_ciz();

		al_flip_display();

	}

	al_destroy_display(display);

	return 0;
}
