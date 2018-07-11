// Progetto_2018.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "GestioneFile.h"
#include "MenuProgetto.h"

int main(int argc, char**argv)
{
	bool esci = false;
	bool modifica;

	vector<UtenteSemplice> persona;
	vector<UtenteAzienda> impresa;
	vector<UtenteGruppo> associazione;
	vector<Notizia> news;

	string nome_file_utenti = "utenti.txt";
	string nome_file_notizie = "notizie.txt";
	string nome_file_relazioni = "relazioni.txt";
	
	if (argc == 4)
	{
		nome_file_utenti = argv[1];
		nome_file_relazioni = argv[2];
		nome_file_notizie = argv[3];
	}
	else
	{
		cout << "Numero di parametri riga di comando errato" << endl;
	}

	//continuo solo se la lettura file non da errori
	if (leggiFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie, nome_file_relazioni))
	{
		do
		{
			//menu + azione
			modifica = sceltaMenuPrincipale(esci, persona, impresa, associazione, news);
			//solo se c'è stata una modifica
			if (modifica)
			{
				//salvataggio
				aggiornaFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie, nome_file_relazioni);
			}
		} while (!esci);
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
	return EXIT_SUCCESS;
}