#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;



enum stan { MENU, PLAN, PLAN_PO_WYBRANIU };

#define NUMBER_OF_COLORS 11


typedef enum kolor {
	bialy = 0, zolty = 1, pomaranczowy = 2, czerwony = 3, rozowy = 4, fioletowy = 5,
	niebieski = 6, blekitny = 7, zielony = 8, szary = 9, czarny = 10
};


static Color tabKolor[NUMBER_OF_COLORS];

//void init_tabKolor();



//---------------------------------------------------------------------
//Klasa Element
//---------------------------------------------------------------------


class Element 
{
protected:
	char* plik=NULL;
	Color k = tabKolor[bialy];
	float Xpos=0, Ypos=0,  pozycja_obrotu; //pozycja elementu, wysokosc, szerokosc okna
	string sciezka;
	
	Texture tekstura;
	Sprite obrazek; //load from file

public:
	FloatRect bounds() {
		return obrazek.getGlobalBounds();
	}
	virtual void przesunLewo(float krok);
	virtual void przesunPrawo(float krok);
	virtual void przesunGora(float krok);
	virtual void przesunDol(float krok);
	virtual void obroc(float obrot);
	virtual void rysuj(RenderWindow &window);
	virtual void wczytaj_plik()=0;
	virtual void koloruj(int wybrany) = 0;
};


//---------------------------------------------------------------------
//Klasa Mebel
//---------------------------------------------------------------------

class Mebel :public virtual Element
{
protected:
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
public:
	void koloruj(int wybrany);
	

};


//---------------------------------------------------------------------
//Meble
//---------------------------------------------------------------------

class Fotel : public Mebel
{

public:
	Fotel(); //domyslnie
	~Fotel() { delete plik; };

protected:
	string sciezka = "png/fotel.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	
			 //Fotel(float x, float y, float skala); 
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	
};

class Sofa : public Mebel
{

public:
	string sciezka = "png/sofa.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	Sofa(); //domyslnie
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	~Sofa() { delete plik; };
};

class Lozko1os : public Mebel
{

public:
	Lozko1os(); //domyslnie
	~Lozko1os() { delete plik; };
protected:
	string sciezka = "png/lozko_1os.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	
};

class Lozko2os : public Mebel
{

public:
	Lozko2os(); //domyslnie
	~Lozko2os() { delete plik; };
protected:
	string sciezka = "png/lozko_2os.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania	
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	
};

class SzafkaNocna : public Mebel
{

public:
	SzafkaNocna(); //domyslnie
	~SzafkaNocna() { delete plik; };
protected:
	string sciezka = "png/szafka_nocna.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	
};

class SzafkaRTV : public Mebel
{

public:
	SzafkaRTV(); //domyslnie
	~SzafkaRTV() { delete plik; };
protected:
	string sciezka = "png/szafka_rtv.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	
};

class Szafka : public Mebel
{

public:
	Szafka(); //domyslnie
	~Szafka() { delete plik; };
protected:
	string sciezka = "png/szafka.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania


	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Szafa : public Mebel
{

public:
	Szafa(); //domyslnie
	~Szafa() { delete plik; };
protected:
	string sciezka = "png/szafa.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class StolikKawowy : public Mebel
{
public:
	StolikKawowy(); //domyslnie
	~StolikKawowy() { delete plik; };
protected:
	string sciezka = "png/stolik_kawowy.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania


	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};


class StolDuzy : public Mebel
{

public:
	StolDuzy(); //domyslnie
	~StolDuzy() { delete plik; };
protected:
	string sciezka = "png/stol_duzy.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class StolOkragly : public Mebel
{

public:
	StolOkragly(); //domyslnie
	~StolOkragly() { delete plik; };
protected:
	string sciezka = "png/stol_okragly.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};


class Krzeslo : public Mebel
{

public:
	Krzeslo(); //domyslnie
	~Krzeslo() { delete plik; };
protected:
	string sciezka = "png/krzeslo.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania	
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};







//inne
//



class Inne : public virtual Element {

public:
	virtual void koloruj(int wybrany) // musi byc bialy
	{
		this->k = tabKolor[bialy];
	}
protected:
	void wczytaj_plik() {
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Okno : public Inne
{

public:
	Okno(); //domyslnie
	~Okno() { delete plik; };
protected:
	string sciezka = "png/okno.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};



class Drzwi : public Inne
{

public:
	Drzwi(); //domyslnie
	~Drzwi() { delete plik; };
protected:
	string sciezka = "png/drzwiL.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Lodowka : public Inne
{

public:
	string sciezka = "png/lodowka.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	Lodowka(); //domyslnie
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
	~Lodowka() { delete plik; };
};

class Pralka : public Inne
{

public:
	Pralka(); //domyslnie
	~Pralka() { delete plik; };
protected:
	string sciezka = "png/pralka.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Prysznic : public Inne
{

public:
	Prysznic();
	~Prysznic() { delete plik; };
protected:
	string sciezka = "png/prysznic.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class WC : public Inne
{

public:
	WC(); //domyslnie
	~WC() { delete plik; };
protected:
	string sciezka = "png/wc.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};


class Kuchenka : public Inne
{

public:
	Kuchenka(); //domyslnie
	~Kuchenka() { delete plik; };
protected:
	string sciezka = "png/kuchenka.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Wanna : public Inne
{

public:
	Wanna(); //domyslnie
	~Wanna() { delete plik; };
protected:
	string sciezka = "png/wanna.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Zlew1kom : public Inne
{

public:
	Zlew1kom(); //domyslnie
	~Zlew1kom() { delete plik; };
protected:
	string sciezka = "png/zlew_1kom.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Zlew2kom : public Inne
{

public:
	Zlew2kom(); //domyslnie
	~Zlew2kom() { delete plik; };
protected:
	string sciezka = "png/zlew_2kom.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania

	void wczytaj_plik()
	{
		if (plik) {
			this->tekstura.loadFromFile(plik);
			this->obrazek.setTexture(tekstura);
		}
	}
};

class Umywalka : public Inne
{
public:
	Umywalka(); //domyslnie
	~Umywalka() { delete plik; };
protected:
	string sciezka = "png/umywalka.png";
	const char *plik = sciezka.c_str(); //potrzebne do przekazania
	void wczytaj_plik();
	
};





struct Wezel
{
	Element*elem;
	Wezel*next;

	Wezel(Element* el) : elem(el) {};
};


class Lista
{
protected:
//public:// dla spr public
	Wezel* head;
	Wezel* wybrany = NULL;
	int sizeOfList(); //zwraca liczbe elementow w liscie

public:
	Element* checkN(int numer); //zwraca element ktory nalezy dodac w zaleznosci od numeru
	Lista() :head(NULL) {} 
	void rysujListe(RenderWindow &window);
	void dodaj(int numer); //wstawia do listy element w zaleznosci od numeru
	void usunEl(Wezel* doUsuniecia); 
	void usunEl(Element* doUsuniecia);
	Wezel* znajdzWezel(Element* szukany);
	Element* wybrano(const Vector2f klik);  //zwraca element na ktory kliknieto( przekazana pozycja klikniecia
	void CheckEvent(Lista &list, Element* wybrany, Event &event, RenderWindow &window, stan &obecnyStan, float krokx, float kroky);
	~Lista();
	/*void draw(RenderWindow &window) //rysuje cala liste
	{
		Wezel* tmp = head;
		while( tmp)
		{
			window.draw(tmp->elem->obrazek);
			tmp = tmp->next;
		}

	}*/

};
