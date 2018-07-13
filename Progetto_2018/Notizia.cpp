#include "Notizia.h"

Notizia::Notizia()
{
	_id_mittente.clear();
	_messaggio.clear();
	_like.clear();
	_dislike.clear();
}

Notizia::Notizia(const string &id_mittente, const string &messaggio, const Data &data_pubblicazione, const vector<string> &like, const vector<string> &dislike)
{
	_id_mittente = id_mittente;
	_messaggio = messaggio;
	_like = like;
	_dislike = dislike;
	_data_pubblicazione = data_pubblicazione;
}

Notizia::~Notizia()
{
}

void Notizia::setIdMittente(const string &id_mittente)
{
	_id_mittente = id_mittente;
}

void Notizia::setMessaggio(const string &messaggio)
{
	_messaggio = messaggio;
}

void Notizia::setDataPubblicazione(const Data &data_pubblicazione)
{
	_data_pubblicazione = data_pubblicazione;
}

void Notizia::setLike(const vector<string> &like)
{
	_like = like;
}

void Notizia::setDislike(const vector<string> &dislike)
{
	_dislike = dislike;
}

string Notizia::getIdMittente() const
{
	return _id_mittente;
}

string Notizia::getMessaggio() const
{
	return _messaggio;
}

Data Notizia::getDataPubblicazione() const
{
	return _data_pubblicazione;
}

vector<string> Notizia::getLike() const
{
	return _like;
}

vector<string> Notizia::getDislike() const
{
	return _dislike;
}

bool Notizia::stringaValida(const string & stringa) const
{
	bool ok = true;
	//controllo che non ci sia uno dei caratteri non permessi e che sia stampabile
	for (unsigned int i = 0; ((i < stringa.size()) && (ok)); i++)
		if (!_carattereValido(stringa[i]))
			ok = false;
	return ok;
}

bool Notizia::convertiIdReazioni(const string & vecchio_id, const string & nuovo_id)
{
	bool conversione = false;

	//conversione like
	for (unsigned int i = 0; ((i < _like.size()) && (!conversione)); i++)
	{
		if (_like[i] == vecchio_id)
		{
			conversione = true;
			_like[i] = nuovo_id;
		}
	}

	//conversione dislike
	for (unsigned int i = 0; ((i < _dislike.size()) && (!conversione)); i++)
	{
		if (_dislike[i] == vecchio_id)
		{
			conversione = true;
			_dislike[i] = nuovo_id;
		}
	}

	return conversione;
}

bool Notizia::notiziaValida() const
{
	bool valida = true;

	//controllo che nessuna stringa sia vuota
	valida &= !_id_mittente.empty();
	valida &= !_messaggio.empty();
	for (unsigned int i = 0; ((i < _like.size())&(valida)); i++)
		valida &= !_like[i].empty();
	for (unsigned int i = 0; ((i < _dislike.size())&(valida)); i++)
		valida &= !_dislike[i].empty();

	//controllo che nessuna stringa contenga caratteri speciali
	valida &= stringaValida(_id_mittente);
	valida &= stringaValida(_messaggio);
	for (unsigned int i = 0; ((i < _like.size())&(valida)); i++)
		valida &= stringaValida(_like[i]);
	for (unsigned int i = 0; ((i < _dislike.size())&(valida)); i++)
		valida &= stringaValida(_dislike[i]);

	//controllo che la data sia valida
	valida &= _data_pubblicazione.isValid();

	//controllo che chi abbia messo like ne abbia messo solo uno e nessun dislike
	for (unsigned int i = 0; ((i < _like.size())&(valida)); i++)
	{
		//controllo che non sia doppio come like
		for (unsigned int j = i + 1; ((j < _like.size())&(valida)); j++)
			if (_like[i] == _like[j])
				valida = false;
		//controllo che non abbia messo anche dislike
		valida &= !_idTrovato(_dislike, _like[i]);
	}

	//controllo che chi abbia messo dislike ne abbia messo solo uno e nessun like
	for (unsigned int i = 0; ((i < _dislike.size())&(valida)); i++)
	{
		//controllo che non sia doppio come dislike
		for (unsigned int j = i + 1; ((j < _dislike.size())&(valida)); j++)
			if (_dislike[i] == _dislike[j])
				valida = false;
		//controllo che non abbia messo anche like
		valida &= !_idTrovato(_like, _dislike[i]);
	}

	return valida;
}

