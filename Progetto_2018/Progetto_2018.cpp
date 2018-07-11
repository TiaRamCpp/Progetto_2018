// Progetto_2018.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "GestioneFile.h"
#include "MenuProgetto.h"

int main(int argc, char**argv)
{
	vector<UtenteSemplice> persona;
	vector<UtenteAzienda> impresa;
	vector<UtenteGruppo> associazione;
	vector<Notizia> news;

	string nome_file_utenti;  //utenti.txt
	string nome_file_relazioni;  //relazioni.txt
	string nome_file_notizie; //notizie.txt
	
	if (argc != 4) 
	{
		cout << "Numero di parametri riga di comando errato" << endl;
		return 1;
	}
	
		
	if(argv[1]!=NULL)
	{
		nome_file_utenti = argv[1];
	}
	if (argv[2] != NULL)
	{
		nome_file_relazioni = argv[2];
	}
	if (argv[3] != NULL)
	{
		nome_file_notizie = argv[3];
	}
	//continuo solo se la lettura file non da errori
	if (leggiFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie, nome_file_relazioni))
	{
		for (bool esci = false, modifica; (!esci);)
		{
			//menu + azione
			modifica = sceltaMenuPrincipale(esci, persona, impresa, associazione, news);
			//solo se c'è stata una modifica
			if (modifica)
			{
				//salvataggio
				aggiornaFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie, nome_file_relazioni);
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
	return EXIT_SUCCESS;
}