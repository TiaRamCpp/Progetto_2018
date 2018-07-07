#pragma once

#include "GestioneUtenti.h"

string stampaRelazioniFile(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	string output;
	output.clear();
	//stampa nodi utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		//se non ho stampato nulla prima e se c'è qualcosa da stampare metto il '\n'
		if ((persona[i].numeroRelazioni() != 0) && (!output.empty()))
			output += '\n';
		//se non c'è nessuna relazione non stampa nulla
		output += persona[i].stampaNodo();
	}
	//stampa nodi utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		//se non ho stampato nulla prima e se c'è qualcosa da stampare metto il '\n'
		if ((impresa[i].numeroRelazioni() != 0) && (!output.empty()))
			output += '\n';
		//se non c'è nessuna relazione non stampa nulla
		output += impresa[i].stampaNodo();
	}
	//stampa nodi utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		//se non ho stampato nulla prima e se c'è qualcosa da stampare metto il '\n'
		if ((associazione[i].numeroRelazioni() != 0) && (!output.empty()))
			output += '\n';
		//se non c'è nessuna relazione non stampa nulla
		output += associazione[i].stampaNodo();
	}
	return output;
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
						numero_dipendenti += contaDipendentiAzienda(impresa, utenteAziendaPosizione(impresa, id_arco[i]), false);
						//con il false per non contare i dipendenti di una consociata di una consociata
					}
				}
			}
	}
	return numero_dipendenti;
}

bool relazioneSpeculare(const string &tipo_relazione, string &relazione_speculare)
{
	bool speculare = false;

	if (tipo_relazione == STR_CONIUGE)
	{
		relazione_speculare = STR_CONIUGE;
		speculare = true;
	}
	else
		if (tipo_relazione == STR_FIGLIO)
		{
			relazione_speculare = STR_GENITORE;
			speculare = true;
		}
		else
			if (tipo_relazione == STR_GENITORE)
			{
				relazione_speculare = STR_FIGLIO;
				speculare = true;
			}
			else
				if (tipo_relazione == STR_DIPENDENTE)
				{
					relazione_speculare = STR_DIPENDENTE;
					speculare = true;
				}
				else
					if (tipo_relazione == STR_MEMBRO)
					{
						relazione_speculare = STR_MEMBRO;
						speculare = true;
					}

	return speculare;
}

//aggiungi relazione

bool aggiungiRelazioneDaTipi(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const unsigned int &posizione_partenza, const string &tipo_partenza, const string &tipo_arrivo, const string &id_arrivo, const string &tipo_relazione)
{
	bool ok = false;
	//se è un utente semplice
	if (tipo_partenza == ID_TIPO_SEMPLICE)
	{
		//se è un tipo di collegamento possibile tra gli utenti
		if (persona[posizione_partenza].tipoRelazionePossibile(tipo_relazione, tipo_arrivo))
		{
			ok = persona[posizione_partenza].aggiungiRelazione(id_arrivo, tipo_relazione);
		}
		//se non è una relazione valida
		else
		{
			cout << "Errore : non puo' esistere una relazione di tipo <" << tipo_relazione << "> tra un utente_semplice e un " << tipo_arrivo << endl;
		}
	}
	else
		//se è un utente azienda
		if (tipo_partenza == ID_TIPO_AZIENDA)
		{
			//se è un tipo di collegamento possibile tra gli utenti
			if (impresa[posizione_partenza].tipoRelazionePossibile(tipo_relazione, tipo_arrivo))
			{
				ok = impresa[posizione_partenza].aggiungiRelazione(id_arrivo, tipo_relazione);
			}
			//se non è una relazione valida
			else
			{
				cout << "Errore : non puo' esistere una relazione di tipo <" << tipo_relazione << "> tra un utente_azienda e un " << tipo_arrivo << endl;
			}
		}
		else
			//se è un utente gruppo
			if (tipo_partenza == ID_TIPO_GRUPPO)
			{
				//se è un tipo di collegamento possibile tra gli utenti
				if (associazione[posizione_partenza].tipoRelazionePossibile(tipo_relazione, tipo_arrivo))
				{
					ok = associazione[posizione_partenza].aggiungiRelazione(id_arrivo, tipo_relazione);
				}
				//se non è una relazione valida
				else
				{
					cout << "Errore : non puo' esistere una relazione di tipo <" << tipo_relazione << "> tra un utente_gruppo e un " << tipo_arrivo << endl;
				}
			}
	return ok;
}

