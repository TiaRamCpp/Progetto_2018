// Progetto_2018.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "GestioneFile.h"
#include "MenuProgetto.h"

int main()
{
	vector<UtenteSemplice> persona;
	vector<UtenteAzienda> impresa;
	vector<UtenteGruppo> associazione;
	vector<Notizia> news;
	vector<Nodo> vertice;

	string nome_file_utenti = "utenti.txt";
	string nome_file_notizie = "notizie.txt";
	string nome_file_relazioni = "relazioni.txt";
	
	//controllo argv argc...
	//prova apertura 3 file da riga di comando?
	
	//continuo solo se la lettura file non da errori
	if (leggiFile(persona, impresa, associazione, news, vertice, nome_file_utenti, nome_file_notizie, nome_file_relazioni))
	{
		for (bool esci = false, modifica; (!esci);)
		{
			cout << stampaDati(persona, impresa, associazione, news, vertice) << endl << endl;

			//menu + azione
			modifica = sceltaMenuPrincipale(esci,persona,impresa,associazione,news);

			//solo se c'è stata una modifica
			if (modifica)
			{
				//salvataggio
				aggiornaFile(persona, impresa, associazione, news, vertice, nome_file_utenti, nome_file_notizie, nome_file_relazioni);
			}
		}
	}
	//errore lettura file
	else
	{
		cerr << endl << "Errore : Lettura file errata o non corretta" << endl;
		cerr << endl << "Premere un tasto per terminare : ";
		getchar();
	}

	persona.clear();
	impresa.clear();
	associazione.clear();
	news.clear();
	vertice.clear();
	return EXIT_SUCCESS;
}