#include "Utente_Azienda.h"

Utente_Azienda::Utente_Azienda()
{
	_id.clear();
	_nome.clear();
	_sede_fiscale.clear();
	_sede_operativa.clear();
	_tipo_prodotto.clear();
}

Utente_Azienda::Utente_Azienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_fiscale = sede_fiscale;
	_sede_operativa = sede_operativa;
	_tipo_prodotto = tipo_prodotto;
	_data_creazione = data_creazione;
}

Utente_Azienda::~Utente_Azienda()
{
}

void Utente_Azienda::set_Id(const string &id)
{
	_id = id;
}

void Utente_Azienda::set_Nome(const string &nome)
{
	_nome = nome;
}

void Utente_Azienda::set_Sede_Fiscale(const string &sede_fiscale)
{
	_sede_fiscale = sede_fiscale;
}

void Utente_Azienda::set_Sede_Operativa(const string &sede_operativa)
{
	_sede_operativa = sede_operativa;
}

void Utente_Azienda::set_Tipo_Prodotto(const string &tipo_prodotto)
{
	_tipo_prodotto = tipo_prodotto;
}

void Utente_Azienda::set_Data_Creazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string Utente_Azienda::get_Id() const
{
	return _id;
}

string Utente_Azienda::get_Nome() const
{
	return _nome;
}

string Utente_Azienda::get_Sede_Fiscale() const
{
	return _sede_fiscale;
}

string Utente_Azienda::get_Sede_Operativa() const
{
	return _sede_operativa;
}

string Utente_Azienda::get_Tipo_Prodotto() const
{
	return _tipo_prodotto;
}

Data Utente_Azienda::get_Data_Creazione() const
{
	return _data_creazione;
}

string Utente_Azienda::stampa_Utente_Azienda() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += to_string(ID_TIPO_AZIENDA) + SEPARATORE + PARENTESI_SX;

	//stampa nome
	output += STR_NOME;
	output += DIVISORE + _nome + SEPARATORE;

	//stampa sede fiscale
	output += STR_SEDE_FISCALE;
	output += DIVISORE + _sede_fiscale + SEPARATORE;

	//stampa sede operativa
	output += STR_SEDE_OPERATIVA;
	output += DIVISORE + _sede_operativa + SEPARATORE;

	//stampa tipo prodotto
	output += STR_TIPO_PRODOTTO;
	output += DIVISORE + _tipo_prodotto + SEPARATORE;

	//stampa data di creazione
	output += STR_DATA_DI_CREAZIONE;
	output += DIVISORE + _data_creazione.stampa_Data() + PARENTESI_DX;

	return output;
}

ostream & operator<<(ostream & output, const Utente_Azienda & da_stampare)
{
	output << da_stampare.stampa_Utente_Azienda();
	return output;
}
