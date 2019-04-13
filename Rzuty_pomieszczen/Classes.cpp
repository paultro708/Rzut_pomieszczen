#include "Classes.h"



void Element::rysuj(RenderWindow & window)
{

	window.draw(obrazek);
}

void Element::obroc(float obrot)
{
	this->pozycja_obrotu += obrot;
	this->obrazek.setRotation(pozycja_obrotu);

}

void Element::przesunLewo(float krok)
{
	this->Xpos -= krok;
	//this->obrazek.move(-krok,0);

	this->obrazek.setPosition(Xpos, Ypos);
}

void Element::przesunPrawo(float krok)
{
	this->Xpos += krok;
	//this->obrazek.move(krok,0);

	this->obrazek.setPosition(Xpos, Ypos);
}

void Element::przesunDol(float krok)
{
	this->Ypos += krok;
//	this->obrazek.move(0, -krok);

	this->obrazek.setPosition(Xpos, Ypos);
}
void Element::przesunGora(float krok)
{
	this->Ypos -= krok;
	//this->obrazek.move(0,krok);
	this->obrazek.setPosition(Xpos, Ypos);
}

///Meble



void Mebel::koloruj(int wybrany)
{


	Color bialyK = Color(255, 255, 255, 255);
	Color zoltyK = Color(255, 255, 0, 255);
	Color pomaranczowyK = Color(255, 165, 0, 255);
	Color czerwonyK = Color(255, 0, 0, 255);
	Color rozowyK = Color(255, 105, 180, 255);
	Color fioletowyK = Color(128, 0, 128, 255);
	Color niebieskiK = Color(0, 0, 255, 255);
	Color blekitnyK = Color(135, 206, 235, 255);
	Color zielonyK = Color(0, 128, 0, 255);
	Color szaryK = Color(128, 128, 128, 255);
	Color czarnyK = Color(22, 22, 22, 255);

	tabKolor[bialy] = bialyK;
	tabKolor[zolty] = zoltyK;
	tabKolor[pomaranczowy] = pomaranczowyK;
	tabKolor[czerwony] = czerwonyK;
	tabKolor[rozowy] = rozowyK;
	tabKolor[fioletowy] = fioletowyK;
	tabKolor[niebieski] = niebieskiK;
	tabKolor[blekitny] = blekitnyK;
	tabKolor[zielony] = zielonyK;
	tabKolor[szary] = szaryK;
	tabKolor[czarny] = czarnyK;

	this->k = tabKolor[wybrany];
	this->obrazek.setColor(k);

}







//






Fotel::Fotel()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Krzeslo::Krzeslo()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}
Sofa::Sofa()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}


Lozko1os::Lozko1os()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Lozko2os::Lozko2os()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

SzafkaNocna::SzafkaNocna()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

SzafkaRTV::SzafkaRTV()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Szafka::Szafka()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Szafa::Szafa()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

StolikKawowy::StolikKawowy()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

StolDuzy::StolDuzy()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

StolOkragly::StolOkragly()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}


//inne



Okno::Okno()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Drzwi::Drzwi()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Lodowka::Lodowka()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}

Pralka::Pralka()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Prysznic::Prysznic()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}
WC::WC()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Wanna::Wanna()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}

Kuchenka::Kuchenka()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

Zlew1kom::Zlew1kom()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}

Zlew2kom::Zlew2kom()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));
}

void Umywalka::wczytaj_plik()
{
	if (plik) {
		this->tekstura.loadFromFile(plik);
		this->obrazek.setTexture(tekstura);
	}
}
Umywalka::Umywalka()
{
	wczytaj_plik();
	obrazek.setPosition(Vector2f(0, 0));

}






//Lista





Element* Lista::checkN(int numer) {
	Element* nowy;
	switch (numer) {
	case 1:
		return nowy = new Okno();
	case 2:
		return nowy = new Drzwi();
	case 3:
		return nowy = new Kuchenka();
	case 4:
		return nowy = new Lodowka();
	case 5:
		return nowy = new Zlew1kom();
	case 6:
		return nowy = new Zlew2kom();
	case 7:
		return nowy = new Pralka();
	case 8:
		return nowy = new Wanna();
	case 9:
		return nowy = new Prysznic();
	case 10:
		return nowy = new WC();
	case 11:
		return nowy = new Umywalka();
	case 12:
		return nowy = new Fotel();
	case 13:
		return nowy = new Krzeslo();
	case 14:
		return nowy = new Sofa();
	case 15:
		return nowy = new Lozko1os();
	case 16:
		return nowy = new Lozko2os();
	case 17:
		return nowy = new Szafa();
	case 18:
		return nowy = new SzafkaRTV();
	case 19:
		return nowy = new SzafkaNocna();
	case 20:
		return nowy = new StolikKawowy();
	case 21:
		return nowy = new StolDuzy();
	case 22:
		return nowy = new StolOkragly();
	case 23:
		return nowy = new Szafka();

	}
}

