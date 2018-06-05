// prog18.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "Progetto_2018.h"
#include "Menu_Progetto.h"

int main()
{
	menu_principale();

	
	vector<Utente_Semplice> persona;
	vector<Utente_Azienda> impresa;
	vector<Utente_Gruppo> associazione;
	vector<Notizia> news;

	bool esci = false;
	string nome_file_utenti = "utenti.txt";
	string nome_file_notizie = "notizie.txt";
	string nome_file_relazioni = "relazioni.txt";

	//persona.push_back(Utente_Semplice("119", "pippo", "baudo", "roma via lazio 10", Data(20, 10, 1950)));
	//impresa.push_back(Utente_Azienda("2009", "apple", "torino via roma 1","milano piazza vittorio 2","telefoni",Data(10, 12, 1970)));
	//associazione.push_back(Utente_Gruppo("1996", "airc", "candiolo strada vinoco 110","ricerca cancro",Data(5, 8, 1987)));
	//vector<int> like{ 1,2,3 };
	//vector<int> dislike{ 4,5,6 };
	//news.push_back(Notizia(119, "zidane lascia il real", like, dislike, Data(31, 5, 2018)));


	leggi_file(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie);

	cout << stampa_dati(persona, impresa, associazione, news) << endl << endl;

	//aggiorna_file(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie);

	//controllo argv argc...
	//prova apertura 3 file da riga di comando?

	while (!esci)
	{
		//carica da file
		//continua solo se nessun errore dai file

		//if file validi
		//menu + azione + salvataggio

		//else 
		//esci
		esci = true;
	}

	persona.clear();
	impresa.clear();
	associazione.clear();
	news.clear();
	getchar();
	return 0;
}

//stampa data pubblicazione notizia