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
#define SALVA 'S'

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
	cout << "6) Informazioni Database" << endl;
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
void stampaMenuGestioneRelazioni()
{
	//stampa menu gestione relazioni(2 livello)
	cout << endl;
	cout << "1) Aggiungi Relazione" << endl;
	cout << "2) Rimuovi Relazione" << endl;
	cout << "3) Modifica Relazione" << endl;
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
	cout << "A) Numero di utenti totali, numero di utenti semplici, azienda e gruppo" << endl;
	cout << "B) Numero di amici e parenti diretti di ogni utente semplice" << endl;
	cout << "C) Numero utenti nati/creati dopo una specifica data" << endl;
	cout << "D) Numero dipendenti e consociate per ogni azienda" << endl;
	cout << "E) Numero di utenti per ogni gruppo" << endl;
	cout << "F) Azienda con il maggior numero di dipendenti diretti" << endl;
	cout << "G) Azienda con il maggior numero di dipendenti cumulativo con le consociate" << endl;
	cout << "H) Notizia con il maggior numero di apprezzamenti" << endl;
	cout << "I) Notizia con il maggior numero di indignazioni" << endl;
	cout << "J) Utente col maggior numero di amici" << endl;
	cout << "K) Utente con il maggior numero di conoscenze" << endl;
	cout << "L) Eta' media degli utenti semplici" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuRicerca()
{
	//stampo menu ricerca (2 livello)
	cout << endl;
	cout << "1) Albero genealogico di Un'Utente" << endl;
	cout << "2) Albero genealogico di Tutti gli Utenti" << endl;
	cout << "3) Lupi solitari" << endl;
	cout << "4) Simpatia" << endl;
	cout << MENU_PRINCIPALE << ") Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}
void stampaMenuInformazioniDatabase()
{
	//stampo menu informazioni database (2 livello)
	cout << endl;
	cout << "A) Stampa Tutti i Dati" << endl;
	cout << "B) Stampa Tutti gli ID degli Utenti" << endl;
	cout << "C) Stampa Tutti gli Utenti" << endl;
	cout << "D) Stampa Tutti gli Utenti Semplici" << endl;
	cout << "E) Stampa Tutti gli Utenti Azienda" << endl;
	cout << "F) Stampa Tutti gli Utenti Gruppo" << endl;
	cout << "G) Stampa Tutte le Notizie" << endl;
	cout << "H) Stampa Tutte le Relazioni" << endl;
	cout << "I) Cerca un Utente" << endl;
	cout << "J) Cerca Notizie di un Utente" << endl;
	cout << "K) Cerca Notizie a cui un Utente ha messo una Reazione" << endl;
	cout << "L) Cerca Relazioni con un Utente" << endl;
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
	cout << SALVA << ") Salva modifiche" << endl;
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
	cout << SALVA << ") Salva modifiche" << endl;
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
	cout << SALVA << ") Salva modifiche" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
}

//gestione scelte menu

// 3 Livello
bool sceltaAttributiModificaUtenteSemplice(UtenteSemplice &persona)
{
	//menu attributi modific utente sempilice (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	do
	{
		stampaModificaAttributiUtenteSemplice();
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
		else
		{
			azione_3 = SCELTA_NON_VALIDA;
		}

		switch (azione_3)
		{
		case '1':
		{
			//modifica nome
			modifica |= utenteSempliceModificaNome(persona);
		}
		break;
		case '2':
		{
			//modifica cognome
			modifica |= utenteSempliceModificaCognome(persona);
		}
		break;
		case '3':
		{
			//modifica domicilio
			modifica |= utenteSempliceModificaDomicilio(persona);
		}
		break;
		case '4':
		{
			//modifica telefono
			modifica |= utenteSempliceModificaTelefono(persona);
		}
		break;
		case '5':
		{
			//modifica email
			modifica |= utenteSempliceModificaEmail(persona);
		}
		break;
		case '6':
		{
			//modifica data di nascita
			modifica |= utenteSempliceModificaDataNascita(persona);
		}
		break;
		case SALVA:
		{
			//salvo modifiche
			cout << "Modifiche salvate" << endl;
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
	} while (azione_3!=SALVA);

	return modifica;
}
bool sceltaAttributiModificaUtenteAzienda( UtenteAzienda &impresa)
{
	//menu attributi modific utente sazienda (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	

	do
	{
		stampaModificaAttributiUtenteAzienda();

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
		else
		{
			azione_3 = SCELTA_NON_VALIDA;
		}

		switch (azione_3)
		{
		case '1':
		{
			//modifica nome
			modifica |= utenteAziendaModificaNome(impresa);
		}
		break;
		case '2':
		{
			//modifica sede fiscale
			modifica |= utenteAziendaModificaSedeFiscale(impresa);
		}
		break;
		case '3':
		{
			//modifica sede operativa
			modifica |= utenteAziendaModificaSedeOperativa(impresa);
		}
		break;
		case '4':
		{
			//modifica tipologia prodotto
			modifica |= utenteAziendaModificaTipoProdotto(impresa);
		}
		break;
		case '5':
		{
			//modifica telefono
			modifica |= utenteAziendaModificaTelefono(impresa);
		}
		break;
		case '6':
		{
			//modifica email
			modifica |= utenteAziendaModificaEmail(impresa);
		}
		break;
		case '7':
		{
			//modifica data di creazione
			modifica |= utenteAziendaModificaDataCreazione(impresa);
		}
		break;
		case SALVA:
		{
			//salva modifiche ed esce
			cout << "Modifiche salvate" << endl;
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
	} while (azione_3!=SALVA);

	return modifica;
}
bool sceltaAttributiModificaUtenteGruppo( UtenteGruppo &associazione)
{
	//menu attributi modific utente gruppo (3 liv)
	string str_azione_3;
	bool modifica = false;
	char azione_3 = SCELTA_NON_VALIDA;

	

	do
	{
		stampaModificaAttributiUtenteGruppo();

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
		else
		{
			azione_3 = SCELTA_NON_VALIDA;
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
		case SALVA:
		{
			//salvo modifiche ed esco
			cout << "Modifiche salvate" << endl;
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
	} while (azione_3 != SALVA);

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
bool ricercaIdUtenteRimuovi(bool &torna_al_menu_precedente, bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news)
{
	//inserisco id e cerco se esistente e lo rimuovo
	string id_utente_da_rimuovere;
	bool modifica = false;

	//se c'è almeno un utente
	if (almenoUnUtenteEsistente(persona, impresa, associazione))
	{
		cout << "Inserire id utente da rimuovere:" << endl;
		getline(cin, id_utente_da_rimuovere);
		modifica = rimuoviUtente(persona, impresa, associazione, news, id_utente_da_rimuovere);
		//rimuove l'utente dalle l'elenco
		//rimuove tutte le notizie pubblicate da lui
		//rimuove tutte le reazioni messe da lui
		//rimuove tutte le relazioni con lui
	}
	else
	{
		cout << endl << "Nessun utente inserito nel database" << endl;
	}
	return modifica;
}
bool ricercaIdUtenteModifica(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//inserisco id e cerco se esistente e a che tipologia appartiene (2/3 liv)
	string id;
	bool modifica = false;
	unsigned int posizione = 0;

	//se c'è almeno un utente
	if (almenoUnUtenteEsistente(persona, impresa, associazione))
	{
		cout << "Inserire id utente da modificare:" << endl;
		//eseguo richiesta fino a che non trovo un id esistente

		getline(cin, id);

		//cerco se esiste utente e tipologia
		if (idUtenteSempliceTrovato(persona, id))
		{
			//trovo posizione
			posizione = utenteSemplicePosizione(persona, id);
			//modifico utente semplice
			modifica = sceltaAttributiModificaUtenteSemplice(persona[posizione]);
		}
		else
		{
			if (idUtenteAziendaTrovato(impresa, id))
			{
				//trovo posizione
				posizione = utenteAziendaPosizione(impresa, id);
				//modifico utente azienda
				modifica = sceltaAttributiModificaUtenteAzienda( impresa[posizione]);
			}
			else
			{
				if (idUtenteGruppoTrovato(associazione, id))
				{
					//trovo posizione
					posizione = utenteGruppoPosizione(associazione, id);
					//modifico utente gruppo
					modifica = sceltaAttributiModificaUtenteGruppo( associazione[posizione]);
				}
				else
				{
					cout << "Id non esistente" << endl;
				}
			}
		}
	}
	else
	{
		cout << endl << "Nessun utente inserito nel database" << endl;
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
			modifica = ricercaIdUtenteModifica(persona,impresa, associazione);
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
bool sceltaMenuGestioneRelazioni(bool &torna_al_menu_principale, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	//menu gestione relazioni (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;

	//ripeti se scelta non valida
	do
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuGestioneRelazioni();
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
			//aggiungi relazione
			modifica = aggiungiRelazione(persona, impresa, associazione);
		}
		break;
		case '2':
		{
			//rimuovi relazione
			modifica = rimuoviRelazione(persona, impresa, associazione);
		}
		break;
		case'3':
		{
			//modifica relazione
			modifica = modificaRelazione(persona, impresa, associazione);
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
bool sceltaMenuGestioneNotizie(bool &torna_al_menu_principale, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, vector<Notizia> &news)
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
bool sceltaMenuFunzionalitaStatistiche(bool &torna_al_menu_principale, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news)
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
			conteggioGenerale(persona, impresa, associazione);
		}
		break;
		case 'B':
		{
			//numero amici e parenti diretti per ogni utente semplice
			numeroAmiciEParentiDirettiPerUtenteSemplice(persona);
		}
		break;
		case'C':
		{
			//numero utenti nati dopo una data
			utentiDopoUnaData(persona, impresa, associazione);
		}
		break;
		case'D':
		{
			//numero dipendenti e consociate azienda
			numeroDipendentiEConsociatePerAzienda(impresa);
		}
		break;
		case'E':
		{
			//numero utenti per gruppo
			numeroUtentiPerGruppo(associazione);
		}
		break;
		case'F':
		{
			//azienda con più dipendenti diretti
			aziendaMaggiorDipendenti(impresa, false); //false per non contare i dipendenti delle consociate
		}
		break;
		case'G':
		{
			//azienda con più dipendenti cumulativi con le consociate
			aziendaMaggiorDipendenti(impresa, true); //true per contare i dipendenti delle consociate
		}
		break;
		case'H':
		{
			//notizia con più apprezzamenti
			migliorNotizia(news);
		}
		break;
		case'I':
		{
			//notizia con più indignazioni
			peggiorNotizia(news);
		}
		break;
		case'J':
		{
			//utente con piu amici
			utenteSempliceMaggiorAmici(persona);
		}
		break;
		case'K':
		{
			//utente con piu conoscenze
			utenteSempliceMaggiorConoscenze(persona);
		}
		break;
		case'L':
		{
			//eta media utenti semplici
			etaMediaUtentiSemplici(persona);
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
bool sceltaMenuRicerca(bool &torna_al_menu_principale, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news)
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
			//Albero genealogico di Un'Utente
			alberoGenealogicoSingoloUtente(persona);
		}
		break;
		case '2':
		{
			//Albero genealogico di Tutti gli Utenti
			alberiGenealogiciTotali(persona);
		}
		break;
		case '3':
		{
			//lupi solitari
			ricercaLupiSolitari(persona, news);
		}
		break; 
		case '4':
		{
			//simpatia
			ordinaAziendaPerSimpatia(impresa, news);
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
bool sceltaMenuInformazioniDatabase(bool &torna_al_menu_principale, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news)
{
	//menu gestione informazioni database (2 livello)
	string str_azione_2;
	bool modifica = false;
	char azione_2 = SCELTA_NON_VALIDA;
	bool torna_al_menu_precedente = true;

	//ripeti se scelta non valida
	do
	{
		if (torna_al_menu_precedente)
		{
			stampaMenuInformazioniDatabase();
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
			//Stampa Tutti i Dati
			stampaUtenti(persona, impresa, associazione);
			cout << endl << endl;
			stampaNotizie(news);
			cout << endl << endl << "Relazioni :" << endl << stampaRelazioniFile(persona, impresa, associazione)<<endl;
		}
		break;
		case 'B':
		{
			//stampa solo id degli utenti
			stampaIdUtenti(persona, impresa, associazione);
		}
		break;
		case 'C':
		{
			//Stampa Tutti gli Utenti
			stampaUtenti(persona, impresa, associazione);
		}
		break;
		case 'D':
		{
			//Stampa Tutti gli Utenti Semplici
			stampaUtentiSemplici(persona);
		}
		break;
		case 'E':
		{
			//Stampa Tutti gli Utenti Azienda
			stampaUtentiAzienda(impresa);
		}
		break;
		case 'F':
		{
			//Stampa Tutti gli Utenti Gruppo
			stampaUtentiGruppo(associazione);
		}
		break;
		case 'G':
		{
			//Stampa Tutte le Notizie
			stampaNotizie(news);
		}
		break;
		case 'H':
		{
			//Stampa Tutte le Relazioni
			cout << "Relazioni :" << endl << endl << stampaRelazioniFile(persona, impresa, associazione);
		}
		break;
		case 'I':
		{
			//Cerca un Utente
			cercaUtente(persona, impresa, associazione);
		}
		break;
		case 'J':
		{
			//Cerca Notizie di un Utente
			cercaNotiziaMittente(news);
		}
		break;
		case 'K':
		{
			//Cerca Notizie a cui un Utente ha messo una Reazione
			cercaNotiziaReazione(news);
		}
		break;
		case 'L':
		{
			//Cerca Relazioni con un Utente
			cercaRelazioneUtente(persona, impresa, associazione);
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
			modifica = sceltaMenuGestioneRelazioni(torna_al_menu_principale, persona, impresa, associazione);
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
		case '6':
		{
			//menu informazioni database
			modifica = sceltaMenuInformazioniDatabase(torna_al_menu_principale, persona, impresa, associazione, news);
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
