#pragma once

//per formattare testo a sinistra
string stampaSinistra(unsigned int dimensione, string stringa) {
	int dimensione_stringa = stringa.size();;
	string stringa_stampa = stringa;

	for (int i = stringa.size(); i < dimensione; i++) {
		stringa_stampa.append(" ");
	}

	return stringa_stampa;
}
