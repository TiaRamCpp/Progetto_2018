#include "UtenteSemplice.h"

UtenteSemplice::UtenteSemplice()
{
	_id.clear();
	_nome.clear();
	_cognome.clear();
	_domicilio.clear();
	_telefono.clear();
	_email.clear();
	_id_arco.clear();
	_tipo_relazione.clear();
}

UtenteSemplice::UtenteSemplice(const string &id, const string &nome, const string &cognome, const string &domicilio, const string &telefono, const string &email, const Data &data_nascita)
{
	_id = id;
	_nome = nome;
	_cognome = cognome;
	_domicilio = domicilio;
	_telefono = telefono;
	_email = email;
	_data_nascita = data_nascita;
	_id_arco.clear();
	_tipo_relazione.clear();
}

UtenteSemplice::~UtenteSemplice()
{
}

void UtenteSemplice::setCognome(const string &cognome)
{
	_cognome = cognome;
}

void UtenteSemplice::setDomicilio(const string &domicilio)
{
	_domicilio = domicilio;
}

void UtenteSemplice::setDataNascita(const Data &data_nascita)
{
	_data_nascita = data_nascita;
}

string UtenteSemplice::getCognome() const
{
	return _cognome;
}

string UtenteSemplice::getDomicilio() const
{
	return _domicilio;
}

Data UtenteSemplice::getDataNascita() const
{
	return _data_nascita;
}

int UtenteSemplice::calcolaEta() const
{
	return _data_nascita.getAnniDa(); //con default la data di oggi
}

bool UtenteSemplice::utenteValido() const
{
	//controlla che tutto l'utente sia valido
	bool ok = true;
	//controllo che nessuna stringa sia vuota o che contenga caratteri speciali

	//controllo id valido
	ok &= stringaValida(_id);
	ok &= idValido(_id);
	ok &= stringaValida(_nome);
	ok &= stringaValida(_cognome);
	if(!_domicilio.empty())
		ok &= stringaValida(_domicilio);
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
	ok &= _data_nascita.isValid();
	return ok;
}

bool UtenteSemplice::tipoRelazionePossibile(const string &tipo_relazione, const string &tipo_id) const
{
	bool ok = false;
	//se è un utente semplice
	if (tipo_id == ID_TIPO_SEMPLICE)
	{
		//se è una delle possibili relazioni tra un utente semplice e un utente semplice
		if ((tipo_relazione == STR_AMICO) || (tipo_relazione == STR_CONIUGE) || (tipo_relazione == STR_CONOSCENTE) || (tipo_relazione == STR_FIGLIO) || (tipo_relazione == STR_GENITORE))
		{
			ok = true;
		}
	}
	else
	{
		//se è un utente azienda
		if (tipo_id == ID_TIPO_AZIENDA)
		{
			//se è una delle possibili relazioni tra un utente semplice e un utente azienda
			if (tipo_relazione == STR_DIPENDENTE)
			{
				ok = true;
			}
		}
		else
		{
			//se è un utente gruppo
			if (tipo_id == ID_TIPO_GRUPPO)
			{
				//se è una delle possibili relazioni tra un utente semplice e un utente gruppo
				if (tipo_relazione == STR_MEMBRO)
				{
					ok = true;
				}
			}
		}
	}
	return ok;
}

string UtenteSemplice::stampaUtente() const
{
	string output;

	//output=<id>,<id_tipo>,{<informazione_1>:<valore>,...,<informazione_n>:<valore>}

	//stampa id
	output = _id + SEPARATORE;

	//stampa id_tipo_utente
	output += ID_TIPO_SEMPLICE;
	output += SEPARATORE;
	output += PARENTESI_SX;

	//stampa nome
	output += STR_NOME;
	output += DIVISORE + _nome + SEPARATORE;

	//stampa cognome
	output += STR_COGNOME;
	output += DIVISORE + _cognome + SEPARATORE;

	//stampa domicilio
	output += STR_DOMICILIO;
	output += DIVISORE + _domicilio + SEPARATORE;

	//stampa telefono
	output += STR_TELEFONO;
	output += DIVISORE + _telefono + SEPARATORE;

	//stampa email
	output += STR_EMAIL;
	output += DIVISORE + _email + SEPARATORE;

	//stampa data di nascita
	output += STR_DATA_DI_NASCITA;
	output += DIVISORE + _data_nascita.stampaData();

	output += PARENTESI_DX;

	return output;
}

string UtenteSemplice::stampaUtenteEstesa() const
{
	string output;

	//stampa id
	output = "Utente : " + _id;

	//stampa id_tipo_utente
	output += "\nTipo Utente : ";
	output += ID_TIPO_SEMPLICE;

	//stampa nome
	output += "\nNome : " + _nome;

	//stampa cognome
	output += "\nCognome : " + _cognome;

	//stampa domicilio
	output += "\nDomicilio : " + _domicilio;

	//stampa telefono
	output += "\nTelefono : " + _telefono;

	//stampa email
	output += "\nEmail : " + _email;

	//stampa data di nascita
	output += "\nData di Nascita : " + _data_nascita.stampaData();

	//stampa relazioni
	output += "\nRelazioni :";
	if (_id_arco.size() != 0)
		output += "\n" + stampaNodo();
	else
		output += " Nessuna Relazione";

	return output;
}
