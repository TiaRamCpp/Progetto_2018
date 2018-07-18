#pragma once

#include "GestioneUtenti.h"
#include "GestioneRelazioni.h"
#include "GestioneStringhe.h"

#include "Notizia.h"

void conteggioGenerale(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	unsigned int numero_utenti_semplici = persona.size();
	unsigned int numero_utenti_azienda = impresa.size();
	unsigned int numero_utenti_gruppo = associazione.size();
	unsigned int numero_utenti_totali = numero_utenti_semplici + numero_utenti_azienda + numero_utenti_gruppo;
	cout << endl << setfill('_') << setw(40) << "_";
	cout << setfill(' ');
	cout << endl << "| Numero utenti totali     |" << setw(10) << numero_utenti_totali << " |";
	cout << endl << "| Numero utenti semplici   |" << setw(10) << numero_utenti_semplici << " |";
	cout << endl << "| Numero utenti azienda    |" << setw(10) << numero_utenti_azienda << " |";
	cout << endl << "| Numero utenti gruppo     |" << setw(10) << numero_utenti_gruppo << " |";
	cout << endl << setfill('-') << setw(40) << "-";
	cout << setfill(' ');
	cout << endl;
}

void numeroAmiciEParentiPerUtenteSemplice(const vector<UtenteSemplice> &persona)
{
	vector<string> id_trovati;
	if (persona.size() != 0)
	{
		cout << endl << "Numero amici e parenti diretti per ogni utente semplice :" << endl;
		cout << setw(71) << setfill('_') << "_";
		cout << setfill(' ') << endl << "|" << setw(20) << "ID" << setw(20) << "|" << setw(15) << "n. amici |" << setw(15) << "n. parenti |" << endl;
		cout << setw(71) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		for (unsigned int i = 0; i < persona.size(); i++)
		{
			id_trovati.clear();
			id_trovati.push_back(persona[i].getId());
			cout << "| " << stampaSinistra(37, persona[i].getId()) << " |" << setw(13) << persona[i].contaTipoRelazione(STR_AMICO) << " |" << setw(13) << contaParenti(persona, i, id_trovati) << " |" << endl;
		}

		cout << setw(71) << setfill('-') << "-" << endl;
		cout << setfill(' ');
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
}

void utentiDopoUnaData(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool riscontro = false;
	bool ok = false;
	bool trovato;
	string str_data_inserita;
	Data data_inserita;

	if (almenoUnUtenteEsistente(persona, impresa, associazione))
	{
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
					cout << setw(60) << setfill('_') << "_";
					cout << setfill(' ') << endl;
				}
				cout << "| " << stampaSinistra(57, persona[i].getId()) << "|" << endl;
			}
		}
		if (trovato)
		{
			cout << setw(60) << setfill('-') << "-" << endl;
			cout << setfill(' ') << endl;
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
					cout << setw(60) << setfill('_') << "_";
					cout << setfill(' ') << endl;
				}
				cout << "| " << stampaSinistra(57, impresa[i].getId()) << "|" << endl;
			}
		}
		if (trovato)
		{
			cout << setw(60) << setfill('-') << "-" << endl;
			cout << setfill(' ') << endl;
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
					cout << setw(60) << setfill('_') << "_";
					cout << setfill(' ') << endl;
				}
				cout << "| " << stampaSinistra(57, associazione[i].getId()) << "|" << endl;
			}
		}
		if (trovato)
		{
			cout << setw(60) << setfill('-') << "-" << endl;
			cout << setfill(' ') << endl;
		}

		//se non ho trovato nemmeno uno
		if (!riscontro)
		{
			cout << endl << "Nessun utente nato o creato dopo la data inserita" << endl;
		}
	}
	//se non esiste nemmeno un utente
	else
	{
		cout << endl << "Nessun utente inserito nel database" << endl;
	}
}

