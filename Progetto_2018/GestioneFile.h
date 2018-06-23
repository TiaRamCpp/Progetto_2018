#pragma once

#include "GestioneUtenti.h"	
#include "GestioneNotizie.h"
#include "GestioneRelazioni.h"

//aggiornamento file
void aggiornaFileUtenti(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &nome_file_utenti)
{
	ofstream file_output;
	file_output.open(nome_file_utenti);
	file_output << stampaUtenti(persona, impresa, associazione);
	file_output.close();
}
void aggiornaFileNotizie(const vector<Notizia> &news, const string &nome_file_notizie)
{
	ofstream file_output;
	file_output.open(nome_file_notizie);
	file_output << stampaNotizie(news);
	file_output.close();
}
void aggiornaFileRelazioni(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &nome_file_relazioni)
{
	ofstream file_output;
	file_output.open(nome_file_relazioni);
	file_output << stampaRelazioni(persona, impresa, associazione);
	file_output.close();
}
void aggiornaFile(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news, const string &nome_file_utenti, const string &nome_file_notizie, const string &nome_file_relazioni)
{
	aggiornaFileUtenti(persona, impresa, associazione, nome_file_utenti);
	aggiornaFileNotizie(news, nome_file_notizie);
	aggiornaFileRelazioni(persona, impresa, associazione, nome_file_relazioni);
}

//stampa
string stampaDati(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news)
{
	string output = stampaUtenti(persona, impresa, associazione);
	output += '\n' + stampaNotizie(news);
	output += '\n' + stampaRelazioni(persona, impresa, associazione);
	return output;
}

//lettura valore informazioni
string leggiFinoA(ifstream &file_lettura, const char &fine)
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
string leggiTipoInformazione(ifstream &file_lettura)
{
	return leggiFinoA(file_lettura, DIVISORE);
}
string leggiValoreInformazione(ifstream &file_lettura, const bool &ultimo_dato = false)
{
	//se è l'ultimo dato
	if (ultimo_dato)
		return leggiFinoA(file_lettura, PARENTESI_DX);
	else
		return leggiFinoA(file_lettura, SEPARATORE);
}