bool aggiungiRelazioneDaId(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &id_partenza, const string &id_arrivo, const string &tipo_relazione)
{
	bool ok = true;
	unsigned int posizione_partenza;
	UtenteSemplice temp;
	string tipo_partenza;
	string tipo_arrivo;

	//controllo che esista l'id di partenza e identifico il tipo e la posizione
	if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_partenza, tipo_partenza, posizione_partenza))
	{
		//controllo che esista l'id di arrivo e identifico il tipo
		if (trovaTipoUtente(persona, impresa, associazione, id_arrivo, tipo_arrivo))
		{
			//controllo che il tipo di relazione sia esistente
			if (temp.tipoRelazioneEsistente(tipo_relazione))
			{
				ok = aggiungiRelazioneDaTipi(persona, impresa, associazione, posizione_partenza, tipo_partenza, tipo_arrivo, id_arrivo, tipo_relazione);
			}
			//se non esiste il tipo di relazione
			else
			{
				cerr << endl << "Errore : il tipo relazione <" << tipo_relazione << "> non esiste" << endl;
				ok = false;
			}
		}
	}

	return ok;
}

bool aggiungiRelazione(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	string id_partenza;
	string id_arrivo;
	string tipo_relazione;
	string relazione_speculare;
	unsigned int posizione_partenza;
	unsigned int posizione_arrivo;
	string tipo_partenza;
	string tipo_arrivo;
	bool aggiunta = false;

	//inserisco id di partenza
	cout << endl << "Inserisci id di partenza della relazione da aggiungere : ";
	getline(cin, id_partenza);
	//inserisco id di arrivo
	cout << endl << "Inserisci id di arrivo della relazione da aggiungere : ";
	getline(cin, id_arrivo);
	//inserisco tipo di relazione
	cout << endl << "Inserisci il tipo della relazione da aggiungere : ";
	getline(cin, tipo_relazione);

	//controllo che esista l'id di partenza e identifico il tipo e la posizione
	if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_partenza, tipo_partenza, posizione_partenza))
	{
		//controllo che esista l'id di arrivo e identifico il tipo e la posizione
		if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_arrivo, tipo_arrivo, posizione_arrivo))
		{
			//se salva la relazione
			if (aggiungiRelazioneDaTipi(persona, impresa, associazione, posizione_partenza, tipo_partenza, tipo_arrivo, id_arrivo, tipo_relazione))
			{
				cout << "Relazione aggiunta" << endl;
				aggiunta = true;
				//se è una relazione speculare converte la relazione
				if (relazioneSpeculare(tipo_relazione, relazione_speculare))
				{
					//salva la relazione speculare
					if (aggiungiRelazioneDaTipi(persona, impresa, associazione, posizione_arrivo, tipo_arrivo, tipo_partenza, id_partenza, relazione_speculare))
					{
						cout << "Relazione speculare aggiunta" << endl;
					}
					//se non l'ha salvata
					else
					{
						cout << endl << "Errore : relazione <" << id_arrivo << SEPARATORE << id_partenza << SEPARATORE << relazione_speculare << "> non valida" << endl;
						aggiunta = false;
					}
				}
			}
			//se non l'ha salvata
			else
			{
				cout << endl << "Errore : relazione <" << id_partenza << SEPARATORE << id_arrivo << SEPARATORE << tipo_relazione << "> non valida" << endl;
			}
		}
	}

	return aggiunta;
}

//rimuovi relazione

bool rimuoviRelazioneDaTipi(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const unsigned int &posizione_partenza, const string &tipo_partenza, const string &id_arrivo, const string &tipo_relazione)
{
	bool ok = false;
	//se è un utente semplice
	if (tipo_partenza == ID_TIPO_SEMPLICE)
	{
		ok = persona[posizione_partenza].rimuoviRelazioneSpecifica(id_arrivo, tipo_relazione);
	}
	else
		//se è un utente azienda
		if (tipo_partenza == ID_TIPO_AZIENDA)
		{
			ok = impresa[posizione_partenza].rimuoviRelazioneSpecifica(id_arrivo, tipo_relazione);
		}
		else
			//se è un utente gruppo
			if (tipo_partenza == ID_TIPO_GRUPPO)
			{
				ok = associazione[posizione_partenza].rimuoviRelazioneSpecifica(id_arrivo, tipo_relazione);
			}
	return ok;
}

