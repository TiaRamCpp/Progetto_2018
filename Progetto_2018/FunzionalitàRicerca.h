#pragma once

#include "GestioneUtenti.h"

bool alberoGenealogicoSingoloUtenteDiscendenti(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, vector<bool> &trattino, string &albero_genealogico, unsigned int &livello_massimo, unsigned int &livello_attuale)
{
	vector<string> figlio;
	vector<string> coniuge;
	vector<unsigned int> posizione_figlio;
	albero_genealogico += persona[posizione_partenza].getId();
	//se trova qualche coniuge o figlio
	if (persona[posizione_partenza].trovaFigliEConiugi(figlio, coniuge))
	{
		//stampo gli eventuali coniugi di lato
		for (unsigned int i = 0; i < coniuge.size(); i++)
		{
			albero_genealogico += " --- " + coniuge[i];
		}
		//calcolo posizione eventuali figli
		posizione_figlio = utenteSemplicePosizioni(persona, figlio);
		if (figlio.size() != 0)
		{
			//incremento conteggio livelli
			livello_attuale++;
			//aggiorno livello massimo se maggiore
			if (livello_attuale > livello_massimo)
				livello_massimo = livello_attuale;
			trattino.push_back(true);
			//stampo gli eventuali figli a capo
			for (unsigned int i = 0; i < figlio.size(); i++)
			{
				//se è l'ultimo figlio
				if (i == figlio.size() - 1)
					trattino[trattino.size() - 1] = false;
				albero_genealogico += '\n';
				for (unsigned int i = 0; i < trattino.size() - 1; i++)
				{
					if (trattino[i])
						albero_genealogico += "|   ";
					else
						albero_genealogico += "    ";
				}
				albero_genealogico += "|---";
				alberoGenealogicoSingoloUtenteDiscendenti(persona, posizione_figlio[i], trattino, albero_genealogico, livello_massimo, livello_attuale);
			}
			livello_attuale--;
			trattino.pop_back();
		}
	}
	return false;
}

bool alberoGenealogicoSingoloUtenteAntenati(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, vector<bool> &trattino, string &albero_genealogico, unsigned int &livello_massimo, unsigned int &livello_attuale)
{
	vector<string> genitore;
	vector<string> coniuge;
	vector<unsigned int> posizione_genitore;
	albero_genealogico += persona[posizione_partenza].getId();
	//se trova qualche coniuge o genitore
	if (persona[posizione_partenza].trovaGenitoriEConiugi(genitore, coniuge))
	{
		//stampo gli eventuali coniugi di lato
		for (unsigned int i = 0; i < coniuge.size(); i++)
		{
			albero_genealogico += " --- " + coniuge[i];
		}
		//calcolo posizione eventuali genitori
		posizione_genitore = utenteSemplicePosizioni(persona, genitore);
		if (genitore.size() != 0)
		{
			//incremento conteggio livelli
			livello_attuale++;
			//aggiorno livello massimo se maggiore
			if (livello_attuale > livello_massimo)
				livello_massimo = livello_attuale;
			trattino.push_back(true);
			//stampo gli eventuali genitori a capo
			for (unsigned int i = 0; i < genitore.size(); i++)
			{
				//se è l'ultimo genitore
				if (i == genitore.size() - 1)
					trattino[trattino.size() - 1] = false;
				albero_genealogico += '\n';
				for (unsigned int i = 0; i < trattino.size() - 1; i++)
				{
					if (trattino[i])
						albero_genealogico += "|   ";
					else
						albero_genealogico += "    ";
				}
				albero_genealogico += "|---";
				alberoGenealogicoSingoloUtenteAntenati(persona, posizione_genitore[i], trattino, albero_genealogico, livello_massimo, livello_attuale);
			}
			livello_attuale--;
			trattino.pop_back();
		}
	}
	return false;
}

void alberoGenealogicoSingoloUtente(const vector<UtenteSemplice> &persona)
{
	bool stampa_su_file = false;
	bool ok = false;
	unsigned int posizione_partenza;
	unsigned int livello_massimo = 0;
	unsigned int livello_attuale = 0;
	string id_partenza;
	string albero_genealogico;
	vector<bool> trattino;

	//inserisco id utente di cui generare l'albero genealogico
	cout << endl << "Inserisci l'Id dell'Utente Semplice di cui calcolare l'Albero Genealogico : ";
	getline(cin, id_partenza);
	//se trova l'utente
	if (trovaPosizioneUtenteSemplice(persona, id_partenza, posizione_partenza))
	{			
		//chiedo se si vuole stampare l'albero genealogico su file
		do
		{
			string scelta_stampa;
			cout << endl << "Vuoi Stampare su un File l'Albero Genealogico ?" << endl;
			cout << "1) SI" << endl;
			cout << "2) NO" << endl;
			cout << endl << "Digitare una Risposta : ";
			getline(cin, scelta_stampa);
			if (scelta_stampa.size() == 1)
			{
				scelta_stampa = scelta_stampa.front();
				//converto in  maiuscolo se minuscolo
				if (islower(scelta_stampa.front()))
				{
					scelta_stampa = toupper(scelta_stampa.front());
				}
				if (scelta_stampa.front() == '1')
				{
					ok = true;
					stampa_su_file = true;
				}
				else
					if (scelta_stampa.front() == '2')
					{
						ok = true;
					}
			}
			if(!ok)
			{
				cout << endl << "Errore : Opzione Non Valida" << endl;
			}
		} while (!ok);

		//genero stringa di stampa discendenti
		alberoGenealogicoSingoloUtenteDiscendenti(persona, posizione_partenza, trattino, albero_genealogico, livello_massimo, livello_attuale);
		//se esiste l'albero dei discendenti
		if (livello_massimo >= 2)
		{
			//stampo a video discendenti
			cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << id_partenza << endl;
			cout << endl << albero_genealogico << endl;
			//se true stampa su file stampo su file discendenti
			if (stampa_su_file)
			{
				ofstream file_output;
				string nome_file_discendenti = id_partenza + "_albero_genealogico_discendenti.txt";
				file_output.open(nome_file_discendenti);
				file_output << albero_genealogico;
				file_output.close();
				cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << id_partenza << " Salvato sul File : " << nome_file_discendenti << endl;
			}
		}
		//se non esiste l'albero dei discendenti
		else
		{
			cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << id_partenza << " Non Esistente" << endl;
		}

		//preparo le variabili per calcolare l'albero degli antenati
		albero_genealogico.clear();
		livello_attuale = 0;
		livello_massimo = 0;
		//genero stringa di stampa antenati
		alberoGenealogicoSingoloUtenteAntenati(persona, posizione_partenza, trattino, albero_genealogico, livello_massimo, livello_attuale);
		//se esiste l'albero degli antenati
		if (livello_massimo >= 2)
		{
			//stampo a video antenati
			cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << id_partenza << endl;
			cout << endl << albero_genealogico << endl;
			//se true stampa su file stampo su file antenati
			if (stampa_su_file)
			{
				ofstream file_output;
				string nome_file_antenati = id_partenza + "_albero_genealogico_antenati.txt";
				file_output.open(nome_file_antenati);
				file_output << albero_genealogico;
				file_output.close();
				cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << id_partenza << " Salvato sul File : " << nome_file_antenati << endl;
			}
		}
		//se non esiste l'albero degli antenati
		else
		{
			cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << id_partenza << " Non Esistente" << endl;
		}
	}
	//se non lo trova
	else
	{
		cout << "Errore : Utente <" << id_partenza << "> Non Trovato" << endl;
	}
}