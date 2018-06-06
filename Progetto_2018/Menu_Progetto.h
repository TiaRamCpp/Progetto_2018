#pragma once

#include <iostream>
#include <string>

#include "Progetto_2018.h"

//menu attributi utente semplice (4 livello)
bool menu_attributi_utente_semplice(bool &torna_al_menu_precedente) {
	bool modifica = false;

	char scelta_attributo;

	cout << "I) Id" << endl;
	cout << "N) Nome" << endl;
	cout << "C) Cognome" << endl;
	cout << "D) Domicilio" << endl;
	cout << "B) Data dui nascita" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_attributo;
	cout << endl;

	if (isalpha(scelta_attributo))
	{
		scelta_attributo = toupper(scelta_attributo);
	}

	switch (scelta_attributo)
	{
	case 'I':
	{
		//Modifica Id
		
	}
	break;
	case 'N':
	{
		//Modifica nome
	}
	break;
	case 'C':
	{
		//Modifica cognome
	}
	break;
	case 'D':
	{
		//Modifica domicilio
	}
	break;
	case 'B':
	{
		//Modifica data di nascita
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
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	return modifica;
}

//menu attributi utente azienda (4 livello)
bool menu_attributi_utente_azienda(bool &torna_al_menu_precedente) {
	bool modifica = false;

	char scelta_attributo;

	cout << "I) Id" << endl;
	cout << "N) Nome" << endl;
	cout << "F) Sede fiscale" << endl;
	cout << "O) Sede operativa" << endl;
	cout << "T) Tipo prodotto" << endl;
	cout << "D) Data creazione" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_attributo;
	cout << endl;

	if (isalpha(scelta_attributo))
	{
		scelta_attributo = toupper(scelta_attributo);
	}

	switch (scelta_attributo)
	{
	case 'I':
	{
		//Modifica Id

	}
	break;
	case 'N':
	{
		//Modifica nome
	}
	break;
	case 'F':
	{
		//Modifica sede fiscale
	}
	break;
	case 'O':
	{
		//Modifica sede operativa
	}
	break;
	case 'T':
	{
		//Modifica tipologia prodotto
	}
	break;
	case 'D':
	{
		//Modifica data di creazione
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
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	return modifica;
}
//menu attributi utente azienda (4 livello)
bool menu_attributi_utente_azienda(bool &torna_al_menu_precedente) {
	bool modifica = false;

	char scelta_attributo;

	cout << "I) Id" << endl;
	cout << "N) Nome" << endl;
	cout << "F) Sede fiscale" << endl;
	cout << "O) Sede operativa" << endl;
	cout << "T) Tipo prodotto" << endl;
	cout << "D) Data creazione" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_attributo;
	cout << endl;

	if (isalpha(scelta_attributo))
	{
		scelta_attributo = toupper(scelta_attributo);
	}

	switch (scelta_attributo)
	{
	case 'I':
	{
		//Modifica Id

	}
	break;
	case 'N':
	{
		//Modifica nome
	}
	break;
	case 'F':
	{
		//Modifica sede fiscale
	}
	break;
	case 'O':
	{
		//Modifica sede operativa
	}
	break;
	case 'T':
	{
		//Modifica tipologia prodotto
	}
	break;
	case 'D':
	{
		//Modifica data di creazione
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
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	return modifica;
}
//menu tipologia aggiunta utenti (3 livello)
bool menu_tipologia_utenti_aggiungi(bool &torna_al_menu_precedente)
{
	bool modifica = false;
	//inizializzo variabili booleane per evitare di tornare a menu precedenti
	torna_al_menu_precedente = false;
	
	char scelta_tipologia;

	cout << "S) Aggiungi Utente Semplice" << endl;
	cout << "A) Aggiungi Utente Azienda" << endl;
	cout << "G) Aggiungi Utente Gruppo" << endl;
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
		//Aggiungi utente semplice
	}
	break;
	case 'A':
	{
		//Aggiungi utente Azienda
	}
	break;
	case 'G':
	{
		//Aggiungi utente Gruppo
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
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	if (torna_al_menu_precedente) {
		menu_tipologia_utenti_aggiungi(torna_al_menu_precedente);
	}
	return modifica;
}

//menu tipologia aggiunta utenti (3 livello)
bool menu_tipologia_utenti_modifica(bool &torna_al_menu_precedente)
{
	bool modifica = false;
	//inizializzo variabili booleane per evitare di tornare a menu precedenti
	torna_al_menu_precedente = false;

	char scelta_tipologia;

	cout << "S) Modifica Utente Semplice" << endl;
	cout << "A) Modifica Utente Azienda" << endl;
	cout << "G) Modifica Utente Gruppo" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> scelta_tipologia;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(scelta_tipologia))
	{
		scelta_tipologia = toupper(scelta_tipologia);
	}

	switch (scelta_tipologia)
	{
	case 'S':
	{
		//Modifica utente semplice
		menu_attributi_utente_semplice(torna_al_menu_precedente);
	}
	break;
	case 'A':
	{
		//modifica utente Azienda
	}
	break;
	case 'G':
	{
		//modifica utente Gruppo
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
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	if (torna_al_menu_precedente) {
		menu_tipologia_utenti_modifica(torna_al_menu_precedente);
	}
	return modifica;
}

//menu gestione utenti (2 livello)
bool menu_gestione_utenti(bool &torna_al_menu_precedente)
{
	bool modifica = false;
	//inizializzo variabile booleana per evitare di tornare a menu precedenti
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
		modifica=menu_tipologia_utenti_aggiungi(torna_al_menu_precedente);
	}
	break;
	case 'R':
	{
		//Tipologia da rimuovere
		
	}
	break;
	case 'M':
	{
		//Tipologia da modificare
		modifica = menu_tipologia_utenti_modifica(torna_al_menu_precedente);
	}
	break;
	case 'E':
	{
		//torna al menu principale
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	//controllo se c'è richiesta di tornare al menu precedente e lo ricarico
	if (torna_al_menu_precedente) {
		modifica = menu_gestione_utenti(torna_al_menu_precedente);
	}
	return modifica;
}

//menu principale (1 livello)
bool menu_principale(bool &esci)
{
	bool modifica = false;
	//variabili booleane che mi permettono di tornare indietro nei menu
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
		modifica=menu_gestione_utenti(torna_al_menu_precedente);
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
		esci = true;
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	return modifica;
}
