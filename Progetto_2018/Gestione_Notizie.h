#pragma once

#include "Notizia.h"

//stampa
string stampa_notizie(const vector<Notizia> &news)
{
	string output;
	output.clear();
	for (unsigned int i = 0; i < news.size(); i++)
	{
		output += news[i].stampa_Notizia();
		//se non è l'ultima riga
		if (i < news.size() - 1)
			output += '\n';
	}
	return output;
}

bool rimuovi_notizia(vector<Notizia> &news)
{
	bool modifica = false;
	//stampa notizie
	cout << stampa_notizie(news) << endl;
	//seleziona notizia da rimuovere + esci ()
	news.erase(news.begin());
	//rimuovo notizia corrispondente
	return modifica;
}

