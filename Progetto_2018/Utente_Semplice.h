#pragma once

#include <iostream>
#include <string>

#include "Data.h"

#define ID_TIPO_SEMPLICE "utente_semplice"

#define STR_NOME "nome"
#define STR_COGNOME "cognome"
#define STR_DOMICILIO "domicilio"
#define STR_DATA_DI_NASCITA "data di nascita"

#define SEPARATORE ','
#define DIVISORE ':'
#define PARENTESI_SX '{'
#define PARENTESI_DX '}'

using namespace std;

class Utente_Semplice
{
public:

	//costruttori e distruttore
	Utente_Semplice();
	Utente_Semplice(const string &id, const string &nome, const string &cognome, const string &domicilio, const Data &data_nascita);
	~Utente_Semplice();

	//metodi di set
	void set_Id(const string &id);
	void set_Nome(const string &nome);
	void set_Cognome(const string &cognome);
	void set_Domicilio(const string &domicilio);
	void set_Data_Nascita(const Data &data_nascita);

	//metodi di get
	string get_Id() const;
	string get_Nome() const;
	string get_Cognome() const;
	string get_Domicilio() const;
	Data get_Data_Nascita() const;

	//metodi della classe
	int calcola_Eta() const;

	//metodi di stampa
	string stampa_Utente_Semplice() const;
	friend ostream & operator<<(ostream &output, const Utente_Semplice &da_stampare);

private:

	//variabili private
	string _id;
	string _nome;
	string _cognome;
	string _domicilio;
	Data _data_nascita;
};