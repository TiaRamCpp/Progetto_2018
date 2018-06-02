#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Data.h"

#define ID_VUOTO 0

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'

using namespace std;

class Notizia
{
public:

	//costruttori e distruttore
	Notizia();
	Notizia(const int &id_mittente, const string &messaggio, const vector<int> &like, const vector<int> &dislike, const Data &data_pubblicazione);
	~Notizia();

	//metodi di set
	void set_Id_Mittente(const int &id_mittente);
	void set_Messaggio(const string &messaggio);
	void set_Like(const vector<int> &like);
	void set_Dislike(const vector<int> &dislike);
	void set_Data_Pubblicazione(const Data &data_pubblicazione);

	//metodi di get
	int get_Id_Mittente() const;
	string get_Messaggio() const;
	vector<int> get_Like() const;
	vector<int> get_Dislike() const;
	Data get_Data_Pubblicazione() const;

	//metodi della classe

	bool notizia_Valida() const;

	//aggiunta reazione
	bool aggiungi_Like(const int &id);
	bool aggiungi_Dislike(const int &id);

	//rimuovi reazione
	bool rimuovi_Reazione(const int &id);

	//metodi di stampa
	string stampa_Notizia() const;
	friend ostream &operator<< (ostream &output, const Notizia &notizia_da_stampare);

private:

	//metodi privati
	bool _id_Trovato(const vector<int> &dati, const int &id) const;
	int _trova_Pos_Id(const vector<int> &dati, const int &id) const;
	bool _aggiungi_Reazione(vector<int> &reazione, const int &id);

	//variabili private
	int _id_mittente;
	string _messaggio;
	vector<int> _like;
	vector<int> _dislike;
	Data _data_pubblicazione;
};