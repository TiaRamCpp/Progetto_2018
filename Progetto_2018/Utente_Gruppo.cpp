#include "Utente_Gruppo.h"

Utente_Gruppo::Utente_Gruppo()
{
	_id.clear();
	_nome.clear();
	_sede_legale.clear();
	_tipologia_attività.clear();
}

Utente_Gruppo::Utente_Gruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_legale = sede_legale;
	_tipologia_attività = tipologia_attività;
	_data_creazione = data_creazione;
}

Utente_Gruppo::~Utente_Gruppo()
{
}

void Utente_Gruppo::set_Id(const string &id)
{
	_id = id;
}

void Utente_Gruppo::set_Nome(const string &nome)
{
	_nome = nome;
}

void Utente_Gruppo::set_Sede_Legale(const string &sede_legale)
{
	_sede_legale = sede_legale;
}

void Utente_Gruppo::set_Tipologia_Attività(const string &tipologia_attività)
{
	_tipologia_attività = tipologia_attività;
}

void Utente_Gruppo::set_Data_Creazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string Utente_Gruppo::get_Id() const
{
	return _id;
}

string Utente_Gruppo::get_Nome() const
{
	return _nome;
}

string Utente_Gruppo::get_Sede_Legale() const
{
	return _sede_legale;
}

string Utente_Gruppo::get_Tipologia_Attività() const
{
	return _tipologia_attività;
}

Data Utente_Gruppo::get_Data_Creazione() const
{
	return _data_creazione;
}

string Utente_Gruppo::stampa_Utente_Gruppo() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += ID_TIPO_GRUPPO + SEPARATORE + PARENTESI_SX;

	//stampa nome
	output += STR_NOME;
	output += DIVISORE + _nome + SEPARATORE;

	//stampa sede legale
	output += STR_SEDE_LEGALE;
	output += DIVISORE + _sede_legale + SEPARATORE;

	//stampa tipologia attività
	output += STR_TIPOLOGIA_ATTIVITA;
	output += DIVISORE + _tipologia_attività + SEPARATORE;

	//stampa data di creazione
	output += STR_DATA_DI_CREAZIONE;
	output += DIVISORE + _data_creazione.stampa_Data() + PARENTESI_DX;

	return output;
}

ostream & operator<<(ostream &output, const Utente_Gruppo &da_stampare)
{
	output << da_stampare.stampa_Utente_Gruppo();
	return output;
}