Lista::~Lista() {
	while (head)
	{
		Wezel* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int Lista::sizeOfList() { //zwraca liczbe elementow w liscie
	int size = 0;
	Wezel* tmp = head;
	while (tmp) {
		size++;
		tmp = tmp->next;
	}
	return size;
}

void Lista::rysujListe(RenderWindow &window)
{
	Wezel* tmp = head;
	if (tmp) {
		for (tmp; tmp != NULL; tmp = tmp->next)
			//while (tmp);
		{
			tmp->elem->rysuj(window);
			//tmp = tmp->next;
		}
	}
}

void Lista::dodaj(int numer) //wstawia do listy element w zaleznosci od numeru
{
	Element* el = NULL;
	el = checkN(numer);



	Wezel* nowy = new Wezel(el);
	nowy->next = head;
	head = nowy;

}

void Lista::usunEl(Wezel* doUsuniecia) {
	Wezel* tmp = head;
	if (tmp == doUsuniecia) //jesli to glowa
	{
		head = tmp->next;
		delete doUsuniecia;
	}
	else {
		while (tmp->next != doUsuniecia)
			tmp = tmp->next;
		tmp->next = doUsuniecia->next;
		delete doUsuniecia;
	}
}

void Lista::usunEl(Element* doUsuniecia) {
	Wezel* WdoUsuniecia = znajdzWezel(doUsuniecia);
	usunEl(WdoUsuniecia);
}

Wezel* Lista::znajdzWezel(Element* szukany)
{
	Wezel*tmp = head;
	while (tmp->elem != szukany)
		tmp = tmp->next;
	return tmp;

}

Element* Lista::wybrano(const Vector2f klik)  //zwraca element na ktory kliknieto( przekazana pozycja klikniecia
{
	Wezel* tmp = head;
	while (tmp)
	{
		if (tmp->elem->bounds().contains(klik)) {
			return tmp->elem;
		}
		else tmp = tmp->next;
	}
	return NULL;
}


void Lista::CheckEvent(Lista &list, Element* wybrany, Event &event, RenderWindow &window, stan &obecnyStan, float krokx, float kroky)
{
	if (!wybrany) return;
	if (obecnyStan == PLAN) {
		switch (event.type)
		{
		case Event::KeyReleased:
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code) {
					// zmiana pozycji
				case Keyboard::Left:
					wybrany->przesunLewo(20);
					break;
				case Keyboard::Right:
					wybrany->przesunPrawo(20);
					break;
				case Keyboard::Up:
					wybrany->przesunGora(20);
					break;
				case Keyboard::Down:
					wybrany->przesunDol(20);
					break;

					//obrot o 15 stopni
				case Keyboard::RShift:
					wybrany->obroc(15);
					break;


					//usuwanie
				case Keyboard::Delete:
					list.usunEl(wybrany);
					break;


					//kolorowanie
				case Keyboard::Num0:
					wybrany->koloruj(0);
					break;
				case Keyboard::Num1:
					wybrany->koloruj(1);
					break;
				case Keyboard::Num2:
					wybrany->koloruj(2);
					break;
				case Keyboard::Num3:
					wybrany->koloruj(3);
					break;
				case Keyboard::Num4:
					wybrany->koloruj(4);
					break;
				case Keyboard::Num5:
					wybrany->koloruj(5);
					break;
				case Keyboard::Num6:
					wybrany->koloruj(6);
					break;
				case Keyboard::Num7:
					wybrany->koloruj(7);
					break;
				case Keyboard::Num8:
					wybrany->koloruj(8);
					break;
				case Keyboard::Num9:
					wybrany->koloruj(9);
					break;
				case Keyboard::Hyphen:
					wybrany->koloruj(10);
					break;
				}
			}break;
		}
	}
}






