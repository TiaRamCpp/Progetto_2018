#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Data.h"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'

#define STR_LIKE "like"
#define STR_DISLIKE "dislike"

using namespace std;

class Notizia
{
public:

	//costruttori e distruttore
	Notizia();
	Notizia(const string &id_mittente, const string &messaggio, const Data &data_pubblicazione, const vector<string> &like, const vector<string> &dislike);
	~Notizia();

	//metodi di set
	void setIdMittente(const string &id_mittente);
	void setMessaggio(const string &messaggio);
	void setDataPubblicazione(const Data &data_pubblicazione);
	void setLike(const vector<string> &like);
	void setDislike(const vector<string> &dislike);

	//metodi di get
	string getIdMittente() const;
	string getMessaggio() const;
	Data getDataPubblicazione() const;
	vector<string> getLike() const;
	vector<string> getDislike() const;

	//metodi della classe
	bool stringaValida(const string &stringa) const;
	bool notiziaValida() const;

	//aggiunta reazione
	bool aggiungiLike(const string &id);
	bool aggiungiDislike(const string &id);

	//rimuovi reazione
	bool rimuoviReazione(const string &id);

	//metodi di stampa
	string stampaNotizia() const;
	friend ostream &operator<< (ostream &output, const Notizia &notizia_da_stampare);

private:

	//metodi privati
	bool _idTrovato(const vector<string> &dati, const string &id) const;
	int _trovaPosId(const vector<string> &dati, const string &id) const;
	bool _aggiungiReazione(vector<string> &reazione, const string &id);	
	bool _carattereValido(const char &carattere) const;

	//variabili private
	string _id_mittente;
	string _messaggio;
	Data _data_pubblicazione;
	vector<string> _like;
	vector<string> _dislike;
};