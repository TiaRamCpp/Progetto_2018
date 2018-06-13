#pragma once

#include "UtenteSemplice.h"
#include "UtenteAzienda.h"
#include "UtenteGruppo.h"

#include "Notizia.h"

bool conteggioGenerale(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	unsigned int numero_utenti_semplici = persona.size();
	unsigned int numero_utenti_azienda = impresa.size();
	unsigned int numero_utenti_gruppo = associazione.size();
	unsigned int numero_utenti_totali = numero_utenti_semplici + numero_utenti_azienda + numero_utenti_gruppo;
	cout << endl << "Numero utenti totali : " << numero_utenti_totali;
	cout << endl << "Numero utenti semplici : " << numero_utenti_semplici;
	cout << endl << "Numero utenti azienda : " << numero_utenti_azienda;
	cout << endl << "Numero utenti gruppo : " << numero_utenti_gruppo;
	cout << endl;
	return modifica; //falsa sempre
}

//numero amici e parenti per ogni utente semplice

bool utentiDopoUnaData(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool riscontro = false;
	bool trovato;
	string str_data_inserita;
	Data data_inserita;
	//inserisco data
	cout << endl << "Inserisci la data nel formato (gg/mm/aaaa) : ";
	getline(cin, str_data_inserita);
	//converte la stringa in una data e contemporaneamente verifica che sia valida
	if (data_inserita.convertiStringaAData(str_data_inserita))
	{
		//cerco tra gli utenti semplici
		trovato = false;
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			//controllo rispetto alla data di nascita
			if (data_inserita < persona[i].getDataNascita())
			{
				//se è il primo che trovo
				if (!trovato)
				{
					riscontro = true;
					trovato = true;
					//stampo il messaggio iniziale
					cout << endl << "Utenti semplici nati dopo la data inserita :" << endl;
				}
				cout << persona[i].getId() << endl;
			}
		}
		//cerco tra gli utenti azienda
		trovato = false;
		for (unsigned int i = 0; i < impresa.size(); i++)
		{
			//controllo rispetto alla data di creazione
			if (data_inserita < impresa[i].getDataCreazione())
			{
				//se è il primo che trovo
				if (!trovato)
				{
					riscontro = true;
					trovato = true;
					//stampo il messaggio iniziale
					cout << endl << "Utenti azienda creati dopo la data inserita :" << endl;
				}
				cout << impresa[i].getId() << endl;
			}
		}
		//cerco tra gli utenti gruppo
		trovato = false;
		for (unsigned int i = 0; i < associazione.size(); i++)
		{
			//controllo rispetto alla data di creazione
			if (data_inserita < associazione[i].getDataCreazione())
			{
				//se è il primo che trovo
				if (!trovato)
				{
					riscontro = true;
					trovato = true;
					//stampo il messaggio iniziale
					cout << endl << "Utenti gruppo creati dopo la data inserita :" << endl;
				}
				cout << associazione[i].getId() << endl;
			}
		}
		//se non ho trovato nemmeno uno
		if (!riscontro)
		{
			cout << endl << "Nessun utente nato o creato dopo la data inserita" << endl;
		}
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la data inserita '" << str_data_inserita << "' non e' valida" << endl;
	}
	return modifica; //falsa sempre
}

//numero di dipendenti e aziende consociate per ogni azienda

//numero utenti per ogni gruppo

//Azienda con il maggior numero di dipendenti (solo diretti o cumulativo con le consociate)

bool migliorNotizia(const vector<Notizia> &news)
{
	bool modifica = false;
	unsigned int posizione = 0;
	unsigned int massimi_like = 0;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		//se ha più like del massimo precedente
		if (massimi_like < news[i].getLike().size())
		{
			posizione = i;
			massimi_like = news[i].getLike().size();
		}
	}
	cout << endl << "La notizia con piu' like ne ha : " << massimi_like;
	cout << endl << "Notizia : " << news[posizione] << endl << endl;
	return modifica; //falsa sempre
}

bool peggiorNotizia(const vector<Notizia> &news)
{
	bool modifica = false;
	unsigned int posizione = 0;
	unsigned int massimi_dislike = 0;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		//se ha più dislike del massimo precedente
		if (massimi_dislike < news[i].getDislike().size())
		{
			posizione = i;
			massimi_dislike = news[i].getDislike().size();
		}
	}
	cout << endl << "La notizia con piu' dislike ne ha : " << massimi_dislike;
	cout << endl << "Notizia : " << news[posizione] << endl << endl;
	return modifica; //falsa sempre
}

//Utente col maggior numero di amici;

//Utente con il maggior numero di conoscenze

bool etaMediaUtentiSemplici(const vector<UtenteSemplice> &persona)
{
	bool modifica = false;
	int eta_media = 0;
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		//calcolo eta e la sommo
		eta_media += persona[i].calcolaEta();
	}
	//calcolo la media
	eta_media /= persona.size();
	cout << endl << "Eta' media degli utenti semplici : " << eta_media << endl << endl;
	return modifica; //falsa sempre
}