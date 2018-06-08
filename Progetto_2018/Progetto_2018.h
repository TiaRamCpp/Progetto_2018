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
	{
		file_output << persona[i];
		//se non è l'ultima riga
		if (i < persona.size() - 1)
			file_output << endl;
		else
			//se dopo devo stampare altri dati
			if ((impresa.size() != 0) || (associazione.size() != 0))
				file_output << endl;
	}
	//stampa utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		file_output << impresa[i];
		//se non è l'ultima riga
		if (i < impresa.size() - 1)
			file_output << endl;
		else
			//se dopo devo stampare altri dati
			if (associazione.size() != 0)
				file_output << endl;
	}
	//stampa utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		file_output << associazione[i];
		//se non è l'ultima riga
		if (i < associazione.size() - 1)
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
	{
		output += persona[i].stampa_Utente_Semplice();
		//se non è l'ultima riga
		if (i < persona.size() - 1)
			output += '\n';
		else
			//se dopo devo stampare altri dati
			if ((impresa.size() != 0) || (associazione.size() != 0))
				output += '\n';
	}
	//stampa utenti aziende
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		output += impresa[i].stampa_Utente_Azienda();
		//se non è l'ultima riga
		if (i < impresa.size() - 1)
			output += '\n';
		else
			//se dopo devo stampare altri dati
			if (associazione.size() != 0)
				output += '\n';
	}
	//stampa utenti gruppi
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		output += associazione[i].stampa_Utente_Gruppo();
		//se non è l'ultima riga
		if (i < associazione.size() - 1)
			output += '\n';
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
			output += '\n';
	}
	return output;
}
//string stampa_relazioni(...);
string stampa_dati(const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const vector<Notizia> &news)
{
	string output = stampa_utenti(persona, impresa, associazione);
	//se prima ho stampato qualcosa e dopo devo stampare qualcosa
	if ((!output.empty()) && (news.size() != 0))
		output += '\n';
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

//lettura utenti informazioni e valore informazioni per il file utenti
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
				//leggo telefono
				if (leggi_informazione_generica(file_utenti, STR_TELEFONO, lettura))
				{
					//salvo telefono
					persona.back().set_Telefono(lettura);
					//leggo email
					if (leggi_informazione_generica(file_utenti, STR_EMAIL, lettura))
					{
						//salvo email
						persona.back().set_Email(lettura);
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
					//leggo telefono
					if (leggi_informazione_generica(file_utenti, STR_TELEFONO, lettura))
					{
						//salvo telefono
						impresa.back().set_Telefono(lettura);
						//leggo email
						if (leggi_informazione_generica(file_utenti, STR_EMAIL, lettura))
						{
							//salvo email
							impresa.back().set_Email(lettura);
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
				//leggo telefono
				if (leggi_informazione_generica(file_utenti, STR_TELEFONO, lettura))
				{
					//salvo telefono
					associazione.back().set_Telefono(lettura);
					//leggo email
					if (leggi_informazione_generica(file_utenti, STR_EMAIL, lettura))
					{
						//salvo email
						associazione.back().set_Email(lettura);
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
	//legge e controlla "<id_utente>," e '\n' prima dell id nel caso in cui non sia il primo

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
				cerr << "Errore formattazione testo id_utente, previsto : /n" << endl;
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
			//controllo che non sia vuoto prima di controllare che sia univoco
			if (!id_utente.empty())
			{
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
			//id_utente vuoto
			else
			{
				cerr << "Errore : l'id_utente e' vuoto" << endl;
			}
		}
	}
	return ok;
}
bool leggi_tipo_utente(ifstream &file_utenti, string &id_tipo_utente)
{
	//legge e controlla "<id_tipo_utente>,{"

	char carattere;
	bool ok = false;
	//leggo id tipo utente
	id_tipo_utente = leggi_valore_informazione(file_utenti);
	//controllo che alla fine ci sia ,
	if (id_tipo_utente.back() == SEPARATORE)
	{
		//elimino ultimo carattere ,
		id_tipo_utente.pop_back();
		//controllo che non sia vuoto
		if (!id_tipo_utente.empty())
		{
			//se l'id tipo utente esiste
			if ((id_tipo_utente == ID_TIPO_SEMPLICE) || (id_tipo_utente == ID_TIPO_AZIENDA) || (id_tipo_utente == ID_TIPO_GRUPPO))
			{
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
			//se non è nessuno dei tipi previsti
			else
			{
				cerr << "Errore : id_tipo_utente = ''" << id_tipo_utente << "'' non previsto" << endl;
			}
		}
		//id_utente vuoto
		else
		{
			cerr << "Errore : l'id_tipo_utente e' vuoto" << endl;
		}
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
	}
	return ok;
}

//lettura informazioni e valore informazioni per il file notizia
bool leggi_id_mittente(ifstream &file_notizie, string &id_mittente, const vector<Utente_Semplice> &persona, const vector<Utente_Azienda> &impresa, const vector<Utente_Gruppo> &associazione, const vector<Notizia> &news)
{
	//legge e controlla "<id_mittente>," e '\n' prima dell id nel caso in cui non sia la prima notizia

	bool ok = true;
	//leggo id mittente
	id_mittente = leggi_valore_informazione(file_notizie);
	//se non è la prima notizia implica che deve essere a capo come nuova notizia rispetto a quella prima
	if (news.size() != 0)
	{
		//quindi all inizio avrà un a capo da eliminare rispetto a quello prima
		if (id_mittente.front() == '\n')
		{
			//allora lo elimino
			id_mittente.erase(id_mittente.begin()); //elimina il primo '\n'
		}
		//errore formattazione o fine file
		else
		{
			//se non era a fine file
			if (!file_notizie.eof())
			{
				cerr << "Errore formattazione testo id_mittente, previsto : /n" << endl;
			}
			ok = false;
		}
	}
	if (ok)
	{
		ok = false;
		//controllo che alla fine ci sia , e contemporaneamente che abbia letto qualcosa
		if (id_mittente.back() == SEPARATORE)
		{
			//elimino ultimo carattere ,
			id_mittente.pop_back();
			//controllo che non sia vuoto prima di controllare che sia un id utente esistente
			if (!id_mittente.empty())
			{
				//se l'id utente esiste
				if (id_utente_trovato(persona, impresa, associazione, id_mittente))
				{
					ok = true;
				}
				//se l'id non esiste
				else
				{
					cerr << "Errore : l'id_mittente = " << id_mittente << " non esiste" << endl;
				}
			}
			//id_mittente vuoto
			else
			{
				cerr << "Errore : l'id_mittente e' vuoto" << endl;
			}
		}
	}
	return ok;
}
bool leggi_messaggio(ifstream &file_notizie, string &messaggio)
{
	//legge e controlla "<messaggio>,"

	bool ok = false;
	messaggio = leggi_valore_informazione(file_notizie);
	//controllo che alla fine ci sia ,
	if (messaggio.back() == SEPARATORE)
	{
		//elimino ultimo carattere ,
		messaggio.pop_back();
		//controllo che non sia vuoto
		if (!messaggio.empty())
		{
			ok = true;
		}
		//messaggio vuoto
		else
		{
			cerr << "Errore : il messaggio e' vuoto" << endl;
		}
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
	}
	return ok;
}
bool leggi_data_pubblicazione(ifstream &file_notizie, Data &data_pubblicazione)
{
	//legge "<data_pubblicazione>," la converte per salvarla e controlla che sia valida

	bool ok = false;
	string data_pubblicazione_str;
	//leggo data
	data_pubblicazione_str = leggi_valore_informazione(file_notizie);
	//controllo che alla fine ci sia ,
	if (data_pubblicazione_str.back() == SEPARATORE)
	{
		//elimino ultimo carattere ,
		data_pubblicazione_str.pop_back();
		//controllo che non sia vuota
		if (!data_pubblicazione_str.empty())
		{
			//converto la stringa per salvarla e contemporaneamente verifico che sia valida
			if (leggi_stringa_data_valida(data_pubblicazione_str, data_pubblicazione))
			{
				ok = true;
			}
		}
		//data vuota
		else
		{
			cerr << "Errore : la data di pubblicazione è vuota" << endl;
		}
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
	}
	return ok;
}
bool leggi_id_utenti_reazione(ifstream &file_notizie, vector<string> &id_utenti_reazione)
{
	//legge "{<id1>,...,<idn>}" e li salva
	bool ok = true;
	char carattere;
	string id_utente;
	//leggo carattere
	file_notizie >> carattere;
	//controllo che sia '{'
	if (carattere == PARENTESI_SX)
	{
		do
		{
			id_utente.clear();
			do
			{
				file_notizie >> carattere;
				id_utente.push_back(carattere);
			} while ((carattere != SEPARATORE) && (carattere != PARENTESI_DX));
			//elimino ultimo carattere
			id_utente.pop_back();
			//nel caso in cui non ci fosse nemmeno una reazione di quel tipo
			if (!id_utente.empty())
				id_utenti_reazione.push_back(id_utente);
			else
				//non formattato correttamente nel caso in cui ci sia almeno una reazione allora controllo che non sia vuoto l'id utente
				if (id_utenti_reazione.size() != 0)
				{
					cerr << "Errore : id utente vuoto" << endl;
					ok = false;
				}
		} while (carattere != PARENTESI_DX);
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, prevista : " << PARENTESI_SX << endl;
		ok = false;
	}
	return ok;
}
bool leggi_reazione(ifstream &file_notizie, const string &tipo_reazione, vector<string> &id_utenti_reazione, const bool ultima_reazione = false)
{
	//legge "<tipo_reazione>:{<id1>,...,<idn>}" + ',' o niente nel caso in cui sia l'ultima reazione (dislike)

	bool ok = true;
	string lettura;
	char carattere;
	//leggo tipo reazione
	lettura = leggi_tipo_informazione(file_notizie);
	//controllo che alla fine del tipo informazione ci sia :
	if (lettura.back() == DIVISORE)
	{
		//elimino carattere alla fine
		lettura.pop_back();
		//controllo che abbia letto "tipo_reazione"
		if (lettura == tipo_reazione)
		{
			//leggo id utenti reazione
			if (leggi_id_utenti_reazione(file_notizie, id_utenti_reazione))
			{
				//se non è l'ultima reazione
				if (!ultima_reazione)
				{
					//leggo carattere
					file_notizie >> carattere;
					//controllo che sia ','
					if (carattere != SEPARATORE)
					{
						cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
						ok = false;
					}
				}
			}
			//se da errore la lettura degli id reazione
			else
			{
				cerr << "Errore id utenti reazione : " << tipo_reazione << endl;
				ok = false;
			}
		}
		//tipo reazione non valido
		else
		{
			cerr << "Errore formattazione testo, previsto : " << tipo_reazione << endl;
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
			//leggo id utente e contemporaneamente verifico sia valido e univoco
			if (leggi_id_utente(file_utenti, id_utente, persona, impresa, associazione))
			{
				//leggo tipo utente e contemporaneamente verifico che sia valido
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
		while ((!file_notizie.eof()) && (ok))
		{
			string id_mittente;
			string messaggio;
			Data data_pubblicazione;
			vector<string> like;
			vector<string> dislike;
			//leggo id mittente e contemporaneamente verifico sia valido e esistente
			if (leggi_id_mittente(file_notizie, id_mittente, persona, impresa, associazione, news))
			{
				news.resize(news.size() + 1);
				//salvo il mittente
				news.back().set_Id_Mittente(id_mittente);
				//leggo messaggio
				if (leggi_messaggio(file_notizie, messaggio))
				{
					//salvo il messaggio
					news.back().set_Messaggio(messaggio);
					//leggo data
					if (leggi_data_pubblicazione(file_notizie, data_pubblicazione))
					{
						//salvo la data
						news.back().set_Data_Pubblicazione(data_pubblicazione);
						//leggo like
						if (leggi_reazione(file_notizie, STR_LIKE, like))
						{
							//salvo like
							news.back().set_Like(like);
							//leggo dislike
							if (leggi_reazione(file_notizie, STR_DISLIKE, dislike, true))
							{
								//salvo dislike
								news.back().set_Dislike(dislike);
								//verifico che la notizia sia valida
								//cioè che like e dislike siano validi, no ripetizioni e voti diversi
								if (news.back().notizia_Valida())
								{
									//verifico che tutti gli id utenti nelle reazioni siano esistenti

									//verifico che tutti i like esistano
									for (unsigned int i = 0; ((i<like.size()) && (ok)); i++)
									{
										if (!id_utente_trovato(persona, impresa, associazione, like[i]))
										{
											cerr << "Errore : l'id_utente ''" << like[i] << "'' ha messo " << STR_LIKE << " ma non esiste" << endl;
											ok = false;
										}
									}
									//verifico che tutti i dislike esistano
									for (unsigned int i = 0; ((i<dislike.size()) && (ok)); i++)
									{
										if (!id_utente_trovato(persona, impresa, associazione, dislike[i]))
										{
											cerr << "Errore : l'id_utente ''" << dislike[i] << "'' ha messo " << STR_DISLIKE << " ma non esiste" << endl;
											ok = false;
										}
									}
								}
								//se non è valida
								else
								{
									cerr << "Errore : notizia non valida " << endl;
									ok = false;
								}
							}
							//se non ha letto i dislike
							else
							{
								cerr << "Errore lettura " << STR_DISLIKE << endl;
								ok = false;
							}
						}
						//se non ha letto i like
						else
						{
							cerr << "Errore lettura " << STR_LIKE << endl;
							ok = false;
						}
					}
					//se non ha letto la data
					else
					{
						cerr << "Errore lettura data pubblicazione" << endl;
						ok = false;
					}
				}
				//se non ha letto il messaggio
				else
				{
					cerr << "Errore lettura messaggio" << endl;
					ok = false;
				}
			}
			//se non ha letto l'id mittente
			else
			{
				//se non era a fine file
				if (!file_notizie.eof())
				{
					cerr << "Errore lettura id_mittente" << endl;
					ok = false;
				}
			}
		}
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


	/*//leggo il file utenti
	if (leggi_file_utenti(persona, impresa, associazione, nome_file_utenti))
		//se non da errori leggo file notizie
		if (leggi_file_notizie(persona, impresa, associazione, news, nome_file_notizie))
			//se non da errori leggo file relazioni
			if (true)
				return true;
	//se la lettura di qualche file non è riuscita
	return false;
	*/

	//oppure + leggi file relazioni tanto se uno non va da errore e si ferma subito
	return ((leggi_file_utenti(persona, impresa, associazione, nome_file_utenti)) && (leggi_file_notizie(persona, impresa, associazione, news, nome_file_notizie)));
}