#pragma once

#include <iostream>
#include <string>

#include "Data.h"

#define ID_VUOTO 0

using namespace std;

class Utente_Semplice
{
public:

	//costruttori e distruttore
	Utente_Semplice();
	Utente_Semplice(const int &id, const string &nome, const string &cognome, const string &domicilio, const Data &data_nascita);
	~Utente_Semplice();

	//metodi di set
	void set_Id(const int &id);
	void set_Nome(const string &nome);
	void set_Cognome(const string &cognome);
	void set_Domicilio(const string &domicilio);
	void set_Data_Nascita(const Data &data_nascita);

	//metodi di get
	int get_Id() const;
	string get_Nome() const;
	string get_Cognome() const;
	string get_Domicilio() const;
	Data get_Data_Nascita() const;

	//metodi della classe
	int calcola_Eta() const;

private:

	//variabili private
	int _id;
	string _nome;
	string _cognome;
	string _domicilio;
	Data _data_nascita;
};