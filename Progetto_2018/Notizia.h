#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Data.h"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'
#define NEW_LINE_CHARACTER '\n'
#define NULL_TERMINATED_STRING '\0'

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
	void set_Id_Mittente(const string &id_mittente);
	void set_Messaggio(const string &messaggio);
	void set_Data_Pubblicazione(const Data &data_pubblicazione);
	void set_Like(const vector<string> &like);
	void set_Dislike(const vector<string> &dislike);

	//metodi di get
	string get_Id_Mittente() const;
	string get_Messaggio() const;
	Data get_Data_Pubblicazione() const;
	vector<string> get_Like() const;
	vector<string> get_Dislike() const;

	//metodi della classe
	bool stringa_Valida(const string &stringa) const;
	bool notizia_Valida() const;

	//aggiunta reazione
	bool aggiungi_Like(const string &id);
	bool aggiungi_Dislike(const string &id);

	//rimuovi reazione
	bool rimuovi_Reazione(const string &id);

	//metodi di stampa
	string stampa_Notizia() const;
	friend ostream &operator<< (ostream &output, const Notizia &notizia_da_stampare);

private:

	//metodi privati
	bool _id_Trovato(const vector<string> &dati, const string &id) const;
	int _trova_Pos_Id(const vector<string> &dati, const string &id) const;
	bool _aggiungi_Reazione(vector<string> &reazione, const string &id);

	//variabili private
	string _id_mittente;
	string _messaggio;
	Data _data_pubblicazione;
	vector<string> _like;
	vector<string> _dislike;
};