#pragma once

#include <iostream>
#include <string>

#include "Data.h"

#define ID_TIPO_AZIENDA 2

#define STR_NOME "nome"
#define STR_SEDE_FISCALE "sede fiscale"
#define STR_SEDE_OPERATIVA "sede operativa"
#define STR_TIPO_PRODOTTO "tipo prodotto"
#define STR_DATA_DI_CREAZIONE "data di creazione"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'

using namespace std;

class Utente_Azienda
{
public:

	//costruttori e distruttore
	Utente_Azienda();
	Utente_Azienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const Data &data_creazione);
	~Utente_Azienda();

	//metodi di set
	void set_Id(const string &id);
	void set_Nome(const string &nome);
	void set_Sede_Fiscale(const string &sede_fiscale);
	void set_Sede_Operativa(const string &sede_operativa);
	void set_Tipo_Prodotto(const string &tipo_prodotto);
	void set_Data_Creazione(const Data &data_creazione);

	//metodi di get
	string get_Id() const;
	string get_Nome() const;
	string get_Sede_Fiscale() const;
	string get_Sede_Operativa() const;
	string get_Tipo_Prodotto() const;
	Data get_Data_Creazione() const;

	//metodi di stampa
	string stampa_Utente_Azienda() const;
	friend ostream & operator<<(ostream &output, const Utente_Azienda &da_stampare);

private:

	//variabili private
	string _id;
	string _nome;
	string _sede_fiscale;
	string _sede_operativa;
	string _tipo_prodotto;
	Data _data_creazione;
};