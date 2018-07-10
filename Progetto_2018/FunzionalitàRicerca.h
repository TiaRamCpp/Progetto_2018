#pragma once

#include "GestioneUtenti.h"
#include "GestioneStringhe.h"

//ALBERO GENEAOLOGICO

void alberoGenealogicoSingoloUtenteDiscendenti(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, vector<bool> &trattino, string &albero_genealogico, unsigned int &livello_massimo, unsigned int &livello_attuale)
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
				albero_genealogico += "|___";
				alberoGenealogicoSingoloUtenteDiscendenti(persona, posizione_figlio[i], trattino, albero_genealogico, livello_massimo, livello_attuale);
			}
			livello_attuale--;
			trattino.pop_back();
		}
	}
}

void alberoGenealogicoSingoloUtenteAntenati(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, vector<bool> &trattino, string &albero_genealogico, unsigned int &livello_massimo, unsigned int &livello_attuale)
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

	if (persona.size() != 0)
	{
		//inserisco id utente di cui generare l'albero genealogico
		cout << endl << "Inserisci l'Id dell'Utente Semplice di cui calcolare l'Albero Genealogico : ";
		getline(cin, id_partenza);
		//se trova l'utente
		if (trovaPosizioneUtenteSemplice(persona, id_partenza, posizione_partenza))
		{
			//chiedo se si vuole salvare gli eventuali alberi genealogici su file
			do
			{
				string scelta_stampa;
				cout << endl << "Vuoi Salvare su un File gli Eventuali Alberi Genealogici ?" << endl;
				cout << "1) SI" << endl;
				cout << "2) NO" << endl;
				cout << endl << "Digitare una Risposta : ";
				getline(cin, scelta_stampa);
				if (scelta_stampa.size() == 1)
				{
					scelta_stampa = scelta_stampa.front();
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
				if (!ok)
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
			trattino.clear();
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
	else
	{
		cout << endl << "Nessun Utente Semplice inserito nel Database" << endl;
	}
}

void alberiGenealogiciTotali(const vector<UtenteSemplice> &persona)
{
	bool stampa_su_file = false;
	bool ok = false;
	unsigned int livello_massimo;
	unsigned int livello_attuale;
	string albero_genealogico;
	vector<bool> trattino;

	if (persona.size() != 0)
	{
		//chiedo se si vuole salvare gli eventuali alberi genealogici su file
		do
		{
			string scelta_stampa;
			cout << endl << "Vuoi Salvare su un File gli Eventuali Alberi Genealogici ?" << endl;
			cout << "1) SI" << endl;
			cout << "2) NO" << endl;
			cout << endl << "Digitare una Risposta : ";
			getline(cin, scelta_stampa);
			if (scelta_stampa.size() == 1)
			{
				scelta_stampa = scelta_stampa.front();
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
			if (!ok)
			{
				cout << endl << "Errore : Opzione Non Valida" << endl;
			}
		} while (!ok);

		//per ogni utente genero l'eventuale coppia di alberi genialogici individuali
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			//preparo le variabili per calcolare l'albero dei discendenti
			albero_genealogico.clear();
			trattino.clear();
			livello_attuale = 0;
			livello_massimo = 0;

			//genero stringa di stampa discendenti
			alberoGenealogicoSingoloUtenteDiscendenti(persona, i, trattino, albero_genealogico, livello_massimo, livello_attuale);
			//se esiste l'albero dei discendenti
			if (livello_massimo >= 2)
			{
				//stampo a video discendenti
				cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << persona[i].getId() << endl;
				cout << endl << albero_genealogico << endl;
				//se true stampa su file stampo su file discendenti
				if (stampa_su_file)
				{
					ofstream file_output;
					string nome_file_discendenti = persona[i].getId() + "_albero_genealogico_discendenti.txt";
					file_output.open(nome_file_discendenti);
					file_output << albero_genealogico;
					file_output.close();
					cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << persona[i].getId() << " Salvato sul File : " << nome_file_discendenti << endl;
				}
			}
			//se non esiste l'albero dei discendenti
			else
			{
				cout << endl << "Albero Genealogico dei Discendenti dell'Utente : " << persona[i].getId() << " Non Esistente" << endl;
			}

			//preparo le variabili per calcolare l'albero degli antenati
			albero_genealogico.clear();
			trattino.clear();
			livello_attuale = 0;
			livello_massimo = 0;

			//genero stringa di stampa antenati
			alberoGenealogicoSingoloUtenteAntenati(persona, i, trattino, albero_genealogico, livello_massimo, livello_attuale);
			//se esiste l'albero degli antenati
			if (livello_massimo >= 2)
			{
				//stampo a video antenati
				cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << persona[i].getId() << endl;
				cout << endl << albero_genealogico << endl;
				//se true stampa su file stampo su file antenati
				if (stampa_su_file)
				{
					ofstream file_output;
					string nome_file_antenati = persona[i].getId() + "_albero_genealogico_antenati.txt";
					file_output.open(nome_file_antenati);
					file_output << albero_genealogico;
					file_output.close();
					cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << persona[i].getId() << " Salvato sul File : " << nome_file_antenati << endl;
				}
			}
			//se non esiste l'albero degli antenati
			else
			{
				cout << endl << "Albero Genealogico degli Antenati dell'Utente : " << persona[i].getId() << " Non Esistente" << endl;
			}
		}
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
}

//LUPI SOLITARI

void ricercaLupiSolitari(const vector<UtenteSemplice> &persona, const vector<Notizia> &news)
{
	bool modifica_valori = false;
	bool ok = false;

	//variabili per il conteggio dei tipi di relazione
	vector<string> tipo_relazione(2);
	vector<unsigned int> numero_tipo_relazione(2);
	tipo_relazione[0] = STR_DIPENDENTE;
	tipo_relazione[1] = STR_MEMBRO;

	//variabili per il conteggio degli interventi nelle news
	vector<string> id_intervento;
	vector<string> id_like;
	vector<string> id_dislike;
	vector<unsigned int> posizione_persona_intervento_news;

	//variabili per il conteggio di ogni parametro per ogni utente
	vector<unsigned int> numero_relazioni_totali(persona.size());  
	vector<unsigned int> numero_aziende_dipendente(persona.size());  
	vector<unsigned int> numero_appartenenza_gruppo(persona.size());
	vector<unsigned int> numero_interventi_news(persona.size());

	//variabili per il valore ponderato di ogni parametro
	double valore_relazione = 5;
	double valore_aziende_dipendente = 50;
	double valore_appartenenza_gruppo = 30;
	double valore_intervento_news = 1;

	//variabili per il punteggio di ogni utente e per la determinazione dei lupi solitari
	vector<double> punteggio(persona.size());
	double media_punteggio = 0;
	double percentuale_sotto_la_media = 0; //in percentuale
	bool almeno_un_lupo_solitario = false;

	if (persona.size() != 0)
	{
		//chiedo se si vuole modificare i valori dei parametri di default
		do
		{
			string scelta;
			cout << endl << "Vuoi Modificare i Valori di Default per il Calcolo dei Lupi Solitari ?" << endl;
			cout << "1) SI" << endl;
			cout << "2) NO" << endl;
			cout << endl << "Digitare una Risposta : ";
			getline(cin, scelta);
			if (scelta.size() == 1)
			{
				scelta = scelta.front();
				if (scelta.front() == '1')
				{
					ok = true;
					modifica_valori = true;
				}
				else
					if (scelta.front() == '2')
					{
						ok = true;
					}
			}
			if (!ok)
			{
				cout << endl << "Errore : Opzione Non Valida" << endl;
			}
		} while (!ok);

		//se vuole modificare i valori dei parametri di default
		if (modifica_valori)
		{
			string nuovo_valore_relazione;
			string nuovo_valore_aziende_dipendente;
			string nuovo_valore_appartenenza_gruppo;
			string nuovo_valore_intervento_news;
			string nuovo_valore_percentuale_sotto_la_media;

			//inserimento nuovo_valore_relazione
			do
			{
				cout << endl << "Valore Attuale Relazione : " << valore_relazione;
				cout << endl << "Inserire Nuovo Valore Relazione Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_relazione);
			} while (!convertiANumero(nuovo_valore_relazione, valore_relazione));

			//inserimento nuovo_valore_aziende_dipendente
			do
			{
				cout << endl << "Valore Attuale Lavoro per un'Azienda : " << valore_aziende_dipendente;
				cout << endl << "Inserire Nuovo Valore Lavoro per un'Azienda Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_aziende_dipendente);
			} while (!convertiANumero(nuovo_valore_aziende_dipendente, valore_aziende_dipendente));

			//inserimento nuovo_valore_appartenenza_gruppo
			do
			{
				cout << endl << "Valore Attuale Appartenenza ad un Gruppo : " << valore_appartenenza_gruppo;
				cout << endl << "Inserire Nuovo Valore Appartenenza ad un Gruppo Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_appartenenza_gruppo);
			} while (!convertiANumero(nuovo_valore_appartenenza_gruppo, valore_appartenenza_gruppo));

			//inserimento nuovo_valore_intervento_news
			do
			{
				cout << endl << "Valore Attuale Intervento News : " << valore_intervento_news;
				cout << endl << "Inserire Nuovo Valore Intervento News Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_intervento_news);
			} while (!convertiANumero(nuovo_valore_intervento_news, valore_intervento_news));

			//inserimento nuovo_valore_percentuale_sotto_la_media
			double temp = percentuale_sotto_la_media;
			do
			{
				do
				{
					cout << endl << "Il Valore Percentuale Sotto la Media Rappresenta di quanto ( in Percentuale ) un Punteggio di un'Utente rispetto alla Media dei Punteggi viene considerato un Lupo Solitario";
					cout << endl << "Piu' il Valore e' Alto e si avvicina a 100 e piu' il Criterio sara' Selettivo" << endl;
					cout << endl << "Esempio_1) Valore Percentuale Sotto la Media = 0";
					cout << endl << "Esempio_1) Media = 100";
					cout << endl << "Tutti gli Utenti con un Punteggio Inferiore a 100 sono considerati dei Lupi Solitari";
					cout << endl << "Esempio_2) Valore Percentuale Sotto la Media = 30";
					cout << endl << "Esempio_2) Media = 100";
					cout << endl << "Tutti gli Utenti con un Punteggio Inferiore a 70 sono considerati dei Lupi Solitari" << endl;
					cout << endl << "Valore Attuale Percentuale Sotto la Media : " << temp;
					cout << endl << "Inserire Nuovo Valore Percentuale Sotto la Media Eventualmente con la Virgola ma Compreso tra 0 e 100 : ";
					getline(cin, nuovo_valore_percentuale_sotto_la_media);
				} while (!convertiANumero(nuovo_valore_percentuale_sotto_la_media, percentuale_sotto_la_media));
			} while ((percentuale_sotto_la_media < 0) || (percentuale_sotto_la_media > 100));
			percentuale_sotto_la_media /= 100;
		}

		//conteggio di ogni parametro per ogni utente
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			//calcolo contemporaneamente di quante aziende è dipendente e a quanti gruppi appartiene
			persona[i].contaTipiRelazione(tipo_relazione, numero_tipo_relazione);
			//calcolo relazioni totali con altri utenti
			numero_relazioni_totali[i] = persona[i].getIdArco().size();
			//salvo numero aziende di cui e dipendente
			numero_aziende_dipendente[i] = numero_tipo_relazione[0];
			//salvo numero di gruppi di cui e dipendente
			numero_appartenenza_gruppo[i] = numero_tipo_relazione[1];
			//inzializzo contatore da utilizzare successivamente
			numero_interventi_news[i] = 0;
		}

		//conteggio degli interventi nelle news per ogni utente
		for (unsigned int i = 0; i < news.size(); i++)
		{
			id_intervento.clear();
			//per scandire solo una volta tutti gli utenti per ogni news e per non scandire tutti gli utenti per ogni like o dislike
			id_like = news[i].getLike();
			id_dislike = news[i].getDislike();
			for (unsigned int j = 0; j < id_like.size(); j++)
			{
				id_intervento.push_back(id_like[j]);
			}
			for (unsigned int j = 0; j < id_dislike.size(); j++)
			{
				id_intervento.push_back(id_dislike[j]);
			}
			//calcolo contemporaneamente le posizioni di ogni reazione sapendo che non possono esserci reazioni multiple per uno stesso utente
			posizione_persona_intervento_news = utenteSemplicePosizioni(persona, id_intervento);
			//incremento il contatore per ogni posizione di un utente
			for (unsigned int j = 0; j < posizione_persona_intervento_news.size(); j++)
			{
				numero_interventi_news[posizione_persona_intervento_news[j]]++;
			}
		}

		//calcolo punteggio di ogni utente
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			punteggio[i] = valore_relazione * numero_relazioni_totali[i];
			punteggio[i] += valore_aziende_dipendente * numero_aziende_dipendente[i];
			punteggio[i] += valore_appartenenza_gruppo * numero_appartenenza_gruppo[i];
			punteggio[i] += valore_intervento_news * numero_interventi_news[i];
			//calcolo media punteggio preliminare prima di dividere per gli utenti semplici totali
			media_punteggio += punteggio[i];
		}
		//calcolo media punteggio
		media_punteggio /= persona.size();

		//stampa elenco eventuali lupi solitari
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			if (punteggio[i] < (media_punteggio * (1 - percentuale_sotto_la_media)))
			{
				//se è il primo lupo solitario trovato
				if (!almeno_un_lupo_solitario)
				{
					cout << endl << "Media Punteggio degli Utenti Semplici nel Database : " << media_punteggio;
					cout << endl << "Soglia Punteggio : " << media_punteggio * (1 - percentuale_sotto_la_media);
					cout << endl << "Lupi Solitari :" << endl;
					cout << setw(56) << setfill('_') << "_";
					cout << setfill(' ') << endl << "| " << stampaSinistra(37, "Utente Semplice") << " |" << setw(13) << "Punteggio" << " |" << endl;
					cout << setw(56) << setfill('-') << "-" << endl;
					cout << setfill(' ');
					almeno_un_lupo_solitario = true;
				}
				cout << "| " << stampaSinistra(37, persona[i].getId()) << " |" << setw(13) << punteggio[i] << " |" << endl;
			}
		}
		//se non ha trovato nessun lupo solitario
		if (!almeno_un_lupo_solitario)
		{
			cout << endl << "Nessun Lupo Solitario Trovato" << endl;
		}
		else
		{
			cout << setw(56) << setfill('-') << "-" << endl;
			cout << setfill(' ');
		}
	}
	else
	{
		cout << endl << "Nessun utente semplice inserito nel database" << endl;
	}
}

//SIMPATIA AZIENDA

double simpatiaAzienda(const string &id_azienda, const vector<Notizia> &news, const double &valore_like, const double &valore_dislike)
{
	double simpatia = 0;
	for (unsigned int i = 0; i < news.size(); i++)
		if (news[i].getIdMittente() == id_azienda)
			simpatia += ((news[i].getLike().size() * valore_like) - (news[i].getDislike().size() * valore_dislike));
	return simpatia;
}

void ordinaAziendaPerSimpatia(const vector<UtenteAzienda> &impresa, const vector<Notizia> &news)
{
	vector<double> simpatia(impresa.size());
	vector<double> simpatia_consociate(impresa.size());
	vector<string> id_azienda(impresa.size());
	double valore_like = 1;
	double valore_dislike = 2;
	bool con_consociate = false;
	bool modifica_valore = false;
	bool ok = false;

	if (impresa.size() != 0)
	{
		//chiedo se si vuole contar nel punteggio anche le consociate
		do
		{
			string scelta;
			cout << endl << "Vuoi Includere nel Conteggio anche il Punteggio delle Aziende Consociate ?" << endl;
			cout << "1) SI" << endl;
			cout << "2) NO" << endl;
			cout << endl << "Digitare una Risposta : ";
			getline(cin, scelta);
			if (scelta.size() == 1)
			{
				scelta = scelta.front();
				if (scelta.front() == '1')
				{
					ok = true;
					con_consociate = true;
				}
				else
					if (scelta.front() == '2')
					{
						ok = true;
					}
			}
			if (!ok)
			{
				cout << endl << "Errore : Opzione Non Valida" << endl;
			}
		} while (!ok);

		//chiedo se si vuole modificare il peso dei like/dislike
		ok = false;
		do
		{
			string scelta;
			cout << endl << "Vuoi Modificare il Peso dei Like e Dislike ?" << endl;
			cout << "1) SI" << endl;
			cout << "2) NO" << endl;
			cout << endl << "Digitare una Risposta : ";
			getline(cin, scelta);
			if (scelta.size() == 1)
			{
				scelta = scelta.front();
				if (scelta.front() == '1')
				{
					ok = true;
					modifica_valore = true;
				}
				else
					if (scelta.front() == '2')
					{
						ok = true;
					}
			}
			if (!ok)
			{
				cout << endl << "Errore : Opzione Non Valida" << endl;
			}
		} while (!ok);

		//se si vuole modificare il peso dei like / dislike
		if (modifica_valore)
		{
			string nuovo_valore_like;
			string nuovo_valore_dislike;
			do
			{
				cout << endl << "Valore Attuale Like : " << valore_like;
				cout << endl << "Inserire Nuovo Valore Like Positivo Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_like);
			} while (!convertiANumero(nuovo_valore_like, valore_like));
			do
			{
				cout << endl << "Valore Attuale Dislike : " << valore_dislike;
				cout << endl << "Inserire Nuovo Valore Dislike Positivo (ma saranno contati Negativamente) Eventualmente con la Virgola : ";
				getline(cin, nuovo_valore_dislike);
			} while (!convertiANumero(nuovo_valore_dislike, valore_dislike));
		}

		//calcolo la simpatia di ogni azienda
		for (unsigned int i = 0; i < impresa.size(); i++)
		{
			simpatia[i] = simpatiaAzienda(impresa[i].getId(), news, valore_like, valore_dislike);
			simpatia_consociate[i] = 0;
			id_azienda[i] = impresa[i].getId();
		}

		//se si vuole contare anche il punteggio delle consociate lo calcolo e lo sommo
		if (con_consociate)
		{
			vector<string> id_arco;
			vector<string> tipo_relazione;
			for (unsigned int i = 0; i < impresa.size(); i++)
			{
				id_arco = impresa[i].getIdArco();
				tipo_relazione = impresa[i].getTipoRelazione();
				for (unsigned int j = 0; j < tipo_relazione.size(); j++)
				{
					if (tipo_relazione[j] == STR_CONSOCIATA)
					{
						simpatia_consociate[i] += simpatia[utenteAziendaPosizione(impresa, id_arco[j])];
					}
				}
			}
		}

		//ordino le aziende dalla più simpatica in giù
		for (unsigned int i = 0; i < id_azienda.size(); i++)
		{
			for (unsigned int j = i; j < id_azienda.size(); j++)
			{
				if (simpatia[i] + simpatia_consociate[i] < simpatia[j] + simpatia_consociate[j])
				{
					swap(simpatia[i], simpatia[j]);
					swap(simpatia_consociate[i], simpatia_consociate[j]);
					swap(id_azienda[i], id_azienda[j]);
				}
			}
		}

		//stampo le aziende ordinate
		cout << endl << "Aziende Ordinate per Simpatia :" << endl;
		cout << setw(56) << setfill('_') << "_";
		cout << setfill(' ') << endl << "| " << stampaSinistra(37, "Azienda") << " |" << setw(13) << "Punteggio" << " |" << endl;
		cout << setw(56) << setfill('-') << "-" << endl;
		cout << setfill(' ');
		for (unsigned int i = 0; i < id_azienda.size(); i++)
		{
			cout << "| " << stampaSinistra(37, id_azienda[i]) << " |" << setw(13) << simpatia[i] + simpatia_consociate[i] <<" |"<< endl;
		}
		cout << setw(56) << setfill('-') << "-" << endl;
		cout << setfill(' ');
	}
	else
	{
		cout << endl << "Nessun Utente Azienda inserito nel Database" << endl;
	}
}
