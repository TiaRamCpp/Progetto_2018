#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#define SEPARATORE_DATA '/'

#pragma warning(disable : 4996)

using namespace std;

class Data
{
public:

	//costruttori e distruttor
	Data();
	Data(const int &giorno, const int &mese, const int &anno);
	Data(const Data &da_copiare);	// Copy Constructor
	~Data();

	//metodi di get
	int get_Anno() const;
	int get_Mese() const;
	int get_Giorno() const;

	//metodi della classe
	string stampa_Data() const;
	int get_Anni_Da(const Data &data_input = Data()) const;
	bool is_Valid() const;

	//operatori della classe
	friend ostream & operator<<(ostream &output, const Data &da_stampare);	// overload of the << operator for the Data class. ---- the fried keyword is mandatory to define the overload.
	bool operator<(const Data &data_destra) const;
	void operator=(const Data &da_assegnare);

private:

	//metodi privati
	int _calcola_Numero_Giorno() const;

	//variabili private
	int _anno;
	int _mese;
	int _giorno;
};