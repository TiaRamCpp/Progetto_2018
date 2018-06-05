#pragma once

#include "Data.h"

#include "Utente_Semplice.h"
#include "Utente_Azienda.h"
#include "Utente_Gruppo.h"

#include "Notizia.h"

//id esistente
bool id_utente_semplice_trovato(const vector<Utente_Semplice> &persona, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < persona.size()) && (!trovato)); i++)
		if (persona[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_azienda_trovato(const vector<Utente_Azienda> &impresa, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < impresa.size()) && (!trovato)); i++)
		if (impresa[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_gruppo_trovato(const vector<Utente_Gruppo> &associazione, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < associazione.size()) && (!trovato)); i++)
		if (associazione[i].get_Id() == id_utente)
			trovato = true;
	return trovato;
}
bool id_utente_trovato(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const string &id_utente)
{
	//se una condizione è verificata non esegue inutilmente le successive
	return (id_utente_semplice_trovato(persona, id_utente)) || (id_utente_azienda_trovato(impresa, id_utente)) || (id_utente_gruppo_trovato(associazione, id_utente));
}

//aggiornamento file
void aggiorna_file_utenti(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const string &nome_file_utenti)
{
	ofstream file_output;
	file_output.open(nome_file_utenti);
	//stampa utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
		file_output << persona[i] << endl;
	//stampa utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
		file_output << impresa[i] << endl;
	//stampa utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		file_output << associazione[i];
		//se non è l'ultima riga
		if (i < persona.size() - 1)
			file_output << endl;
	}
	file_output.close();
}
void aggiorna_file_notizie(const vector<Notizia> &news, const string &nome_file_notizie)
{
	ofstream file_output;
	file_output.open(nome_file_notizie);
	for (unsigned int i = 0; i < news.size(); i++)
	{
		file_output << news[i];
		//se non è l'ultima riga
		if (i < news.size() - 1)
			file_output << endl;
	}
	file_output.close();
}
//void aggiorna_file_relazioni(...);
void aggiorna_file(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const vector<Notizia> &news, const string &nome_file_utenti, const string &nome_file_notizie)
{
	aggiorna_file_utenti(persona, impresa, associazione, nome_file_utenti);
	aggiorna_file_notizie(news, nome_file_notizie);
	//aggiungi aggiorna file relazioni e aggiungi variabili da passare;
}

//stampa dati
string stampa_utenti(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione)
{
	string output;
	output.clear();
	//stampa utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
		output += persona[i].stampa_Utente_Semplice() + "\n";
	//stampa utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
		output += impresa[i].stampa_Utente_Azienda() + "\n";
	//stampa utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		output += associazione[i].stampa_Utente_Gruppo();
		//se non è l'ultima riga
		if (i < persona.size() - 1)
			output += "\n";
	}
	return output;
}
string stampa_notizie(const vector<Notizia> &news)
{
	string output;
	output.clear();
	for (unsigned int i = 0; i < news.size(); i++)
	{
		output += news[i].stampa_Notizia();
		//se non è l'ultima riga
		if (i < news.size() - 1)
			output += "\n";
	}
	return output;
}
//string stampa_relazioni(...);
string stampa_dati(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const vector<Notizia> &news)
{
	string output = stampa_utenti(persona, impresa, associazione) + "\n";
	output += stampa_notizie(news);
	//aggiungi stampa relazioni e aggiungi variabili da passare;
	return output;
}

//lettura valore informazioni
string leggi_fino_a(ifstream &file_lettura, const char &fine)
{
	bool stop = false;
	char carattere;
	string output;
	output.clear();
	while ((!file_lettura.eof()) && (!stop))
	{
		//file_lettura >> carattere;
		file_lettura.get(carattere);
		output.push_back(carattere);
		//se è la fine mi fermo
		if (carattere == fine)
			stop = true;
	}
	return output;
}
string leggi_tipo_informazione(ifstream &file_lettura)
{
	return leggi_fino_a(file_lettura, DIVISORE);
}
string leggi_valore_informazione(ifstream &file_lettura, const bool &ultimo_dato = false)
{
	//se è l'ultimo dato
	if (ultimo_dato)
		return leggi_fino_a(file_lettura, PARENTESI_DX);
	else
		return leggi_fino_a(file_lettura, SEPARATORE);
}

