#pragma once

#include "Notizia.h"

#include "Gestione_Utenti.h" //per le funzioni che verificano l'esistenza di un id_utente

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
	cin >> id_mittente;
	//se esiste l'utente
	if (idUtenteTrovato(persona, impresa, associazione, id_mittente))
	{
		//inserisco messaggio
		cout << endl << "Inserisci messaggio : ";
		//preparazione lettura riga eliminando '\n'
		cin.ignore(1, '\n');
		getline(cin, messaggio);
		//inserisco data pubblicazione
		cout << endl << "Inserisci data pubblicazione formato (gg/mm/aaaa) : ";
		cin >> str_data_pubblicazione;
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
	unsigned int numero_notizia;
	char tipo_reazione;

	//stampa notizie
	cout << endl << stampaNotizie(news, true) << endl << endl;
	cout << "Seleziona numero notizia a cui aggiungere una reazione : ";
	//inserimento numero notizia
	cin >> str_numero_notizia;
	//conversione da stringa a numero
	numero_notizia = stoi(str_numero_notizia);
	//controllo che sia una notizia esistente
	if ((numero_notizia >= 0) && (numero_notizia < news.size()))
	{
		cout << endl << "Inserisci l'utente che vuole aggiungere una reazione : ";
		cin >> id_utente;
		//se esiste l'utente
		if (idUtenteTrovato(persona, impresa, associazione, id_utente))
		{
			//scelta tipo reazione
			cout << endl << "L) " << STR_LIKE;
			cout << endl << "D) " << STR_DISLIKE;
			cout << endl << endl << "Inserisci il tipo di reazione da aggiungere : ";
			cin >> tipo_reazione;
			//formatto
			if (isalpha(tipo_reazione))
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
	return modifica;
}

bool rimuoviNotizia(vector<Notizia> &news)
{
	bool modifica = false;
	string str_numero_notizia;
	unsigned int numero_notizia;
	//stampa notizie
	cout << endl << stampaNotizie(news, true) << endl << endl;
	cout << "Seleziona numero notizia da rimuovere : ";
	//inserimento numero notizia
	cin >> str_numero_notizia;
	//conversione da stringa a numero
	numero_notizia = stoi(str_numero_notizia);
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
	return modifica;
}

bool rimuoviReazioneNotizia(vector<Notizia> &news)
{
	bool modifica = false;
	string str_numero_notizia;
	unsigned int numero_notizia;
	string id_utente;
	//stampa notizie
	cout << endl << stampaNotizie(news, true) << endl << endl;
	cout << "Seleziona numero notizia da cui rimuovere la reazione : ";
	//inserimento numero notizia
	cin >> str_numero_notizia;
	//conversione da stringa a numero
	numero_notizia = stoi(str_numero_notizia);
	//controllo che sia una notizia esistente
	if ((numero_notizia >= 0) && (numero_notizia < news.size()))
	{
		cout << endl << news[numero_notizia] << endl;
		cout << "Digita l'id_utente di cui rimuovere la reazione : ";
		//inserimento id utente
		cin >> id_utente;
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
	return modifica;
}