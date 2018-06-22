#pragma once

#include "GestioneUtenti.h"
#include "GestioneRelazioni.h"
#include "GestioneNotizie.h"
#include "FunzionalitàStatistiche.h"
#include "FunzionalitàRicerca.h"

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
	//stampa menu funzionalità statistiche (2 livello)
	cout << endl;
	cout << "A) Numero utenti" << endl;
	cout << "B) Numero amici e parenti di ogni utente semplice" << endl;
	cout << "C) Numero utenti nati dopo una data" << endl;
	cout << "D) Numero dipendenti e consociate per ogni azienda" << endl;
	cout << "E) Numero di utenti per ogni gruppo" << endl;
	cout << "F) Azienda con il maggior numero di dipendenti diretti" << endl;
	cout << "G) Azienda con il maggior numero di dipendenti cumulativo con le consociate" << endl;
	cout << "H) Notizia con piu' apprezzamenti" << endl;
	cout << "I) Notizia con piu' indignazioni" << endl;
	cout << "J) Utente con piu' amici" << endl;
	cout << "K) Utente con piu' conoscenze" << endl;
	cout << "L) Eta' media utenti semplici" << endl;
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
	cout << "4) Telefono" << endl;
	cout << "5) E-mail" << endl;
	cout << "6) Data di nascita" << endl;
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
	cout << "4) Tipologia prodotto" << endl;
	cout << "5) Telefono" << endl;
	cout << "6) E-mail" << endl;
	cout << "7) Data di creazione" << endl;
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
	cout << "2) Sede legale" << endl;
	cout << "3) Tipologia attivita'" << endl;
	cout << "4) Telefono" << endl;
	cout << "5) E-mail" << endl;
	cout << "6) Data di creazione" << endl;
	cout << MENU_PRECEDENTE << ") Torna al Menu Precedente" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}

