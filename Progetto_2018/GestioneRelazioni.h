#pragma once

#include "Nodo.h"

string stampaRelazioni(const vector<Nodo> &vertice)
{
	string output;
	for (unsigned int i = 0; i < vertice.size(); i++)
	{
		//se non è la prima riga
		if (i != 0)
			output += '\n';
		output += vertice[i].stampaNodo();
	}
	return output;
}

bool trovaPosizioneNodo(const vector<Nodo> &vertice, const string &id, unsigned int &posizione)
{
	bool trovato = false;
	posizione = 0;
	//cerco se esiste
	for (unsigned int i = 0; ((i < vertice.size()) && (!trovato)); i++)
	{
		//se lo trovo
		if (vertice[i].getIdNodo() == id)
		{
			//salvo la posizione
			posizione = i;
			trovato = true;
		}
	}	
	return trovato;
}