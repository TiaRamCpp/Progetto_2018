#pragma once

#include "Utente.h"

#define STR_SEDE_LEGALE "sede legale"
#define STR_TIPOLOGIA_ATTIVITA "tipologia attivita'"
#define STR_DATA_DI_CREAZIONE "data di creazione"

using namespace std;

class UtenteGruppo :
	public Utente
{
public:

	//costruttori e distruttore
	UtenteGruppo();
	UtenteGruppo(const string &id, const string &nome, const string &sede_legale, const string &tipologia_attività, const string &telefono, const string &email, const Data &data_creazione);
	~UtenteGruppo();

	//metodi di set
	void setSedeLegale(const string &sede_legale);
	void setTipologiaAttività(const string &tipologia_attività);
	void setDataCreazione(const Data &data_creazione);

	//metodi di get
	string getSedeLegale() const;
	string getTipologiaAttività() const;
	Data getDataCreazione() const;

	//metodi della classe
	bool utenteValido() const;

	//metodi per le relazioni
	bool tipoRelazionePossibile(const string &tipo_relazione, const string &tipo_id) const;

	//metodo di stampa
	string stampaUtente() const;
	string stampaUtenteEstesa() const;

private:

	//variabili private
	string _sede_legale;
	string _tipologia_attività;
	Data _data_creazione;
};