//gestione scelte menu
// 3 Livello
bool sceltaAttributiModificaUtenteSemplice(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, UtenteSemplice &persona)
{
	//menu attributi modific utente sempilice (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteSemplice();

	do
	{
		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_3);
		if (str_azione_3.size() == 1)
		{
			azione_3 = str_azione_3.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_3)) 
			{
				azione_3 = toupper(azione_3);
			}
		}

		switch (azione_3)
		{
		case '1':
		{
			//modifica nome
			modifica = utenteSempliceModificaNome(persona);
		}
		break;
		case '2':
		{
			//modifica cognome
			modifica = utenteSempliceModificaCognome(persona);
		}
		break;
		case '3':
		{
			//modifica domicilio
			modifica = utenteSempliceModificaDomicilio(persona);
		}
		break;
		case '4':
		{
			//modifica telefono
			modifica = utenteSempliceModificaTelefono(persona);
		}
		break;
		case '5':
		{
			//modifica email
			modifica = utenteSempliceModificaEmail(persona);
		}
		break;
		case '6':
		{
			//modifica data di nascita
			modifica = utenteSempliceModificaDataNascita(persona);
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
bool sceltaAttributiModificaUtenteAzienda(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, UtenteAzienda &impresa)
{
	//menu attributi modific utente sazienda (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteAzienda();

	do
	{
		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_3);
		if (str_azione_3.size() == 1)
		{
			azione_3 = str_azione_3.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_3)) 
			{
				azione_3 = toupper(azione_3);
			}
		}

		switch (azione_3)
		{
		case '1':
		{
			//modifica nome
			modifica = utenteAziendaModificaNome(impresa);
		}
		break;
		case '2':
		{
			//modifica sede fiscale
			modifica = utenteAziendaModificaSedeFiscale(impresa);
		}
		break;
		case '3':
		{
			//modifica sede operativa
			modifica = utenteAziendaModificaSedeOperativa(impresa);
		}
		break;
		case '4':
		{
			//modifica tipologia prodotto
			modifica = utenteAziendaModificaTipoProdotto(impresa);
		}
		break;
		case '5':
		{
			//modifica telefono
			modifica = utenteAziendaModificaTelefono(impresa);
		}
		break;
		case '6':
		{
			//modifica email
			modifica = utenteAziendaModificaEmail(impresa);
		}
		break;
		case '7':
		{
			//modifica data di creazione
			modifica = utenteAziendaModificaDataCreazione(impresa);
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
bool sceltaAttributiModificaUtenteGruppo(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, UtenteGruppo &associazione)
{
	//menu attributi modific utente gruppo (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	stampaModificaAttributiUtenteGruppo();

	do
	{
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
			modifica = utenteGruppoModificaNome(associazione);
		}
		break;
		case '2':
		{
			//modifica sede legale
			modifica = utenteGruppoModificaSedeLegale(associazione);
		}
		break;
		case '3':
		{
			//modifica tipologia attività
			modifica = utenteGruppoModificaDataCreazione(associazione);
		}
		break;
		case '4':
		{
			//modifica telefono
			modifica = utenteGruppoModificaTelefono(associazione);
		}
		break;
		case '5':
		{
			//modifica email
			modifica = utenteGruppoModificaEmail(associazione);
		}
		break;
		case '6':
		{
			//modifica data di creazione
			modifica = utenteGruppoModificaDataCreazione(associazione);
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
bool sceltaMenuAggiungiUtenti(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//menu gestione utenti (3 livello)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	//stampo menu gestione utenti
	stampaMenuAggiungiUtenti();

	//ripeti se scelta non valida
	do 
	{
		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_3);
		if (str_azione_3.size() == 1)
		{
			azione_3 = str_azione_3.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_3)) 
			{
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
	bool valido = true;

	cout << "Inserire id utente da rimuovere:" << endl;
	//eseguo richiesta fino a che non trovo un id esistente
	do	
	{
		valido = true;
		getline(cin, id);

		//cerco se esiste utente e tipologia
		if (idUtenteSempliceTrovato(persona, id))
		{
			//rimuovo utente semplice
			modifica = utenteSempliceRimuovi(persona, news, id);
		}
		else
		{
			if (idUtenteAziendaTrovato(impresa, id))
			{
				//rimuovo utente azienda
				modifica = utenteAziendaRimuovi(impresa, news, id);
			}
			else
			{
				if (idUtenteGruppoTrovato(associazione, id))
				{
					//rimuovi utente gruppo
					modifica = utenteGruppoRimuovi(associazione, news, id);
				}
				else
				{
					cout << "Id non esistente, inserirne un altro: " << endl;
					valido = false;
				}
			}	
		}
	} while (!valido);
	return modifica;
}
bool ricercaIdUtenteModifica(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//inserisco id e cerco se esistente e a che tipologia appartiene (2/3 liv)
	string id;
	bool modifica = false;
	bool valido = true;
	unsigned int posizione = 0;

	cout << "Inserire id utente da modificare:" << endl;
	//eseguo richiesta fino a che non trovo un id esistente
	do
	{
		valido = true;
		getline(cin, id);

		//cerco se esiste utente e tipologia
		if (idUtenteSempliceTrovato(persona, id))
		{
			//trovo posizione
			posizione = utenteSemplicePosizione(persona, id);
			//modifico utente semplice
			modifica = sceltaAttributiModificaUtenteSemplice(torna_al_menu_precedente, torna_al_menu_principale, persona[posizione]);
		}
		else
		{
			if (idUtenteAziendaTrovato(impresa, id))
			{
				//trovo posizione
				posizione = utenteAziendaPosizione(impresa, id);
				//modifico utente azienda
				modifica = sceltaAttributiModificaUtenteAzienda(torna_al_menu_precedente, torna_al_menu_principale, impresa[posizione]);
			}
			else
			{
				if (idUtenteGruppoTrovato(associazione, id))
				{
					//trovo posizione
					posizione = utenteGruppoPosizione(associazione, id);
					//modifico utente gruppo
					modifica = sceltaAttributiModificaUtenteGruppo(torna_al_menu_precedente, torna_al_menu_principale, associazione[posizione]);
				}
				else
				{
					cout << "Id non esistente, inserirne un altro: " << endl;
					valido = false;
				}
			}
		}
	} while (!valido);
	return modifica;
}
bool sceltaMenuGestioneUtenti(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//menu gestione utenti (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;

	do 
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuGestioneUtenti();
		}
		torna_al_menu_precedente = false;

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_2);
		if (str_azione_2.size() == 1)
		{
			azione_2 = str_azione_2.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_2))
			{
				azione_2 = toupper(azione_2);
			}
		}
		else 
		{
			azione_2 = SCELTA_NON_VALIDA;
		}

		switch (azione_2)
		{
		case '1':
		{
			//aggiungi utente
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
	do 
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuGestioneNotizie();
		}
		torna_al_menu_precedente = false;

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_2);
		if (str_azione_2.size() == 1)
		{
			azione_2 = str_azione_2.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_2)) 
			{
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
	//menu gestione funzionalità statistiche (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;

	//ripeti se scelta non valida
	do
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuFunzionalitaStatistiche();
		}
		torna_al_menu_precedente = false;

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_2);
		if (str_azione_2.size() == 1)
		{
			azione_2 = str_azione_2.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_2))
			{
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
			modifica = numeroDipendentiEConsociatePerAzienda(impresa);
		}
		break;
		case'E':
		{
			//numero utenti per gruppo
			modifica = numeroUtentiPerGruppo(associazione);
		}
		break;
		case'F':
		{
			//azienda con più dipendenti diretti
			modifica = aziendaMaggiorDipendenti(impresa, false); //false per non contare i dipendenti delle consociate
		}
		break;
		case'G':
		{
			//azienda con più dipendenti cumulativi con le consociate
			modifica = aziendaMaggiorDipendenti(impresa, true); //true per contare i dipendenti delle consociate
		}
		break;
		case'H':
		{
			//notizia con più apprezzamenti
			modifica = migliorNotizia(news);
		}
		break;
		case'I':
		{
			//notizia con più indignazioni
			modifica = peggiorNotizia(news);
		}
		break;
		case'J':
		{
			//utente con piu amici
			modifica = utenteSempliceMaggiorAmici(persona);
		}
		break;
		case'K':
		{
			//utente con piu conoscenze
			modifica = utenteSempliceMaggiorConoscenze(persona);
		}
		break;
		case'L':
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
	do
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuRicerca();
		}
		torna_al_menu_precedente = false;

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_2);
		if (str_azione_2.size() == 1)
		{
			azione_2 = str_azione_2.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_2))
			{
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

	do 
	{
		if (torna_al_menu_principale) 
		{
			stampaMenuPrincipale();
		}
		torna_al_menu_principale = false;

		//leggo carattere e se non valido non lo considero
		getline(cin, str_azione_1);
		if (str_azione_1.size() == 1)
		{
			azione_1 = str_azione_1.front();
			//converto in  maiuscolo se minuscolo
			if (islower(azione_1))
			{
				azione_1 = toupper(azione_1);
			}
		}
		else 
		{
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
