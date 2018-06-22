#pragma once

#include "GestioneUtenti.h"

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
	return modifica;
}

//numero amici e parenti per ogni utente semplice

bool utentiDopoUnaData(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool riscontro = false;
	bool ok = false;
	bool trovato;
	string str_data_inserita;
	Data data_inserita;
	
	//inserimento data
	do
	{
		//inserisco data
		cout << endl << "Inserisci la data nel formato (gg/mm/aaaa) : ";
		getline(cin, str_data_inserita);
		//controllo che sia una data valida e contemporaneamente la converto
		if (data_inserita.convertiStringaAData(str_data_inserita))
		{
			ok = true;
		}
		//se non lo è
		else
		{
			cout << endl << "Errore : la data inserita '" << str_data_inserita << "' non e' valida" << endl;
		}
	} while (!ok);

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

	return modifica;
}

bool numeroDipendentiEConsociatePerAzienda(const vector<UtenteAzienda> &impresa)
{
	bool modifica = false;
	if (impresa.size() != 0)
	{
		cout << endl << "Numero dipendenti e aziende consociate per ogni azienda :";
	}
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		cout << endl << "Impresa : <" << impresa[i].getId() << ">";
		cout << ", numero di dipendenti : " << impresa[i].contaTipoRelazione(STR_DIPENDENTE);
		cout << ", numero di aziende consociate : " << impresa[i].contaTipoRelazione(STR_CONSOCIATA);
	}
	return modifica;
}

bool numeroUtentiPerGruppo(const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	if (associazione.size() != 0)
	{
		cout << endl << "Numero utenti semplici per ogni gruppo :";
	}
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		cout << endl << "Gruppo : <" << associazione[i].getId() << ">, numero utenti nel gruppo : " << associazione[i].contaTipoRelazione(STR_MEMBRO);
	}
	return modifica;
}

unsigned int contaDipendentiAzienda(const vector<UtenteAzienda> &impresa, const unsigned int &posizione_azienda, const bool &cumulativi)
{
	unsigned int numero_dipendenti = 0;
	vector<string> id_arco = impresa[posizione_azienda].getIdArco();
	vector<string> tipo_relazione = impresa[posizione_azienda].getTipoRelazione();
	for (unsigned int i = 0; i < tipo_relazione.size(); i++)
	{
		//se è un dipendente
		if (tipo_relazione[i] == STR_DIPENDENTE)
		{
			numero_dipendenti++;
		}
		else
			//se sono richiesti anche i dipendenti cumulativi
			if (cumulativi)
			{
				//se è un'azienda consociata
				if (tipo_relazione[i] == STR_CONSOCIATA)
				{
					//se non è la stessa azienda di partenza
					if (id_arco[i] != impresa[posizione_azienda].getId())
					{
						//conto i dipendenti per quell'azienda
						numero_dipendenti += contaDipendentiAzienda(impresa, utenteAziendaPosizione(impresa, id_arco[i]), false); //con il false per non contare i dipendenti di una consociata di una consociata
					}
				}
			}
	}
	return numero_dipendenti;
}

bool aziendaMaggiorDipendenti(const vector<UtenteAzienda> &impresa, const bool &cumulativi)
{
	//se cumulativi è true conta anche i dipendendi delle consociate altrimenti se è false non li conta

	bool modifica = false;
	vector<unsigned int> posizione;
	unsigned int numero_aziende_a_parimerito = 0;
	unsigned int massimi_dipendenti = 0;
	unsigned int numero_dipendenti;
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		numero_dipendenti = contaDipendentiAzienda(impresa, i, cumulativi);
		//se ha più dipendenti del massimo precedente
		if (massimi_dipendenti < numero_dipendenti)
		{
			numero_aziende_a_parimerito = 1;
			posizione.clear();
			posizione.push_back(i);
			massimi_dipendenti = numero_dipendenti;
		}
		else
			//se ha lo stesso numero di dipendenti
			if (massimi_dipendenti == numero_dipendenti)
			{
				numero_aziende_a_parimerito++;
				posizione.push_back(i);
			}
	}
	//se c'è solo un'azienda con più dipendenti
	if (numero_aziende_a_parimerito == 1)
	{
		cout << endl << "L'azienda con piu' dipendenti ";
		if(cumulativi)
			cout << "cumulativi con le consociate ";
		cout << "ne ha : " << massimi_dipendenti;
		cout << endl << "Id azienda : " << impresa[posizione.front()].getId();
	}
	//se sono più aziende a parimerito
	else
	{
		cout << endl << "Ci sono " << numero_aziende_a_parimerito << " aziende a parimerito con " << massimi_dipendenti << " dipendenti";
		if (cumulativi)
			cout << " cumulativi con le consociate";
		cout << endl << "Elenco :";
		for (unsigned int i = 0; i < numero_aziende_a_parimerito; i++)
		{
			cout << endl << "Id azienda : " << impresa[posizione[i]].getId();
		}
	}
	return modifica;
}

