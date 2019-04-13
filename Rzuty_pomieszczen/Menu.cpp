#include "Menu.h"


Menu::Menu(float width, float height) // do poprawienia - inicjalizacja w petli+ pozycja wyswietlenia
{
	if (!czcionka.loadFromFile("arial.ttf"))
	{
		string blad = "Nie udalo sie wczytac czcionki! ";
			//error
		throw blad;
	}

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setCharacterSize(15);
		menu[i].setFont(czcionka);
	}

	for (int i = 1; i < 11; i++)
	{
		int j = i+1;
		menu[i].setFillColor(Color::Black);
		menu[i].setPosition(Vector2f(0, height / (MAX_NUMBER_OF_ITEMS + 1) * j));
	}

	int j = 0;
	for (int i = 11; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		j++;
		menu[i].setFillColor(Color::Black);
		menu[i].setPosition(Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1) * j));
	}


	menu[0].setFillColor(Color::Red);
	menu[0].setString("Okno");
	menu[0].setPosition(Vector2f(0 , height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setString("Drzwi");
	menu[2].setString("Kuchenka");
	menu[3].setString("Lodowka");
	menu[4].setString("Zlew 1 komora");
	menu[5].setString("Zlew 2 komory");
	menu[6].setString("Pralka");
	menu[7].setString("Wanna");
	menu[8].setString("Prysznic");
	menu[9].setString("WC");
	menu[10].setString("Umywalka");
	menu[11].setString("Fotel");
	menu[12].setString("Krzeslo");
	menu[13].setString("Sofa");
	menu[14].setString("Lozko 1 osobowe");
	menu[15].setString("Lozko 2 osobowe");
	menu[16].setString("Szafa");
	menu[17].setString("Szafka RTV");
	menu[18].setString("Szafka nocna");
	menu[19].setString("Stolik kawowy");
	menu[20].setString("Stol duzy");
	menu[21].setString("Stol okragly");
	menu[22].setString("Szafka");
	

	selectedItemIndex = 0;
}



Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}



void Menu::CheckEvent(Menu &menu, Event &event, RenderWindow &window, stan &obecnyStan)
{
	if(obecnyStan==MENU){

	switch (event.type)
	{
	case Event::KeyReleased:
		switch (event.type)
		{
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
			{menu.MoveUp(); kolejny = true; }
				break;

			case Keyboard::Down:
				menu.MoveDown(); 
				break;

			case Keyboard::Return: 
			{
				kolejny = true;
				obecnyStan = PLAN_PO_WYBRANIU;
				czyEnter=true;
				break;
			}
			}
		}
		break;
	}
}
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
} 