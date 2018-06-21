#pragma once

#include <iostream>
#include <string>
#include <vector>

#define STR_AMICO "amico"
#define STR_CONOSCENTE "conoscente"
#define STR_CONIUGE "coniuge"
#define STR_FIGLIO "figlio"
#define STR_GENITORE "genitore"
#define STR_DIPENDENTE "dipendente"
#define STR_CONSOCIATA "consociata"
#define STR_COLLABORAZIONE "collaborazione"

#define SEPARATORE ','

using namespace std;

class Nodo
{
public:
	//costruttori
	Nodo();
	Nodo(const string &id, const string &tipo_nodo);	
	//distruttore
	~Nodo();	

	//modifico di set
	void setIdNodo(const string &id);
	void setTipoNodo(const string &tipo_nodo);

	//metodi di get
	string getIdNodo() const;
	string getTipoNodo() const;
	vector<string> getIdArco() const;
	vector<string> getTipoRelazione() const;
	
	//rimuovo, modifico o aggiungo relazione del nodo con altri
	bool aggiungiRelazione(const string &id, const string &tipo_relazione);
	bool modificaRelazione(const string &id, const string &nuovo_tipo_relazione, const string &vecchio_tipo_relazione);
	bool rimuoviRelazione(const string &id, const string &tipo_relazione);

	//metodi della classe
	unsigned int numeroRelazioni() const;
	bool tipoRelazioneEsistente(const string &tipo_relazione) const;
	bool trovaPosizioneRelazione(const string &id, const string &tipo_relazione, unsigned int &posizione) const;

	//metodi di stampa
	string stampaNodo() const;
	friend ostream & operator<<(ostream &output, const Nodo &da_stampare);

private:
	string _id;
	string _tipo_nodo;
	vector<string> _id_arco;
	vector<string> _tipologia_relazione;
};

