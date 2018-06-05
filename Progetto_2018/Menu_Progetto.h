#pragma once

#include <iostream>
#include <string>

using namespace std;

void menu_tipologia_utenti() {
	char u;

	cout << "S) Aggiungi Utente" << endl;
	cout << "A) Rimuovi Utente" << endl;
	cout << "G) Modifica Utente" << endl;
	cout << "P) Torna al Menu Precedente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> u;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(u))
	{
		toupper(u);
	}


	switch (u)
	{
	case 'S':
	{

	}
	break;
	case 'A':
	{

	}
	break;
	case 'G':
	{

	}
	break;
	case 'P':
	{
		menu_gestione_utenti();
	}
	break;
	case 'E':
	{
		menu_principale();
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
}

void menu_gestione_utenti() {

	char a;

	cout << "A) Aggiungi Utente" << endl;
	cout << "R) Rimuovi Utente" << endl;
	cout << "M) Modifica Utente" << endl;
	cout << "E) Torna al Menu Principale" << endl;
	cout << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> a;
	cout << endl;

	//controllo se lettera e converto in maiuscolo
	if (isalpha(a))
	{
		toupper(a);
	}

	
		switch (a)
		{
		case 'A':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'R':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'M':
		{
			menu_tipologia_utenti();
		}
		break;
		case 'E':
		{
			menu_principale();
		}
		break;
		default:
		{
			cout << "Opzione non valida" << endl;
		}
		break;
		}
	

}

void menu_principale() {
	char m;
	bool esci = false;

	while (esci==false) {
		//stampo voci menu
		cout << "1) Gestione Utenti" << endl;
		cout << "2) Gestione Relazioni" << endl;
		cout << "3) Gestione Notizie" << endl;
		cout << "4) Statistiche" << endl;
		cout << "5) Ricerche" << endl;
		cout << "6) Esci" << endl;
		cout << endl;
		cout << "Selezionare una voce del menu: ";
		cin >> m;
		cout << endl;

		//controllo ed eseguo operazione scelta
		switch (m) {
		case '1':
		{
			menu_gestione_utenti();
		}
		break;
		case '2':
		{

		}
		break;
		case '3':
		{

		}
		break;
		case '4':
		{

		}
		break;
		case '5':
		{

		}
		break;
		case '6':
		{
			esci = true;
		}
		break;
		default:
		{
			cout << "Opzione non valida" << endl;
			cout << endl;
		}
		break;
		}
	}

}

//menu di prova poi elimina pure

void menu_primo()
{
	bool torna_al_menu_precedente = false;
	char a;
	cout << " 2) menu secondo" << endl;
	cout << " 3) menu blabla" << endl;
	cout << " 4) menu sbdiabdasb" << endl;
	cout << " E) esci" << endl;
	//nessun menu principale o precedente come opzione perchè è l'inizio
	cout << "Selezionare una voce del menu: ";
	cin >> a;
	//controllo se lettera e converto in maiuscolo
	if (isalpha(a))
	{
		toupper(a);
	}
	switch (a)
	{
	case '2':
	{
		menu_secondo(torna_al_menu_precedente);
	}
	break;
	case '3':
	{
		//opzione 3
	}
	break;
	case '4':
	{
		//opzione 4
	}
	break;
	case 'E':
	{
		//vuoto per uscire e non fare nulla
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	if (torna_al_menu_precedente)
		menu_primo();
}

void menu_secondo(bool &torna_al_menu_precedente)
{
	torna_al_menu_precedente = false;
	char a;
	cout << " 1) menu terzo" << endl;
	cout << " 2) menu pippo" << endl;
	cout << " 3) menu pluto" << endl;
	cout << " 4) menu principale " << endl;
	//nessun menu precedente tanto il menu principale è già il menu principale oppure li mettiamo tutti e due ma rimanderebbero tutti e due a menu_primo()
	cout << "Selezionare una voce del menu: ";
	cin >> a;
	//controllo se lettera e converto in maiuscolo
	if (isalpha(a))
	{
		toupper(a);
	}
	switch (a)
	{
	case '1':
	{
		menu_terzo(torna_al_menu_precedente);
	}
	break;
	case '2':
	{
		//opz 2
		//menu_quarto(torna_al_menu_precedente);
	}
	break;
	case '3':
	{
		//opzione 3
	}
	break;
	case '4':
	{
		//menu principale
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
	if(torna_al_menu_precedente)
		menu_secondo()
}

void menu_terzo(bool &torna_al_menu_precedente)
{
	torna_al_menu_precedente = false;
	char a;
	cout << " 1) menu minni" << endl;
	cout << " 2) menu pippo" << endl;
	cout << " 3) menu pluto" << endl;
	cout << " 4) menu principale " << endl;
	cout << " 5) menu precedente " << endl;
	cout << "Selezionare una voce del menu: ";
	cin >> a;
	//controllo se lettera e converto in maiuscolo
	if (isalpha(a))
	{
		toupper(a);
	}
	switch (a)
	{
	case '1':
	{
		//opz1
	}
	break;
	case '2':
	{
		//opz 2
	}
	break;
	case '3':
	{
		//opzione 3
	}
	break;
	case '4':
	{
		//menu principale
	}
	break; 
	case '5':
	{
		//menu precedente
		torna_al_menu_precedente = true;
	}
	break;
	default:
	{
		cout << "Opzione non valida" << endl;
	}
	break;
	}
}