void numeroDipendentiEConsociatePerAzienda(const vector<UtenteAzienda> &impresa)
{
	vector<string> tipo_relazione(2);
	vector<unsigned int> numero_tipo_relazione(2);
	tipo_relazione[0] = STR_DIPENDENTE;
	tipo_relazione[1] = STR_CONSOCIATA;

	if (impresa.size() != 0)
	{
		cout << endl << "Numero dipendenti e aziende consociate per ogni azienda :";

		cout << endl << setw(81) << setfill('_') << "_";
		cout << setfill(' ') << endl << "|" << setw(20) << "ID" << setw(20) << "|" << setw(20) << "n. dipendenti |" << setw(20) << "n. consociate |" << endl;
		cout << setw(81) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		for (unsigned int i = 0; i < impresa.size(); i++)
		{
			//conta contemporaneamente i diversi tipi di reazione
			impresa[i].contaTipiRelazione(tipo_relazione, numero_tipo_relazione);

			cout << "| " << stampaSinistra(37, impresa[i].getId()) << " |" << setw(18) << numero_tipo_relazione[0] << " |" << setw(18) << numero_tipo_relazione[1] << " |" << endl;

		}

		cout << setw(81) << setfill('-') << "-" << endl;
		cout << setfill(' ');
	}
	else
	{
		cout << endl << "Nessun utente azienda inserito nel database" << endl;
	}
}

void numeroUtentiPerGruppo(const vector<UtenteGruppo> &associazione)
{
	if (associazione.size() != 0)
	{
		cout << endl << "Numero utenti semplici per ogni gruppo :";

		cout << endl << setw(56) << setfill('_') << "_";
		cout << setfill(' ') << endl << "|" << setw(20) << "ID" << setw(20) << "|" << setw(15) << "n. utenti |" << endl;
		cout << setw(56) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		for (unsigned int i = 0; i < associazione.size(); i++)
		{
			cout << "| " << stampaSinistra(37, associazione[i].getId()) << " |" << setw(13) << associazione[i].contaTipoRelazione(STR_MEMBRO) << " |" << endl;
		}

		cout << setw(56) << setfill('-') << "-" << endl;
		cout << setfill(' ');
	}
	else
	{
		cout << endl << "Nessun utente gruppo inserito nel database" << endl;
	}
}

void aziendaMaggiorDipendenti(const vector<UtenteAzienda> &impresa, const bool &cumulativi)
{
	//se cumulativi è true conta anche i dipendendi delle consociate altrimenti se è false non li conta

	vector<unsigned int> posizione;
	unsigned int numero_aziende_a_parimerito = 0;
	unsigned int massimi_dipendenti = 0;
	unsigned int numero_dipendenti;
	//se esiste almeno un'azienda
	if (impresa.size() != 0)
	{
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
			if (cumulativi)
				cout << "cumulativi con le consociate ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. dipendenti |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			cout << "| " << stampaSinistra(57, impresa[posizione.front()].getId()) << " |" << setw(18) << massimi_dipendenti << " |" << endl;

		}
		//se sono più aziende a parimerito
		else
		{
			cout << endl << "Le aziende con piu' dipendenti ";
			if (cumulativi)
				cout << "cumulativi con le consociate ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. dipendenti |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			for (unsigned int i = 0; i < numero_aziende_a_parimerito; i++)
			{
				cout << "| " << stampaSinistra(57, impresa[posizione.front()].getId()) << " |" << setw(18) << massimi_dipendenti << " |" << endl;
			}
		}

		if (numero_aziende_a_parimerito != 0)
		{
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');
		}
	}
	else
	{
		cout << endl << "Nessun utente azienda inserito nel database" << endl;
	}
	cout << endl;
}

void migliorNotizia(const vector<Notizia> &news)
{
	vector<unsigned int> posizione;
	unsigned int numero_notizie_a_parimerito = 0;
	unsigned int massimi_like = 0;
	unsigned int numero_like;
	//se c'è almeno una notizia
	if (news.size() != 0)
	{
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
			cout << endl << "La notizia con piu' like : " << massimi_like;

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
	}
	else
	{
		cout << endl << "Nessuna notizia inserita nel database" << endl;
	}
}

