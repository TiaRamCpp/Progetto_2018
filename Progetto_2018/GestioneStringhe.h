#pragma once

#include <iomanip>

//per formattare testo a sinistra
string stampaSinistra(const unsigned int &dimensione, const string &stringa) 
{
	string output;
	for (unsigned int i = 0; i < dimensione; i++) 
	{
		if (i < stringa.size())
			output += stringa[i];
		//se non ci sono più caratteri da stampare
		else
			output += ' ';
	}
	return output;
}

//CONVERSIONE STR A NUMERO

bool convertiANumero(const string &str_numero, unsigned int &numero)
{
	//converte la stringa a un numero ma per sicurezza verifica che siano presenti solo cifre per evitare errori di conversione tramite stoi()

	bool convertita = false;
	bool solo_cifre = true;

	//controllo che ci siano solo cifre
	for (unsigned int i = 0; ((i < str_numero.size()) && (solo_cifre)); i++)
		//se non è una cifra
		if (!isdigit(str_numero[i]))
			solo_cifre = false;

	//se c'erano solo cifre
	if (solo_cifre)
	{
		//conversione da stringa a numero
		numero = stoi(str_numero);
		convertita = true;
	}
	//caratteri non validi
	else
	{
		cout << endl << "Errore : inserisci solo cifre" << endl;
	}

	return convertita;
}
bool convertiANumero(const string &str_numero, double &numero)
{
	//converte la stringa a un numero ma per sicurezza verifica che siano presenti solo cifre o un punto per evitare errori di conversione tramite stod()

	bool convertita = false;
	bool ok = true;
	char virgola = '.';
	unsigned int numero_virgole = 0;

	//controllo che ci siano solo cifre o un punto
	for (unsigned int i = 0; ((i < str_numero.size()) && (ok)); i++)
	{
		//se non è una cifra
		if (!isdigit(str_numero[i]))
		{
			//se è una virgola
			if (str_numero[i] == virgola)
			{
				numero_virgole++;
				//se ci sono troppe virgole
				if (numero_virgole > 1)
				{
					ok = false;
				}
			}
			//se non è una virgola
			else
			{
				ok = false;
			}
		}
	}

	//se si può convertire
	if (ok)
	{
		//conversione da stringa a numero
		numero = stod(str_numero);
		convertita = true;
	}
	//caratteri non validi
	else
	{
		cout << endl << "Errore : inserisci solo numeri positivi eventualmente con la virgola" << endl;
	}

	return convertita;
}
