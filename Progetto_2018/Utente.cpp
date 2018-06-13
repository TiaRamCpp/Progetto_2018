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
	//se è vuota
	if (stringa.empty())
		ok = false;
	//controllo che non ci sia uno dei caratteri non permessi e che sia stampabile
	for (unsigned int i = 0; ((i < stringa.size()) && (ok)); i++)
		if (!_carattereValido(stringa[i]))
			ok = false;
	return ok;
}

bool Utente::idValido(const string &id) const
{
	bool ok = true;
	//controllo che non ci siano spazi o altri caratteri di formattazione
	for (unsigned int i = 0; ((i < id.size()) && (ok)); i++)
		//se c'è uno spazio o altri caratteri non validi
		if (!isgraph(id[i]))
			ok = false;
	return ok;
}

bool Utente::telefonoValido(const string &telefono) const
{
	bool ok = true;
	//controllo che ci siano solo numeri
	for (unsigned int i = 0; ((i < telefono.size()) && (ok)); i++)
		//se non è un numero
		if (!isdigit(telefono[i]))
			ok = false;
	return ok;
}

bool Utente::emailValida(const string &email) const
{
	//formattazzione valida <id_utente_email>@<dominio>
	int chiocciola = 0;
	bool ok = false;
	//conto i caratteri '@'
	for (unsigned int i = 0; (i < email.size()); i++)
		if (email[i] == CHIOCCIOLA)
			chiocciola++;
	//se c'è un solo '@'
	if(chiocciola==1)
		ok=true;
	//controllo che non ci siano spazi o altri caratteri di formattazione
	for (unsigned int i = 0; ((i < email.size()) && (ok)); i++)
		//se c'è uno spazio o altri caratteri non validi
		if (!isgraph(email[i]))
			ok = false;
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
