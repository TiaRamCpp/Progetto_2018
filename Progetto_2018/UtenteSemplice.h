#pragma once

#include "Utente.h"

#define ID_TIPO_SEMPLICE "utente_semplice"

#define STR_COGNOME "cognome"
#define STR_DOMICILIO "domicilio"
#define STR_DATA_DI_NASCITA "data di nascita"

using namespace std;

class UtenteSemplice :
	public Utente
{
public:

	//costruttori e distruttore
	UtenteSemplice();
	UtenteSemplice(const string &id, const string &nome, const string &cognome, const string &domicilio, const string &telefono, const string &email, const Data &data_nascita);
	~UtenteSemplice();

	//metodi di set
	void setCognome(const string &cognome);
	void setDomicilio(const string &domicilio);
	void setDataNascita(const Data &data_nascita);

	//metodi di get
	string getCognome() const;
	string getDomicilio() const;
	Data getDataNascita() const;

	//metodi della classe
	int calcolaEta() const;
	bool utenteValido() const;

	//metodo di stampa
	string stampaUtente() const;

private:

	//variabili private
	string _cognome;
	string _domicilio;
	Data _data_nascita;
};