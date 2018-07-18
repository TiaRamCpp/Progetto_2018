#pragma once

#include "Notizia.h"

#include "GestioneUtenti.h" //per le funzioni che verificano l'esistenza di un id_utente

string stampaNotizieFile(const vector<Notizia> &news, const bool &visualizza_posizione = false)
{
	string output;
	output.clear();
	for (unsigned int i = 0; i < news.size(); i++)
	{
		//se ho bisogno di vedere la posizione per magari selezionarne una
		if (visualizza_posizione)
			output += "Notizia # = '" + to_string(i) + "' : ";
		output += news[i].stampaNotizia();
		//se non è l'ultima riga
		if (i < news.size() - 1)
			output += '\n';
	}
	return output;
}

void stampaNotizie(const vector<Notizia> &news)
{
	if (news.size() != 0)
	{
		cout << "Notizie :";
		for (unsigned int i = 0; i < news.size(); i++)
		{
			cout << endl << endl << news[i].stampaNotiziaEstesa();
		}
	}
	else
	{
		cout << "Nessuna Notizia nel Database" << endl;
	}
	
}

bool aggiungiNotizia(vector<Notizia> &news, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool messaggio_ok = true;
	string id_mittente;
	string messaggio;
	string str_data_pubblicazione;
	Data data_pubblicazione;
	Notizia temp;
	//inserisco id mittente
	cout << endl << "Inserisci id_mittente : ";
	getline(cin, id_mittente);
	//se esiste l'utente
	if (idUtenteTrovato(persona, impresa, associazione, id_mittente))
	{
		//inserisco messaggio
		cout << endl << "Inserisci messaggio : ";
		getline(cin, messaggio);
		//controllo messaggio
		for (unsigned int i = 0; ((i < messaggio.size()) && (messaggio_ok)); i++)
		{
			if (messaggio[i] == SEPARATORE)
			{
				messaggio_ok = false;
				cout << endl << "Errore Messaggio Non Valido" << endl;
			}
		}
		if (messaggio_ok)
		{
			//inserisco data pubblicazione
			cout << endl << "Inserisci data pubblicazione formato (gg/mm/aaaa) : ";
			getline(cin, str_data_pubblicazione);
			//converte la stringa in una data e contemporaneamente verifica che sia valida
			if (data_pubblicazione.convertiStringaAData(str_data_pubblicazione))
			{
				temp.setIdMittente(id_mittente);
				temp.setMessaggio(messaggio);
				temp.setDataPubblicazione(data_pubblicazione);
				//se la notizia non contiene errori
				if (temp.notiziaValida())
				{
					//aggiungo la notizia
					news.push_back(temp);
					modifica = true;
					cout << endl << "Notizia aggiunta" << endl;
				}
				//se non è valida
				else
				{
					cout << endl << "Errore : notizia non valida" << endl;
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : la data di pubblicazione '" << str_data_pubblicazione << "' non e' valida" << endl;
			}
		}
	}
	//id utente non esistente
	else
	{
		cout << endl << "Errore : id_utente '" << id_mittente << "' non esistente" << endl;
	}
	return modifica;
}

bool aggiungiReazioneNotizia(vector<Notizia> &news, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	string str_numero_notizia;
	string id_utente;
	string str_tipo_reazione;
	unsigned int numero_notizia;
	char tipo_reazione;

	//se c'è almeno una notizia
	if (news.size() != 0)
	{
		//stampa notizie
		cout << endl << stampaNotizieFile(news, true) << endl << endl;
		cout << "Seleziona numero notizia a cui aggiungere una reazione : ";
		//inserimento numero notizia
		getline(cin, str_numero_notizia);
		//conversione da stringa a numero e contemporaneamente verifico che non dia errori
		if (convertiANumero(str_numero_notizia, numero_notizia))
		{
			//controllo che sia una notizia esistente
			if ((numero_notizia >= 0) && (numero_notizia < news.size()))
			{
				cout << endl << "Inserisci l'utente che vuole aggiungere una reazione : ";
				getline(cin, id_utente);
				//se esiste l'utente
				if (idUtenteTrovato(persona, impresa, associazione, id_utente))
				{
					//scelta tipo reazione
					cout << endl << "L) " << STR_LIKE;
					cout << endl << "D) " << STR_DISLIKE;
					cout << endl << endl << "Inserisci il tipo di reazione da aggiungere : ";
					getline(cin, str_tipo_reazione);
					//se ha inserito solo una lettera
					if (str_tipo_reazione.size() == 1)
					{
						tipo_reazione = str_tipo_reazione.front();
						//formatto
						if (islower(tipo_reazione))
							tipo_reazione = toupper(tipo_reazione);
						switch (tipo_reazione)
						{
						case 'L':
						{
							//se aggiunge la notizia
							if (news[numero_notizia].aggiungiLike(id_utente))
							{
								modifica = true;
								cout << endl << "Like aggiunto" << endl;
							}
							//se non l'aggiunge
							else
							{
								cout << endl << "L'utente = '" << id_utente << "' ha gia' messo una reazione a questa notizia" << endl;
							}
						}
						break;
						case 'D':
						{
							//se aggiunge la notizia
							if (news[numero_notizia].aggiungiDislike(id_utente))
							{
								modifica = true;
								cout << endl << "Dislike aggiunto" << endl;
							}
							//se non l'aggiunge
							else
							{
								cout << endl << "L'utente = '" << id_utente << "' ha gia' messo una reazione a questa notizia" << endl;
							}
						}
						break;
						default:
						{
							cout << endl << "Errore : tipo reazione non valida" << endl;
						}
						break;
						}
					}
					//se ha inserito troppe lettere
					else
					{
						cout << endl << "Errore : troppe lettere inserite" << endl;
					}
				}
				//id utente non esistente
				else
				{
					cout << endl << "Errore : id_utente '" << id_utente << "' non esistente" << endl;
				}
			}
			//numero errato
			else
			{
				cout << endl << "Errore : numero notizia non esistente" << endl;
			}
		}
	}
	else
	{
		cout << endl << "Nessuna notizia inserita nel database" << endl;
	}
	return modifica;
}

bool rimuoviNotizia(vector<Notizia> &news)
{
	bool modifica = false;
	string str_numero_notizia;
	unsigned int numero_notizia;

	//se c'è almeno una notizia
	if (news.size() != 0)
	{
		//stampa notizie
		cout << endl << stampaNotizieFile(news, true) << endl << endl;
		cout << "Seleziona numero notizia da rimuovere : ";
		//inserimento numero notizia
		getline(cin, str_numero_notizia);
		//conversione da stringa a numero e contemporaneamente verifico che non dia errori
		if (convertiANumero(str_numero_notizia, numero_notizia))
		{
			//controllo che sia una notizia esistente
			if ((numero_notizia >= 0) && (numero_notizia < news.size()))
			{
				//rimuovo notizia corrispondente
				news.erase(news.begin() + numero_notizia);
				modifica = true;
				cout << endl << "Notizia rimossa" << endl;
			}
			//numero errato
			else
			{
				cout << endl << "Errore : numero notizia non esistente" << endl;
			}
		}
	}
	else
	{
		cout << endl << "Nessuna notizia inserita nel database" << endl;
	}
	return modifica;
}

bool rimuoviReazioneNotizia(vector<Notizia> &news)
{
	bool modifica = false;
	string str_numero_notizia;
	unsigned int numero_notizia;
	string id_utente;

	//se c'è almeno una notizia
	if (news.size() != 0)
	{
		//stampa notizie
		cout << endl << stampaNotizieFile(news, true) << endl << endl;
		cout << "Seleziona numero notizia da cui rimuovere la reazione : ";
		//inserimento numero notizia
		getline(cin, str_numero_notizia);
		//conversione da stringa a numero e contemporaneamente verifico che non dia errori
		if (convertiANumero(str_numero_notizia, numero_notizia))
		{
			//controllo che sia una notizia esistente
			if ((numero_notizia >= 0) && (numero_notizia < news.size()))
			{
				cout << endl << news[numero_notizia] << endl;
				cout << "Digita l'id_utente di cui rimuovere la reazione : ";
				//inserimento id utente
				getline(cin, id_utente);
				//rimuovo id utente dalla notizia
				if (news[numero_notizia].rimuoviReazione(id_utente))
				{
					modifica = true;
					cout << endl << "Reazione rimossa" << endl;
				}
				//se non viene rimossa
				else
				{
					cout << "L'utente = '" << id_utente << "' non ha messo nessuna reazione a questa notizia" << endl;
				}
			}
			//numero errato
			else
			{
				cout << endl << "Errore : numero notizia non esistente" << endl;
			}
		}
	}
	else
	{
		cout << endl << "Nessuna notizia inserita nel database" << endl;
	}
	return modifica;
}

void cercaNotiziaMittente(const vector<Notizia> &news)
{
	string id_mittente;
	vector<unsigned int> posizione;
	if (news.size() != 0)
	{
		//inserisco id utente
		cout << endl << "Inserisci id_utente di cui cercare le notizie pubblicate : ";
		getline(cin, id_mittente);
		for (unsigned int i = 0; i < news.size(); i++)
			if (news[i].getIdMittente() == id_mittente)
				posizione.push_back(i);
		//se ne ha trovato qualche notizia
		if (posizione.size() != 0)
		{
			cout << endl << "Notizia/e Pubblicata/e da : " << id_mittente;
			for (unsigned int i = 0; i < posizione.size(); i++)
			{
				cout << endl << endl << news[posizione[i]].stampaNotiziaEstesa();
			}
		}
		//se non ne ha trovata nemmeno una
		else
		{
			cout << endl << "Nessuna Notizia Pubblicata da : " << id_mittente;
		}
	}
	else
	{
		cout << "Nessuna Notizia Inserita nel Database" << endl;
	}
}

void cercaNotiziaReazione(const vector<Notizia> &news)
{
	string id_utente;
	vector<unsigned int> posizione;
	vector<string> like;
	vector<string> dislike;
	vector<string> tipo_reazione;
	bool trovata_reazione;

	if (news.size() != 0)
	{
		//inserisco id utente
		cout << endl << "Inserisci id_utente di cui cercare le reazioni : ";
		getline(cin, id_utente);
		for (unsigned int i = 0; i < news.size(); i++)
		{
			trovata_reazione = false;
			like = news[i].getLike();
			dislike = news[i].getDislike();
			//cerco se ha messo like
			for (unsigned int j = 0; ((j < like.size()) && (!trovata_reazione)); j++)
			{
				if (like[j] == id_utente)
				{
					trovata_reazione = true;
					posizione.push_back(i);
					tipo_reazione.push_back(STR_LIKE);
				}
			}
			//cerco se ha messo dislike
			for (unsigned int j = 0; ((j < dislike.size()) && (!trovata_reazione)); j++)
			{
				if (dislike[j] == id_utente)
				{
					trovata_reazione = true;
					posizione.push_back(i);
					tipo_reazione.push_back(STR_DISLIKE);
				}
			}
		}
		//se ne ha trovato qualche notizia a cui messo una reazione
		if (posizione.size() != 0)
		{
			cout << endl << "Notizia/e Pubblicata/e con delle Reazioni dell'Utente : " << id_utente;
			for (unsigned int i = 0; i < posizione.size(); i++)
			{
				cout << endl << endl << news[posizione[i]].stampaNotiziaEstesa();
				cout << endl << "Tipo Reazione Inserita dall'Utente : " << tipo_reazione[i]<<endl;
			}
		}
		//se non ne ha trovata nemmeno una
		else
		{
			cout << endl << "L'Utente " << id_utente << " Non ha messo Nessuna Reazione";
		}
	}
	else
	{
		cout << "Nessuna Notizia Inserita nel Database" << endl;
	}
}
