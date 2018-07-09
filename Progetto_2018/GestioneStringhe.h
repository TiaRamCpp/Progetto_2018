#pragma once

//per formattare testo a sinistra
string stampaSinistra(unsigned int dimensione, string stringa) {
	unsigned int dimensione_stringa = stringa.size();;
	string stringa_stampa = stringa;

	for (unsigned int i = stringa.size(); i < dimensione; i++) {
		stringa_stampa.append(" ");
	}

	return stringa_stampa;
}
