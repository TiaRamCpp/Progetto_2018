#pragma once

#include "GestioneUtenti.h"

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

string stampaRelazioni(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
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

bool salvaRelazioneDaId(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &id_partenza, const string &id_arrivo, const string &tipo_relazione)
{
	bool ok = true;
	unsigned int posizione;
	UtenteSemplice temp;
	
	//controllo se l'utente di arrivo esiste
	if (idUtenteTrovato(persona, impresa, associazione, id_arrivo))
	{
		//controllo che il tipo di relazione sia esistente
		if (temp.tipoRelazioneEsistente(tipo_relazione))
		{
			//se è un utente semplice
			if (trovaPosizioneUtenteSemplice(persona, id_partenza, posizione))
			{
				persona[posizione].aggiungiRelazione(id_arrivo, tipo_relazione);
			}
			else
				//se è un utente azienda
				if (trovaPosizioneUtenteAzienda(impresa, id_partenza, posizione))
				{
					impresa[posizione].aggiungiRelazione(id_arrivo, tipo_relazione);
				}
				else
					//se è un utente gruppo
					if (trovaPosizioneUtenteGruppo(associazione, id_partenza, posizione))
					{
						associazione[posizione].aggiungiRelazione(id_arrivo, tipo_relazione);
					}
		}
		//se non esiste il tipo di relazione
		else
		{
			cerr << endl << "Errore : il tipo relazione <" << tipo_relazione << "> non esiste" << endl;
			ok = false;
		}
	}
	//id utente di arrivo non esistente
	else
	{
		cerr << endl << "Errore : id utente <" << id_arrivo << "> non esistente" << endl;
		ok = false;
	}
	
	return ok;
}