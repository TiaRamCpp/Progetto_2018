#pragma once

#include <iostream>
#include <string>

using namespace std;

//menu principale
void menu_tipologia_utenti(bool &torna_al_menu_precedente, bool &torna_al_menu_principale)
{
	//inizializzo variabili booleane per evitare di tornare a menu precedenti
	torna_al_menu_principale = false;
	torna_al_menu_precedente = false;
	
	char scelta_tipologia;

	cout << "S) Utente Semplice" << endl;
	cout << "A) Utente Azienda" << endl;
	cout << "G) Utente Gruppo" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_tipologia;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(scelta_tipologia))
	{
		scelta_tipologia=toupper(scelta_tipologia);
	}

	switch (scelta_tipologia)
	{
	case 'S':
	{
		//Utente semplice
	}
	break;
	case 'A':
	{
		//Utente Azienda
	}
	break;
	case 'G':
	{
		//Utente Gruppo
	}
	break;
	case 'P':
	{
		//torna al menu precedente
		torna_al_menu_precedente = true;
	}
	break;
	case 'E':
	{
		//torna al menu principale
		torna_al_menu_principale = true;
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
}

//menu gestione utenti
void menu_gestione_utenti(bool &torna_al_menu_precedente, bool &torna_al_menu_principale)
{
	//inizializzo variabili booleane per evitare di tornare a menu precedenti
	torna_al_menu_principale = false;
	torna_al_menu_precedente = false;
	
	char scelta_gestione;

	cout << "A) Aggiungi Utente" << endl;
	cout << "R) Rimuovi Utente" << endl;
	cout << "M) Modifica Utente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_gestione;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(scelta_gestione))
	{
		scelta_gestione=toupper(scelta_gestione);
	}

	switch (scelta_gestione)
	{
	case 'A':
	{
		//Tipologia da aggiungere
		menu_tipologia_utenti(torna_al_menu_precedente,torna_al_menu_principale);
	}
	break;
	case 'R':
	{
		//Tipologia da rimuovere
		menu_tipologia_utenti(torna_al_menu_precedente, torna_al_menu_principale);
	}
	break;
	case 'M':
	{
		//Tipologia da modificare
		menu_tipologia_utenti(torna_al_menu_precedente, torna_al_menu_principale);
	}
	break;
	case 'E':
	{
		//torna al menu principale
		torna_al_menu_principale = true;
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	//controllo se c'è richiesta di tornare al menu precedente e lo ricarico
	if (torna_al_menu_precedente)
		menu_gestione_utenti(torna_al_menu_precedente,torna_al_menu_principale);
}

//menu principale
void menu_principale()
{
	//variabili booleane che mi permettono di tornare indietro nei menu
	bool torna_al_menu_principale = false;
	bool torna_al_menu_precedente = false;
	
	char scelta_principale;

	//stampo voci menu
	cout << "1) Gestione Utenti" << endl;
	cout << "2) Gestione Relazioni" << endl;
	cout << "3) Gestione Notizie" << endl;
	cout << "4) Statistiche" << endl;
	cout << "5) Ricerche" << endl;
	cout << "6) Esci" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_principale;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(scelta_principale))
	{
		scelta_principale=toupper(scelta_principale);
	}

	switch (scelta_principale)
	{
	case '1':
	{
		//menu gestione utenti
		menu_gestione_utenti(torna_al_menu_precedente,torna_al_menu_principale);
	}
	break;
	case '2':
	{
		//menu gestione relazioni
	}
	break;
	case '3':
	{
		//menu gestione notizie
	}
	break;
	case '4':
	{
		//menu statistiche
	}
	break;
	case '5':
	{
		//menu ricerche
	}
	break;
	case '6':
	{
		//uscita
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	//controllo se c'è richiesta di tornare al menu pricipale e lo ricarico
	if (torna_al_menu_principale)
		menu_principale();
}
