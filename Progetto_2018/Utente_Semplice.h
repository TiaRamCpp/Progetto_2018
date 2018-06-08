#pragma once

#include "Utente.h"

#define ID_TIPO_SEMPLICE "utente_semplice"

#define STR_COGNOME "cognome"
#define STR_DOMICILIO "domicilio"
#define STR_DATA_DI_NASCITA "data di nascita"

using namespace std;

class Utente_Semplice :
	public Utente
{
public:

	//costruttori e distruttore
	Utente_Semplice();
	Utente_Semplice(const string &id, const string &nome, const string &cognome, const string &domicilio, const string &telefono, const string &email, const Data &data_nascita);
	~Utente_Semplice();

	//metodi di set
	void set_Cognome(const string &cognome);
	void set_Domicilio(const string &domicilio);
	void set_Data_Nascita(const Data &data_nascita);

	//metodi di get
	string get_Cognome() const;
	string get_Domicilio() const;
	Data get_Data_Nascita() const;

	//metodi della classe
	int calcola_Eta() const;
	bool utente_Valido() const;

	//metodo di stampa
	string stampa_Utente() const;

private:

	//variabili private
	string _cognome;
	string _domicilio;
	Data _data_nascita;
};