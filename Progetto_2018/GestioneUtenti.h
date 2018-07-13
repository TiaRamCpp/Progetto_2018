#pragma once

#include "UtenteSemplice.h"
#include "UtenteAzienda.h"
#include "UtenteGruppo.h"

#include "Notizia.h"

#include "GestioneStringhe.h"

//STAMPA

string stampaUtentiFile(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	string output;
	output.clear();
	//stampa utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		output += persona[i].stampaUtente();
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
		output += impresa[i].stampaUtente();
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
		output += associazione[i].stampaUtente();
		//se non è l'ultima riga
		if (i < associazione.size() - 1)
			output += '\n';
	}
	return output;
}
void stampaUtentiSemplici(const vector<UtenteSemplice> &persona)
{
	if (persona.size() != 0)
	{
		cout << "Utenti Semplici :";
		for (unsigned int i = 0; i < persona.size(); i++)
			cout << endl << endl << persona[i].stampaUtenteEstesa();
	}
	else
	{
		cout << "Nessun Utente Semplice Inserito Nel Database";
	}
}
void stampaUtentiAzienda(const vector<UtenteAzienda> &impresa)
{
	if (impresa.size() != 0)
	{
		cout << "Utenti Azienda :";
		for (unsigned int i = 0; i < impresa.size(); i++)
			cout << endl << endl << impresa[i].stampaUtenteEstesa();
	}
	else
	{
		cout << "Nessun Utente Azienda Inserito Nel Database";
	}
}
void stampaUtentiGruppo(const vector<UtenteGruppo> &associazione)
{
	if (associazione.size() != 0)
	{
		cout << "Utenti Gruppo :";
		for (unsigned int i = 0; i < associazione.size(); i++)
			cout << endl << endl << associazione[i].stampaUtenteEstesa();
	}
	else
	{
		cout << "Nessun Utente Gruppo Inserito Nel Database";
	}
}
void stampaUtenti(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	cout << "Utenti Nel Database :";
	cout << endl << endl;
	stampaUtentiSemplici(persona);
	cout << endl << endl;
	stampaUtentiAzienda(impresa);
	cout << endl << endl;
	stampaUtentiGruppo(associazione);
}
void stampaIdUtenti(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	if (persona.size() != 0)
	{
		cout << "Id Utenti Semplici :";
		for (unsigned int i = 0; i < persona.size(); i++)
			cout << endl << persona[i].getId();
	}
	else
	{
		cout << "Nessun Utente Semplice Inserito Nel Database";
	}
	if (impresa.size() != 0)
	{
		cout << endl << endl << "Id Utenti Azienda :";
		for (unsigned int i = 0; i < impresa.size(); i++)
			cout << endl << impresa[i].getId();
	}
	else
	{
		cout << endl << endl << "Nessun Utente Azienda Inserito Nel Database";
	}
	if (associazione.size() != 0)
	{
		cout << endl << endl << "Id Utenti Gruppo :";
		for (unsigned int i = 0; i < associazione.size(); i++)
			cout << endl << associazione[i].getId();
	}
	else
	{
		cout << endl << endl << "Nessun Utente Gruppo Inserito Nel Database";
	}
}

//TROVA UTENTE E CALCOLA INFORMAZIONI

