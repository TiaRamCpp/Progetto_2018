#pragma once

#include "GestioneUtenti.h"
#include "GestioneNotizie.h"
#include "FunzionalitàStatistiche.h"

#define ESCI 'Z'
#define SCELTA_NON_VALIDA 'N'
#define MENU_PRECEDENTE 'P'
#define MENU_PRINCIPALE 'M'
#define VALORE_DEFAULT '0'
#define UT_SEMPLICE 1
#define UT_AZIENDA 2
#define UT_GRUPPO 3

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
	//stampa menu pricipale (1 livello)
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
	//stampa menu aggiungi utenti (2 livello)
	cout << endl;
	cout << "1) Aggiungi Utente" << endl;
	cout << "2) Rimuovi Utente" << endl;
	cout << "3) Modifica Utente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuGestioneNotizie() 
{
	//stampa menu gestione notizie (2 livello)
	cout << endl;
	cout << "1) Aggiungi Notizia" << endl;
	cout << "2) Rimuovi Notizia" << endl;
	cout << "3) Aggiungi Reazione a Notizia" << endl;
	cout << "4) Rimuovi Reazione a Notizia" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";

}
void stampaMenuFunzionalitaStatistiche()
{
	//stampa menu funzionalità statistiche (2 livello)
	cout << endl;
	cout << "A) Numero utenti" << endl;
	cout << "B) Numero amici e parenti di ogni utente semplice" << endl;
	cout << "C) Numero utenti nati dopo una data" << endl;
	cout << "D) Numero dipendenti e consociate per ogni azienda" << endl;
	cout << "E) Numero di utenti per ogni gruppo" << endl;
	cout << "F) Azienda con il maggior numero di dipendenti" << endl;
	cout << "G) Notizia con piu' apprezzamenti" << endl;
	cout << "H) Notizia con piu' indignazioni" << endl;
	cout << "I) Utente con piu' amici" << endl;
	cout << "J) Utente con piu' conoscenze" << endl;
	cout << "K) Eta' media utenti semplici" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuRicerca()
{
	//stampo menu ricerca (2 livello)
	cout << endl;
	cout << "1) Albero genealogico" << endl;
	cout << "2) Lupi solitari" << endl;
	cout << "3) Simpatia" << endl;
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
void stampaModificaAttributiUtenteSemplice()
{
	//stampa menu modifica attributi utente semplice (3 liv)
	cout << endl;
	cout << "1) Nome" << endl;
	cout << "2) Cognome" << endl;
	cout << "3) Domicilio" << endl;
	cout << "4) Data di nascita" << endl;
	cout << "5) Telefono" << endl;
	cout << "6) E-mail" << endl;
	cout << MENU_PRECEDENTE << ") Torna al Menu Precedente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaModificaAttributiUtenteAzienda()
{
	//stampa menu modifica attributi utente azienda (3 liv)
	cout << endl;
	cout << "1) Nome" << endl;
	cout << "2) Sede fiscale" << endl;
	cout << "3) Sede operativa" << endl;
	cout << "4) Data di creazione" << endl;
	cout << "5) Tipologia prodotto" << endl;
	cout << "6) Telefono" << endl;
	cout << "7) E-mail" << endl;
	cout << MENU_PRECEDENTE << ") Torna al Menu Precedente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaModificaAttributiUtenteGruppo()
{
	//stampa menu modifica attributi utente gruppo (3 liv)
	cout << endl;
	cout << "1) Nome" << endl;
	cout << "2) Sede operativa" << endl;
	cout << "3) Data di creazione" << endl;
	cout << "4) Tipologia attivita'" << endl;
	cout << "5) Telefono" << endl;
	cout << "6) E-mail" << endl;
	cout << MENU_PRECEDENTE << ") Torna al Menu Precedente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}

//gestione scelte menu
// 3 Livello
bool sceltaAttributiModificaUtenteSemplice(char &scelta_2, vector<UtenteSemplice> &persona)
{
	//menu attributi modific utente sempilice (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteSemplice();

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
			//modifica nome

		}
		break;
		case '2':
		{
			//modifica cognome
		}
		break;
		case '3':
		{
			//modifica domicilio
		}
		break;
		case '4':
		{
			//modifica data di nascita
		}
		break;
		case '5':
		{
			//modifica telefono
		}
		break;
		case '6':
		{
			//modifica email
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
bool sceltaAttributiModificaUtenteAzienda(char &scelta_2, vector<UtenteAzienda> &impresa)
{
	//menu attributi modific utente sazienda (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteAzienda();

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
			//modifica nome

		}
		break;
		case '2':
		{
			//modifica sede fiscale
		}
		break;
		case '3':
		{
			//modifica sede operativa
		}
		break;
		case '4':
		{
			//modifica data di creazione
		}
		break;
		case '5':
		{
			//modifica tipologia prodotto
		}
		break;
		case '6':
		{
			//modifica telefono
		}
		break;
		case '7':
		{
			//modifica email
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
bool sceltaAttributiModificaUtenteGruppo(char &scelta_2, vector<UtenteGruppo> &associazione)
{
	//menu attributi modific utente gruppo (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteAzienda();

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
			//modifica nome

		}
		break;
		case '2':
		{
			//modifica sede operativa
		}
		break;
		case '3':
		{
			//modifica data di creazione
		}
		break;
		case '4':
		{
			//modifica tipologia attività
		}
		break;
		case '5':
		{
			//modifica telefono
		}
		break;
		case '6':
		{
			//modifica email
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
bool sceltaMenuAggiungiUtenti(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
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
			//aggiungi utente semplice

		}
		break;
		case '2':
		{
			//aggiungi utente azienda
		}
		break;
		case '3':
		{
			//aggiungi utente gruppo
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

// 2 livello
bool ricercaIdUtenteRimuovi(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//inserisco id e cerco se esistente, a che tipologia appartiene e lo rimuovo (2/3 liv)
	string id;
	bool modifica = false;
	bool valido = false;
	int tipo_utente;

	cout << "Inserire id utente da rimuovere:" << endl;
	//eseguo richiesta fino a che non trovo un id esistente
	while (!valido)
	{
		getline(cin, id);

		//cerco se esiste utente e tipologia
		if (idUtenteTrovato(persona, impresa, associazione, id)) {
			if (idUtenteSempliceTrovato(persona, id))
			{
				tipo_utente = UT_SEMPLICE;
				valido = true;
			}
			if (idUtenteAziendaTrovato(impresa, id))
			{
				tipo_utente = UT_AZIENDA;
				valido = true;
			}
			if (idUtenteGruppoTrovato(associazione, id))
			{
				tipo_utente = UT_GRUPPO;
				valido = true;
			}
		}
		if (!valido)
		{
			cout << "Id non esistente, inserirne un altro: " << endl;
		}
	}

	//entro in menu diversi in base al tipo di utente
	switch (tipo_utente)
	{
	case UT_SEMPLICE:
	{
		//modifico utente semplice
		modifica = utenteSempliceRimuovi(persona, news, id);

	}
	break;
	case UT_AZIENDA:
	{
		//modifico utente azienda
		modifica = utenteAziendaRimuovi(impresa, news, id);
	}
	break;
	case UT_GRUPPO:
	{
		//modifico utente gruppo
		modifica = utenteGruppoRimuovi(associazione, news, id);
	}
	break;
	}
	return modifica;
}
bool ricercaIdUtenteModifica(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//inserisco id e cerco se esistente e a che tipologia appartiene (2/3 liv)
	string id;
	bool modifica = false;
	bool valido = false;
	int tipo_utente;

	cout << "Inserire id utente da modificare:" << endl;
	//eseguo richiesta fino a che non trovo un id esistente
	while (!valido)
	{
		getline(cin, id);

		//cerco se esiste utente e tipologia
		if (idUtenteTrovato(persona, impresa, associazione, id)) {
			if (idUtenteSempliceTrovato(persona, id))
			{
				tipo_utente = UT_SEMPLICE;
				valido = true;
			}
			if (idUtenteAziendaTrovato(impresa, id))
			{
				tipo_utente = UT_AZIENDA;
				valido = true;
			}
			if (idUtenteGruppoTrovato(associazione, id))
			{
				tipo_utente = UT_GRUPPO;
				valido = true;
			}
		}
		if (!valido)
		{
			cout << "Id non esistente, inserirne un altro: " << endl;
		}
	}

	//entro in menu diversi in base al tipo di utente
	switch (tipo_utente)
	{
	case UT_SEMPLICE:
	{
		//modifico utente semplice
		modifica = sceltaAttributiModificaUtenteSemplice(scelta_2, persona);

	}
	break;
	case UT_AZIENDA:
	{
		//modifico utente azienda
		modifica = sceltaAttributiModificaUtenteAzienda(scelta_2, impresa);
	}
	break;
	case UT_GRUPPO:
	{
		//modifico utente gruppo
		modifica = sceltaAttributiModificaUtenteGruppo(scelta_2, associazione);
	}
	break;
	}
	return modifica;
}
bool sceltaMenuGestioneUtenti(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
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
			modifica = sceltaMenuAggiungiUtenti(scelta_2,persona,impresa,associazione);
		}
		break;
		case '2':
		{
			//rimuovi utente
			modifica=ricercaIdUtenteRimuovi(scelta_2, persona, impresa, associazione, news);
		}
		break;
		case'3':
		{
			//modifica utente
			modifica = ricercaIdUtenteModifica(scelta_2, persona, impresa, associazione);
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
bool sceltaMenuGestioneNotizie(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione notizie (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;

	//stampo menu gestione notizie
	stampaMenuGestioneNotizie();


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
			//aggiungi notizia
			modifica = aggiungiNotizia(news, persona, impresa, associazione);
		}
		break;
		case '2':
		{
			//rimuovi notizia
			modifica = rimuoviNotizia(news);
		}
		break;
		case'3':
		{
			//aggiungi reazione a notizia
			modifica = aggiungiReazioneNotizia(news, persona, impresa, associazione);
		}
		break;
		case'4':
		{
			//aggiungi reazione a notizia
			modifica = rimuoviReazioneNotizia(news);
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
bool sceltaMenuFunzionalitaStatistiche(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione funzionalità statistiche (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;

	//stampo menu gestione funzionalità statistiche
	stampaMenuFunzionalitaStatistiche();


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
		case 'A':
		{
			//numero utenti totali
			modifica = conteggioGenerale(persona, impresa, associazione);
			
		}
		break;
		case 'B':
		{
			//numero amici e parenti utente semplice
			
		}
		break;
		case'C':
		{
			//numero utenti nati dopo una data
			modifica = utentiDopoUnaData(persona, impresa, associazione);
			
		}
		break;
		case'D':
		{
			//numero dipendenti e consociate azienda
			
		}
		break;
		case'E':
		{
			//numero utenti per gruppo

		}
		break;
		case'F':
		{
			//azienda con più dipendenti

		}
		break;
		case'G':
		{
			//notizia con più apprezzamenti
			modifica = migliorNotizia(news);

		}
		break;
		case'H':
		{
			//notizia con più indignazioni
			modifica = peggiorNotizia(news);

		}
		break;
		case'I':
		{
			//utente con piu amici

		}
		case'J':
		{
			//utente con piu conoscenze

		}
		case'K':
		{
			//eta media utenti semplici
			modifica = etaMediaUtentiSemplici(persona);
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
bool sceltaMenuRicerca(char &scelta_2, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news) 
{
	//menu gestione ricerca (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;

	//stampo menu gestione ricerca
	stampaMenuRicerca();


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
			//albero genealogico
		}
		break;
		case '2':
		{
			//lupi solitari
		}
		break;
		case'3':
		{
			//simpatia
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

// 1 livello
bool sceltaMenuPrincipale(char &scelta_1, char &scelta_2, bool &esci, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu principale (1 livello)

	bool modifica = false;
	bool precedente = false;
	string str_azione_1;

	//controllo se c'è richiesta di tornare al menu precendente altrimenti pulisco scelte
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
			modifica = sceltaMenuGestioneUtenti(scelta_2,persona,impresa,associazione,news);
		}
		break;
		case '2':
		{
			//menu gestione relazioni
			//mancante
			scelta_1 = azione_1;
		}
		break;
		case '3':
		{
			//menu gestione notizie
			modifica = sceltaMenuGestioneNotizie(scelta_2, persona, impresa, associazione, news);
			scelta_1 = azione_1;
		}
		break;
		case '4':
		{
			//menu statistiche
			modifica = sceltaMenuFunzionalitaStatistiche(scelta_2, persona, impresa, associazione, news);
			scelta_1 = azione_1;
		}
		break;
		case '5':
		{
			//menu ricerche
			modifica = sceltaMenuRicerca(scelta_2, persona, impresa, associazione, news);
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