void peggiorNotizia(const vector<Notizia> &news)
{
	vector<unsigned int> posizione;
	unsigned int numero_notizie_a_parimerito = 0;
	unsigned int massimi_dislike = 0;
	unsigned int numero_dislike;
	//se c'è almeno una notizia
	if (news.size() != 0)
	{
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
	}
	else
	{
		cout << endl << "Nessuna notizia inserita nel database" << endl;
	}
}

void utenteSempliceMaggiorAmici(const vector<UtenteSemplice> &persona)
{
	vector<unsigned int> posizione;
	unsigned int numero_utenti_a_parimerito = 0;
	unsigned int massimi_amici = 0;
	unsigned int numero_amici;
	//se c'è almeno un utente semplice
	if (persona.size() != 0)
	{
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
			cout << endl << "L'utente semplice con piu' amici : ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. amici |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			cout << "| " << stampaSinistra(57, persona[posizione.front()].getId()) << " |" << setw(18) << massimi_amici << " |" << endl;
		}
		//se sono più utenti a parimerito
		else
		{
			cout << endl << "Gli utenti semplici con piu' amici : ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. amici |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			for (unsigned int i = 0; i < numero_utenti_a_parimerito; i++)
			{
				cout << "| " << stampaSinistra(57, persona[posizione[i]].getId()) << " |" << setw(18) << massimi_amici << " |" << endl;
			}
		}
		if (numero_utenti_a_parimerito != 0)
		{
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');
		}
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
	cout << endl;
}

void utenteSempliceMaggiorConoscenze(const vector<UtenteSemplice> &persona)
{
	vector<unsigned int> posizione;
	unsigned int numero_utenti_a_parimerito = 0;
	unsigned int massime_conoscenze = 0;
	unsigned int numero_conoscenze;
	//se c'è almeno un utente semplice
	if (persona.size() != 0)
	{
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
			cout << endl << "L'utente semplice con piu' conoscenze: ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. conoscenze |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			cout << "| " << stampaSinistra(57, persona[posizione.front()].getId()) << " |" << setw(18) << massime_conoscenze << " |" << endl;
		}
		//se sono più utenti a parimerito
		else
		{
			cout << endl << "Gli utenti semplici con piu' conoscenze: ";

			cout << endl << setw(81) << setfill('_') << "_";
			cout << setfill(' ') << endl;

			cout << "|" << setw(30) << "ID" << setw(30) << "|" << setw(20) << "n. conoscenze |" << endl;
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			for (unsigned int i = 0; i < numero_utenti_a_parimerito; i++)
			{
				cout << "| " << stampaSinistra(57, persona[posizione[i]].getId()) << " |" << setw(18) << massime_conoscenze << " |" << endl;

			}
		}
		if (numero_utenti_a_parimerito != 0)
		{
			cout << setw(81) << setfill('-') << "-" << endl;
			cout << setfill(' ');
		}
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
	cout << endl;
}

void etaMediaUtentiSemplici(const vector<UtenteSemplice> &persona)
{
	int eta_media = 0;
	//se c'è almeno un utente semplice
	if (persona.size() != 0)
	{
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			//calcolo eta e la sommo
			eta_media += persona[i].calcolaEta();
		}
		//calcolo la media
		eta_media /= persona.size();


		cout << endl << setw(30) << setfill('_') << "_";
		cout << setfill(' ') << endl;
		cout << "| " << stampaSinistra(27, "Eta' media [anni]") << "|" << endl;
		cout << setw(30) << setfill('-') << "-";
		cout << setfill(' ') << endl;
		cout << "| " << stampaSinistra(27, to_string(eta_media)) << "|" << endl;
		cout << setw(30) << setfill('-') << "-";
		cout << setfill(' ') << endl;
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
}