bool migliorNotizia(const vector<Notizia> &news)
{
	bool modifica = false;
	vector<unsigned int> posizione;
	unsigned int numero_notizie_a_parimerito = 0;
	unsigned int massimi_like = 0;
	unsigned int numero_like;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		numero_like = news[i].getLike().size();
		//se ha più like del massimo precedente
		if (massimi_like < numero_like)
		{
			numero_notizie_a_parimerito = 1;
			posizione.clear();
			posizione.push_back(i);
			massimi_like = numero_like;
		}
		else
			//se ha lo stesso numero di like
			if (massimi_like == numero_like)
			{
				numero_notizie_a_parimerito++;
				posizione.push_back(i);
			}
	}
	//se c'è solo una notizia con più like
	if (numero_notizie_a_parimerito == 1)
	{
		cout << endl << "La notizia con piu' like ne ha : " << massimi_like;
		cout << endl << "Notizia : " << news[posizione.front()] << endl << endl;
	}
	//se sono più notizie a parimerito
	else
	{
		cout << endl << "Ci sono " << numero_notizie_a_parimerito << " notizie a parimerito con " << massimi_like << " like";
		cout << endl << "Elenco :";
		for (unsigned int i = 0; i < numero_notizie_a_parimerito; i++)
		{
			cout << endl << "Notizia : " << news[posizione[i]];
		}
	}
	return modifica;
}

bool peggiorNotizia(const vector<Notizia> &news)
{
	bool modifica = false;
	vector<unsigned int> posizione;
	unsigned int numero_notizie_a_parimerito = 0;
	unsigned int massimi_dislike = 0;
	unsigned int numero_dislike;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		numero_dislike = news[i].getDislike().size();
		//se ha più dislike del massimo precedente
		if (massimi_dislike < numero_dislike)
		{
			numero_notizie_a_parimerito = 1;
			posizione.clear();
			posizione.push_back(i);
			massimi_dislike = numero_dislike;
		}
		else
			//se ha lo stesso numero di dislike
			if (massimi_dislike == numero_dislike)
			{
				numero_notizie_a_parimerito++;
				posizione.push_back(i);
			}
	}
	//se c'è solo una notizia con più dislike
	if (numero_notizie_a_parimerito == 1)
	{
		cout << endl << "La notizia con piu' dislike ne ha : " << massimi_dislike;
		cout << endl << "Notizia : " << news[posizione.front()] << endl << endl;
	}
	//se sono più notizie a parimerito
	else
	{
		cout << endl << "Ci sono " << numero_notizie_a_parimerito << " notizie a parimerito con " << massimi_dislike << " dislike";
		cout << endl << "Elenco :";
		for (unsigned int i = 0; i < numero_notizie_a_parimerito; i++)
		{
			cout << endl << "Notizia : " << news[posizione[i]];
		}
	}

	return modifica;
}

bool utenteSempliceMaggiorAmici(const vector<UtenteSemplice> &persona)
{
	bool modifica = false;
	vector<unsigned int> posizione;
	unsigned int numero_utenti_a_parimerito = 0;
	unsigned int massimi_amici = 0;
	unsigned int numero_amici;
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		numero_amici = persona[i].contaTipoRelazione(STR_AMICO);
		//se ha più amici del massimo precedente
		if (massimi_amici < numero_amici)
		{
			numero_utenti_a_parimerito = 1;
			posizione.clear();
			posizione.push_back(i);
			massimi_amici = numero_amici;
		}
		else
			//se ha lo stesso numero di amici
			if (massimi_amici == numero_amici)
			{
				numero_utenti_a_parimerito++;
				posizione.push_back(i);
			}
	}
	//se c'è solo un utente con più amici
	if (numero_utenti_a_parimerito == 1)
	{
		cout << endl << "L'utente semplice con piu' amici ne ha : " << massimi_amici;
		cout << endl << "Id utente : " << persona[posizione.front()].getId();
	}
	//se sono più utenti a parimerito
	else
	{
		cout << endl << "Ci sono " << numero_utenti_a_parimerito << " utenti semplici a parimerito con " << massimi_amici << " amici";
		cout << endl << "Elenco :";
		for (unsigned int i = 0; i < numero_utenti_a_parimerito; i++)
		{
			cout << endl << "Id utente : " << persona[posizione[i]].getId();
		}
	}
	return modifica;
}

bool utenteSempliceMaggiorConoscenze(const vector<UtenteSemplice> &persona)
{
	bool modifica = false;
	vector<unsigned int> posizione;
	unsigned int numero_utenti_a_parimerito = 0;
	unsigned int massime_conoscenze = 0;
	unsigned int numero_conoscenze;
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		numero_conoscenze = persona[i].contaTipoRelazione(STR_CONOSCENTE);
		//se ha più conoscenti del massimo precedente
		if (massime_conoscenze < numero_conoscenze)
		{
			numero_utenti_a_parimerito = 1;
			posizione.clear();
			posizione.push_back(i);
			massime_conoscenze = numero_conoscenze;
		}
		else
			//se ha lo stesso numero di conoscenze
			if (massime_conoscenze == numero_conoscenze)
			{
				numero_utenti_a_parimerito++;
				posizione.push_back(i);
			}
	}
	//se c'è solo un utente con più conoscenze
	if (numero_utenti_a_parimerito == 1)
	{
		cout << endl << "L'utente semplice con piu' conoscenze ne ha : " << massime_conoscenze;
		cout << endl << "Id utente : " << persona[posizione.front()].getId();
	}
	//se sono più utenti a parimerito
	else
	{
		cout << endl << "Ci sono " << numero_utenti_a_parimerito << " utenti semplici a parimerito con " << massime_conoscenze << " conoscenze";
		cout << endl << "Elenco :";
		for (unsigned int i = 0; i < numero_utenti_a_parimerito; i++)
		{
			cout << endl << "Id utente : " << persona[posizione[i]].getId();
		}
	}
	return modifica;
}

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
	return modifica;
}