#include "UtenteGruppo.h"

UtenteGruppo::UtenteGruppo()
{
	_id.clear();
	_nome.clear();
	_sede_legale.clear();
	_tipologia_attività.clear();
	_telefono.clear();
	_email.clear();
	_id_arco.clear();
	_tipo_relazione.clear();
}

UtenteGruppo::UtenteGruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const string &telefono, const string &email, const Data &data_creazione)
{
	_id = id;
	_nome = nome;
	_sede_legale = sede_legale;
	_tipologia_attività = tipologia_attività;
	_telefono = telefono;
	_email = email;
	_data_creazione = data_creazione;
	_id_arco.clear();
	_tipo_relazione.clear();
}

UtenteGruppo::~UtenteGruppo()
{
}

void UtenteGruppo::setSedeLegale(const string &sede_legale)
{
	_sede_legale = sede_legale;
}

void UtenteGruppo::setTipologiaAttività(const string &tipologia_attività)
{
	_tipologia_attività = tipologia_attività;
}

void UtenteGruppo::setDataCreazione(const Data &data_creazione)
{
	_data_creazione = data_creazione;
}

string UtenteGruppo::getSedeLegale() const
{
	return _sede_legale;
}

string UtenteGruppo::getTipologiaAttività() const
{
	return _tipologia_attività;
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
	
	//controllo id valido
	ok &= stringaValida(_id);
	ok &= idValido(_id);
	ok &= stringaValida(_nome);
	if (!_sede_legale.empty())
		ok &= stringaValida(_sede_legale);
	if (!_tipologia_attività.empty())
		ok &= stringaValida(_tipologia_attività);
	//controllo telefono valido
	if (!_telefono.empty())
	{
		ok &= stringaValida(_telefono);
		ok &= telefonoValido(_telefono);
	}
	//controllo email valida
	if (!_email.empty())
	{
		ok &= stringaValida(_email);
		ok &= emailValida(_email);
	}
	//controllo che la data inserita sia valida
	ok &= _data_creazione.isValid();
	return ok;
}

bool UtenteGruppo::tipoRelazionePossibile(const string & tipo_relazione, const string & tipo_id) const
{
	bool ok = false;
	//se è un utente semplice
	if (tipo_id == ID_TIPO_SEMPLICE)
	{
		//se è una delle possibili relazioni tra un utente gruppo e un utente semplice
		if (tipo_relazione == STR_MEMBRO)
		{
			ok = true;
		}
	}
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
	output += DIVISORE + _data_creazione.stampaData() + PARENTESI_DX;

	return output;
}

string UtenteGruppo::stampaUtenteEstesa() const
{
	string output;

	//stampa id
	output = "Utente : " + _id;

	//stampa id_tipo_utente
	output += "\nTipo Utente : ";
	output += ID_TIPO_GRUPPO;

	//stampa nome
	output += "\nNome : " + _nome;

	//stampa sede legale
	output += "\nSede Legale : " + _sede_legale;

	//stampa tipologia attività
	output += "\nTipologia attivita' : " + _tipologia_attività;

	//stampa telefono
	output += "\nTelefono : " + _telefono;

	//stampa email
	output += "\nEmail : " + _email;

	//stampa data di creazione
	output += "\nData di Creazione : " + _data_creazione.stampaData();

	//stampa relazioni
	output += "\nRelazioni :";
	if (_id_arco.size() != 0)
		output += "\n" + stampaNodo();
	else
		output += " Nessuna Relazione";

	return output;
}
