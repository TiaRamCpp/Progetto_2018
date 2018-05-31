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
	if (!_is_Valid()) {
		cerr << "Data non valida" << endl;
		getchar();
		getchar();
		exit(EXIT_FAILURE);
	}
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

string Data::stampa_Data() const
{
	string output;
	output = to_string(_giorno) + "/" + to_string(_mese) + "/" + to_string(_anno);
	return output;
}

int Data::get_Anni_Da(const Data &data_input) const
{
	if (_calcola_Numero_Giorno() > data_input._calcola_Numero_Giorno()) //se non ha compiuto gli anni tolgo un anno
		return data_input._anno - _anno - 1;
	return data_input._anno - _anno;
}

int Data::_calcola_Numero_Giorno() const
{
	int giorni_nel_mese[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int numero_giorno = _giorno;
	for (int i = 1; i < _mese; i++)
	{
		numero_giorno += giorni_nel_mese[i];
	}
	return numero_giorno;
}

bool Data::_is_Valid() const
{
	//manca bisestile
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
			//manca bisestile
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

int Data::get_Anno() const
{
	return _anno;
}

int Data::get_Mese() const
{
	return _mese;
}

int Data::get_Giorno() const
{
	return _giorno;
}

bool Data::operator<(const Data &data_destra) const
{
	if (this->_anno < data_destra._anno)
		return true;
	if (this->_anno > data_destra._anno)
		return false;
	if (this->_mese < data_destra._mese)
		return true;
	if (this->_mese > data_destra._mese)
		return false;
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

ostream & operator<<(ostream &stream, const Data &da_stampare)
{
	stream << da_stampare.stampa_Data();
	return stream;
}