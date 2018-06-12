#pragma once

#include "UtenteSemplice.h"
#include "UtenteAzienda.h"
#include "UtenteGruppo.h"

#include "Notizia.h"

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

//trova posizione id
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

//stampa
string stampaUtenti(const vector<UtenteSemplice> &persona, const vector<UtenteAzienda> &impresa, const vector<UtenteGruppo> &associazione)
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

//selezione utente
bool utenteSempliceSeleziona(const vector<UtenteSemplice> &persona, unsigned int &posizione)
{
	bool selezionato = false;
	string id_utente_semplice;
	posizione = 0;
	//scelta utente semplice da modificare
	cout << endl << "Inserire l'id_utente_semplice da selezionare : ";
	getline(cin, id_utente_semplice);
	//se esiste
	if (idUtenteSempliceTrovato(persona, id_utente_semplice))
	{
		posizione = utenteSemplicePosizione(persona, id_utente_semplice);
		selezionato = true;
	}
	//id utente semplice non esistente
	else
	{
		cout << endl << "Errore : id_utente_semplice '" << id_utente_semplice << "' non trovato" << endl;
	}
	return selezionato;
}
bool utenteAziendaSeleziona(const vector<UtenteAzienda> &impresa, unsigned int &posizione)
{
	bool selezionato = false;
	string id_utente_azienda;
	posizione = 0;
	//scelta utente azienda da modificare
	cout << endl << "Inserire l'id_utente_azienda da selezionare : ";
	getline(cin, id_utente_azienda);
	//se esiste
	if (idUtenteAziendaTrovato(impresa, id_utente_azienda))
	{
		posizione = utenteAziendaPosizione(impresa, id_utente_azienda);
		selezionato = true;
	}
	//id utente azienda non esistente
	else
	{
		cout << endl << "Errore : id_utente_azienda '" << id_utente_azienda << "' non trovato" << endl;
	}
	return selezionato;
}
bool utenteGruppoSeleziona(const vector<UtenteGruppo> &associazione, unsigned int &posizione)
{
	bool selezionato = false;
	string id_utente_gruppo;
	posizione = 0;
	//scelta utente gruppo da modificare
	cout << endl << "Inserire l'id_utente_gruppo da selezionare : ";
	getline(cin, id_utente_gruppo);
	//se esiste
	if (idUtenteGruppoTrovato(associazione, id_utente_gruppo))
	{
		posizione = utenteGruppoPosizione(associazione, id_utente_gruppo);
		selezionato = true;
	}
	//id utente gruppo non esistente
	else
	{
		cout << endl << "Errore : id_utente_gruppo '" << id_utente_gruppo << "' non trovato" << endl;
	}
	return selezionato;
}

