#pragma once

#include "Utente.h"

#define ID_TIPO_AZIENDA "utente_azienda"

#define STR_SEDE_FISCALE "sede fiscale"
#define STR_SEDE_OPERATIVA "sede operativa"
#define STR_TIPO_PRODOTTO "tipo prodotto"
#define STR_DATA_DI_CREAZIONE "data di creazione"

using namespace std;

class Utente_Azienda :
	public Utente
{
public:

	//costruttori e distruttore
	Utente_Azienda();
	Utente_Azienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const string &telefono, const string &email, const Data &data_creazione);
	~Utente_Azienda();

	//metodi di set
	void set_Sede_Fiscale(const string &sede_fiscale);
	void set_Sede_Operativa(const string &sede_operativa);
	void set_Tipo_Prodotto(const string &tipo_prodotto);
	void set_Data_Creazione(const Data &data_creazione);

	//metodi di get
	string get_Sede_Fiscale() const;
	string get_Sede_Operativa() const;
	string get_Tipo_Prodotto() const;
	Data get_Data_Creazione() const;

	//metodi della classe
	bool utente_Valido() const;

	//metodi di stampa
	string stampa_Utente_Azienda() const;
	friend ostream & operator<<(ostream &output, const Utente_Azienda &da_stampare);

private:

	//variabili private
	string _sede_fiscale;
	string _sede_operativa;
	string _tipo_prodotto;
	Data _data_creazione;
};
