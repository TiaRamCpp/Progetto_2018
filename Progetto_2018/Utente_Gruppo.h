#pragma once

#include <iostream>
#include <string>

#include "Data.h"

#define ID_TIPO_GRUPPO "utente_gruppo"

#define STR_NOME "nome"
#define STR_SEDE_LEGALE "sede legale"
#define STR_TIPOLOGIA_ATTIVITA "tipologia attivita'"
#define STR_DATA_DI_CREAZIONE "data di creazione"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'
#define NEW_LINE_CHARACTER '\n'
#define NULL_TERMINATED_STRING '\0'

using namespace std;

class Utente_Gruppo
{
public:

	//costruttori e distruttore
	Utente_Gruppo();
	Utente_Gruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const Data &data_creazione);
	~Utente_Gruppo();

	//metodi di set
	void set_Id(const string &id);
	void set_Nome(const string &nome);
	void set_Sede_Legale(const string &sede_legale);
	void set_Tipologia_Attività(const string &tipologia_attività);
	void set_Data_Creazione(const Data &data_creazione);

	//metodi di get
	string get_Id() const;
	string get_Nome() const;
	string get_Sede_Legale() const;
	string get_Tipologia_Attività() const;
	Data get_Data_Creazione() const;

	//metodi della classe
	bool stringa_Valida(const string &stringa) const;
	bool utente_Valido() const;

	//metodi di stampa
	string stampa_Utente_Gruppo() const;
	friend ostream & operator<<(ostream &output, const Utente_Gruppo &da_stampare);

private:

	//variabili private
	string _id;
	string _nome;
	string _sede_legale;
	string _tipologia_attività;
	Data _data_creazione;
};