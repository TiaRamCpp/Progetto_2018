#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Data.h"

#define ID_TIPO_SEMPLICE "utente_semplice"
#define ID_TIPO_AZIENDA "utente_azienda"
#define ID_TIPO_GRUPPO "utente_gruppo"

#define STR_NOME "nome"
#define STR_TELEFONO "telefono"
#define STR_EMAIL "email"

#define STR_AMICO "amico"
#define STR_CONOSCENTE "conoscente"
#define STR_CONIUGE "coniuge"
#define STR_FIGLIO "figlio"
#define STR_GENITORE "genitore"
#define STR_DIPENDENTE "dipendente"
#define STR_CONSOCIATA "consociata"
#define STR_MEMBRO "membro"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'
#define CHIOCCIOLA '@'

class Utente
{
public:

	Utente();
	~Utente();

	//metodi di set
	void setId(const string &id);
	void setNome(const string &nome);
	void setTelefono(const string &telefono);
	void setEmail(const string &email);

	//metodi di get
	string getId() const;
	string getNome() const;
	string getTelefono() const;
	string getEmail() const;
	vector<string> getIdArco() const;
	vector<string> getTipoRelazione() const;

	//metodi della classe
	bool stringaValida(const string &stringa) const;
	bool idValido(const string &id) const;
	bool telefonoValido(const string &telefono) const;
	bool emailValida(const string &email) const;
	virtual bool utenteValido() const = 0;

	//metodi per le relazioni
	unsigned int numeroRelazioni() const;
	unsigned int contaTipoRelazione(const string &tipo_relazione) const;
	void contaTipiRelazione(const vector<string> &tipo_relazione, vector<unsigned int> &numero_tipo_relazione) const;
	bool tipoRelazioneEsistente(const string &tipo_relazione) const;
	virtual bool tipoRelazionePossibile(const string &tipo_relazione, const string &tipo_id) const = 0;
	bool trovaPosizioneRelazione(const string &id, const string &tipo_relazione, unsigned int &posizione) const;
	bool convertiIdRelazioni(const string &vecchio_id, const string &nuovo_id);
	//rimuovo, modifico o aggiungo relazione del nodo con altri
	bool aggiungiRelazione(const string &id, const string &tipo_relazione);
	bool modificaRelazione(const string &id, const string &nuovo_tipo_relazione, const string &vecchio_tipo_relazione);
	bool rimuoviRelazioneSpecifica(const string &id, const string &tipo_relazione);
	bool rimuoviRelazioniConUtente(const string &id_utente_da_rimuovere);

	//metodi di stampa
	string stampaNodo() const;
	virtual string stampaUtente() const = 0;
	virtual string stampaUtenteEstesa() const = 0;
	friend ostream & operator<<(ostream &output, const Utente &da_stampare);

protected: 

	bool _carattereValido(const char &carattere) const;

	//variabili protette
	string _id;
	string _nome;
	string _telefono;
	string _email;

	//variabili per le relazioni
	vector<string> _id_arco;
	vector<string> _tipo_relazione;
};