//lettura tipo informazione
bool leggi_informazione_generica(ifstream &file_utenti, const string &tipo_informazione, string &valore_informazione, const bool &ultimo_dato = false)
{
	//legge e controlla <tipo_informazione> ':' <valore_informazione> ',' ( o '}' nel caso sia l'ultimo dato)

	bool ok = true;
	string lettura;
	//leggo da file un ipotetico "tipo_informazione:"
	lettura = leggi_tipo_informazione(file_utenti);
	//controllo che alla fine del tipo informazione ci sia :
	if (lettura.back() == DIVISORE)
	{
		//elimino carattere alla fine
		lettura.pop_back();
		//controllo che abbia letto "tipo_informazione"
		if (lettura == tipo_informazione)
		{
			//leggo valore informazione
			lettura = leggi_valore_informazione(file_utenti, ultimo_dato);
			//controllo che alla fine del nome ci sia , o } se è l'ultimo
			if (((lettura.back() == SEPARATORE) && (!ultimo_dato)) || ((lettura.back() == PARENTESI_DX) && (ultimo_dato))) //a seconda se doveva terminare con , o }
			{
				//elimino carattere alla fine
				lettura.pop_back();
				//salvo valore informazione
				valore_informazione = lettura;
			}
			//non formattato correttamente
			else
			{
				cerr << "Errore formattazione testo, previsto : ";
				if (ultimo_dato)
					cerr << PARENTESI_DX; //se doveva finire con }
				else
					cerr << SEPARATORE;  //se doveva finire con ,
				cerr << endl;
				ok = false;
			}
		}
		//tipo informazione non valido
		else
		{
			cerr << "Errore formattazione testo, previsto : " << tipo_informazione << endl;
			ok = false;
		}
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, previsto : " << DIVISORE << endl;
		ok = false;
	}
	return ok;
}
bool leggi_stringa_data_valida(const string &data, Data &data_letta)
{
	//legge e controlla gg/mm/aaaa o g/mm/aaaa o gg/m/aaaa

	bool ok = true;
	bool stop = false;
	unsigned int posizione = 0;
	string giorno;
	string mese;
	string anno;
	giorno.clear();
	mese.clear();
	anno.clear();
	//leggo giorno
	for (; ((posizione < data.size()) && (!stop)); posizione++)
	{
		if (isdigit(data[posizione]))
			giorno += data[posizione];
		else
			stop = true;
	}
	//controllo che il carattere dopo sia '/'
	if (data[posizione - 1] == SEPARATORE_DATA)
	{
		//leggo il mese
		for (stop = false; ((posizione < data.size()) && (!stop)); posizione++)
		{
			if (isdigit(data[posizione]))
				mese += data[posizione];
			else
				stop = true;
		}
		//controllo che il carattere dopo sia '/'
		if (data[posizione - 1] == SEPARATORE_DATA)
		{
			//leggo l'anno
			for (stop = false; ((posizione < data.size()) && (!stop)); posizione++)
			{
				if (isdigit(data[posizione]))
					anno += data[posizione];
				else
					stop = true;
			}
			//controllo che quello che ho letto sia la data passata e che quindi non ci siano caratteri dopo l'anno
			if ((giorno + SEPARATORE_DATA + mese + SEPARATORE_DATA + anno) == data)
			{
				//assegno valori a data_letta
				data_letta = Data(atoi(giorno.c_str()), atoi(mese.c_str()), atoi(anno.c_str()));
				//c.str() trasforma la stringa in una stringa di c
				//cioe aggiunge il terminatore '\0' e cosi è compatibile con la funzione atoi()
				//la quale trasforma la stringa in un numero intero

				//se la non data è valida
				if (!data_letta.is_Valid())
				{
					cerr << "Errore : data non valida" << endl;
					ok = false;
				}
			}
			//errore formattazione data 
			else
			{
				cerr << "Errore formattazione data" << endl;
				ok = false;
			}
		}
		//errore formattazione data 
		else
		{
			cerr << "Errore formattazione data" << endl;
			ok = false;
		}
	}
	//errore formattazione data 
	else
	{
		cerr << "Errore formattazione data" << endl;
		ok = false;
	}
	return ok;
}

