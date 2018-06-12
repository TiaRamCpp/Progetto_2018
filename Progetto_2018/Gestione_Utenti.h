#pragma once

#include "UtenteSemplice.h"
#include "UtenteAzienda.h"
#include "UtenteGruppo.h"

#include "Notizia.h"

//id esistente
bool idUtenteSempliceTrovato(const vector<UtenteSemplice> &persona, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < persona.size()) && (!trovato)); i++)
		if (persona[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteAziendaTrovato(const vector<UtenteAzienda> &impresa, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < impresa.size()) && (!trovato)); i++)
		if (impresa[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteGruppoTrovato(const vector<UtenteGruppo> &associazione, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < associazione.size()) && (!trovato)); i++)
		if (associazione[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteTrovato(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &id_utente)
{
	//se una condizione è verificata non esegue inutilmente le successive
	return (idUtenteSempliceTrovato(persona, id_utente)) || (idUtenteAziendaTrovato(impresa, id_utente)) || (idUtenteGruppoTrovato(associazione, id_utente));
}

//stampa
string stampaUtenti(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	string output;
	output.clear();
	//stampa utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		output += persona[i].stampaUtente();
		//se non è l'ultima riga
		if (i < persona.size() - 1)
			output += '\n';
		else
			//se dopo devo stampare altri dati
			if ((impresa.size() != 0) || (associazione.size() != 0))
				output += '\n';
	}
	//stampa utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		output += impresa[i].stampaUtente();
		//se non è l'ultima riga
		if (i < impresa.size() - 1)
			output += '\n';
		else
			//se dopo devo stampare altri dati
			if (associazione.size() != 0)
				output += '\n';
	}
	//stampa utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		output += associazione[i].stampaUtente();
		//se non è l'ultima riga
		if (i < associazione.size() - 1)
			output += '\n';
	}
	return output;
}
