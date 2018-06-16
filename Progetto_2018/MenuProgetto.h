#pragma once

#include "GestioneUtenti.h"
#include "GestioneNotizie.h"
#include "Funzionalit�Statistiche.h"

#define ESCI 'Z'
#define SCELTA_NON_VALIDA 'N'
#define MENU_PRECEDENTE 'P'
#define MENU_PRINCIPALE 'M'
#define VALORE_DEFAULT '0'
#define UT_SEMPLICE 1
#define UT_AZIENDA 2
#define UT_GRUPPO 3

using namespace std;

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
	//stampa menu funzionalit� statistiche (2 livello)
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
bool sceltaAttributiModificaUtenteSemplice(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona)
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
			//torna al menu precedente
			torna_al_menu_precedente = true;
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			torna_al_menu_principale = true;
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
bool sceltaAttributiModificaUtenteAzienda(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteAzienda> &impresa)
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
			//torna al menu precedente
			torna_al_menu_precedente = true;
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			torna_al_menu_principale = true;
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
bool sceltaAttributiModificaUtenteGruppo(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteGruppo> &associazione)
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
			//modifica tipologia attivit�
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
			//torna al menu precedente
			torna_al_menu_precedente = true;
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			torna_al_menu_principale = true;
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
bool sceltaMenuAggiungiUtenti(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//menu gestione utenti (3 livello)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	//stampo menu gestione utenti
	stampaMenuAggiungiUtenti();

	//ripeti se scelta non valida
	do {

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
			modifica = utenteSempliceAggiungi(persona, impresa, associazione);
		}
		break;
		case '2':
		{
			//aggiungi utente azienda
			modifica = utenteAziendaAggiungi(persona, impresa, associazione);
		}
		break;
		case '3':
		{
			//aggiungi utente gruppo
			modifica = utenteGruppoAggiungi(persona, impresa, associazione);
		}
		break;
		case MENU_PRECEDENTE:
		{
			//torna al menu precedente
			torna_al_menu_precedente = true;
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			torna_al_menu_principale = true;
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
	} while (azione_3 == SCELTA_NON_VALIDA);

	return modifica;
}

// 2 livello
bool ricercaIdUtenteRimuovi( bool &torna_al_menu_precedente,bool &torna_al_menu_principale,vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
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
bool ricercaIdUtenteModifica(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
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
		modifica = sceltaAttributiModificaUtenteSemplice(torna_al_menu_precedente, torna_al_menu_principale, persona);

	}
	break;
	case UT_AZIENDA:
	{
		//modifico utente azienda
		modifica = sceltaAttributiModificaUtenteAzienda(torna_al_menu_precedente, torna_al_menu_principale, impresa);
	}
	break;
	case UT_GRUPPO:
	{
		//modifico utente gruppo
		modifica = sceltaAttributiModificaUtenteGruppo(torna_al_menu_precedente, torna_al_menu_principale, associazione);
	}
	break;
	}
	return modifica;
}
bool sceltaMenuGestioneUtenti(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione utenti (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;



	do {

		if (torna_al_menu_precedente) {
			stampaMenuGestioneUtenti();
		}
		torna_al_menu_precedente = false;

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
		else {
			azione_2 = SCELTA_NON_VALIDA;
		}

		switch (azione_2)
		{
		case '1':
		{
			//aggiungi utente
			//modifica = sceltaMenuAggiungiUtenti(scelta_2, persona, impresa, associazione);
			modifica = sceltaMenuAggiungiUtenti(torna_al_menu_precedente, torna_al_menu_principale, persona, impresa, associazione);
		}
		break;
		case '2':
		{
			//rimuovi utente
			modifica = ricercaIdUtenteRimuovi(torna_al_menu_precedente, torna_al_menu_principale,persona, impresa, associazione, news);
		}
		break;
		case'3':
		{
			//modifica utente
			modifica = ricercaIdUtenteModifica(torna_al_menu_precedente, torna_al_menu_principale,persona, impresa, associazione);
		}
		break;
		case MENU_PRINCIPALE:
		{
			//torna al menu principale
			//scelta_2 = azione_2;
			torna_al_menu_principale = true;
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
	} while (azione_2 == SCELTA_NON_VALIDA || torna_al_menu_precedente);

	return modifica;
}
bool sceltaMenuGestioneNotizie(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione notizie (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;


	//ripeti se scelta non valida
	do {
		if (torna_al_menu_precedente) {
			stampaMenuGestioneNotizie();
		}
		torna_al_menu_precedente = false;

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
			torna_al_menu_principale = true;
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
	} while (azione_2 == SCELTA_NON_VALIDA || torna_al_menu_precedente);

	return modifica;
}
bool sceltaMenuFunzionalitaStatistiche(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione funzionalit� statistiche (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;



	//ripeti se scelta non valida
	do {
		if (torna_al_menu_precedente) {
			stampaMenuFunzionalitaStatistiche();
		}
		torna_al_menu_precedente = false;

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
			//azienda con pi� dipendenti

		}
		break;
		case'G':
		{
			//notizia con pi� apprezzamenti
			modifica = migliorNotizia(news);

		}
		break;
		case'H':
		{
			//notizia con pi� indignazioni
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
			torna_al_menu_principale = true;
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
	} while (azione_2 == SCELTA_NON_VALIDA || torna_al_menu_precedente);

	return modifica;
}
bool sceltaMenuRicerca(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione ricerca (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;


	//ripeti se scelta non valida
	do{
		if (torna_al_menu_precedente) {
			stampaMenuRicerca();
		}
		torna_al_menu_precedente = false;

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
			torna_al_menu_principale = true;
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
	} while (azione_2 == SCELTA_NON_VALIDA || torna_al_menu_precedente);

	return modifica;
}

// 1 livello
bool sceltaMenuPrincipale(bool &esci, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu principale (1 livello)

	bool modifica = false;
	bool torna_al_menu_principale = true;
	
	string str_azione_1;
	
	//azione 1 livello
	char azione_1 = SCELTA_NON_VALIDA;

	do {
		if (torna_al_menu_principale) {
			stampaMenuPrincipale();
		}
		torna_al_menu_principale = false;

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
		else {
			azione_1 = SCELTA_NON_VALIDA;
		}

		//selezione voce in base a scelta
		switch (azione_1)
		{
		case '1':
		{
			//menu gestione utenti
			modifica = sceltaMenuGestioneUtenti(torna_al_menu_principale, persona, impresa, associazione, news);
		}
		break;
		case '2':
		{
			//menu gestione relazioni
			//mancante
		}
		break;
		case '3':
		{
			//menu gestione notizie
			modifica = sceltaMenuGestioneNotizie(torna_al_menu_principale, persona, impresa, associazione, news);
		}
		break;
		case '4':
		{
			//menu statistiche
			modifica = sceltaMenuFunzionalitaStatistiche(torna_al_menu_principale, persona, impresa, associazione, news);
		}
		break;
		case '5':
		{
			//menu ricerche
			modifica = sceltaMenuRicerca(torna_al_menu_principale, persona, impresa, associazione, news);

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

	} while (azione_1 == SCELTA_NON_VALIDA || torna_al_menu_principale);


	return modifica;
}
