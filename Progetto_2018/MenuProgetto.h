#pragma once

#include "GestioneUtenti.h"
#include "GestioneNotizie.h"
#include "Funzionalit‡Statistiche.h"

#define ESCI 'E'
#define SCELTA_NON_VALIDA 'N'
#define MENU_PRECEDENTE 'P'
#define MENU_PRINCIPALE 'M'
#define VALORE_DEFAULT '0'

using namespace std;

//funzioni per cercare valori di ritorno
bool trovaRitornoMenuPrincipale(char &scelta_2)
{
	//cerca condizione per tornare al menu principale
	bool menu_principale = false;
	if (scelta_2 == MENU_PRINCIPALE)
	{
		menu_principale = true;
	}

	return menu_principale;
}
bool trovaRitornoMenuPrecedente(char &scelta_2)
{
	//cerca condizione per tornare al menu precednte
	bool menu_precedente = false;

	if (scelta_2 == MENU_PRECEDENTE)
	{
		menu_precedente = true;
	}

	return menu_precedente;
}

//stampe voci menu
void stampaMenuPrincipale()
{
	//stampa menu pricipale (1 liv)
	cout << endl;
	cout << "1) Gestione Utenti" << endl;
	cout << "2) Gestione Relazioni" << endl;
	cout << "3) Gestione Notizie" << endl;
	cout << "4) Statistiche" << endl;
	cout << "5) Ricerche" << endl;
	cout << ESCI << ") Esci" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuGestioneUtenti()
{
	//stampa menu aggiungi utenti (2 liv)
	cout << endl;
	cout << "1) Aggiungi Utente" << endl;
	cout << "2) Rimuovi Utente" << endl;
	cout << "3) Modifica Utente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuAggiungiUtenti()
{
	//stampa menu gestione utenti (3 liv)
	cout << endl;
	cout << "1) Aggiungi Utente Semplice" << endl;
	cout << "2) Aggiungi Utente Azienda" << endl;
	cout << "3) Aggiungi Utente Gruppo" << endl;
	cout << MENU_PRECEDENTE << ") Torna al Menu Precedente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}

//gestione scelte menu
bool sceltaMenuAggiungiUtenti(char &scelta_2)
{
	//menu gestione utenti (3 livello)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	//stampo menu gestione utenti
	stampaMenuAggiungiUtenti();

	//ripeti se scelta non valida
	while (azione_3 == SCELTA_NON_VALIDA) {

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_3);
		if (str_azione_3.size() == 1)
		{
			azione_3 = str_azione_3.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_3)) {
				azione_3 = toupper(azione_3);
			}
		}

		switch (azione_3)
		{
		case '1':
		{
			//aggiungi utente
			modifica = true;

		}
		break;
		case '2':
		{
			//rimuovi utente
		}
		break;
		case '3':
		{
			//modifica utente
		}
		break;
		case MENU_PRECEDENTE:
		{
			//torna al menu principale
			scelta_2 = azione_3;
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			scelta_2 = azione_3;
		}
		break;
		default:
		{
			//scelta non valida
			cout << "Opzione non valida" << endl;
			azione_3 = SCELTA_NON_VALIDA;
		}
		break;
		}
	}
	return modifica;
}
bool sceltaMenuGestioneUtenti(char &scelta_2)
{
	//menu gestione utenti (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;

	//stampo menu gestione utenti
	stampaMenuGestioneUtenti();


	//ripeti se scelta non valida
	while (azione_2 == SCELTA_NON_VALIDA) {


		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_2);
		if (str_azione_2.size() == 1)
		{
			azione_2 = str_azione_2.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_2)) {
				azione_2 = toupper(azione_2);
			}
		}

		switch (azione_2)
		{
		case '1':
		{
			//aggiungi utente
			modifica = sceltaMenuAggiungiUtenti(scelta_2);
		}
		break;
		case '2':
		{
			//rimuovi utente
		}
		break;
		case'3':
		{
			//modifica utente
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			scelta_2 = azione_2;
		}
		break;
		default:
		{
			//scelta non valida
			cout << "Opzione non valida" << endl;
			azione_2 = SCELTA_NON_VALIDA;
		}
		break;
		}
	}
	return modifica;
}
bool sceltaMenuPrincipale(char &scelta_1, char &scelta_2, bool &esci)
{
	//menu principale (1 livello)
	cout << scelta_2;

	bool modifica = false;
	bool precedente = false;
	string str_azione_1;

	//controllo se c'Ë richiesta di tornare al menu precendente altrimenti pulisco scelte
	if (trovaRitornoMenuPrecedente(scelta_2)) {
		precedente = true;
	}
	else {
		//pulisco e imposto tutti a default
		scelta_1 = VALORE_DEFAULT;
	}

	scelta_2 = VALORE_DEFAULT;

	//azione 1 livello
	char azione_1 = SCELTA_NON_VALIDA;

	//stampo menu principale se non devo tornare al menu precedente
	if ((!precedente) || (trovaRitornoMenuPrincipale(scelta_2)))
	{
		stampaMenuPrincipale();
	}

	//ripeti se scelta non valida
	while (azione_1 == SCELTA_NON_VALIDA) {

		//se voglio tornare a menu precedente non richiedo scelta
		if (precedente)
		{
			azione_1 = scelta_1;
			scelta_2 = '0';
		}

		if (azione_1 == SCELTA_NON_VALIDA)
		{
			//leggo carattere e se non valido non lo considero
			getline(cin, str_azione_1);
			if (str_azione_1.size() == 1)
			{
				azione_1 = str_azione_1.front();
				//converto in  maiuscolo se minuscolo
				if (islower(azione_1)) {
					azione_1 = toupper(azione_1);
				}
			}
		}

		switch (azione_1)
		{
		case '1':
		{
			//menu gestione utenti
			scelta_1 = azione_1;
			modifica = sceltaMenuGestioneUtenti(scelta_2);
		}
		break;
		case '2':
		{
			//menu gestione relazioni

			scelta_1 = azione_1;
		}
		break;
		case '3':
		{
			//menu gestione notizie

			scelta_1 = azione_1;
		}
		break;
		case '4':
		{
			//menu statistiche

			scelta_1 = azione_1;
		}
		break;
		case '5':
		{
			//menu ricerche
			scelta_1 = azione_1;

		}
		break;
		case ESCI:
		{
			//uscita
			esci = true;
		}
		break;
		default:
		{
			cout << "Opzione non valida" << endl;
			cout << "Selezionare nuovamente voce menu: ";
			azione_1 = SCELTA_NON_VALIDA;
		}
		break;
		}
	}
	return modifica;
}