//modifica singolo attributo utente semplice
bool utenteSempliceModificaNome(UtenteSemplice &persona)
{
	bool modifica = false;
	string nuovo_nome;
	//inserimento nuovo nome
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
	string nuovo_domicilio;
	//inserimento nuovo domicilio
	cout << endl << "Inserire il nuovo domicilio : ";
	getline(cin, nuovo_domicilio);
	//se è valido
	if (persona.stringaValida(nuovo_domicilio))
	{
		persona.setDomicilio(nuovo_domicilio);
		modifica = true;
		cout << endl << "Domicilio modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo domicilio '" << nuovo_domicilio << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaTelefono(UtenteSemplice &persona)
{
	bool modifica = false;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se è valido
	if ((persona.stringaValida(nuovo_telefono)) && (persona.telefonoValido(nuovo_telefono)))
	{
		persona.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaEmail(UtenteSemplice &persona)
{
	bool modifica = false;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se è valido
	if ((persona.stringaValida(nuova_email)) && (persona.emailValida(nuova_email)))
	{
		persona.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteSempliceModificaDataNascita(UtenteSemplice &persona)
{
	bool modifica = false;
	string str_nuova_data_nascita;
	Data nuova_data_nascita;
	//inserimento nuova data di nascita
	cout << endl << "Inserire la nuova data di nascita nel formato gg/mm/aaaa : ";
	getline(cin, str_nuova_data_nascita);
	//converto e se è valida
	if (nuova_data_nascita.convertiStringaAData(str_nuova_data_nascita))
	{
		persona.setDataNascita(nuova_data_nascita);
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
	string nuova_sede_fiscale;
	//inserimento nuova sede fiscale
	cout << endl << "Inserire la nuova sede fiscale : ";
	getline(cin, nuova_sede_fiscale);
	//se è valida
	if (impresa.stringaValida(nuova_sede_fiscale))
	{
		impresa.setSedeFiscale(nuova_sede_fiscale);
		modifica = true;
		cout << endl << "Sede fiscale modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova sede fiscale '" << nuova_sede_fiscale << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaSedeOperativa(UtenteAzienda &impresa)
{
	bool modifica = false;
	string nuova_sede_operativa;
	//inserimento nuova sede operativa
	cout << endl << "Inserire la nuova sede operativa : ";
	getline(cin, nuova_sede_operativa);
	//se è valida
	if (impresa.stringaValida(nuova_sede_operativa))
	{
		impresa.setSedeOperativa(nuova_sede_operativa);
		modifica = true;
		cout << endl << "Sede operativa modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova sede operativa '" << nuova_sede_operativa << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaTipoProdotto(UtenteAzienda &impresa)
{
	bool modifica = false;
	string nuovo_tipo_prodotto;
	//inserimento nuovo tipo prodotto
	cout << endl << "Inserire il nuovo tipo di prodotto : ";
	getline(cin, nuovo_tipo_prodotto);
	//se è valido
	if (impresa.stringaValida(nuovo_tipo_prodotto))
	{
		impresa.setTipoProdotto(nuovo_tipo_prodotto);
		modifica = true;
		cout << endl << "Tipo prodotto modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo tipo prodotto '" << nuovo_tipo_prodotto << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaTelefono(UtenteAzienda &impresa)
{
	bool modifica = false;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se è valido
	if ((impresa.stringaValida(nuovo_telefono)) && (impresa.telefonoValido(nuovo_telefono)))
	{
		impresa.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaEmail(UtenteAzienda &impresa)
{
	bool modifica = false;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se è valido
	if ((impresa.stringaValida(nuova_email)) && (impresa.emailValida(nuova_email)))
	{
		impresa.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteAziendaModificaDataCreazione(UtenteAzienda &impresa)
{
	bool modifica = false;
	string str_nuova_data_creazione;
	Data nuova_data_creazione;
	//inserimento nuova data di creazione
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
	string nuova_sede_legale;
	//inserimento nuova sede legale
	cout << endl << "Inserire la nuova sede legale : ";
	getline(cin, nuova_sede_legale);
	//se è valida
	if (associazione.stringaValida(nuova_sede_legale))
	{
		associazione.setSedeLegale(nuova_sede_legale);
		modifica = true;
		cout << endl << "Sede legale modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova sede legale '" << nuova_sede_legale << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaTipologiaAttivita(UtenteGruppo &associazione)
{
	bool modifica = false;
	string nuova_tipologia_attivita;
	//inserimento nuova tipologia attività
	cout << endl << "Inserire la nuova tipologia di attivita' : ";
	getline(cin, nuova_tipologia_attivita);
	//se è valida
	if (associazione.stringaValida(nuova_tipologia_attivita))
	{
		associazione.setTipologiaAttività(nuova_tipologia_attivita);
		modifica = true;
		cout << endl << "Tipologia attivita' modificata" << endl;
	}
	//se non è valida
	else
	{
		cout << endl << "Errore : la nuova tipologia di attivita' '" << nuova_tipologia_attivita << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaTelefono(UtenteGruppo &associazione)
{
	bool modifica = false;
	string nuovo_telefono;
	//inserimento nuovo telefono
	cout << endl << "Inserire il nuovo telefono : ";
	getline(cin, nuovo_telefono);
	//se è valido
	if ((associazione.stringaValida(nuovo_telefono)) && (associazione.telefonoValido(nuovo_telefono)))
	{
		associazione.setTelefono(nuovo_telefono);
		modifica = true;
		cout << endl << "Telefono modificato" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : il nuovo telefono '" << nuovo_telefono << "' non e' valido" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaEmail(UtenteGruppo &associazione)
{
	bool modifica = false;
	string nuova_email;
	//inserimento nuova email
	cout << endl << "Inserire la nuova email formato <id_utente_email>@<dominio> : ";
	getline(cin, nuova_email);
	//se è valido
	if ((associazione.stringaValida(nuova_email)) && (associazione.emailValida(nuova_email)))
	{
		associazione.setEmail(nuova_email);
		modifica = true;
		cout << endl << "Email modificata" << endl;
	}
	//se non è valido
	else
	{
		cout << endl << "Errore : la nuova email '" << nuova_email << "' non e' valida" << endl;
	}
	return modifica;
}
bool utenteGruppoModificaDataCreazione(UtenteGruppo &associazione)
{
	bool modifica = false;
	string str_nuova_data_creazione;
	Data nuova_data_creazione;
	//inserimento nuova data di creazione
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
