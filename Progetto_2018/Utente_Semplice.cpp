#include "Utente_Semplice.h"

Utente_Semplice::Utente_Semplice()
{
	_id = ID_VUOTO;
	_nome.clear();
	_cognome.clear();
	_domicilio.clear();
}

Utente_Semplice::Utente_Semplice(const int &id, const string &nome, const string &cognome, const string &domicilio, const Data &data_nascita)
{
	_id = id;
	_nome = nome;
	_cognome = cognome;
	_domicilio = domicilio;
	_data_nascita = data_nascita;
}

Utente_Semplice::~Utente_Semplice()
{
}

void Utente_Semplice::set_Id(const int &id)
{
	_id = id;
}

void Utente_Semplice::set_Nome(const string &nome)
{
	_nome = nome;
}

void Utente_Semplice::set_Cognome(const string &cognome)
{
	_cognome = cognome;
}

void Utente_Semplice::set_Domicilio(const string &domicilio)
{
	_domicilio = domicilio;
}

void Utente_Semplice::set_Data_Nascita(const Data &data_nascita)
{
	_data_nascita = data_nascita;
}

int Utente_Semplice::get_Id() const
{
	return _id;
}

string Utente_Semplice::get_Nome() const
{
	return _nome;
}

string Utente_Semplice::get_Cognome() const
{
	return _cognome;
}

string Utente_Semplice::get_Domicilio() const
{
	return _domicilio;
}

Data Utente_Semplice::get_Data_Nascita() const
{
	return _data_nascita;
}

int Utente_Semplice::calcola_Eta() const
{
	return _data_nascita.get_Anni_Da(); //con default la data di oggi
}