//lettura tipo informazione generica
bool leggiInformazioneGenerica(ifstream &file_utenti, const string &tipo_informazione, string &valore_informazione, const bool &ultimo_dato = false)
{
	//legge e controlla <tipo_informazione> ':' <valore_informazione> ',' ( o '}' nel caso sia l'ultimo dato)

	bool ok = true;
	string lettura;
	//leggo da file un ipotetico "tipo_informazione:"
	lettura = leggiTipoInformazione(file_utenti);
	//controllo che alla fine del tipo informazione ci sia :
	if (lettura.back() == DIVISORE)
	{
		//elimino carattere alla fine
		lettura.pop_back();
		//controllo che abbia letto "tipo_informazione"
		if (lettura == tipo_informazione)
		{
			//leggo valore informazione
			lettura = leggiValoreInformazione(file_utenti, ultimo_dato);
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

//lettura utenti informazioni e valore informazioni per il file utenti
bool leggiUtenteSemplice(ifstream &file_utenti, UtenteSemplice &persona)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggiInformazioneGenerica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		persona.setNome(lettura);
		//leggo cognome
		if (leggiInformazioneGenerica(file_utenti, STR_COGNOME, lettura))
		{
			//salvo cognome
			persona.setCognome(lettura);
			//leggo domicilio
			if (leggiInformazioneGenerica(file_utenti, STR_DOMICILIO, lettura))
			{
				//salvo domicilio
				persona.setDomicilio(lettura);
				//leggo telefono
				if (leggiInformazioneGenerica(file_utenti, STR_TELEFONO, lettura))
				{
					//salvo telefono
					persona.setTelefono(lettura);
					//leggo email
					if (leggiInformazioneGenerica(file_utenti, STR_EMAIL, lettura))
					{
						//salvo email
						persona.setEmail(lettura);
						//leggo data di nascita
						if (leggiInformazioneGenerica(file_utenti, STR_DATA_DI_NASCITA, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
						{
							//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
							if(data_letta.convertiStringaAData(lettura))
							{
								//salvo la data
								persona.setDataNascita(data_letta);
								//controllo che tutto quello che ho letto sia valido
								if (persona.utenteValido())
								{
									ok = true;
								}
								//utente non valido
								else
								{
									cerr << "Errore : utente semplice non valido" << endl;
								}
							}
							//se non è valida
							else
							{
								cout << endl << "Errore : la data di nascita '" << lettura << "' non e' valida" << endl;
							}
						}
					}
				}
			}
		}
	}
	return ok;
}
bool leggiUtenteAzienda(ifstream &file_utenti, UtenteAzienda &impresa)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggiInformazioneGenerica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		impresa.setNome(lettura);
		//leggo sede fiscale
		if (leggiInformazioneGenerica(file_utenti, STR_SEDE_FISCALE, lettura))
		{
			//salvo sede fiscale
			impresa.setSedeFiscale(lettura);
			//leggo sede operativa
			if (leggiInformazioneGenerica(file_utenti, STR_SEDE_OPERATIVA, lettura))
			{
				//salvo sede operativa
				impresa.setSedeOperativa(lettura);
				//leggo tipo prodotto
				if (leggiInformazioneGenerica(file_utenti, STR_TIPO_PRODOTTO, lettura))
				{
					//salvo tipo prodotto
					impresa.setTipoProdotto(lettura);
					//leggo telefono
					if (leggiInformazioneGenerica(file_utenti, STR_TELEFONO, lettura))
					{
						//salvo telefono
						impresa.setTelefono(lettura);
						//leggo email
						if (leggiInformazioneGenerica(file_utenti, STR_EMAIL, lettura))
						{
							//salvo email
							impresa.setEmail(lettura);
							//leggo data di creazione
							if (leggiInformazioneGenerica(file_utenti, STR_DATA_DI_CREAZIONE, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
							{
								//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
								if (data_letta.convertiStringaAData(lettura))
								{
									//salvo la data
									impresa.setDataCreazione(data_letta);
									//controllo che tutto quello che ho letto sia valido
									if (impresa.utenteValido())
									{
										ok = true;
									}
									//utente non valido
									else
									{
										cerr << "Errore : utente azienda non valido" << endl;
									}
								}
								//se non è valida
								else
								{
									cout << endl << "Errore : la data di creazione '" << lettura << "' non e' valida" << endl;
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
bool leggiUtenteGruppo(ifstream &file_utenti, UtenteGruppo &associazione)
{
	bool ok = false;
	string lettura;
	Data data_letta;
	//leggo nome
	if (leggiInformazioneGenerica(file_utenti, STR_NOME, lettura))
	{
		//salvo nome
		associazione.setNome(lettura);
		//leggo sede legale
		if (leggiInformazioneGenerica(file_utenti, STR_SEDE_LEGALE, lettura))
		{
			//salvo sede legale
			associazione.setSedeLegale(lettura);
			//leggo tipologia attività
			if (leggiInformazioneGenerica(file_utenti, STR_TIPOLOGIA_ATTIVITA, lettura))
			{
				//salvo tipologia attività
				associazione.setTipologiaAttività(lettura);
				//leggo telefono
				if (leggiInformazioneGenerica(file_utenti, STR_TELEFONO, lettura))
				{
					//salvo telefono
					associazione.setTelefono(lettura);
					//leggo email
					if (leggiInformazioneGenerica(file_utenti, STR_EMAIL, lettura))
					{
						//salvo email
						associazione.setEmail(lettura);
						//leggo data di creazione
						if (leggiInformazioneGenerica(file_utenti, STR_DATA_DI_CREAZIONE, lettura, true)) //true perchè è l'ultimo dato da leggere e deve finire con }
						{
							//verifico che sia stata letta una data corretta e contemporaneamente verifico che sia valida
							if (data_letta.convertiStringaAData(lettura))
							{
								//salvo la data
								associazione.setDataCreazione(data_letta);
								//controllo che tutto quello che ho letto sia valido
								if (associazione.utenteValido())
								{
									ok = true;
								}
								//utente non valido
								else
								{
									cerr << "Errore : utente gruppo non valido" << endl;
								}
							}
							//se non è valida
							else
							{
								cout << endl << "Errore : la data di creazione '" << lettura << "' non e' valida" << endl;
							}
						}
					}
				}
			}
		}
	}
	return ok;
}
bool leggiUtente(ifstream &file_utenti, vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &id_utente, const string &id_tipo_utente)
{
	bool ok = true;
	//se è un utente semplice
	if (id_tipo_utente == ID_TIPO_SEMPLICE)
	{
		//incremento la dimensione
		persona.resize(persona.size() + 1);
		//precarico le cose che ho già letto
		persona.back().setId(id_utente);
		//leggo altri eventuali dati
		if (!leggiUtenteSemplice(file_utenti, persona.back()))
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
			impresa.back().setId(id_utente);
			//leggo altri eventuali dati
			if (!leggiUtenteAzienda(file_utenti, impresa.back()))
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
				associazione.back().setId(id_utente);
				//leggo altri eventuali dati
				if (!leggiUtenteGruppo(file_utenti, associazione.back()))
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
bool leggiIdUtente(ifstream &file_utenti, string &id_utente, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	//legge e controlla "<id_utente>," e '\n' prima dell id nel caso in cui non sia il primo

	bool ok = true;
	//leggo id
	id_utente = leggiValoreInformazione(file_utenti);
	//se non è il primo utente implica che deve essere a capo come nuovo utente rispetto a quello prima
	if (almenoUnUtenteEsistente(persona, impresa, associazione))
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
				if (!idUtenteTrovato(persona, impresa, associazione, id_utente))
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
		//non formattato correttamente
		else
		{
			cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
		}
	}
	return ok;
}
bool leggiTipoUtente(ifstream &file_utenti, string &id_tipo_utente)
{
	//legge e controlla "<id_tipo_utente>,{"

	char carattere;
	bool ok = false;
	//leggo id tipo utente
	id_tipo_utente = leggiValoreInformazione(file_utenti);
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
bool leggiIdMittente(ifstream &file_notizie, string &id_mittente, const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const vector<Notizia> &news)
{
	//legge e controlla "<id_mittente>," e '\n' prima dell id nel caso in cui non sia la prima notizia

	bool ok = true;
	//leggo id mittente
	id_mittente = leggiValoreInformazione(file_notizie);
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
				if (idUtenteTrovato(persona, impresa, associazione, id_mittente))
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
bool leggiMessaggio(ifstream &file_notizie, string &messaggio)
{
	//legge e controlla "<messaggio>,"

	bool ok = false;
	messaggio = leggiValoreInformazione(file_notizie);
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
bool leggiDataPubblicazione(ifstream &file_notizie, Data &data_pubblicazione)
{
	//legge "<data_pubblicazione>," la converte per salvarla e controlla che sia valida

	bool ok = false;
	string str_data_pubblicazione;
	//leggo data
	str_data_pubblicazione = leggiValoreInformazione(file_notizie);
	//controllo che alla fine ci sia ,
	if (str_data_pubblicazione.back() == SEPARATORE)
	{
		//elimino ultimo carattere ,
		str_data_pubblicazione.pop_back();
		//controllo che non sia vuota
		if (!str_data_pubblicazione.empty())
		{
			//converto la stringa per salvarla e contemporaneamente verifico che sia valida
			if (data_pubblicazione.convertiStringaAData(str_data_pubblicazione))
			{
				ok = true;
			}
			//errore lettura data pubblicazione
			else
			{
				cout << endl << "Errore : la data di pubblicazione '" << str_data_pubblicazione << "' non e' valida" << endl;
			}
		}
		//data vuota
		else
		{
			cerr << "Errore : la data di pubblicazione e' vuota" << endl;
		}
	}
	//non formattato correttamente
	else
	{
		cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
	}
	return ok;
}
bool leggiIdUtentiReazione(ifstream &file_notizie, vector<string> &id_utenti_reazione)
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
			} 
			while ((carattere != SEPARATORE) && (carattere != PARENTESI_DX));
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
bool leggiReazione(ifstream &file_notizie, const string &tipo_reazione, vector<string> &id_utenti_reazione, const bool ultima_reazione = false)
{
	//legge "<tipo_reazione>:{<id1>,...,<idn>}" + ',' o niente nel caso in cui sia l'ultima reazione (dislike)

	bool ok = true;
	string lettura;
	char carattere;
	//leggo tipo reazione
	lettura = leggiTipoInformazione(file_notizie);
	//controllo che alla fine del tipo informazione ci sia :
	if (lettura.back() == DIVISORE)
	{
		//elimino carattere alla fine
		lettura.pop_back();
		//controllo che abbia letto "tipo_reazione"
		if (lettura == tipo_reazione)
		{
			//leggo id utenti reazione
			if (leggiIdUtentiReazione(file_notizie, id_utenti_reazione))
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

//lettura informazioni e valore informazioni per il file relazioni
bool leggiIdVertice(ifstream &file_relazioni, string &id_vertice, bool &prima_relazione, const bool &partenza = false)
{
	bool ok = true;
	//leggo vertice
	id_vertice = leggiValoreInformazione(file_relazioni);
	//se è il vertice di partenza
	if (partenza)
	{
		//se non è il primo nodo letto implica che deve essere a capo come nuovo nodo rispetto a quello prima
		if (!prima_relazione)
		{
			//quindi all inizio avra un a capo da eliminare rispetto a quello prima
			if (id_vertice.front() == '\n')
			{
				//allora lo elimino
				id_vertice.erase(id_vertice.begin()); //elimina il primo '\n'
			}
			//errore formattazione o fine file
			else
			{
				//se non era a fine file
				if (!file_relazioni.eof())
				{
					cerr << "Errore formattazione testo id_utente, previsto : /n" << endl;
					cout << endl << id_vertice << endl;;
				}
				ok = false;
			}
		}
		else
		{
			//se era la prima relazione quella dopo non lo sarà più
			prima_relazione = false;
		}
	}
	if (ok)
	{
		ok = false;
		//controllo che alla fine ci sia , e contemporaneamente che abbia letto qualcosa
		if (id_vertice.back() == SEPARATORE)
		{
			//elimino ultimo carattere ,
			id_vertice.pop_back();
			//controllo che non sia vuoto
			if (!id_vertice.empty())
			{
				ok = true;
			}
			//id_mittente vuoto
			else
			{
				cerr << "Errore : l'id_utente e' vuoto" << endl;
			}
		}
		//non formattato correttamente
		else
		{
			cerr << "Errore formattazione testo, previsto : " << SEPARATORE << endl;
		}
	}
	return ok;
}
bool leggiTipoRelazione(ifstream &file_relazioni, string &tipo_relazione)
{
	bool ok = true;
	tipo_relazione.clear();
	//leggo vertice
	file_relazioni >> tipo_relazione;
	//se è vuota
	if (tipo_relazione.empty())
	{
		cerr << endl << "Errore : tipo relazione vuota" << endl;
		ok = false;
	}
	return ok;
}

//lettura file
bool leggiFileUtenti(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &nome_file_utenti)
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
			if (leggiIdUtente(file_utenti, id_utente, persona, impresa, associazione))
			{
				//leggo tipo utente e contemporaneamente verifico che sia valido
				if (leggiTipoUtente(file_utenti, id_tipo_utente))
				{
					//leggo le informazioni a seconda del tipo di utente
					ok = leggiUtente(file_utenti, persona, impresa, associazione, id_utente, id_tipo_utente);
				}
				//se non ha letto l'id tipo utente
				else
				{
					cerr << "Errore lettura id_tipo_utente nel utente : " << id_utente << endl;
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
bool leggiFileNotizie(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, vector<Notizia> &news, const string &nome_file_notizie)
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
			if (leggiIdMittente(file_notizie, id_mittente, persona, impresa, associazione, news))
			{
				news.resize(news.size() + 1);
				//salvo il mittente
				news.back().setIdMittente(id_mittente);
				//leggo messaggio
				if (leggiMessaggio(file_notizie, messaggio))
				{
					//salvo il messaggio
					news.back().setMessaggio(messaggio);
					//leggo data
					if (leggiDataPubblicazione(file_notizie, data_pubblicazione))
					{
						//salvo la data
						news.back().setDataPubblicazione(data_pubblicazione);
						//leggo like
						if (leggiReazione(file_notizie, STR_LIKE, like))
						{
							//salvo like
							news.back().setLike(like);
							//leggo dislike
							if (leggiReazione(file_notizie, STR_DISLIKE, dislike, true))
							{
								//salvo dislike
								news.back().setDislike(dislike);
								//verifico che la notizia sia valida
								//cioè che like e dislike siano validi, no ripetizioni e voti diversi
								if (news.back().notiziaValida())
								{
									//verifico che tutti gli id utenti nelle reazioni siano esistenti

									//verifico che tutti i like esistano
									for (unsigned int i = 0; ((i<like.size()) && (ok)); i++)
									{
										if (!idUtenteTrovato(persona, impresa, associazione, like[i]))
										{
											cerr << "Errore : l'id_utente ''" << like[i] << "'' ha messo " << STR_LIKE << " ma non esiste" << endl;
											ok = false;
										}
									}
									//verifico che tutti i dislike esistano
									for (unsigned int i = 0; ((i<dislike.size()) && (ok)); i++)
									{
										if (!idUtenteTrovato(persona, impresa, associazione, dislike[i]))
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
bool leggiFileRelazioni(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &nome_file_relazioni)
{
	ifstream file_relazioni;
	bool ok = true;
	bool prima_relazione = true;
	//apro il file
	file_relazioni.open(nome_file_relazioni);
	//se si è aperto il file
	if (file_relazioni.is_open())
	{
		//comincio a leggere il file
		while ((!file_relazioni.eof()) && (ok))
		{
			string tipo_utente;
			string id_partenza;
			string id_arrivo;
			string tipo_relazione;
			//leggo id di partenza 
			if (leggiIdVertice(file_relazioni, id_partenza, prima_relazione, true)) //true perchè è il vertice di partenza e serve il '\n'
			{
				//leggo id di arrivo
				if (leggiIdVertice(file_relazioni, id_arrivo, prima_relazione))
				{
					//leggo tipo relazione e controllo che esista
					if (leggiTipoRelazione(file_relazioni, tipo_relazione))
					{
						//salva la relazione
						if (!salvaRelazioneDaId(persona, impresa, associazione, id_partenza, id_arrivo, tipo_relazione))
						{
							//se non è valida
							cerr << endl << "Errore : relazione <" << id_partenza << SEPARATORE << id_arrivo << SEPARATORE << tipo_relazione << "> non valida" << endl;
							ok = false;
						}
					}
					//errore lettura tipo relazione
					else
					{
						cerr << endl << "Errore lettura tipo relazione" << endl;
						ok = false;
					}
				}
				//errore lettura id arrivo
				else
				{
					cerr << endl << "Errore lettura id vertice arrivo" << endl;
					ok = false;
				}
			}
			//errore lettura id partenza
			else
			{
				cerr << endl << "Errore lettura id vertice partenza" << endl;
				ok = false;
			}
		}
	}
	//se non si è aperto
	else
	{
		cerr << "Errore apertura file : " << nome_file_relazioni << endl;
		ok = false;
	}
	file_relazioni.close();
	return ok;
}
bool leggiFile(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news, const string &nome_file_utenti, const string &nome_file_notizie, const string &nome_file_relazioni)
{
	//legge i tre file e se uno è errato si ferma
	return ((leggiFileUtenti(persona, impresa, associazione, nome_file_utenti)) && (leggiFileNotizie(persona, impresa, associazione, news, nome_file_notizie)) && (leggiFileRelazioni(persona, impresa, associazione, nome_file_relazioni)));
}