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
	void setId(const string &id);
	void setNome(const string &nome);
	void setTelefono(const string &telefono);
	void setEmail(const string &email);

	//metodi di get
	string getId() const;
	string getNome() const;
	string getTelefono() const;
	string getEmail() const;

	//metodi della classe
	bool stringaValida(const string &stringa) const;
	bool telefonoValido() const;
	bool emailValida() const;
	virtual bool utenteValido() const = 0;

	//metodi di stampa
	virtual string stampaUtente() const = 0;
	friend ostream & operator<<(ostream &output, const Utente &da_stampare);

protected: 

	bool _carattereValido(const char &carattere) const;

	//variabili protette

	string _id;
	string _nome;
	string _telefono;
	string _email;
};