//lettura utenti informazioni e valore informazioni
bool leggi_utente_semplice(ifstream &file_utenti, vector<Utente_Semplice> &persona)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggi_informazione_generica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		persona.back().set_Nome(lettura);
		//leggo cognome
		if (leggi_informazione_generica(file_utenti, STR_COGNOME, lettura))
		{
			//salvo cognome
			persona.back().set_Cognome(lettura);
			//leggo domicilio
			if (leggi_informazione_generica(file_utenti, STR_DOMICILIO, lettura))
			{
				//salvo domicilio
				persona.back().set_Domicilio(lettura);
				//leggo data di nascita
				if (leggi_informazione_generica(file_utenti, STR_DATA_DI_NASCITA, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
				{
					//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
					if (leggi_stringa_data_valida(lettura, data_letta))
					{
						//salvo la data
						persona.back().set_Data_Nascita(data_letta);
						//controllo che tutto quello che ho letto sia valido
						if (persona.back().utente_Valido())
						{
							ok = true;
						}
						//utente non valido
						else
						{
							cerr << "Errore : utente semplice non valido" << endl;
						}
					}
				}
			}
		}
	}
	return ok;
}
bool leggi_utente_azienda(ifstream &file_utenti, vector<Utente_Azienda> &impresa)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggi_informazione_generica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		impresa.back().set_Nome(lettura);
		//leggo sede fiscale
		if (leggi_informazione_generica(file_utenti, STR_SEDE_FISCALE, lettura))
		{
			//salvo sede fiscale
			impresa.back().set_Sede_Fiscale(lettura);
			//leggo sede operativa
			if (leggi_informazione_generica(file_utenti, STR_SEDE_OPERATIVA, lettura))
			{
				//salvo sede operativa
				impresa.back().set_Sede_Operativa(lettura);
				//leggo tipo prodotto
				if (leggi_informazione_generica(file_utenti, STR_TIPO_PRODOTTO, lettura))
				{
					//salvo tipo prodotto
					impresa.back().set_Tipo_Prodotto(lettura);
					//leggo data di creazione
					if (leggi_informazione_generica(file_utenti, STR_DATA_DI_CREAZIONE, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
					{
						//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
						if (leggi_stringa_data_valida(lettura, data_letta))
						{
							//salvo la data
							impresa.back().set_Data_Creazione(data_letta);
							//controllo che tutto quello che ho letto sia valido
							if (impresa.back().utente_Valido())
							{
								ok = true;
							}
							//utente non valido
							else
							{
								cerr << "Errore : utente azienda non valido" << endl;
							}
						}
					}
				}
			}
		}
	}
	return ok;
}
bool leggi_utente_gruppo(ifstream &file_utenti, vector<Utente_Gruppo> &associazione)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggi_informazione_generica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		associazione.back().set_Nome(lettura);
		//leggo sede legale
		if (leggi_informazione_generica(file_utenti, STR_SEDE_LEGALE, lettura))
		{
			//salvo sede legale
			associazione.back().set_Sede_Legale(lettura);
			//leggo tipologia attività
			if (leggi_informazione_generica(file_utenti, STR_TIPOLOGIA_ATTIVITA, lettura))
			{
				//salvo tipologia attività
				associazione.back().set_Tipologia_Attività(lettura);
				//leggo data di creazione
				if (leggi_informazione_generica(file_utenti, STR_DATA_DI_CREAZIONE, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
				{
					//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
					if (leggi_stringa_data_valida(lettura, data_letta))
					{
						//salvo la data
						associazione.back().set_Data_Creazione(data_letta);
						//controllo che tutto quello che ho letto sia valido
						if (associazione.back().utente_Valido())
						{
							ok = true;
						}
						//utente non valido
						else
						{
							cerr << "Errore : utente gruppo non valido" << endl;
						}
					}
				}
			}
		}
	}
	return ok;
}
bool leggi_utente(ifstream &file_utenti, vector<Utente_Semplice> &persona, vector<Utente_Azienda> &impresa, vector<Utente_Gruppo> &associazione, const string &id_utente, const string &id_tipo_utente)
{
	bool ok = true;
	//se è un utente semplice
	if (id_tipo_utente == ID_TIPO_SEMPLICE)
	{
		//incremento la dimensione
		persona.resize(persona.size() + 1);
		//precarico le cose che ho già letto
		persona.back().set_Id(id_utente);
		//leggo altri eventuali dati
		if (!leggi_utente_semplice(file_utenti, persona))
		{
			//se non legge correttamente l'utente
			cerr << "Errore lettura utente id : " << id_utente << endl;
			ok = false;
		}
	}
	else
	{
		//se è un utente azienda
		if (id_tipo_utente == ID_TIPO_AZIENDA)
		{
			//incremento la dimensione
			impresa.resize(impresa.size() + 1);
			//precarico le cose che ho già letto
			impresa.back().set_Id(id_utente);
			//leggo altri eventuali dati
			if (!leggi_utente_azienda(file_utenti, impresa))
			{
				//se non legge correttamente l'utente
				cerr << "Errore lettura utente id : " << id_utente << endl;
				ok = false;
			}
		}
		else
		{
			//se è un utente gruppo
			if (id_tipo_utente == ID_TIPO_GRUPPO)
			{
				//incremento la dimensione
				associazione.resize(associazione.size() + 1);
				//precarico le cose che ho già letto
				associazione.back().set_Id(id_utente);
				//leggo altri eventuali dati
				if (!leggi_utente_gruppo(file_utenti, associazione))
				{
					//se non legge correttamente l'utente
					cerr << "Errore lettura utente id : " << id_utente << endl;
					ok = false;
				}
			}
			//se non è nessuno dei tipi previsti
			else
			{
				cerr << "Errore : id_tipo_utente = ''" << id_tipo_utente << "'' non previsto" << endl;
				ok = false;
			}
		}
	}
	return ok;
}
bool leggi_id_utente(ifstream &file_utenti, string &id_utente, const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione)
{
	bool ok = true;
	//leggo id
	id_utente = leggi_valore_informazione(file_utenti);
	//se non è il primo utente implica che deve essere a capo come nuovo utente rispetto a quello prima
	if ((persona.size() != 0) || (impresa.size() > 0) || (associazione.size() > 0))
	{
		//quindi all inizio avra un a capo da eliminare rispetto a quello prima
		if (id_utente.front() == '\n')
		{
			//allora lo elimino
			id_utente.erase(id_utente.begin()); //elimina il primo '\n'
		}
		//errore formattazione o fine file
		else
		{
			//se non era a fine file
			if (!file_utenti.eof())
			{
				cerr << "Errore formattazione testo, previsto : /n" << endl;
			}
			ok = false;
		}
	}
	if (ok)
	{
		ok = false;
		//controllo che alla fine ci sia , e contemporaneamente che abbia letto qualcosa
		if (id_utente.back() == SEPARATORE)
		{
			//elimino ultimo carattere ,
			id_utente.pop_back();
			//se l'id utente è univoco
			if (!id_utente_trovato(persona, impresa, associazione, id_utente))
			{
				ok = true;
			}
			//se l'id esiste già
			else
			{
				cerr << "Errore : l'id_utente = " << id_utente << " non e' univoco" << endl;
			}
		}
	}
	return ok;
}
bool leggi_tipo_utente(ifstream &file_utenti, string &id_tipo_utente)
{
	char carattere;
	bool ok = false;
	//leggo id tipo utente
	id_tipo_utente = leggi_valore_informazione(file_utenti);
	//controllo che alla fine ci sia , e contemporaneamente che abbia letto qualcosa
	if (id_tipo_utente.back() == SEPARATORE)
	{
		//elimino ultimo carattere ,
		id_tipo_utente.pop_back();
		//leggo carattere dopo
		file_utenti.get(carattere);
		//verifico che sia una parentesi {
		if (carattere == PARENTESI_SX)
		{
			ok = true;
		}
		//non formattato correttamente
		else
		{
			cerr << "Errore formattazione testo, prevista : " << PARENTESI_SX << endl;
		}
	}
	return ok;
}

