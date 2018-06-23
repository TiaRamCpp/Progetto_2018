#pragma once

#include "Notizia.h"

#include "GestioneUtenti.h" //per le funzioni che verificano l'esistenza di un id_utente

//stampa
string stampaNotizie(const vector<Notizia> &news, const bool &visualizza_posizione = false)
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

bool convertiANumero(const string &str_numero_notizia, unsigned int &numero_notizia)
{
	//converte la stringa a un numero ma per sicurezza verifica che siano presenti solo cifre per evitare errori di conversione tramite stoi()
	
	bool convertita = false;
	bool solo_cifre = true;
	
	//controllo che ci siano solo cifre
	for (unsigned int i = 0; ((i < str_numero_notizia.size()) && (solo_cifre)); i++)
		//se non è una cifra
		if (!isdigit(str_numero_notizia[i]))
			solo_cifre = false;

	//se c'erano solo cifre
	if (solo_cifre)
	{
		//conversione da stringa a numero
		numero_notizia = stoi(str_numero_notizia);
		convertita = true;
	}
	//caratteri non validi
	else
	{
		cout << endl << "Errore : inserisci solo cifre" << endl;
	}

	return convertita;
}

bool aggiungiNotizia(vector<Notizia> &news, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
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
		cout << endl << stampaNotizie(news, true) << endl << endl;
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
		cout << endl << stampaNotizie(news, true) << endl << endl;
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
		cout << endl << stampaNotizie(news, true) << endl << endl;
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
