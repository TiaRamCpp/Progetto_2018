#include "Utente_Gruppo.h"

Utente_Gruppo::Utente_Gruppo()
{
	_id.clear();
	_nome.clear();
	_sede_legale.clear();
	_tipologia_attività.clear();
	_telefono.clear();
	_email.clear();
}

Utente_Gruppo::Utente_Gruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const string &telefono, const string &email, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_legale = sede_legale;
	_tipologia_attività = tipologia_attività;
	_telefono = telefono;
	_email = email;
	_data_creazione = data_creazione;
}

Utente_Gruppo::~Utente_Gruppo()
{
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

bool Utente_Gruppo::utente_Valido() const
{
	//controlla che tutto l'utente sia valido
	//controllo che nessuna stringa contenga caratteri non validi e che la data sia valida
	bool ok = true;
	//controllo che nessuna stringa sia vuota
	ok &= !_id.empty();
	ok &= !_nome.empty();
	ok &= !_sede_legale.empty();
	ok &= !_tipologia_attività.empty();
	ok &= !_telefono.empty();
	ok &= !_email.empty();
	//controllo che nessuna stringa contenga caratteri speciali
	ok &= stringa_Valida(_id);
	ok &= stringa_Valida(_nome);
	ok &= stringa_Valida(_sede_legale);
	ok &= stringa_Valida(_tipologia_attività);
	ok &= stringa_Valida(_telefono);
	ok &= stringa_Valida(_email);
	//controllo telefono valido
	ok &= telefono_Valido();
	//controllo email valida
	ok &= email_Valida();
	//controllo che la data inserita sia valida
	ok &= _data_creazione.is_Valid();
	return ok;
}

string Utente_Gruppo::stampa_Utente() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += ID_TIPO_GRUPPO;
	output += SEPARATORE;
	output += PARENTESI_SX;

	//stampa nome
	output += STR_NOME;
	output += DIVISORE + _nome + SEPARATORE;

	//stampa sede legale
	output += STR_SEDE_LEGALE;
	output += DIVISORE + _sede_legale + SEPARATORE;

	//stampa tipologia attività
	output += STR_TIPOLOGIA_ATTIVITA;
	output += DIVISORE + _tipologia_attività + SEPARATORE;

	//stampa telefono
	output += STR_TELEFONO;
	output += DIVISORE + _telefono + SEPARATORE;

	//stampa email
	output += STR_EMAIL;
	output += DIVISORE + _email + SEPARATORE;

	//stampa data di creazione
	output += STR_DATA_DI_CREAZIONE;
	output += DIVISORE + _data_creazione.stampa_Data() + PARENTESI_DX;

	return output;
}