#pragma once

#include "Utente.h"

#define STR_SEDE_FISCALE "sede fiscale"
#define STR_SEDE_OPERATIVA "sede operativa"
#define STR_TIPO_PRODOTTO "tipo prodotto"
#define STR_DATA_DI_CREAZIONE "data di creazione"

using namespace std;

class UtenteAzienda :
	public Utente
{
public:

	//costruttori e distruttore
	UtenteAzienda();
	UtenteAzienda(const string &id, const string &nome, const string &sede_fiscale, const string &sede_operativa, const string &tipo_prodotto, const string &telefono, const string &email, const Data &data_creazione);
	~UtenteAzienda();

	//metodi di set
	void setSedeFiscale(const string &sede_fiscale);
	void setSedeOperativa(const string &sede_operativa);
	void setTipoProdotto(const string &tipo_prodotto);
	void setDataCreazione(const Data &data_creazione);

	//metodi di get
	string getSedeFiscale() const;
	string getSedeOperativa() const;
	string getTipoProdotto() const;
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
	string _sede_fiscale;
	string _sede_operativa;
	string _tipo_prodotto;
	Data _data_creazione;
};