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

	string nome_file_utenti = "utenti.txt";
	string nome_file_notizie = "notizie.txt";
	string nome_file_relazioni = "relazioni.txt";
	
	//controllo argv argc...
	//prova apertura 3 file da riga di comando?

	//continuo solo se la lettura file non da errori
	if (leggiFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie))
	{
		for (bool esci = false, modifica = true; (!esci);)
		{
			cout << stampaDati(persona, impresa, associazione, news) << endl << endl;

			//menu + azione
			modifica = aggiungiReazioneNotizia(news, persona, impresa, associazione);

			//solo se c'è stata una modifica
			if (modifica)
			{
				//salvataggio
				aggiornaFile(persona, impresa, associazione, news, nome_file_utenti, nome_file_notizie);
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