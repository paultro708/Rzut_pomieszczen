#pragma once
#include "SFML/Graphics.hpp"
#include "Classes.h"

#define MAX_NUMBER_OF_ITEMS 23

using namespace sf;
class Menu
{
public:
	bool kolejny = false;
	bool czyEnter=false; 
	
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow &window); //rysuje menu 
	void CheckEvent(Menu &menu, Event &event, RenderWindow &window, stan &obecnyStan); //reaguje na event- w zaleznosci od tego co robi uzytkownik
	void MoveUp(); //zmienia podswietlana (do wybrania) opcje wstawienia elementu na plan na znajdujacy sie u gory
	void MoveDown(); // -,- u dolu 
	int GetPressedItem() { return selectedItemIndex+1; }; //zwraca podswietlany wybor
	
	int potwierdzony()  // sprawdza czy podswietlony wybor zotal zatwierdzony enterem
	{
		if (czyEnter)
			return GetPressedItem();

	}
private:
	int selectedItemIndex;
	Font czcionka;
	Text menu[MAX_NUMBER_OF_ITEMS];

};
