#include "Utente_Azienda.h"

Utente_Azienda::Utente_Azienda()
{
	_id.clear();
	_nome.clear();
	_sede_fiscale.clear();
	_sede_operativa.clear();
	_tipo_prodotto.clear();
	_telefono.clear();
	_email.clear();
}

Utente_Azienda::Utente_Azienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const string &telefono, const string &email, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_fiscale = sede_fiscale;
	_sede_operativa = sede_operativa;
	_tipo_prodotto = tipo_prodotto;
	_telefono = telefono;
	_email = email;
	_data_creazione = data_creazione;
}

Utente_Azienda::~Utente_Azienda()
{
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

bool Utente_Azienda::utente_Valido() const
{
	//controlla che tutto l'utente sia valido
	//controllo che nessuna stringa contenga caratteri non validi e che la data sia valida
	bool ok = true;
	//controllo che nessuna stringa sia vuota
	ok &= !_id.empty();
	ok &= !_nome.empty();
	ok &= !_sede_fiscale.empty();
	ok &= !_sede_operativa.empty();
	ok &= !_tipo_prodotto.empty();
	ok &= !_telefono.empty();
	ok &= !_email.empty();
	//controllo che nessuna stringa contenga caratteri speciali
	ok &= stringa_Valida(_id);
	ok &= stringa_Valida(_nome);
	ok &= stringa_Valida(_sede_fiscale);
	ok &= stringa_Valida(_sede_operativa);
	ok &= stringa_Valida(_tipo_prodotto);
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

string Utente_Azienda::stampa_Utente() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += ID_TIPO_AZIENDA;
	output += SEPARATORE;
	output += PARENTESI_SX;

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