#pragma once

#include "Utente.h"

#define ID_TIPO_GRUPPO "utente_gruppo"

#define STR_SEDE_LEGALE "sede legale"
#define STR_TIPOLOGIA_ATTIVITA "tipologia attivita'"
#define STR_DATA_DI_CREAZIONE "data di creazione"

using namespace std;

class Utente_Gruppo :
	public Utente
{
public:

	//costruttori e distruttore
	Utente_Gruppo();
	Utente_Gruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const string &telefono, const string &email, const Data &data_creazione);
	~Utente_Gruppo();

	//metodi di set
	void set_Sede_Legale(const string &sede_legale);
	void set_Tipologia_Attività(const string &tipologia_attività);
	void set_Data_Creazione(const Data &data_creazione);

	//metodi di get
	string get_Sede_Legale() const;
	string get_Tipologia_Attività() const;
	Data get_Data_Creazione() const;

	//metodi della classe
	bool utente_Valido() const;

	//metodo di stampa
	string stampa_Utente() const;

private:

	//variabili private
	string _sede_legale;
	string _tipologia_attività;
	Data _data_creazione;
};