//lettura file
bool leggi_file_utenti(vector<Utente_Semplice> &persona, vector<Utente_Azienda> &impresa, vector<Utente_Gruppo> &associazione, const string &nome_file_utenti)
{
	ifstream file_utenti;
	bool ok = true;
	//pulisco vector
	persona.clear();
	impresa.clear();
	associazione.clear();
	//apro il file
	file_utenti.open(nome_file_utenti);
	//se si è aperto il file
	if (file_utenti.is_open())
	{
		//comincio a leggere il file
		while ((!file_utenti.eof()) && (ok))
		{
			string id_utente;
			string id_tipo_utente;
			//leggo id utente
			if (leggi_id_utente(file_utenti, id_utente, persona, impresa, associazione))
			{
				//leggo tipo utente
				if (leggi_tipo_utente(file_utenti, id_tipo_utente))
				{
					//leggo le informazioni a seconda del tipo di utente
					ok = leggi_utente(file_utenti, persona, impresa, associazione, id_utente, id_tipo_utente);
				}
				//se non ha letto l'id tipo utente
				else
				{
					cerr << "Errore lettura id_tipo_utente" << endl;
					ok = false;
				}
			}
			//se non ha letto l'id utente
			else
			{
				//se non era a fine file
				if (!file_utenti.eof())
				{
					cerr << "Errore lettura id_utente" << endl;
					ok = false;
				}
			}
		}
	}
	//se non si è aperto
	else
	{
		cerr << "Errore apertura file : " << nome_file_utenti << endl;
		ok = false;
	}
	file_utenti.close();
	return ok;
}
bool leggi_file_notizie(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, vector<Notizia> &news, const string &nome_file_notizie)
{
	ifstream file_notizie;
	bool ok = true;
	//pulisco vector
	news.clear();
	//apro il file
	file_notizie.open(nome_file_notizie);
	//se si è aperto il file
	if (file_notizie.is_open())
	{
		//comincio a leggere il file





		//leggo id_mittente
		//verifico che esista l'id
		//leggo messaggio,like,dislike
		//verifico che tutti gli id siano esistenti
		//verifico che like e dislike siano validi, no ripetizioni e voti diversi
	}
	//se non si è aperto
	else
	{
		cerr << "Errore apertura file : " << nome_file_notizie << endl;
		ok = false;
	}
	file_notizie.close();
	return ok;
}
//bool leggi_file_relazioni(...)
bool leggi_file(vector<Utente_Semplice> &persona, vector<Utente_Azienda> &impresa, vector<Utente_Gruppo> &associazione, vector<Notizia> &news, const string &nome_file_utenti, const string &nome_file_notizie)
{
	//aggiungi &&leggi file relazioni e nome file relazioni


	//leggo il file utenti
	if (leggi_file_utenti(persona, impresa, associazione, nome_file_utenti))
		//se non da errori leggo file notizie
		if (leggi_file_notizie(persona, impresa, associazione, news, nome_file_notizie))
			//se non da errori leggo file relazioni
			if (true)
				return true;
	//se la lettura di qualche file non è riuscita
	return false;
}