bool Notizia::aggiungiLike(const string &id)
{
	return _aggiungiReazione(_like, id);
}

bool Notizia::aggiungiDislike(const string &id)
{
	return _aggiungiReazione(_dislike, id);
}

bool Notizia::rimuoviReazione(const string &id)
{
	bool rimossa = false;
	//se ha messo like lo rimuovo
	if (_idTrovato(_like, id))
	{
		_like.erase(_like.begin() + _trovaPosId(_like, id));
		rimossa = true;
	}
	//se non ha messo like
	else
		//controllo se abbia messo dislike
		if (_idTrovato(_dislike, id))
		{
			_dislike.erase(_dislike.begin() + _trovaPosId(_dislike, id));
			rimossa = true;
		}
	return rimossa;
}

string Notizia::stampaNotizia() const
{
	string output;

	//output=<id_mittente>,<messaggio>,like:{<id1>,...,<idn>},dislike:{<id1>,...,<idn>}

	//stampa id mittente
	output = _id_mittente + SEPARATORE;

	//stampa messaggio
	output += _messaggio + SEPARATORE;

	//stampa data
	output += _data_pubblicazione.stampaData() + SEPARATORE;

	//stampa like
	output += STR_LIKE;
	output += DIVISORE;
	output += PARENTESI_SX;
	for (unsigned int i = 0; i < _like.size(); i++)
	{
		output += _like[i];
		//se non è l'ultimo
		if (i < _like.size() - 1)
			output += SEPARATORE;
	}
	output += PARENTESI_DX;
	output += SEPARATORE;

	//stampa dislike
	output += STR_DISLIKE;
	output += DIVISORE;
	output += PARENTESI_SX;
	for (unsigned int i = 0; i < _dislike.size(); i++)
	{
		output += _dislike[i];
		//se non è l'ultimo
		if (i < _dislike.size() - 1)
			output += SEPARATORE;
	}
	output += PARENTESI_DX;

	return output;
}

string Notizia::stampaNotiziaEstesa() const
{
	string output;

	//stampa id mittente
	output = "Mittente Notizia : " + _id_mittente;

	//stampa messaggio
	output += "\nMessaggio : <<" + _messaggio + ">>";

	//stampa data
	output += "\nData di Pubblicazione : " + _data_pubblicazione.stampaData();

	//stampa like dislike
	output += "\nNumero di Like : " + to_string(_like.size());
	output += "\nNumero di Dislike : " + to_string(_dislike.size());

	return output;
}

ostream & operator<<(ostream &output, const Notizia &notizia_da_stampare)
{
	output << notizia_da_stampare.stampaNotizia();
	return output;
}

bool Notizia::_idTrovato(const vector<string> &dati, const string &id) const
{
	bool trovato = false;
	//cerco se c'è l'id nella reazione passata
	for (unsigned int i = 0; ((i < dati.size()) && (!trovato)); i++)
		if (dati[i] == id)
			trovato = true;
	return trovato;
}

unsigned int Notizia::_trovaPosId(const vector<string> &dati, const string &id) const
{
	//funzione usata sempre dopo il controllo _id_Trovato() per essere sicuro che sia presente e non restituire una posizione sbagliata
	unsigned int posizione = 0;
	//cerco posizione id nella reazione passata
	for (; ((posizione < dati.size()) && (dati[posizione] != id)); posizione++);
	return posizione;
}

bool Notizia::_aggiungiReazione(vector<string> &reazione, const string &id)
{
	bool like_espresso = _idTrovato(_like, id);
	bool dislike_espresso = _idTrovato(_dislike, id);
	bool ok = !(like_espresso || dislike_espresso);
	//se non ha già messo una reazione
	if (ok)
	{
		//aggiungo reazione
		reazione.push_back(id);
	}
	return ok;
}

bool Notizia::_carattereValido(const char & carattere) const
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
	//controllo che sia stampabile
	if (!isprint(carattere))
		ok = false;
	return ok;
}
