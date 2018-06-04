#include "Notizia.h"

Notizia::Notizia()
{
	_id_mittente.clear();
	_messaggio.clear();
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

void Notizia::set_Id_Mittente(const string &id_mittente)
{
	_id_mittente = id_mittente;
}

void Notizia::set_Messaggio(const string &messaggio)
{
	_messaggio = messaggio;
}

void Notizia::set_Data_Pubblicazione(const Data &data_pubblicazione)
{
	_data_pubblicazione = data_pubblicazione;
}

void Notizia::set_Like(const vector<string> &like)
{
	_like = like;
}

void Notizia::set_Dislike(const vector<string> &dislike)
{
	_dislike = dislike;
}

string Notizia::get_Id_Mittente() const
{
	return _id_mittente;
}

string Notizia::get_Messaggio() const
{
	return _messaggio;
}

Data Notizia::get_Data_Pubblicazione() const
{
	return _data_pubblicazione;
}

vector<string> Notizia::get_Like() const
{
	return _like;
}

vector<string> Notizia::get_Dislike() const
{
	return _dislike;
}

bool Notizia::stringa_Valida(const string &stringa) const
{
	bool ok = true;
	//controllo che non ci sia uno dei caratteri non permessi
	for (unsigned int i = 0; ((i < stringa.size()) && (ok)); i++)
		if ((stringa[i] == NEW_LINE_CHARACTER) || (stringa[i] == NULL_TERMINATED_STRING) || (stringa[i] == SEPARATORE_DATA) || (stringa[i] == SEPARATORE) || (stringa[i] == DIVISORE) || (stringa[i] == PARENTESI_SX) || (stringa[i] == PARENTESI_DX))
			ok = false;
	return ok;
}

bool Notizia::notizia_Valida() const
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
	valida &= stringa_Valida(_id_mittente);
	valida &= stringa_Valida(_messaggio);
	for (unsigned int i = 0; ((i < _like.size())&(valida)); i++)
		valida &= stringa_Valida(_like[i]);
	for (unsigned int i = 0; ((i < _dislike.size())&(valida)); i++)
		valida &= stringa_Valida(_dislike[i]);

	//controllo che la data sia valida
	valida &= _data_pubblicazione.is_Valid();

	//controllo che chi abbia messo like ne abbia messo solo uno e nessun dislike
	for (unsigned int i = 0; ((i < _like.size())&(valida)); i++)
	{
		//controllo che non sia doppio come like
		for (unsigned int j = i + 1; ((j < _like.size())&(valida)); j++)
			if (_like[i] == _like[j])
				valida = false;
		//controllo che non abbia messo anche dislike
		if (valida)
			valida = _id_Trovato(_dislike, _like[i]);
	}

	//controllo che chi abbia messo dislike ne abbia messo solo uno e nessun like
	for (unsigned int i = 0; ((i < _dislike.size())&(valida)); i++)
	{
		//controllo che non sia doppio come dislike
		for (unsigned int j = i + 1; ((j < _dislike.size())&(valida)); j++)
			if (_dislike[i] == _dislike[j])
				valida = false;
		//controllo che non abbia messo anche like
		if (valida)
			valida = _id_Trovato(_like, _dislike[i]);
	}

	return valida;
}

bool Notizia::aggiungi_Like(const string &id)
{
	return _aggiungi_Reazione(_like, id);
}

bool Notizia::aggiungi_Dislike(const string &id)
{
	return _aggiungi_Reazione(_dislike, id);
}

bool Notizia::rimuovi_Reazione(const string &id)
{
	bool like_espresso = _id_Trovato(_like, id);
	bool dislike_espresso = _id_Trovato(_dislike, id);
	bool rimossa = like_espresso || dislike_espresso;
	//se ha messo like lo rimuovo
	if (like_espresso)
	{
		_like.erase(_like.begin() + _trova_Pos_Id(_like, id));
		cout << "Like rimosso" << endl;
	}
	//se ha messo dislike lo rimuovo
	if (dislike_espresso)
	{
		_dislike.erase(_dislike.begin() + _trova_Pos_Id(_dislike, id));
		cout << "Dislike rimosso" << endl;
	}
	//se non ha messo nessuna reazione
	if (!rimossa)
		cout << "L'ID = " << id << " non ha messo nessuna reazione a questa notizia" << endl;
	return rimossa;
}

string Notizia::stampa_Notizia() const
{
	string output;

	//output=<id_mittente>,<messaggio>,like:{<id1>,...,<idn>},dislike:{<id1>,...,<idn>}

	//stampa id mittente
	output = _id_mittente + SEPARATORE;

	//stampa messaggio
	output += _messaggio + SEPARATORE;

	//stampa data
	output += _data_pubblicazione.stampa_Data() + SEPARATORE;

	//stampa like
	output += "like" + DIVISORE;
	output += PARENTESI_SX;
	for (unsigned int i = 0; i < _like.size(); i++)
	{
		output += _like[i];
		//se non è l'ultimo
		if (i < _like.size() - 1)
			output += SEPARATORE;
	}
	output += PARENTESI_DX;

	//stampa dislike
	output += SEPARATORE + "dislike" + DIVISORE;
	output += PARENTESI_SX;
	for (unsigned int i = 0; i < _dislike.size(); i++)
	{
		output += _dislike[i];
		//se non è l'ultimo
		if (i < _dislike.size() - 1)
			output += SEPARATORE;
	}
	output += DIVISORE;

	return output;
}

ostream & operator<<(ostream &output, const Notizia &notizia_da_stampare)
{
	output << notizia_da_stampare.stampa_Notizia();
	return output;
}

bool Notizia::_id_Trovato(const vector<string> &dati, const string &id) const
{
	bool trovato = false;
	//cerco se c'è l'id nella reazione passata
	for (unsigned int i = 0; ((i < dati.size()) && (!trovato)); i++)
		if (dati[i] == id)
			trovato = true;
	return trovato;
}

int Notizia::_trova_Pos_Id(const vector<string> &dati, const string &id) const
{
	//funzione usata sempre dopo il controllo _id_Trovato() per essere sicuro che sia presente e non restituire una posizione sbagliata
	unsigned int posizione = 0;
	//cerco posizione id nella reazione passata
	for (; ((posizione < dati.size()) && (dati[posizione] != id)); posizione++);
	return posizione;
}

bool Notizia::_aggiungi_Reazione(vector<string> &reazione, const string &id)
{
	bool like_espresso = _id_Trovato(_like, id);
	bool dislike_espresso = _id_Trovato(_dislike, id);
	bool ok = !(like_espresso || dislike_espresso);
	string tipo_reazione;
	//se non ha già messo una reazione
	if (ok)
	{
		//identificazione reazione da aggiungere
		if (reazione == _dislike)
			tipo_reazione = "Dislike";
		else
			tipo_reazione = "Like";
		//aggiungo reazione
		reazione.push_back(id);
		//stampa aggiunta reazione
		cout << tipo_reazione << " aggiunto" << endl;
	}
	//se l'ha già messa
	else
	{
		//identificazione reazione già espressa
		if (dislike_espresso)
			tipo_reazione = "dislike";
		else
			tipo_reazione = "like";
		//stampa tipo errore già espresso
		cout << "L'ID = " << id << " ha gia' messo " << tipo_reazione << " a questa notizia" << endl;
	}
	return ok;
}