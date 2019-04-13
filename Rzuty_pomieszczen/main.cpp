#include <SFML/Graphics.hpp>
#include "Classes.h"
#include "Menu.h"


const int n = 80;    // skala

int main()
{
	//wczytanie wielkosci pomieszczenia
	cout << "Podaj wymiary pomieszczenia w metrach " << endl;
	cout << "szerokosc: ";
	float W, H;
	cin >> W;
	cout << "wysokokosc: ";
	cin >> H;

	cout << "Kliknij na obiekt, by zmienic jego parametry " << endl;
	cout << "Zmiana polozenia - STRZALKI " << endl;
	cout << "Obrot - Lewy SHIFT " << endl;
	cout << "Zmiana koloru " << endl;
	cout << "1 - zolty " << endl;
	cout << "2 - pomaranczowy " << endl;
	cout << "3 - czerwony " << endl;
	cout << "4 - rozowy " << endl;
	cout << "5 - fioletowy " << endl;
	cout << "6 - nebieski " << endl;
	cout << "7 - blekitny " << endl;
	cout << "8 - zielony " << endl;
	cout << "9 - szary" << endl;
	cout << "klawisz '-' - czarny " << endl;



	stan obecnyStan = MENU;

	Element* wybrany = NULL;

	float width = n * W; float height = n* H;

	const float krokx = width / n;
	const float kroky = height / n;

	RenderWindow window(VideoMode(width, height, 32), "Plan");//, Style::Fullscreen); 
	Menu menu(window.getSize().x, window.getSize().y);

	Lista lista;
	Event event;


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape))) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::F1) {
					obecnyStan = MENU;
					wybrany = NULL;
				}
				else if (event.key.code == Keyboard::F2) {
					obecnyStan = PLAN;

				}
			}
			if (obecnyStan == PLAN) {
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					Vector2f klik = (Vector2f)Mouse::getPosition(window);
					wybrany = lista.wybrano(klik);
				}
				lista.CheckEvent(lista, wybrany, event, window, obecnyStan, krokx, kroky);
			}
			if (obecnyStan == MENU) {
				menu.CheckEvent(menu, event, window, obecnyStan);
			}
		}
		window.clear(Color(255, 255, 255));


		if (obecnyStan == 1)
		{
		}
		switch (obecnyStan) {
		case MENU:
		{
			wybrany = NULL;
			menu.draw(window);
			break;
		}
		case PLAN:
		{
			lista.rysujListe(window);
			break;
		}
		case PLAN_PO_WYBRANIU:
		{
			wybrany = NULL;
			if (menu.kolejny) {
				lista.dodaj(menu.potwierdzony());
				menu.czyEnter = false;
			} //zmiana po wstawieniu elementu
			lista.rysujListe(window);
			obecnyStan = PLAN;
			break;
		}

		}

		window.display();
	}
	return 0;
}


