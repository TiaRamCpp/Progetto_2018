#include "UtenteAzienda.h"

UtenteAzienda::UtenteAzienda()
{
	_id.clear();
	_nome.clear();
	_sede_fiscale.clear();
	_sede_operativa.clear();
	_tipo_prodotto.clear();
	_telefono.clear();
	_email.clear();
}

UtenteAzienda::UtenteAzienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const string &telefono, const string &email, const Data &data_creazione)
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

UtenteAzienda::~UtenteAzienda()
{
}

void UtenteAzienda::setSedeFiscale(const string &sede_fiscale)
{
	_sede_fiscale = sede_fiscale;
}

void UtenteAzienda::setSedeOperativa(const string &sede_operativa)
{
	_sede_operativa = sede_operativa;
}

void UtenteAzienda::setTipoProdotto(const string &tipo_prodotto)
{
	_tipo_prodotto = tipo_prodotto;
}

void UtenteAzienda::setDataCreazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string UtenteAzienda::getSedeFiscale() const
{
	return _sede_fiscale;
}

string UtenteAzienda::getSedeOperativa() const
{
	return _sede_operativa;
}

string UtenteAzienda::getTipoProdotto() const
{
	return _tipo_prodotto;
}

Data UtenteAzienda::getDataCreazione() const
{
	return _data_creazione;
}

bool UtenteAzienda::utenteValido() const
{
	//controlla che tutto l'utente sia valido
	bool ok = true;
	//controllo che nessuna stringa sia vuota o che contenga caratteri speciali
	ok &= stringaValida(_id);
	ok &= stringaValida(_nome);
	ok &= stringaValida(_sede_fiscale);
	ok &= stringaValida(_sede_operativa);
	ok &= stringaValida(_tipo_prodotto);
	ok &= stringaValida(_telefono);
	ok &= stringaValida(_email);
	//controllo id valido
	ok &= idValido(_id);
	//controllo telefono valido
	ok &= telefonoValido(_telefono);
	//controllo email valida
	ok &= emailValida(_email);
	//controllo che la data inserita sia valida
	ok &= _data_creazione.isValid();
	return ok;
}

string UtenteAzienda::stampaUtente() const
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
	output += DIVISORE + _data_creazione.stampaData() + PARENTESI_DX;

	return output;
}