bool rimuoviRelazione(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	bool rimossa = false;
	string id_partenza;
	string id_arrivo;
	string tipo_relazione;
	string relazione_speculare;
	string tipo_partenza;
	string tipo_arrivo;
	unsigned int posizione_partenza;
	unsigned int posizione_arrivo;

	//inserisco id di partenza
	cout << endl << "Inserisci id di partenza della relazione da rimuovere : ";
	getline(cin, id_partenza);
	//inserisco id di arrivo
	cout << endl << "Inserisci id di arrivo della relazione da rimuovere : ";
	getline(cin, id_arrivo);
	//inserisco tipo di relazione
	cout << endl << "Inserisci il tipo della relazione da rimuovere : ";
	getline(cin, tipo_relazione);

	//controllo che esista l'id di partenza e identifico il tipo e la posizione
	if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_partenza, tipo_partenza, posizione_partenza))
	{
		//controllo che esista l'id di arrivo e identifico il tipo e la posizione
		if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_arrivo, tipo_arrivo, posizione_arrivo))
		{
			//se rimuove la relazione
			if (rimuoviRelazioneDaTipi(persona, impresa, associazione, posizione_partenza, tipo_partenza, id_arrivo, tipo_relazione))
			{
				cout << "Relazione rimossa" << endl;
				rimossa = true;
				//se è una relazione speculare converte la relazione
				if (relazioneSpeculare(tipo_relazione, relazione_speculare))
				{
					//rimuove la relazione speculare
					if (rimuoviRelazioneDaTipi(persona, impresa, associazione, posizione_arrivo, tipo_arrivo, id_partenza, relazione_speculare))
					{
						cout << "Relazione speculare rimossa" << endl;
					}
					//se non l'ha rimossa
					else
					{
						cout << endl << "Errore : relazione <" << id_arrivo << SEPARATORE << id_partenza << SEPARATORE << relazione_speculare << "> non rimossa" << endl;
						rimossa = false;
					}
				}
			}
			//se non l'ha rimossa
			else
			{
				cout << endl << "Errore : relazione <" << id_partenza << SEPARATORE << id_arrivo << SEPARATORE << tipo_relazione << "> non rimossa" << endl;
			}
		}
	}

	return rimossa;
}

//modifica relazione

bool modificaRelazione(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	bool modifica = true;

	return modifica;
}

//cerca relazioni con un utente
void cercaRelazioneUtente(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	string id_utente;
	vector<string> id_arco;
	vector<string> tipo_relazione;
	bool relazione_trovata = false;
	if (almenoUnUtenteEsistente(persona, impresa, associazione))
	{
		//inserisco id utente
		cout << endl << "Inserisci id_utente di cui cercare le relazioni : ";
		getline(cin, id_utente);
		//cerco tra gli utenti semplici
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			id_arco = persona[i].getIdArco();
			tipo_relazione = persona[i].getTipoRelazione();
			//cerco se c'è una relazione con l'utente
			for (unsigned int j = 0; j < id_arco.size(); j++)
			{
				if ((id_arco[j] == id_utente) || (persona[i].getId() == id_utente))
				{
					relazione_trovata = true;
					cout << endl << persona[i].getId() << SEPARATORE << id_arco[j] << SEPARATORE << tipo_relazione[j];
				}
			}
		}
		//cerco tra gli utenti azienda
		for (unsigned int i = 0; i < impresa.size(); i++)
		{
			id_arco = impresa[i].getIdArco();
			tipo_relazione = impresa[i].getTipoRelazione();
			//cerco se c'è una relazione con l'utente
			for (unsigned int j = 0; j < id_arco.size(); j++)
			{
				if ((id_arco[j] == id_utente) || (impresa[i].getId() == id_utente))
				{
					relazione_trovata = true;
					cout << endl << impresa[i].getId() << SEPARATORE << id_arco[j] << SEPARATORE << tipo_relazione[j];
				}
			}
		}
		//cerco tra gli utenti gruppo
		for (unsigned int i = 0; i < associazione.size(); i++)
		{
			id_arco = associazione[i].getIdArco();
			tipo_relazione = associazione[i].getTipoRelazione();
			//cerco se c'è una relazione con l'utente
			for (unsigned int j = 0; j < id_arco.size(); j++)
			{
				if ((id_arco[j] == id_utente) || (associazione[i].getId() == id_utente))
				{
					relazione_trovata = true;
					cout << endl << associazione[i].getId() << SEPARATORE << id_arco[j] << SEPARATORE << tipo_relazione[j];
				}
			}
		}
		//se non ha trovato nessuna relazione
		if (!relazione_trovata)
		{
			cout << endl << "Nessuna Relazione Trovata con L'Utente : " << id_utente << endl;
		}
	}
	else
	{
		cout << "Nessun Utente Inserito nel Database" << endl;
	}
}
