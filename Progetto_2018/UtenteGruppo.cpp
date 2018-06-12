#include "UtenteGruppo.h"

UtenteGruppo::UtenteGruppo()
{
	_id.clear();
	_nome.clear();
	_sede_legale.clear();
	_tipologia_attivitą.clear();
	_telefono.clear();
	_email.clear();
}

UtenteGruppo::UtenteGruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attivitą, const string &telefono, const string &email, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_legale = sede_legale;
	_tipologia_attivitą = tipologia_attivitą;
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

void UtenteGruppo::setTipologiaAttivitą(const string &tipologia_attivitą)
{
	_tipologia_attivitą = tipologia_attivitą;
}

void UtenteGruppo::setDataCreazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string UtenteGruppo::getSedeLegale() const
{
	return _sede_legale;
}

string UtenteGruppo::getTipologiaAttivitą() const
{
	return _tipologia_attivitą;
}

Data UtenteGruppo::getDataCreazione() const
{
	return _data_creazione;
}

bool UtenteGruppo::utenteValido() const
{
	//controlla che tutto l'utente sia valido
	bool ok = true;
	//controllo che nessuna stringa sia vuota o che contenga caratteri speciali
	ok &= stringaValida(_id);
	ok &= stringaValida(_nome);
	ok &= stringaValida(_sede_legale);
	ok &= stringaValida(_tipologia_attivitą);
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

	//stampa tipologia attivitą
	output += STR_TIPOLOGIA_ATTIVITA;
	output += DIVISORE + _tipologia_attivitą + SEPARATORE;

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