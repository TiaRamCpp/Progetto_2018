#include "Utente.h"

Utente::Utente()
{
	_id.clear();
	_nome.clear();
	_telefono.clear();
	_email.clear();
	_id_arco.clear();
	_tipo_relazione.clear();
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

vector<string> Utente::getIdArco() const
{
	return _id_arco;
}

vector<string> Utente::getTipoRelazione() const
{
	return _tipo_relazione;
}

bool Utente::stringaValida(const string &stringa) const
{
	bool ok = true;
	//se � vuota
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
		//se c'� uno spazio o altri caratteri non validi
		if (!isgraph(id[i]))
			ok = false;
	return ok;
}

bool Utente::telefonoValido(const string &telefono) const
{
	bool ok = true;
	//controllo che ci siano solo numeri
	for (unsigned int i = 0; ((i < telefono.size()) && (ok)); i++)
		//se non � un numero
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
	//se c'� un solo '@'
	if(chiocciola==1)
		ok=true;
	//controllo che la '@' non sia ne all inizio ne alla fine
	//controllo che non sia all inizio
	if (email.front() == CHIOCCIOLA)
		ok = false;
	//controllo che non sia alla fine
	if (email.back() == CHIOCCIOLA)
		ok = false;
	//controllo che non ci siano spazi o altri caratteri di formattazione
	for (unsigned int i = 0; ((i < email.size()) && (ok)); i++)
		//se c'� uno spazio o altri caratteri non validi
		if (!isgraph(email[i]))
			ok = false;
	return ok;
}

unsigned int Utente::numeroRelazioni() const
{
	return _id_arco.size();
}

unsigned int Utente::contaTipoRelazione(const string &tipo_relazione) const
{
	//conta direttamente un unico tipo di relazione
	unsigned int numero_tipo_relazione = 0;
	for (unsigned int i = 0; i < _tipo_relazione.size(); i++)
	{
		if (_tipo_relazione[i] == tipo_relazione)
		{
			numero_tipo_relazione++;
		}
	}
	return numero_tipo_relazione;
}

void Utente::contaTipiRelazione(const vector<string> &tipo_relazione_cercata, vector<unsigned int> &numero_tipo_relazione) const
{
	//utile per scandendire una sola volta il vettore di _tipo_relazione e contare pi� tipi di relazioni contemporaneamente

	//inizializzo contatori
	numero_tipo_relazione.resize(tipo_relazione_cercata.size());
	for (unsigned int i = 0; i < numero_tipo_relazione.size(); i++)
	{
		numero_tipo_relazione[i] = 0;
	}

	//cerco i tipi di reazione per ogni relazione
	for (unsigned int i = 0; i < _tipo_relazione.size(); i++)
	{
		//cerco se � una delle relazioni cercate
		for (unsigned int j = 0; j < tipo_relazione_cercata.size(); j++)
		{
			//se � uno delle relazioni cercate
			if (tipo_relazione_cercata[j] == _tipo_relazione[i])
			{
				numero_tipo_relazione[j]++;
			}
		}
	}
}

bool Utente::tipoRelazioneEsistente(const string &tipo_relazione) const
{
	bool esistente = false;
	//se � una delle relazioni possibili
	if ((tipo_relazione == STR_AMICO) || (tipo_relazione == STR_CONOSCENTE) || (tipo_relazione == STR_CONIUGE) || (tipo_relazione == STR_FIGLIO) || (tipo_relazione == STR_GENITORE) || (tipo_relazione == STR_DIPENDENTE) || (tipo_relazione == STR_CONSOCIATA) || (tipo_relazione == STR_MEMBRO))
		esistente = true;
	return esistente;
}

bool Utente::trovaPosizioneRelazione(const string &id, const string &tipo_relazione, unsigned int &posizione) const
{
	bool trovata = false;
	posizione = 0;
	//cerco se esiste
	for (unsigned int i = 0; ((i < _id_arco.size()) && (!trovata)); i++)
	{
		//se la trova
		if ((_id_arco[i] == id) && (_tipo_relazione[i] == tipo_relazione))
		{
			//salvo la posizione
			posizione = i;
			trovata = true;
		}
	}
	return trovata;
}

bool Utente::convertiIdRelazioni(const string &vecchio_id, const string &nuovo_id)
{
	bool conversione = false;
	for (unsigned int i = 0; i < _id_arco.size(); i++)
	{
		if (_id_arco[i] == vecchio_id)
		{
			conversione = true;
			_id_arco[i] = nuovo_id;
		}
	}
	return conversione;
}

bool Utente::aggiungiRelazione(const string &id, const string &tipo_relazione)
{
	bool aggiunta = false;
	unsigned int posizione;

	//se non � una relazione con se stesso
	if (id != _id)
	{
		//se non trovo la relazione
		if (!trovaPosizioneRelazione(id, tipo_relazione, posizione))
		{
			//la aggiungo
			_id_arco.push_back(id);
			_tipo_relazione.push_back(tipo_relazione);
			aggiunta = true;
		}
	}

	return aggiunta;
}

bool Utente::modificaRelazione(const string &id, const string &nuovo_tipo_relazione, const string &vecchio_tipo_relazione)
{
	bool modificata = false;
	unsigned int posizione;

	//se non � una relazione con se stesso
	if (id != _id)
	{
		//se trovo la relazione
		if (trovaPosizioneRelazione(id, vecchio_tipo_relazione, posizione))
		{
			//la modifico
			_tipo_relazione[posizione] = nuovo_tipo_relazione;
			modificata = true;
		}
	}

	return modificata;
}

bool Utente::rimuoviRelazioneSpecifica(const string &id, const string &tipo_relazione)
{
	bool eliminata = false;
	unsigned int posizione;

	//se trovo la relazione
	if (trovaPosizioneRelazione(id, tipo_relazione, posizione))
	{
		//la elimino
		_id_arco.erase(_id_arco.begin() + posizione);
		_tipo_relazione.erase(_tipo_relazione.begin() + posizione);
		eliminata = true;
	}

	return eliminata;
}

bool Utente::rimuoviRelazioniConUtente(const string &id_utente_da_rimuovere)
{
	//rimuove tutte le eventuali relazioni con un utente
	//utile per quando viene rimosso un utente e per eliminare tutte le relazioni con lui
	bool eliminata = false;

	//cerco tra tutte le relazioni
	for (unsigned int i = 0; i < _id_arco.size(); i++)
	{
		//se trovo la relazione
		if (_id_arco[i] == id_utente_da_rimuovere)
		{
			_id_arco.erase(_id_arco.begin() + i);
			_tipo_relazione.erase(_tipo_relazione.begin() + i--);
			//i-- perch� avendone tolta una il totale � diminuito di 1
			eliminata = true;
		}
	}	

	return eliminata;
}

string Utente::stampaNodo() const
{
	string stampa;
	for (unsigned int i = 0; i < _id_arco.size(); i++)
	{
		//se non � il primo
		if (i != 0)
			stampa += '\n';
		stampa += _id + SEPARATORE + _id_arco[i] + SEPARATORE + _tipo_relazione[i];
	}
	return stampa;
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
