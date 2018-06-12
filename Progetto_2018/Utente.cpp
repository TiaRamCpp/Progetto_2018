#include "Utente.h"

Utente::Utente()
{
}

Utente::~Utente()
{
}

void Utente::setId(const string &id)
{
	_id = id;
}

void Utente::setNome(const string &nome)
{
	_nome = nome;
}

void Utente::setTelefono(const string &telefono)
{
	_telefono = telefono;
}

void Utente::setEmail(const string &email)
{
	_email = email;
}

string Utente::getId() const
{
	return _id;
}

string Utente::getNome() const
{
	return _nome;
}

string Utente::getTelefono() const
{
	return _telefono;
}

string Utente::getEmail() const
{
	return _email;
}

bool Utente::stringaValida(const string &stringa) const
{
	bool ok = true;
	//controllo che non ci sia uno dei caratteri non permessi e che sia stampabile
	for (unsigned int i = 0; ((i < stringa.size()) && (ok)); i++)
		if (!_carattereValido(stringa[i]))
			ok = false;
	return ok;
}

bool Utente::telefonoValido() const
{
	bool ok = true;
	//controllo che ci siano solo numeri
	for (unsigned int i = 0; ((i < _telefono.size()) && (ok)); i++)
		//se non è un numero
		if (!isdigit(_telefono[i]))
			ok = false;
	return ok;
}

bool Utente::emailValida() const
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

ostream & operator<<(ostream &output, const Utente &da_stampare)
{
	output << da_stampare.stampaUtente();
	return output;
}

bool Utente::_carattereValido(const char & carattere) const
{
	bool ok = true;
	//controllo che non ci sia uno dei caratteri proibiti
	if (carattere == SEPARATORE)
		ok = false;
	if (carattere == DIVISORE)
		ok = false;
	if (carattere == PARENTESI_SX)
		ok = false;
	if (carattere == PARENTESI_DX)
		ok = false;
	//controllo che sia un carattere stampabile
	if (!isprint(carattere))
		ok = false;
	return ok;
}
