#include "Data.h"

Data::Data()
{
	time_t tempo;
	time(&tempo);
	struct tm* tempoLoc = localtime(&tempo);

	_giorno = tempoLoc->tm_mday;
	_mese = tempoLoc->tm_mon + 1;
	_anno = tempoLoc->tm_year + 1900;

}

Data::Data(const int &giorno, const int &mese, const int &anno)
{
	_giorno = giorno;
	_mese = mese;
	_anno = anno;
}

Data::Data(const Data &da_copiare)
{
	_giorno = da_copiare._giorno;
	_mese = da_copiare._mese;
	_anno = da_copiare._anno;
}

Data::~Data()
{
}

string Data::stampaData() const
{
	string output;
	output = to_string(_giorno) + SEPARATORE_DATA + to_string(_mese) + SEPARATORE_DATA + to_string(_anno);
	return output;
}

int Data::getAnniDa(const Data &data_input) const
{
	if (_calcolaNumeroGiorno() > data_input._calcolaNumeroGiorno()) //se non ha compiuto gli anni tolgo un anno
		return data_input._anno - _anno - 1;
	return data_input._anno - _anno;
}

bool Data::isValid() const
{
	bool valido = true;
	if ((_mese < 1) || (_mese > 12) || (_giorno < 1))
	{
		valido = false;
	}
	else
	{
		switch (_mese)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (_giorno > 31)
			{
				valido = false;
			}
		}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (_giorno > 30)
			{
				valido = false;
			}
		}
		break;
		case 2:
		{
			if (_giorno > 28)
			{
				valido = false;
			}
		}
		break;
		}
	}
	return valido;
}

bool Data::convertiStringaAData(const string &data)
{
	//legge e controlla gg/mm/aaaa o g/mm/aaaa o gg/m/aaaa

	bool ok = false;
	bool stop = false;
	unsigned int posizione = 0;
	string giorno;
	string mese;
	string anno;
	giorno.clear();
	mese.clear();
	anno.clear();
	//leggo giorno
	for (; ((posizione < data.size()) && (!stop)); posizione++)
	{
		if (isdigit(data[posizione]))
			giorno += data[posizione];
		else
			stop = true;
	}
	if (data.size() != 0)
	{
		//controllo che il carattere dopo sia '/'
		if (data[posizione - 1] == SEPARATORE_DATA)
		{
			//leggo il mese
			for (stop = false; ((posizione < data.size()) && (!stop)); posizione++)
			{
				if (isdigit(data[posizione]))
					mese += data[posizione];
				else
					stop = true;
			}
			//controllo che il carattere dopo sia '/'
			if (data[posizione - 1] == SEPARATORE_DATA)
			{
				//leggo l'anno
				for (stop = false; ((posizione < data.size()) && (!stop)); posizione++)
				{
					if (isdigit(data[posizione]))
						anno += data[posizione];
					else
						stop = true;
				}
				//controllo che quello che ho letto sia la data passata e che quindi non ci siano caratteri dopo l'anno
				if ((giorno + SEPARATORE_DATA + mese + SEPARATORE_DATA + anno) == data)
				{
					//assegno valori a data_letta
					_giorno = stoi(giorno);
					_mese = stoi(mese);
					_anno = stoi(anno);
					//la funzione stoi trasforma la stringa in un numero intero

					//se la data è valida
					if (isValid())
					{
						ok = true;
					}
				}
			}
		}
	}
	return ok;
}

int Data::_calcolaNumeroGiorno() const
{
	int giorni_nel_mese[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int numero_giorno = _giorno;
	for (int i = 1; i < _mese; i++)
	{
		numero_giorno += giorni_nel_mese[i];
	}
	return numero_giorno;
}

int Data::getAnno() const
{
	return _anno;
}

int Data::getMese() const
{
	return _mese;
}

int Data::getGiorno() const
{
	return _giorno;
}

bool Data::operator<(const Data &data_destra) const
{
	//data_sx < data_dx true se data_sx più nel passato rispetto a data_dx

	//controllo se differiscono di anno/i
	if (this->_anno < data_destra._anno)
		return true;
	if (this->_anno > data_destra._anno)
		return false;
	//altrimenti controllo se differiscono per mese/i
	if (this->_mese < data_destra._mese)
		return true;
	if (this->_mese > data_destra._mese)
		return false;
	//altrimenti controllo se differiscono per giorno/i
	if (this->_giorno < data_destra._giorno)
		return true;
	return false;
}

void Data::operator=(const Data &da_assegnare)
{
	this->_anno = da_assegnare._anno;
	this->_mese = da_assegnare._mese;
	this->_giorno = da_assegnare._giorno;
}

ostream & operator<<(ostream &output, const Data &da_stampare)
{
	output << da_stampare.stampaData();
	return output;
}
