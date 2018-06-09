// prog18.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "Gestione_File.h"
#include "Gestione_Utenti.h"
#include "Gestione_Notizie.h"

#include "Menu_Progetto.h"

int main()
{

	vector<Utente_Semplice> persona;
	vector<Utente_Azienda> impresa;
	vector<Utente_Gruppo> associazione;
	vector<Notizia> news;

	string nome_file_utenti = "utenti.txt";
	string nome_file_notizie = "notizie.txt";
	string nome_file_relazioni = "relazioni.txt";

	
	//controllo argv argc...
	//prova apertura 3 file da riga di comando?

	for (bool errore = false, esci = false, modifica = true; (!errore) && (!esci);)
	{
		//solo se c'è stata una modifica
		if (modifica) 
		{
			//caricamento file
			errore = !leggi_file(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie);
		}
		//continuo solo se la lettura file non da errori
		if (!errore)
		{
			cout << stampa_dati(persona, impresa, associazione, news) << endl << endl;

			//menu + azione
			modifica = menu_principale(esci);

			//solo se c'è stata una modifica
			if (modifica) 
			{
				//salvataggio
				aggiorna_file(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie);
			}
		}
	}

	persona.clear();
	impresa.clear();
	associazione.clear();
	news.clear();
	getchar();
	return 0;
}