//id esistente
bool idUtenteSempliceTrovato(const vector<UtenteSemplice> &persona, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < persona.size()) && (!trovato)); i++)
		if (persona[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteAziendaTrovato(const vector<UtenteAzienda> &impresa, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < impresa.size()) && (!trovato)); i++)
		if (impresa[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteGruppoTrovato(const vector<UtenteGruppo> &associazione, const string &id_utente)
{
	bool trovato = false;
	for (unsigned int i = 0; ((i < associazione.size()) && (!trovato)); i++)
		if (associazione[i].getId() == id_utente)
			trovato = true;
	return trovato;
}
bool idUtenteTrovato(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &id_utente)
{
	//se una condizione è verificata non esegue inutilmente le successive
	return (idUtenteSempliceTrovato(persona, id_utente)) || (idUtenteAziendaTrovato(impresa, id_utente)) || (idUtenteGruppoTrovato(associazione, id_utente));
}
bool almenoUnUtenteEsistente(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	//se c'è almeno un utente ritorna vero
	return ((persona.size() != 0) || (impresa.size() != 0) || (associazione.size() != 0));
}

//trova posizione id
vector<unsigned int> utenteSemplicePosizioni(const vector<UtenteSemplice> &persona, const vector<string> &id_utente)
{
	//calcola le posizioni di più utenti contemporaneamente
	vector<unsigned int> posizione(id_utente.size());
	//cerco posizione di ogni id nell'elenco
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		//controllo se è uno degli utenti cercati
		for (unsigned int j = 0; j < id_utente.size(); j++)
		{
			if (persona[i].getId() == id_utente[j])
			{
				//salvo nella posizione corrispondente all'utente cercato
				posizione[j] = i;
			}
		}
	}
	return posizione;
}
unsigned int utenteSemplicePosizione(const vector<UtenteSemplice> &persona, const string &id_utente)
{
	//funzione usata sempre dopo il controllo che esista per essere sicuro che sia presente e non restituire una posizione sbagliata
	unsigned int posizione = 0;
	//cerco posizione id nell'elenco
	for (; ((posizione < persona.size()) && (persona[posizione].getId() != id_utente)); posizione++);
	return posizione;
}
unsigned int utenteAziendaPosizione(const vector<UtenteAzienda> &impresa, const string &id_utente)
{
	//funzione usata sempre dopo il controllo che esista per essere sicuro che sia presente e non restituire una posizione sbagliata
	unsigned int posizione = 0;
	//cerco posizione id nell'elenco
	for (; ((posizione < impresa.size()) && (impresa[posizione].getId() != id_utente)); posizione++);
	return posizione;
}
unsigned int utenteGruppoPosizione(const vector<UtenteGruppo> &associazione, const string &id_utente)
{
	//funzione usata sempre dopo il controllo che esista per essere sicuro che sia presente e non restituire una posizione sbagliata
	unsigned int posizione = 0;
	//cerco posizione id nell'elenco
	for (; ((posizione < associazione.size()) && (associazione[posizione].getId() != id_utente)); posizione++);
	return posizione;
}

//verifica se è il tipo giusto e trova contemporaneamente la posizione
bool trovaPosizioneUtenteSemplice(const vector<UtenteSemplice> &persona, const string &id_utente, unsigned int &posizione)
{
	bool trovato = false;
	posizione = 0;
	for (unsigned int i = 0; ((i < persona.size()) && (!trovato)); i++)
	{
		if (persona[i].getId() == id_utente)
		{
			trovato = true;
			posizione = i;
		}
	}
	return trovato;
}
bool trovaPosizioneUtenteAzienda(const vector<UtenteAzienda> &impresa, const string &id_utente, unsigned int &posizione)
{
	bool trovato = false;
	posizione = 0;
	for (unsigned int i = 0; ((i < impresa.size()) && (!trovato)); i++)
	{
		if (impresa[i].getId() == id_utente)
		{
			trovato = true;
			posizione = i;
		}
	}
	return trovato;
}
bool trovaPosizioneUtenteGruppo(const vector<UtenteGruppo> &associazione, const string &id_utente, unsigned int &posizione)
{
	bool trovato = false;
	posizione = 0;
	for (unsigned int i = 0; ((i < associazione.size()) && (!trovato)); i++)
	{
		if (associazione[i].getId() == id_utente)
		{
			trovato = true;
			posizione = i;
		}
	}
	return trovato;
}

//verifica se esiste e trova contemporaneamente la posizione e il tipo di utente
bool trovaTipoEPosizioneUtente(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &id_utente, string &tipo_utente, unsigned int &posizione)
{
	bool ok = true;

	//se è un utente semplice
	if (trovaPosizioneUtenteSemplice(persona, id_utente, posizione))
	{
		tipo_utente = ID_TIPO_SEMPLICE;
	}
	else
		//se è un utente azienda
		if (trovaPosizioneUtenteAzienda(impresa, id_utente, posizione))
		{
			tipo_utente = ID_TIPO_AZIENDA;
		}
		else
			//se è un utente gruppo
			if (trovaPosizioneUtenteGruppo(associazione, id_utente, posizione))
			{
				tipo_utente = ID_TIPO_GRUPPO;
			}
			//id utente di arrivo non esistente
			else
			{
				cout << endl << "Errore : id utente <" << id_utente << "> non esistente" << endl;
				ok = false;
			}

	return ok;
}

//verifica se esiste e trova contemporaneamente il tipo di utente
bool trovaTipoUtente(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione, const string &id_utente, string &tipo_utente)
{
	bool ok = true;

	//se è un utente semplice
	if (idUtenteSempliceTrovato(persona, id_utente))
	{
		tipo_utente = ID_TIPO_SEMPLICE;
	}
	else
		//se è un utente azienda
		if (idUtenteAziendaTrovato(impresa, id_utente))
		{
			tipo_utente = ID_TIPO_AZIENDA;
		}
		else
			//se è un utente gruppo
			if (idUtenteGruppoTrovato(associazione, id_utente))
			{
				tipo_utente = ID_TIPO_GRUPPO;
			}
			//id utente di arrivo non esistente
			else
			{
				cout << endl << "Errore : id utente <" << id_utente << "> non esistente" << endl;
				ok = false;
			}

	return ok;
}

//cerca utente
void cercaUtente(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	string id_utente;
	string tipo_utente;
	unsigned int posizione;
	if (almenoUnUtenteEsistente(persona, impresa, associazione))
	{
		//inserisco id utente
		cout << endl << "Inserisci id_utente da cercare : ";
		getline(cin, id_utente);
		//se lo trova
		if (trovaTipoEPosizioneUtente(persona, impresa, associazione, id_utente, tipo_utente, posizione))
		{
			cout << "Utente Trovato :" << endl;
			if (tipo_utente == ID_TIPO_SEMPLICE)
			{
				cout << persona[posizione].stampaUtenteEstesa();
			}
			else
				if (tipo_utente == ID_TIPO_AZIENDA)
				{
					cout << impresa[posizione].stampaUtenteEstesa();
				}
				else
					if (tipo_utente == ID_TIPO_GRUPPO)
					{
						cout << associazione[posizione].stampaUtenteEstesa();
					}

		}
		//se non esiste
		else
		{
			cout << "Id Utente <" << id_utente << "> Non Trovato" << endl;
		}
	}
	else
	{
		cout << "Nessun Utente Inserito nel Database" << endl;
	}
}


//CONTROLLO PARENTELA UTENTE SEMPLICE

bool cercaDiscendente(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, const unsigned int &posizione_arrivo)
{
	//cerca se trova id_arrivo tra i discendenti dell id_partenza
	bool discendente = false;
	vector<string> id_arco = persona[posizione_partenza].getIdArco();
	vector<string> tipo_relazione = persona[posizione_partenza].getTipoRelazione();
	vector<string> id_figlio;
	vector<unsigned int> posizione_figlio;

	//calcolo id eventuali figli
	for (unsigned int i = 0; ((i < tipo_relazione.size()) && (!discendente)); i++)
	{
		if (tipo_relazione[i] == STR_FIGLIO)
		{
			id_figlio.push_back(id_arco[i]);
			//controllo se è l'id cercato
			if (id_arco[i] == persona[posizione_arrivo].getId())
				discendente = true;
		}
	}

	//se non era tra i suoi figli allora controllo tra i figli dei suoi figli
	if (!discendente)
	{
		//calcolo posizione eventuali figli
		posizione_figlio = utenteSemplicePosizioni(persona, id_figlio);
		//per ogni eventuale figlio dell id di partenza
		for (unsigned int i = 0; ((i < posizione_figlio.size()) && (!discendente)); i++)
			discendente = cercaDiscendente(persona, posizione_figlio[i], posizione_arrivo);
	}

	return discendente;
}
bool cercaAntenato(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, const unsigned int &posizione_arrivo)
{
	//cerca se trova id_arrivo tra gli antenati dell id_partenza
	bool antenato = false;
	vector<string> id_arco = persona[posizione_partenza].getIdArco();
	vector<string> tipo_relazione = persona[posizione_partenza].getTipoRelazione();
	vector<string> id_genitore;
	vector<unsigned int> posizione_genitore;

	//calcolo id eventuali genitori
	for (unsigned int i = 0; ((i < tipo_relazione.size()) && (!antenato)); i++)
	{
		if (tipo_relazione[i] == STR_GENITORE)
		{
			id_genitore.push_back(id_arco[i]);
			//controllo se è l'id cercato
			if (id_arco[i] == persona[posizione_arrivo].getId())
				antenato = true;
		}
	}

	//se non era tra i suoi genitori allora controllo tra i genitori dei suoi genitori
	if (!antenato)
	{
		//calcolo posizione eventuali genitori
		posizione_genitore = utenteSemplicePosizioni(persona, id_genitore);
		//per ogni eventuale genitore dell id di partenza
		for (unsigned int i = 0; ((i < posizione_genitore.size()) && (!antenato)); i++)
			antenato = cercaAntenato(persona, posizione_genitore[i], posizione_arrivo);
	}

	return antenato;
}
unsigned int contaParenti(const vector<UtenteSemplice> &persona, const unsigned int &posizione_partenza, vector<string> &id_trovati)
{
	unsigned int parenti_trovati = 0;
	vector<string> id_arco = persona[posizione_partenza].getIdArco();
	vector<string> tipo_relazione = persona[posizione_partenza].getTipoRelazione();
	vector<string> id_parenti;
	vector<unsigned int> posizione_parente;
	bool parente_trovato;

	for (unsigned int i = 0; i < tipo_relazione.size(); i++)
	{
		//se è un genitore o un figlio o un coniuge
		if ((tipo_relazione[i] == STR_GENITORE) || (tipo_relazione[i] == STR_FIGLIO) || (tipo_relazione[i] == STR_CONIUGE))
		{
			parente_trovato = false;
			//cerco se non l'ho trovato prima
			for (unsigned int j = 0; ((j < id_trovati.size()) && (!parente_trovato)); j++)
			{
				//se l'avevo già trovato prima
				if (id_trovati[j] == id_arco[i])
				{
					parente_trovato = true;
				}
			}

			//se non l'avevo già trovato
			if (!parente_trovato)
			{
				id_parenti.push_back(id_arco[i]);
				id_trovati.push_back(id_arco[i]);
			}
		}
	}

	//se ho trovato dei parenti nuovi
	if (id_parenti.size() != 0)
	{
		//calcolo posizione parenti
		posizione_parente = utenteSemplicePosizioni(persona, id_parenti);
		//per ogni parente trovato
		for (unsigned int i = 0; i < id_parenti.size(); i++)
		{
			//conto i parenti di quel utente
			++parenti_trovati += contaParenti(persona, posizione_parente[i], id_trovati);
		}
	}

	return parenti_trovati;
}

//AGGIUNTA UTENTE

bool utenteSempliceAggiungi(vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool ok;
	UtenteSemplice temp;
	string id_utente;
	string nome;
	string cognome;
	string domicilio;
	string telefono;
	string email;
	string str_data_nascita;
	Data data_nascita;

	//inserimento vari attributi utente semplice

	//inserimento id utente
	do
	{
		ok = false;
		//inserisco id utente
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci nuovo id_utente_semplice : ";
		getline(cin, id_utente);
		//controllo che sia una stringa valida
		if (temp.stringaValida(id_utente))
		{
			//controllo che non ne esista già uno
			if (!idUtenteTrovato(persona, impresa, associazione, id_utente))
			{
				ok = true;
			}
			//se c'è già
			else
			{
				cout << endl << "Errore : id_utente gia' esistente";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento nome
	do
	{
		ok = false;
		//inserisco nome
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci il nome : ";
		getline(cin, nome);
		//controllo che sia una stringa valida
		if (temp.stringaValida(nome))
		{
				ok = true;	
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento cognome
	do
	{
		ok = false;
		//inserisco cognome
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci il cognome : ";
		getline(cin, cognome);
		//controllo che sia una stringa valida
		if (temp.stringaValida(cognome))
		{
			ok = true;
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento domicilio
	do
	{
		ok = false;
		//inserisco domicilio
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci il domicilio : ";
		getline(cin, domicilio);
		//se ha inserito qualcosa
		if (!domicilio.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(domicilio))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento telefono
	do
	{
		ok = false;
		//inserisco telefono
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci telefono : ";
		getline(cin, telefono);
		//se ha inserito qualcosa
		if (!telefono.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(telefono))
			{
				//controllo che sia un telefono valido
				if (temp.telefonoValido(telefono))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : telefono non valido, inserisci solo cifre";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento email
	do
	{
		ok = false;
		//inserisco email
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci email (formato <id_utente_email>@<dominio> ) : ";
		getline(cin, email);
		//se ha inserito qualcosa
		if (!email.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(email))
			{
				//controllo che sia un'email valida
				if (temp.emailValida(email))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : email non valida";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento data di nascita
	do
	{
		ok = false;
		//inserisco data di nascita
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci data di nascita (formato gg/mm/aaaa ) : ";
		getline(cin, str_data_nascita);
		//controllo che sia una stringa valida
		if (temp.stringaValida(str_data_nascita))
		{
			//controllo che sia una data valida e contemporaneamente la converto
			if (data_nascita.convertiStringaAData(str_data_nascita))
			{
				ok = true;
			}
			//se non lo è
			else
			{
				cout << endl << "Errore : data di nascita non valida";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);

	//salvataggio dati acquisiti
	temp.setId(id_utente);
	temp.setNome(nome);
	temp.setCognome(cognome);
	temp.setDomicilio(domicilio);
	temp.setTelefono(telefono);
	temp.setEmail(email);
	temp.setDataNascita(data_nascita);

	//se è un utente valido completamente
	if (temp.utenteValido())
	{
		//aggiungo il nuovo utente semplice
		persona.push_back(temp);
		modifica = true;
		cout << endl << "Utente semplice aggiunto";
	}
	else
	{
		cout << endl << "Errore : utente non valido";
	}

	return modifica;
}
bool utenteAziendaAggiungi(const vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool ok;
	UtenteAzienda temp;
	string id_utente;
	string nome;
	string sede_fiscale;
	string sede_operativa;
	string tipo_prodotto;
	string telefono;
	string email;
	string str_data_creazione;
	Data data_creazione;

	//inserimento vari attributi utente azienda

	//inserimento id utente
	do
	{
		ok = false;
		//inserisco id utente
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci nuovo id_utente_azienda : ";
		getline(cin, id_utente);
		//controllo che sia una stringa valida
		if (temp.stringaValida(id_utente))
		{
			//controllo che non ne esista già uno
			if (!idUtenteTrovato(persona, impresa, associazione, id_utente))
			{
				ok = true;
			}
			//se c'è già
			else
			{
				cout << endl << "Errore : id_utente gia' esistente";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento nome
	do
	{
		ok = false;
		//inserisco nome
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci il nome : ";
		getline(cin, nome);
		//controllo che sia una stringa valida
		if (temp.stringaValida(nome))
		{
			ok = true;
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento sede fiscale
	do
	{
		ok = false;
		//inserisco sede fiscale
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci la sede fiscale : ";
		getline(cin, sede_fiscale);
		//se ha inserito qualcosa
		if (!sede_fiscale.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(sede_fiscale))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento sede operativa
	do
	{
		ok = false;
		//inserisco sede operativa
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci la sede operativa : ";
		getline(cin, sede_operativa);
		//se ha inserito qualcosa
		if (!sede_operativa.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(sede_operativa))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento tipo prodotto
	do
	{
		ok = false;
		//inserisco tipo prodotto
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci il tipo di prodotto : ";
		getline(cin, tipo_prodotto);
		//se ha inserito qualcosa
		if (!tipo_prodotto.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(tipo_prodotto))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento telefono
	do
	{
		ok = false;
		//inserisco telefono
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci telefono : ";
		getline(cin, telefono);
		//se ha inserito qualcosa
		if (!telefono.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(telefono))
			{
				//controllo che sia un telefono valido
				if (temp.telefonoValido(telefono))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : telefono non valido, inserisci solo cifre";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento email
	do
	{
		ok = false;
		//inserisco email
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci email (formato <id_utente_email>@<dominio> ) : ";
		getline(cin, email);
		//se ha inserito qualcosa
		if (!email.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(email))
			{
				//controllo che sia un'email valida
				if (temp.emailValida(email))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : email non valida";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento data di creazione
	do
	{
		ok = false;
		//inserisco data di creazione
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci data di creazione (formato gg/mm/aaaa ) : ";
		getline(cin, str_data_creazione);
		//controllo che sia una stringa valida
		if (temp.stringaValida(str_data_creazione))
		{
			//controllo che sia una data valida e contemporaneamente la converto
			if (data_creazione.convertiStringaAData(str_data_creazione))
			{
				ok = true;
			}
			//se non lo è
			else
			{
				cout << endl << "Errore : data di creazione non valida";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);

	//salvataggio dati acquisiti
	temp.setId(id_utente);
	temp.setNome(nome);
	temp.setSedeFiscale(sede_fiscale);
	temp.setSedeOperativa(sede_operativa);
	temp.setTipoProdotto(tipo_prodotto);
	temp.setTelefono(telefono);
	temp.setEmail(email);
	temp.setDataCreazione(data_creazione);

	//se è un utente valido completamente
	if (temp.utenteValido())
	{
		//aggiungo il nuovo utente azienda
		impresa.push_back(temp);
		modifica = true;
		cout << endl << "Utente azienda aggiunto";
	}
	else
	{
		cout << endl << "Errore : utente non valido";
	}

	return modifica;
}
bool utenteGruppoAggiungi(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione)
{
	bool modifica = false;
	bool ok;
	UtenteGruppo temp;
	string id_utente;
	string nome;
	string sede_legale;
	string tipologia_attivita;
	string telefono;
	string email;
	string str_data_creazione;
	Data data_creazione;

	//inserimento vari attributi utente gruppo

	//inserimento id utente
	do
	{
		ok = false;
		//inserisco id utente
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci nuovo id_utente_gruppo : ";
		getline(cin, id_utente);
		//controllo che sia una stringa valida
		if (temp.stringaValida(id_utente))
		{
			//controllo che non ne esista già uno
			if (!idUtenteTrovato(persona, impresa, associazione, id_utente))
			{
				ok = true;
			}
			//se c'è già
			else
			{
				cout << endl << "Errore : id_utente gia' esistente";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento nome
	do
	{
		ok = false;
		//inserisco nome
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci il nome : ";
		getline(cin, nome);
		//controllo che sia una stringa valida
		if (temp.stringaValida(nome))
		{
			ok = true;
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);
	//inserimento sede legale
	do
	{
		ok = false;
		//inserisco sede legale
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci la sede legale : ";
		getline(cin, sede_legale);
		//se ha inserito qualcosa
		if (!sede_legale.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(sede_legale))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento tipologia attività
	do
	{
		ok = false;
		//inserisco tipologia attività
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci la tipologia di attivita' : ";
		getline(cin, tipologia_attivita);
		//se ha inserito qualcosa
		if (!tipologia_attivita.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(tipologia_attivita))
			{
				ok = true;
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento telefono
	do
	{
		ok = false;
		//inserisco telefono
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci telefono : ";
		getline(cin, telefono);
		//se ha inserito qualcosa
		if (!telefono.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(telefono))
			{
				//controllo che sia un telefono valido
				if (temp.telefonoValido(telefono))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : telefono non valido, inserisci solo cifre";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento email
	do
	{
		ok = false;
		//inserisco email
		cout << endl << "(Campo facoltativo, premere invio per saltare)";
		cout << endl << "Inserisci email (formato <id_utente_email>@<dominio> ) : ";
		getline(cin, email);
		//se ha inserito qualcosa
		if (!email.empty())
		{
			//controllo che sia una stringa valida
			if (temp.stringaValida(email))
			{
				//controllo che sia un'email valida
				if (temp.emailValida(email))
				{
					ok = true;
				}
				//se non lo è
				else
				{
					cout << endl << "Errore : email non valida";
				}
			}
			//se non è valida
			else
			{
				cout << endl << "Errore : stringa inserita non valida";
			}
		}
		//se non ha inserito nulla nel campo facoltativo
		else
		{
			ok = true;
		}
	} while (!ok);
	//inserimento data di creazione
	do
	{
		ok = false;
		//inserisco data di creazione
		cout << endl << "(Campo obbligatorio)";
		cout << endl << "Inserisci data di creazione (formato gg/mm/aaaa ) : ";
		getline(cin, str_data_creazione);
		//controllo che sia una stringa valida
		if (temp.stringaValida(str_data_creazione))
		{
			//controllo che sia una data valida e contemporaneamente la converto
			if (data_creazione.convertiStringaAData(str_data_creazione))
			{
				ok = true;
			}
			//se non lo è
			else
			{
				cout << endl << "Errore : data di creazione non valida";
			}
		}
		//se non è valida
		else
		{
			cout << endl << "Errore : stringa inserita non valida";
		}
	} while (!ok);

	//salvataggio dati acquisiti
	temp.setId(id_utente);
	temp.setNome(nome);
	temp.setSedeLegale(sede_legale);
	temp.setTipologiaAttività(tipologia_attivita);
	temp.setTelefono(telefono);
	temp.setEmail(email);
	temp.setDataCreazione(data_creazione);

	//se è un utente valido completamente
	if (temp.utenteValido())
	{
		//aggiungo il nuovo utente gruppo
		associazione.push_back(temp);
		modifica = true;
		cout << endl << "Utente gruppo aggiunto";
	}
	else
	{
		cout << endl << "Errore : utente non valido";
	}

	return modifica;
}


//RIMOZIONE UTENTE

//rimozione id_utente dalle notizie
bool rimuoviIdMittenteNotizie(vector<Notizia> &news, const string &id_utente_da_rimuovere)
{
	//rimuovo tutte le notizie pubblicate dall id_utente da rimuovere

	bool modifica = false;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		//se è il mittente
		if (news[i].getIdMittente() == id_utente_da_rimuovere)
		{
			//rimuovo la notizia
			news.erase(news.begin() + i--);
			//i-- perchè avendone tolta una il totale è diminuito di 1
			modifica = true;
		}
	}
	return modifica;
}
bool rimuoviIdUtenteReazioniNotizie(vector<Notizia> &news, const string &id_utente_da_rimuovere)
{
	//rimuovo tutte le reazioni messe dall id_utente da rimuovere

	bool modifica = false;
	for (unsigned int i = 0; i < news.size(); i++)
	{
		//controlla se abbia messo una reazione e contemporaneamente la rimuove
		modifica |= news[i].rimuoviReazione(id_utente_da_rimuovere);
	}
	return modifica;
}

//rimozione id_utente dalle relazioni
bool rimuoviIdUtenteRelazioni(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, const string &id_utente_da_rimuovere)
{
	//rimuovo tutte le relazioni con l' id_utente da rimuovere
	bool modifica = false;
	
	//rimuovo dagli utenti semplici
	for (unsigned int i = 0; i < persona.size(); i++)
	{
		//controlla se hanno delle relazioni in comune e le rimuove
		modifica |= persona[i].rimuoviRelazioniConUtente(id_utente_da_rimuovere);
	}

	//rimuovo dagli utenti azienda
	for (unsigned int i = 0; i < impresa.size(); i++)
	{
		//controlla se hanno delle relazioni in comune e le rimuove
		modifica |= impresa[i].rimuoviRelazioniConUtente(id_utente_da_rimuovere);
	}

	//rimuovo dagli utenti gruppo
	for (unsigned int i = 0; i < associazione.size(); i++)
	{
		//controlla se hanno delle relazioni in comune e le rimuove
		modifica |= associazione[i].rimuoviRelazioniConUtente(id_utente_da_rimuovere);
	}

	return modifica;
}

bool rimuoviUtente(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news, const string &id_utente_da_rimuovere)
{
	bool modifica = false;
	unsigned int posizione = 0;

	//se è un utente semplice
	if (trovaPosizioneUtenteSemplice(persona, id_utente_da_rimuovere, posizione))
	{
		//rimuovi utente semplice
		persona.erase(persona.begin() + posizione);
		modifica = true;
	}
	else
	{
		//se è un utente azienda
		if (trovaPosizioneUtenteAzienda(impresa, id_utente_da_rimuovere, posizione))
		{
			//rimuovo utente azienda
			impresa.erase(impresa.begin() + posizione);
			modifica = true;
		}
		else
		{
			//se è un utente gruppo
			if (trovaPosizioneUtenteGruppo(associazione, id_utente_da_rimuovere, posizione))
			{
				//rimuovi utente gruppo
				associazione.erase(associazione.begin() + posizione);
				modifica = true;
			}
			else
			{
				cout << "Id utente <" << id_utente_da_rimuovere << "> non esistente" << endl;
			}
		}
	}
	//se l'id utente esisteva e quindi rimuovendolo c'è stata una modifica
	if (modifica)
	{
		//scandisco tutte le notizie e elimino tutte quelle con il suo id mittente
		rimuoviIdMittenteNotizie(news, id_utente_da_rimuovere);
		//scandisco tutte le notizie e elimino tutti i like o dislike che ha messo
		rimuoviIdUtenteReazioniNotizie(news, id_utente_da_rimuovere);
		//rimuovo tutte le relazioni con lui
		rimuoviIdUtenteRelazioni(persona, impresa, associazione, id_utente_da_rimuovere);
		cout << endl << "Utente rimosso";
	}
	return modifica;
}


//MODIFICA ATTRIBUTI UTENTE

//modifica id utente
bool utenteModificaId(vector<UtenteSemplice> &persona, vector<UtenteAzienda> &impresa, vector<UtenteGruppo> &associazione, vector<Notizia> &news, const string &vecchio_id)
{
	string nuovo_id;
	bool modifica = true;

	//inserimento nuovo id utente
	cout << "Inserire nuovo id utente : " << endl;
	getline(cin, nuovo_id);

	//se è un nuovo id utente non esistente
	if (!idUtenteTrovato(persona, impresa, associazione, nuovo_id))
	{
		//utente semplice
		for (unsigned int i = 0; i < persona.size(); i++)
		{
			//modifica relazioni id utente semplice
			persona[i].convertiIdRelazioni(vecchio_id, nuovo_id);
			//se è l'utente da modificare
			if (persona[i].getId() == vecchio_id)
			{
				persona[i].setId(nuovo_id);
			}
		}

		//utente azienda
		for (unsigned int i = 0; i < impresa.size(); i++)
		{
			//modifica relazioni id utente impresa
			impresa[i].convertiIdRelazioni(vecchio_id, nuovo_id);
			//se è l'utente da modificare
			if (impresa[i].getId() == vecchio_id)
			{
				impresa[i].setId(nuovo_id);
			}
		}

		//utente gruppo
		for (unsigned int i = 0; i < associazione.size(); i++)
		{
			//modifica relazioni id utente gruppo
			associazione[i].convertiIdRelazioni(vecchio_id, nuovo_id);
			//se è l'utente da modificare
			if (associazione[i].getId() == vecchio_id)
			{
				associazione[i].setId(nuovo_id);
			}
		}

		//modifica notizie
		for (unsigned int i = 0; i < news.size(); i++)
		{
			//modifica relazioni id utente gruppo
			news[i].convertiIdReazioni(vecchio_id, nuovo_id);
			//se è l'utente da modificare
			if (news[i].getIdMittente() == vecchio_id)
			{
				news[i].setIdMittente(nuovo_id);
			}
		}
	}
	//se esiste già
	else
	{
		cout << endl << "Errore : Id Utente <" << nuovo_id << "> gia' Esistente" << endl;
		modifica = false;
	}

	return modifica;
}

//modifica singolo attributo utente semplice
bool utenteSempliceModificaNome(UtenteSemplice &persona)
{
	bool modifica = false;
	string nuovo_nome;
	//inserimento nuovo nome
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire il nuovo nome : ";
	getline(cin, nuovo_nome);
	//se è valido
	if (persona.stringaValida(nuovo_nome))
	{
		persona.setNome(nuovo_nome);
		modifica = true;
		cout << endl << "Nome modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo nome '" << nuovo_nome << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaCognome(UtenteSemplice &persona)
{
	bool modifica = false;
	string nuovo_cognome;
	//inserimento nuovo cognome
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire il nuovo cognome : ";
	getline(cin, nuovo_cognome);
	//se è valido
	if (persona.stringaValida(nuovo_cognome))
	{
		persona.setCognome(nuovo_cognome);
		modifica = true;
		cout << endl << "Cognome modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo cognome '" << nuovo_cognome << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaDomicilio(UtenteSemplice &persona)
{
	bool modifica = false;
	bool ok = true;
	string nuovo_domicilio;
	//inserimento nuovo domicilio
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire il nuovo domicilio : ";
	getline(cin, nuovo_domicilio);
	//se ha inserito qualcosa
	if (!nuovo_domicilio.empty())
	{
		//se non è valido
		if (!persona.stringaValida(nuovo_domicilio))
		{
			ok = false;
			cout << endl << "Errore : il nuovo domicilio '" << nuovo_domicilio << "' non e' valido" << endl;
		}
	}
	if (ok)
	{
		persona.setDomicilio(nuovo_domicilio);
		modifica = true;
		cout << endl << "Domicilio modificato" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaTelefono(UtenteSemplice &persona)
{
	bool modifica = false;
	bool ok = true;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se ha inserito qualcosa
	if (!nuovo_telefono.empty())
	{
		//se non è valido
		if ((!persona.stringaValida(nuovo_telefono)) || (!persona.telefonoValido(nuovo_telefono)))
		{
			ok = false;
			cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
		}
	}
	if (ok)
	{
		persona.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaEmail(UtenteSemplice &persona)
{
	bool modifica = false;
	bool ok = true;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se ha inserito qualcosa
	if (!nuova_email.empty())
	{
		//se non è valida
		if ((!persona.stringaValida(nuova_email)) || (!persona.emailValida(nuova_email)))
		{
			ok = false;
			cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		persona.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaDataNascita(vector<UtenteSemplice> &persona, const unsigned int &posizione)
{
	bool modifica = false;
	bool ok = true;
	string str_nuova_data_nascita;
	Data nuova_data_nascita;
	vector<string> id_arco = persona[posizione].getIdArco();
	vector<string> tipo_relazione = persona[posizione].getTipoRelazione();
	vector<unsigned int> posizione_parente;
	vector<string> id_parente;
	vector<string> tipo_parentela;
	vector<Data> nascita_antenato;
	vector<Data> nascita_discendente;

	//inserimento nuova data di nascita
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire la nuova data di nascita nel formato gg/mm/aaaa : ";
	getline(cin, str_nuova_data_nascita);
	//converto e se è valida
	if (nuova_data_nascita.convertiStringaAData(str_nuova_data_nascita))
	{
		//cerco figli e genitori
		for (unsigned int i = 0; i < tipo_relazione.size(); i++)
		{
			if (tipo_relazione[i] == STR_FIGLIO)
			{
				tipo_parentela.push_back(STR_FIGLIO);
				id_parente.push_back(id_arco[i]);
			}
			else
			{
				if (tipo_relazione[i] == STR_GENITORE)
				{
					tipo_parentela.push_back(STR_GENITORE);
					id_parente.push_back(id_arco[i]);
				}
			}
		}

		//se c'è qualche figlio o genitore
		if (id_parente.size() != 0)
		{
			//calcolo le posizioni dei figli e dei genitori
			posizione_parente = utenteSemplicePosizioni(persona, id_parente);

			//controllo che sia compatibile con le date di nascita degli eventuali figli e dei genitori
			for (unsigned int i = 0; ((i < id_parente.size()) && (ok)); i++)
			{
				if (tipo_parentela[i] == STR_FIGLIO)
				{
					//se la nuova data implica che è più giovane di un figlio
					if (!(nuova_data_nascita < persona[posizione_parente[i]].getDataNascita()))
					{
						ok = false;
						cout << endl << "Errore : Data Non Valida Perche' l'Utente " << id_parente[i] << " Nato/a il " << persona[posizione_parente[i]].getDataNascita() << " Essendo il/la Figlio/a dell'Utente " << persona[posizione].getId() << " Risulterebbe Nato/a Prima" << endl;
					}
				}
				else
				{
					if (tipo_parentela[i] == STR_GENITORE)
					{
						//se la nuova data implica che è più vecchio di un genitore
						if (!(persona[posizione_parente[i]].getDataNascita() < nuova_data_nascita))
						{
							ok = false;
							cout << endl << "Errore : Data Non Valida Perche' l'Utente " << id_parente[i] << " Nato/a il " << persona[posizione_parente[i]].getDataNascita() << " Essendo il/la Genitore dell'Utente " << persona[posizione].getId() << " Risulterebbe Nato/a Dopo" << endl;
						}
					}
				}
			}
		}

		persona[posizione].setDataNascita(nuova_data_nascita);
		modifica = true;
		cout << endl << "Data di nascita modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova data di nascita '" << str_nuova_data_nascita << "' non e' valida" << endl;
	}
	return modifica;
}

//modifica singolo attributo utente azienda
bool utenteAziendaModificaNome(UtenteAzienda &impresa)
{
	bool modifica = false;
	string nuovo_nome;
	//inserimento nuovo nome
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire il nuovo nome : ";
	getline(cin, nuovo_nome);
	//se è valido
	if (impresa.stringaValida(nuovo_nome))
	{
		impresa.setNome(nuovo_nome);
		modifica = true;
		cout << endl << "Nome modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo nome '" << nuovo_nome << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaSedeFiscale(UtenteAzienda &impresa)
{
	bool modifica = false;
	bool ok = true;
	string nuova_sede_fiscale;
	//inserimento nuova sede fiscale
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova sede fiscale : ";
	getline(cin, nuova_sede_fiscale);
	//se ha inserito qualcosa
	if (!nuova_sede_fiscale.empty())
	{
		//se non è valida
		if (!impresa.stringaValida(nuova_sede_fiscale))
		{
			ok = false;
			cout << endl << "Errore : la nuova sede fiscale '" << nuova_sede_fiscale << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		impresa.setSedeFiscale(nuova_sede_fiscale);
		modifica = true;
		cout << endl << "Sede fiscale modificata" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaSedeOperativa(UtenteAzienda &impresa)
{
	bool modifica = false;
	bool ok = true;
	string nuova_sede_operativa;
	//inserimento nuova sede operativa
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova sede operativa : ";
	getline(cin, nuova_sede_operativa);
	//se ha inserito qualcosa
	if (!nuova_sede_operativa.empty())
	{
		//se non è valida
		if (!impresa.stringaValida(nuova_sede_operativa))
		{
			ok = false;
			cout << endl << "Errore : la nuova sede operativa '" << nuova_sede_operativa << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		impresa.setSedeOperativa(nuova_sede_operativa);
		modifica = true;
		cout << endl << "Sede operativa modificata" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaTipoProdotto(UtenteAzienda &impresa)
{
	bool modifica = false;
	bool ok = true;
	string nuovo_tipo_prodotto;
	//inserimento nuovo tipo prodotto
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire il nuovo tipo di prodotto : ";
	getline(cin, nuovo_tipo_prodotto);
	//se ha inserito qualcosa
	if (!nuovo_tipo_prodotto.empty())
	{
		//se non è valido
		if (!impresa.stringaValida(nuovo_tipo_prodotto))
		{
			ok = false;
			cout << endl << "Errore : il nuovo tipo prodotto '" << nuovo_tipo_prodotto << "' non e' valido" << endl;
		}
	}
	if (ok)
	{
		impresa.setTipoProdotto(nuovo_tipo_prodotto);
		modifica = true;
		cout << endl << "Tipo prodotto modificato" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaTelefono(UtenteAzienda &impresa)
{
	bool modifica = false;
	bool ok = true;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se ha inserito qualcosa
	if (!nuovo_telefono.empty())
	{
		//se non è valido
		if ((!impresa.stringaValida(nuovo_telefono)) || (!impresa.telefonoValido(nuovo_telefono)))
		{
			ok = false;
			cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
		}
	}
	if (ok)
	{
		impresa.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaEmail(UtenteAzienda &impresa)
{
	bool modifica = false;
	bool ok = true;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se ha inserito qualcosa
	if (!nuova_email.empty())
	{
		//se non è valida
		if ((!impresa.stringaValida(nuova_email)) || (!impresa.emailValida(nuova_email)))
		{
			ok = false;
			cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		impresa.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaDataCreazione(UtenteAzienda &impresa)
{
	bool modifica = false;
	string str_nuova_data_creazione;
	Data nuova_data_creazione;
	//inserimento nuova data di creazione
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire la nuova data di creazione nel formato gg/mm/aaaa : ";
	getline(cin, str_nuova_data_creazione);
	//converto e se è valida
	if (nuova_data_creazione.convertiStringaAData(str_nuova_data_creazione))
	{
		impresa.setDataCreazione(nuova_data_creazione);
		modifica = true;
		cout << endl << "Data di creazione modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova data di creazione '" << str_nuova_data_creazione << "' non e' valida" << endl;
	}
	return modifica;
}

//modifica singolo attributo utente gruppo
bool utenteGruppoModificaNome(UtenteGruppo &associazione)
{
	bool modifica = false;
	string nuovo_nome;
	//inserimento nuovo nome
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire il nuovo nome : ";
	getline(cin, nuovo_nome);
	//se è valido
	if (associazione.stringaValida(nuovo_nome))
	{
		associazione.setNome(nuovo_nome);
		modifica = true;
		cout << endl << "Nome modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo nome '" << nuovo_nome << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaSedeLegale(UtenteGruppo &associazione)
{
	bool modifica = false;
	bool ok = true;
	string nuova_sede_legale;
	//inserimento nuova sede legale
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova sede legale : ";
	getline(cin, nuova_sede_legale);
	//se ha inserito qualcosa
	if (!nuova_sede_legale.empty())
	{
		//se non è valida
		if (!associazione.stringaValida(nuova_sede_legale))
		{
			ok = false;
			cout << endl << "Errore : la nuova sede legale '" << nuova_sede_legale << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		associazione.setSedeLegale(nuova_sede_legale);
		modifica = true;
		cout << endl << "Sede legale modificata" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaTipologiaAttivita(UtenteGruppo &associazione)
{
	bool modifica = false;
	bool ok = true;
	string nuova_tipologia_attivita;
	//inserimento nuova tipologia attività
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova tipologia di attivita' : ";
	getline(cin, nuova_tipologia_attivita);
	//se ha inserito qualcosa
	if (!nuova_tipologia_attivita.empty())
	{
		//se non è valida
		if (!associazione.stringaValida(nuova_tipologia_attivita))
		{
			ok = false;
			cout << endl << "Errore : la nuova tipologia di attivita' '" << nuova_tipologia_attivita << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		associazione.setTipologiaAttività(nuova_tipologia_attivita);
		modifica = true;
		cout << endl << "Tipologia attivita' modificata" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaTelefono(UtenteGruppo &associazione)
{
	bool modifica = false;
	bool ok = true;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se ha inserito qualcosa
	if (!nuovo_telefono.empty())
	{
		//se non è valido
		if ((!associazione.stringaValida(nuovo_telefono)) || (!associazione.telefonoValido(nuovo_telefono)))
		{
			ok = false;
			cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
		}
	}
	if (ok)
	{
		associazione.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaEmail(UtenteGruppo &associazione)
{
	bool modifica = false;
	bool ok = true;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "(Campo facoltativo, premere invio per rimuovere)";
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se ha inserito qualcosa
	if (!nuova_email.empty())
	{
		//se non è valida
		if ((!associazione.stringaValida(nuova_email)) || (!associazione.emailValida(nuova_email)))
		{
			ok = false;
			cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
		}
	}
	if (ok)
	{
		associazione.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaDataCreazione(UtenteGruppo &associazione)
{
	bool modifica = false;
	string str_nuova_data_creazione;
	Data nuova_data_creazione;
	//inserimento nuova data di creazione
	cout << endl << "(Campo obbligatorio)";
	cout << endl << "Inserire la nuova data di creazione nel formato gg/mm/aaaa : ";
	getline(cin, str_nuova_data_creazione);
	//converto e se è valida
	if (nuova_data_creazione.convertiStringaAData(str_nuova_data_creazione))
	{
		associazione.setDataCreazione(nuova_data_creazione);
		modifica = true;
		cout << endl << "Data di creazione modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova data di creazione '" << str_nuova_data_creazione << "' non e' valida" << endl;
	}
	return modifica;
}
