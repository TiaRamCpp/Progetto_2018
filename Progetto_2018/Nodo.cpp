#include "Nodo.h"

using namespace std;

Nodo::Nodo()
{
	_id.clear();
	_tipo_nodo.clear();
	_id_arco.clear();
	_tipologia_relazione.clear();
}

Nodo::Nodo(const string &id, const string &tipo_nodo)
{
	//imposto id nodo e inizializzo vettori per relazioni e relative tipologie
	_id = id;
	_tipo_nodo = tipo_nodo;
	_id_arco.clear();
	_tipologia_relazione.clear();
}

Nodo::~Nodo()
{
}

void Nodo::setIdNodo(const string &id)
{
	_id = id;
}

void Nodo::setTipoNodo(const string &tipo_nodo)
{
	_tipo_nodo = tipo_nodo;
}

string Nodo::getIdNodo() const
{
	return _id;
}

string Nodo::getTipoNodo() const
{
	return _tipo_nodo;
}

vector<string> Nodo::getIdArco() const
{
	return _id_arco;
}

vector<string> Nodo::getTipoRelazione() const
{
	return _tipologia_relazione;
}

bool Nodo::aggiungiRelazione(const string &id, const string &tipo_relazione)
{
	bool aggiunta = false;
	unsigned int posizione;

	//se non trovo la relazione
	if (!trovaPosizioneRelazione(id, tipo_relazione, posizione))
	{
		//allora verifico che sia un tipo di relazione esistente
		if (tipoRelazioneEsistente(tipo_relazione))
		{
			//la aggiungo
			_id_arco.push_back(id);
			_tipologia_relazione.push_back(tipo_relazione);
			aggiunta = true;
		}
	}

	return aggiunta;
}

bool Nodo::modificaRelazione(const string &id, const string &nuovo_tipo_relazione, const string &vecchio_tipo_relazione)
{
	bool modificata = false;
	unsigned int posizione;

	//se trovo la relazione
	if (trovaPosizioneRelazione(id, vecchio_tipo_relazione, posizione))
	{
		//allora verifico che sia un tipo di relazione esistente
		if (tipoRelazioneEsistente(nuovo_tipo_relazione))
		{
			//la modifico
			_tipologia_relazione[posizione] = nuovo_tipo_relazione;
			modificata = true;
		}
	}

	return modificata;
}

bool Nodo::rimuoviRelazione(const string &id, const string &tipo_relazione)
{
	bool eliminata = false;
	unsigned int posizione;

	//se trovo la relazione
	if (trovaPosizioneRelazione(id, tipo_relazione, posizione))
	{
		//la elimino
		_id_arco.erase(_id_arco.begin() + posizione);
		_tipologia_relazione.erase(_tipologia_relazione.begin() + posizione);
		eliminata = true;
	}

	return eliminata;
}

unsigned int Nodo::numeroRelazioni() const
{
	//numero di archi con altri nodi
	return _id_arco.size();
}

bool Nodo::tipoRelazioneEsistente(const string &tipo_relazione) const
{
	bool esistente = false;
	//se è una delle relazioni possibili
	if ((tipo_relazione == STR_AMICO) || (tipo_relazione == STR_CONOSCENTE) || (tipo_relazione == STR_CONIUGE) || (tipo_relazione == STR_FIGLIO) || (tipo_relazione == STR_GENITORE) || (tipo_relazione == STR_DIPENDENTE) || (tipo_relazione == STR_CONSOCIATA) || (tipo_relazione == STR_COLLABORAZIONE))
		esistente = true;
	return esistente;
}

bool Nodo::trovaPosizioneRelazione(const string &id, const string &tipo_relazione, unsigned int &posizione) const
{
	bool trovata = false;
	posizione = 0;
	//cerco se esiste
	for (unsigned int i = 0; ((i < _id_arco.size()) && (!trovata)); i++)
	{
		//se la trova
		if ((_id_arco[i] == id) && (_tipologia_relazione[i] == tipo_relazione))
		{
			//salvo la posizione
			posizione = i;
			trovata = true;
		}
	}
	return trovata;
}

string Nodo::stampaNodo() const
{
	string stampa;
	for (unsigned int i = 0; i < _id_arco.size(); i++)
	{
		//se non è il primo
		if (i != 0)
			stampa += '\n';
		stampa += _id + SEPARATORE + _id_arco[i] + SEPARATORE + _tipologia_relazione[i];
	}
	return stampa;
}

ostream & operator<<(ostream &output, const Nodo &da_stampare)
{
	output << da_stampare.stampaNodo();
	return output;
}
