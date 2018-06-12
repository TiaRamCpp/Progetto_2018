#include "UtenteGruppo.h"

UtenteGruppo::UtenteGruppo()
{
	_id.clear();
	_nome.clear();
	_sede_legale.clear();
	_tipologia_attivit�.clear();
	_telefono.clear();
	_email.clear();
}

UtenteGruppo::UtenteGruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attivit�, const string &telefono, const string &email, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_legale = sede_legale;
	_tipologia_attivit� = tipologia_attivit�;
	_telefono = telefono;
	_email = email;
	_data_creazione = data_creazione;
}

UtenteGruppo::~UtenteGruppo()
{
}

void UtenteGruppo::setSedeLegale(const string &sede_legale)
{
	_sede_legale = sede_legale;
}

void UtenteGruppo::setTipologiaAttivit�(const string &tipologia_attivit�)
{
	_tipologia_attivit� = tipologia_attivit�;
}

void UtenteGruppo::setDataCreazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string UtenteGruppo::getSedeLegale() const
{
	return _sede_legale;
}

string UtenteGruppo::getTipologiaAttivit�() const
{
	return _tipologia_attivit�;
}

Data UtenteGruppo::getDataCreazione() const
{
	return _data_creazione;
}

bool UtenteGruppo::utenteValido() const
{
	//controlla che tutto l'utente sia valido
	//controllo che nessuna stringa contenga caratteri non validi e che la data sia valida
	bool ok = true;
	//controllo che nessuna stringa sia vuota
	ok &= !_id.empty();
	ok &= !_nome.empty();
	ok &= !_sede_legale.empty();
	ok &= !_tipologia_attivit�.empty();
	ok &= !_telefono.empty();
	ok &= !_email.empty();
	//controllo che nessuna stringa contenga caratteri speciali
	ok &= stringaValida(_id);
	ok &= stringaValida(_nome);
	ok &= stringaValida(_sede_legale);
	ok &= stringaValida(_tipologia_attivit�);
	ok &= stringaValida(_telefono);
	ok &= stringaValida(_email);
	//controllo telefono valido
	ok &= telefonoValido();
	//controllo email valida
	ok &= emailValida();
	//controllo che la data inserita sia valida
	ok &= _data_creazione.isValid();
	return ok;
}

string UtenteGruppo::stampaUtente() const
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

	//stampa tipologia attivit�
	output += STR_TIPOLOGIA_ATTIVITA;
	output += DIVISORE + _tipologia_attivit� + SEPARATORE;

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