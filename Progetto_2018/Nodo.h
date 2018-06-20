#pragma once

#include <iostream>
#include <string>
#include <vector>

#define AMICO 1
#define CONOSCENTE 2
#define CONIUGE 3
#define FIGLIO 4
#define GENITORE 5
#define DIPENDENTE 6
#define CONSOCIATA 7
#define COLLABORAZIONE 8

using namespace std;

class Nodo
{
public:
	//costruttore
	Nodo(int id);	
	//distruttore
	~Nodo();	

	//modifico id nodo
	void modificaIdNodo(int id);  
	
	//rimuovo, modifico o aggiungo relazione del nodo con altri
	bool aggiungiRelazione(string id,int tipo_relazione);
	bool modificaRelazione(string id,int tipo_relazione);
	bool rimuoviRelazione(string id);

	//grado in e out
	int numeroRelazioni();

private:
	string _id;
	vector<string> _id_archi;
	vector<int> _tipologia_relazioni;
};

