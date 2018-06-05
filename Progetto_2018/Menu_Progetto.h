#pragma once

#include <iostream>
#include <string>

using namespace std;

void menu_tipologia_utenti() {
	char u;

	cout << "S) Aggiungi Utente" << endl;
	cout << "A) Rimuovi Utente" << endl;
	cout << "G) Modifica Utente" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> u;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(u))
	{
		toupper(u);
	}


	switch (u)
	{
	case 'S':
	{

	}
	break;
	case 'A':
	{

	}
	break;
	case 'G':
	{

	}
	break;
	case 'P':
	{
		menu_gestione_utenti();
	}
	break;
	case 'E':
	{
		menu_principale();
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
}

void menu_gestione_utenti() {

	char a;

	cout << "A) Aggiungi Utente" << endl;
	cout << "R) Rimuovi Utente" << endl;
	cout << "M) Modifica Utente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> a;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(a))
	{
		toupper(a);
	}

	
		switch (a)
		{
		case 'A':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'R':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'M':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'E':
		{
			menu_principale();
		}
		break;
		default:
		{
			cout << "Opzione non valida" << endl;
		}
		break;
		}
	

}


void menu_principale() {
	char m;
	bool esci = false;

	while (esci==false) {
		//stampo voci menu
		cout << "1) Gestione Utenti" << endl;
		cout << "2) Gestione Relazioni" << endl;
		cout << "3) Gestione Notizie" << endl;
		cout << "4) Statistiche" << endl;
		cout << "5) Ricerche" << endl;
		cout << "6) Esci" << endl;
		cout << endl;
		cout << "Selezionare una voce del menu: ";
		cin >> m;
		cout << endl;

		//controllo ed eseguo operazione scelta
		switch (m) {
		case '1':
		{
			menu_gestione_utenti();
		}
		break;
		case '2':
		{

		}
		break;
		case '3':
		{

		}
		break;
		case '4':
		{

		}
		break;
		case '5':
		{

		}
		break;
		case '6':
		{
			esci = true;
		}
		break;
		default:
		{
			cout << "Opzione non valida" << endl;
			cout << endl;
		}
		break;
		}
	}

}




