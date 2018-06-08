#include "Utente.h"

Utente::Utente()
{
}

Utente::~Utente()
{
}

void Utente::set_Id(const string &id)
{
	_id = id;
}

void Utente::set_Nome(const string &nome)
{
	_nome = nome;
}

void Utente::set_Telefono(const string &telefono)
{
	_telefono = telefono;
}

void Utente::set_Email(const string &email)
{
	_email = email;
}

string Utente::get_Id() const
{
	return _id;
}

string Utente::get_Nome() const
{
	return _nome;
}

string Utente::get_Telefono() const
{
	return _telefono;
}

string Utente::get_Email() const
{
	return _email;
}

bool Utente::stringa_Valida(const string &stringa) const
{
	bool ok = true;
	//controllo che non ci sia uno dei caratteri non permessi
	for (unsigned int i = 0; ((i < stringa.size()) && (ok)); i++)
		if ((stringa[i] == NEW_LINE_CHARACTER) || (stringa[i] == NULL_TERMINATED_STRING) || (stringa[i] == SEPARATORE) || (stringa[i] == DIVISORE) || (stringa[i] == PARENTESI_SX) || (stringa[i] == PARENTESI_DX))
			ok = false;
	return ok;
}

bool Utente::telefono_Valido() const
{
	bool ok = true;
	//controllo che ci siano solo numeri
	for (unsigned int i = 0; ((i < _telefono.size()) && (ok)); i++)
		//se non è un numero
		if (!isdigit(_telefono[i]))
			ok = false;
	return ok;
}

bool Utente::email_Valida() const
{
	//formattazzione valida <id_utente_email>@<dominio>
	int chiocciola = 0;
	bool ok = false;
	//conto i caratteri '@'
	for (unsigned int i = 0; (i < _email.size()); i++)
		if (_email[i] == CHIOCCIOLA)
			chiocciola++;
	//se c'è un solo '@'
	if(chiocciola==1)
		ok=true;
	return ok;
}
