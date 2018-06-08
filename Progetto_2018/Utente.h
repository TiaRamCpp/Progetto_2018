#pragma once

#include <iostream>
#include <string>

#include "Data.h"

#define STR_NOME "nome"
#define STR_TELEFONO "telefono"
#define STR_EMAIL "email"

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
	void set_Id(const string &id);
	void set_Nome(const string &nome);
	void set_Telefono(const string &telefono);
	void set_Email(const string &email);

	//metodi di get
	string get_Id() const;
	string get_Nome() const;
	string get_Telefono() const;
	string get_Email() const;

	//metodi della classe
	bool stringa_Valida(const string &stringa) const;
	bool telefono_Valido() const;
	bool email_Valida() const;
	virtual bool utente_Valido() const = 0;

	//metodi di stampa
	virtual string stampa_Utente() const = 0;
	friend ostream & operator<<(ostream &output, const Utente &da_stampare);

protected: 

	bool _carattere_Valido(const char &carattere) const;

	//variabili protette

	string _id;
	string _nome;
	string _telefono;
	string _email;
};

