#include "Nodo.h"

using namespace std;

Nodo::Nodo(int id)
{
	//imposto id nodo e inizializzo vettori per relazioni e relative tipologie
	_id = id;
	_id_archi.clear();
	_tipologia_relazioni.clear();
}

Nodo::~Nodo()
{
}

void Nodo::modificaIdNodo(int id)
{
	_id = id;
}

bool Nodo::aggiungiRelazione(string id, int tipo_relazione)
{
	bool esistente = false;
	unsigned int i = 0;

	//controllo che relazione non sia già esistente
	for (; (i < _id_archi.size()) && (!esistente); i++)
	{
		if (id == _id_archi[i])
		{
			esistente = true;
		}
	}

	//se non esistente lo aggiungo
	if (!esistente)
	{
		_id_archi.push_back(id);
		_tipologia_relazioni.push_back(tipo_relazione);
	}

	return !esistente;
}

bool Nodo::modificaRelazione(string id, int tipo_relazione)
{
	bool esistente = false;
	unsigned int i = 0;

	//controllo che relazione cercata sia esistente
	for (; (i < _id_archi.size()) && (!esistente); i++)
	{
		if (id == _id_archi[i])
		{
			esistente = true;
		}
	}

	//se esistente allora la modifico
	if (esistente) 
	{
		_tipologia_relazioni[i] = tipo_relazione;
	}

	return esistente;
}

bool Nodo::rimuoviRelazione(string id)
{
	bool esistente = false;
	unsigned int i = 0;

	//controllo che relazione sia esistente
	for (; (i < _id_archi.size())&&(!esistente); i++) 
	{
		if (id == _id_archi[i]) 
		{
			esistente = true;
		}
	}

	//se esistente elimino id e relativa relazione
	if(esistente)
	{
		_id_archi.erase(_id_archi.begin()+i+1);
		_tipologia_relazioni.erase(_tipologia_relazioni.begin() + i+1);
	}
	
	return esistente;
}

int Nodo::numeroRelazioni()
{
	//numero di archi con altri nodi
	return _id_archi.size();
}

