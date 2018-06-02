#include "Utente_Semplice.h"

Utente_Semplice::Utente_Semplice()
{
	_id.clear();
	_nome.clear();
	_cognome.clear();
	_domicilio.clear();
}

Utente_Semplice::Utente_Semplice(const string &id, const string &nome, const string &cognome, const string &domicilio, const Data &data_nascita)
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

void Utente_Semplice::set_Id(const string &id)
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

string Utente_Semplice::get_Id() const
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

string Utente_Semplice::stampa_Utente_Semplice() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += ID_TIPO_SEMPLICE + SEPARATORE + PARENTESI_SX;

	//stampa nome
	output += STR_NOME;
	output += DIVISORE + _nome + SEPARATORE;

	//stampa cognome
	output += STR_COGNOME;
	output += DIVISORE + _cognome + SEPARATORE;

	//stampa domicilio
	output += STR_DOMICILIO;
	output += DIVISORE + _domicilio + SEPARATORE;

	//stampa data di nascita
	output += STR_DATA_DI_NASCITA;
	output += DIVISORE + _data_nascita.stampa_Data();

	output += PARENTESI_DX;

	return output;
}

ostream & operator<<(ostream &output, const Utente_Semplice &da_stampare)
{
	output << da_stampare.stampa_Utente_Semplice();
	return output;
}