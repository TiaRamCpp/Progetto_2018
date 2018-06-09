#pragma once

#include "Utente_Semplice.h"
#include "Utente_Azienda.h"
#include "Utente_Gruppo.h"

#include "Notizia.h"

//id esistente
bool id_utente_semplice_trovato(const vector<Utente_Semplice> &persona, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < persona.size()) && (!trovato)); i++)
		if (persona[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_azienda_trovato(const vector<Utente_Azienda> &impresa, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < impresa.size()) && (!trovato)); i++)
		if (impresa[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_gruppo_trovato(const vector<Utente_Gruppo> &associazione, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < associazione.size()) && (!trovato)); i++)
		if (associazione[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_trovato(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const string &id_utente)
{
	//se una condizione è verificata non esegue inutilmente le successive
	return (id_utente_semplice_trovato(persona, id_utente)) || (id_utente_azienda_trovato(impresa, id_utente)) || (id_utente_gruppo_trovato(associazione, id_utente));
}

//stampa
string stampa_utenti(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione)
{
	string output;
	output.clear();
	//stampa utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		output += persona[i].stampa_Utente();
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
		output += impresa[i].stampa_Utente();
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
		output += associazione[i].stampa_Utente();
		//se non è l'ultima riga
		if (i < associazione.size() - 1)
			output += '\n';
	}
	return output;
}
