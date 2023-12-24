//PETERCA ANDREI GRUPA 1049
//PROGRAM, ANTIVIRUS, CALCULATOR

//Imi cer scuze pentru incarcarile tarzii ale catorva faze din proiect.
//--
// Proasta gestiune a timpului m-a impiedicat din a le posta la timp. Am incercat sa le postez cat mai rapid cu putinta.
//--
//Pentru implementarea fazei 8 in clasa "has-a". Pentru clasa mea,
//  "Programator" am incercat sa pastrez ideea originala . "Programatorul are UN SINGUR calculator si MAI MULTE programe."

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include <dos.h>
using namespace std;

class Actualizabil
{
public:
	virtual void verificaActualizari() = 0;
	virtual void aplicaActualizari() = 0;
};

class Program : public Actualizabil
{
private:
	const int id;
	static string corporatie;
	string nume;
	float stocare;
	int nrLimbajeFolosite;
	string* limbajeFolosite;

public:

	void verificaActualizari()
	{
		cout << "Se verifica daca programul necesita actualziari...";
	}

	void aplicaActualizari()
	{
		cout << " Actualizari au fost aplicate cu succes programului!";
	}

	Program() :id(0)
	{
		this->nume = "NoName";
		this->stocare = 50;
		this->nrLimbajeFolosite = 0;
		this->limbajeFolosite = NULL;
	}

	Program(string nume, float stocare) : id(2)
	{
		this->nume = nume;
		this->stocare = stocare;
		this->nrLimbajeFolosite = 0;
		this->limbajeFolosite = NULL;
	}

	Program(int id, string nume, float stocare, int nrLimbajeFolosite, string* limbajeFolosite) : id(id)
	{

		this->nume = nume;
		this->stocare = stocare;
		this->nrLimbajeFolosite = nrLimbajeFolosite;
		this->limbajeFolosite = new string[nrLimbajeFolosite];
		for (int i = 0; i < nrLimbajeFolosite; i++)
			this->limbajeFolosite[i] = limbajeFolosite[i];
	}

	Program(const Program& p) : id(p.id)
	{
		this->nume = p.nume;
		this->stocare = p.stocare;
		this->nrLimbajeFolosite = p.nrLimbajeFolosite;
		this->limbajeFolosite = new string[p.nrLimbajeFolosite];
		for (int i = 0; i < p.nrLimbajeFolosite; i++)
			this->limbajeFolosite[i] = p.limbajeFolosite[i];
	}

	~Program()
	{
		if (limbajeFolosite != NULL)
		{
			delete[]this->limbajeFolosite;
		}
	}

	Program operator=(const Program& p)
	{
		if (this != &p)
		{
			if (this->limbajeFolosite != NULL)
				delete[]this->limbajeFolosite;
			this->nume = p.nume;
			this->stocare = p.stocare;
			this->nrLimbajeFolosite = p.nrLimbajeFolosite;
			this->limbajeFolosite = new string[p.nrLimbajeFolosite];
			for (int i = 0; i < p.nrLimbajeFolosite; i++)
				this->limbajeFolosite[i] = p.limbajeFolosite[i];
		}
		return *this;
	}

	void afisare()
	{
		cout << " Programul " << nume << " are id-ul " << id << " ,este folosit de " << corporatie <<
			" , ocupa spatiu de " << stocare << " GB , iar pentru cele " << nrLimbajeFolosite << " limbaje s-au folosit: ";
		if (nrLimbajeFolosite == 0)
		{
			cout << " - ";
		}
		else
		{
			for (int i = 0; i < nrLimbajeFolosite; i++)
				cout << "\n" << limbajeFolosite[i] << " ";
			cout << endl;
		}
		cout << endl;
	}



	int getId()
	{
		return this->id;
	}

	string getNume()
	{
		return this->nume;
	}

	string getCorporatie()
	{
		return Program::corporatie;
	}

	float getStocare()
	{
		return this->stocare;
	}

	int getNrLimbajeFolosite()
	{
		return this->nrLimbajeFolosite;
	}

	string* getLimbajeFolosite()
	{
		return this->limbajeFolosite;
	}

	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setStocare(float stocare)
	{
		this->stocare = stocare;
	}

	void setLimbajeFolosite(int nrLimbaje, string* limbaje)
	{
		if (nrLimbaje > 0)
		{
			this->nrLimbajeFolosite = nrLimbaje;
			if (this->limbajeFolosite != NULL)
			{
				delete[]this->limbajeFolosite;
			}
			limbajeFolosite = new string[nrLimbaje];
			for (int i = 0; i < nrLimbaje; i++)
			{
				this->limbajeFolosite[i] = limbaje[i];
			}
		}
	}

	static void setCorporatie(string corporatie)
	{
		Program::corporatie = corporatie;
	}


	Program& operator++()
	{                                      /*pre*/
		this->stocare = this->stocare + 34;
		return *this;
	}

	Program operator++(int)
	{                                      /*post*/
		Program aux = *this;
		this->stocare = this->stocare + 34;
		return aux;
	}

	friend float conversieGbToMb(Program p);
	friend istream& operator>>(istream& in, Program& p);
	friend ostream& operator<<(ostream& out, Program p);
	friend class Programator;

	friend ofstream& operator<<(ofstream& ofs, Program p)
	{
		ofs << p.nume << " " << p.stocare << " " << p.nrLimbajeFolosite;
		for (int i = 0; i < p.nrLimbajeFolosite; i++) {
			ofs << " " << p.limbajeFolosite[i] << " ";
		}
		return ofs;
	}

	friend ifstream& operator>>(ifstream& ifs, Program& p) {
		ifs >> p.nume;
		ifs >> p.stocare;
		ifs >> p.nrLimbajeFolosite;
		delete[] p.limbajeFolosite;
		p.limbajeFolosite = new string[p.nrLimbajeFolosite];
		for (int i = 0; i < p.nrLimbajeFolosite; i++) {
			ifs >> p.limbajeFolosite[i];
		}
		return ifs;
	}

	void scrieFisBinar(const string& numeFisier) {
		ofstream fisier(numeFisier, ios::binary | ios::out);
		if (!fisier) {
			cout << "Eroare la deschiderea fișierului!" << endl;
			return;
		}
		int lungime1 = nume.length() + 1;
		fisier.write((char*)&lungime1, sizeof(lungime1));
		fisier.write((char*)nume.c_str(), lungime1);
		fisier.write((char*)(&stocare), sizeof(stocare));
		fisier.write((char*)(&nrLimbajeFolosite), sizeof(nrLimbajeFolosite));

		for (int i = 0; i < nrLimbajeFolosite; ++i) {
			int lungime = limbajeFolosite[i].length();
			fisier.write((char*)(&lungime), sizeof(lungime));
			fisier.write(limbajeFolosite[i].c_str(), lungime);
		}

		fisier.close();
	}

	void citesteFisBinar(const string& numeFisier) {
		ifstream fisier(numeFisier, ios::binary | ios::in);
		if (!fisier) {
			cout << "Eroare la deschiderea fișierului!" << endl;
			return;
		}

		int lungime1;
		fisier.read((char*)(&lungime1), sizeof(lungime1));
		char* temp = new char[lungime1 + 1];
		fisier.read(temp, lungime1);

		nume = temp;
		delete[]temp;
		fisier.read((char*)(&stocare), sizeof(stocare));
		fisier.read((char*)(&nrLimbajeFolosite), sizeof(nrLimbajeFolosite));

		delete[] limbajeFolosite;
		limbajeFolosite = new string[nrLimbajeFolosite];
		for (int i = 0; i < nrLimbajeFolosite; ++i) {
			int lungime;
			fisier.read((char*)(&lungime), sizeof(lungime));
			char* buffer = new char[lungime + 1];
			fisier.read(buffer, lungime);
			buffer[lungime] = '\0';
			limbajeFolosite[i] = string(buffer);
			delete[] buffer;
		}

		fisier.close();
	}

	virtual void metoda()
	{
		cout << "Acesta este un simplu program";
	}
};
istream& operator>>(istream& in, Program& p)
{
	cout << " \nNume:";
	in >> p.nume;
	cout << " \nStocare:";
	in >> p.stocare;
	cout << " \n Nr limbaje folosite:";
	in >> p.nrLimbajeFolosite;
	if (p.limbajeFolosite != NULL)
	{
		delete[]p.limbajeFolosite;
	}
	p.limbajeFolosite = new string[p.nrLimbajeFolosite];
	for (int i = 0; i < p.nrLimbajeFolosite; i++)
	{
		cout << " Limbajul " << i + 1 << " : ";
		in >> p.limbajeFolosite[i];
	}

	return in;
}

ostream& operator<<(ostream& out, Program p)
{
	cout << " Programul ";
	out << p.nume;
	cout << " are id-ul ";
	out << p.id;
	out << " ,este folosit de "; out << p.corporatie;
	cout << " , ocupa spatiu de ";
	out << p.stocare;
	cout << " GB , iar pentru cele ";
	out << p.nrLimbajeFolosite;
	cout << " limbaje s-au folosit: ";
	if (p.nrLimbajeFolosite == 0)
	{
		cout << " - ";
	}
	else
	{
		for (int i = 0; i < p.nrLimbajeFolosite; i++)
			out << "\n" << p.limbajeFolosite[i] << " ";
		cout << endl;
	}
	cout << endl;
	return out;
}
float conversieGbToMb(Program p)
{
	return p.stocare * 1024;
}
string Program::corporatie = "HoneyWell";

class Antivirus
{
private:

	const int numar;
	static int versiune;
	string nume;
	float timpAnalizare;
	bool esteComplex;
	int nrDetinatori;
	string* departamente;

public:

	Antivirus() : numar(0)
	{
		this->nume = "NoName";
		this->timpAnalizare = 0;
		this->esteComplex = false;
		this->nrDetinatori = 0;
		this->departamente = NULL;
	}

	Antivirus(string nume, float timpAnalizare) : numar(5)
	{
		this->nume = nume;
		this->timpAnalizare = timpAnalizare;
		this->esteComplex = false;
		this->nrDetinatori = 0;
		this->departamente = NULL;
	}

	Antivirus(int numar, string nume, float timpAnalizare, bool esteComplex, int nrDetinatori, string* departamente) : numar(numar)
	{
		this->nume = nume;
		this->timpAnalizare = timpAnalizare;
		this->esteComplex = esteComplex;
		this->nrDetinatori = nrDetinatori;
		this->departamente = new string[nrDetinatori];
		if (nrDetinatori == 0)
			cout << " - ";
		else
			for (int i = 0; i < nrDetinatori; i++)
				this->departamente[i] = departamente[i];
	}

	Antivirus(const Antivirus& a) :numar(a.numar)
	{
		this->nume = a.nume;
		this->timpAnalizare = a.timpAnalizare;
		this->esteComplex = a.esteComplex;
		this->nrDetinatori = a.nrDetinatori;
		this->departamente = new string[a.nrDetinatori];
		if (nrDetinatori == 0)
			cout << " - ";
		else
			for (int i = 0; i < a.nrDetinatori; i++)
				this->departamente[i] = a.departamente[i];
	}

	const Antivirus& operator=(const Antivirus& a)
	{
		if (this != &a)
		{
			if (this->departamente != NULL)
				delete[]this->departamente;
			this->nume = a.nume;
			this->timpAnalizare = a.timpAnalizare;
			this->esteComplex = a.esteComplex;
			this->nrDetinatori = a.nrDetinatori;
			this->departamente = new string[a.nrDetinatori];
			if (nrDetinatori == 0)
				cout << " - ";
			else
				for (int i = 0; i < a.nrDetinatori; i++)
					this->departamente[i] = a.departamente[i];
		}
		return *this;
	}

	~Antivirus()
	{
		if (this->departamente != NULL)
			delete[]this->departamente;
	}

	void afisare()
	{
		cout << " Antivirusul " << nume << " are id-ul " << numar << " ,are actualizarile aferente anului  " << versiune << " , un timp de analizare de " << timpAnalizare << " minute " << " , ";
		(esteComplex == true) ? (cout << " prezinta complexitate mare") : (cout << " nu prezinta complexitate mare ");
		cout << " si este detinut de " << nrDetinatori << " departamente : ";

		for (int i = 0; i < nrDetinatori; i++)
			cout << " \n" << departamente[i];
		cout << endl;
	}

	static void setVersiune(int versiune)
	{
		Antivirus::versiune = versiune;
	}


	int getNumar() const
	{
		return this->numar;
	}

	string getNume()
	{
		return this->nume;
	}

	static int getVersiune()
	{
		return Antivirus::versiune;
	}

	float getTimpAnalizare()
	{
		return this->timpAnalizare;
	}

	int getNrDetinatori() const
	{
		return this->nrDetinatori;
	}

	string* getDepartamente()
	{
		return this->departamente;
	}

	void setCuloare(string nume)
	{
		this->nume = nume;
	}

	void setTimpAnalizare(float timpAnalizare)
	{
		this->timpAnalizare = timpAnalizare;
	}

	void setDepartamente(int nrDetinatori, string* departamente)
	{
		if (nrDetinatori > 0)
		{
			this->nrDetinatori = nrDetinatori;
			if (this->departamente != NULL)
			{
				delete[]this->departamente;
			}
			this->departamente = new string[nrDetinatori];
			for (int i = 0; i < nrDetinatori; i++)
			{
				this->departamente[i] = departamente[i];
			}
		}
	}

	void setEsteComplex(bool esteComplex)
	{
		this->esteComplex = esteComplex;
	}

	bool getEsteComplex()
	{
		return this->esteComplex;
	}

	void setNume(string nume)
	{
		this->nume = nume;
	}

	friend float conversieMinToHr(Antivirus a);
	friend istream& operator>>(istream& in, Antivirus& a);
	friend ostream& operator<<(ostream& out, Antivirus a);

	Antivirus& operator--()            //pre
	{
		if (this->timpAnalizare > 0)
		{
			this->timpAnalizare = this->timpAnalizare - 10;
			return *this;
		}

	}

	Antivirus operator--(int)              //post
	{
		Antivirus aux = *this;
		if (this->timpAnalizare > 0)
		{
			this->timpAnalizare = this->timpAnalizare - 10;
			return aux;
		}
	}

	bool operator==(const Antivirus& a)
	{
		bool ok1 = false;
		bool ok2 = false;
		int check = 0;
		if (this->nume == a.nume && this->timpAnalizare == a.timpAnalizare && this->esteComplex == a.esteComplex && this->nrDetinatori == a.nrDetinatori)
		{
			ok1 = true;
		}
		for (int i = 0; i < this->nrDetinatori; i++)
		{
			if (this->departamente[i] == a.departamente[i])
			{
				check = check + 1;
			}
		}
		if (check == this->nrDetinatori)
		{
			ok2 = true;
		}
		if (ok1 == false || ok2 == false)
		{
			return false;
		}
		else
		{
			return true;
		}
	}



	void scrieFisBinar(const string& numeFisier) {
		ofstream fisier(numeFisier, ios::binary | ios::out);
		if (!fisier) {
			cout << "Eroare la deschiderea fișierului!" << endl;
			return;
		}
		int lungime1 = nume.length() + 1;
		fisier.write((char*)&lungime1, sizeof(lungime1));
		fisier.write((char*)nume.c_str(), lungime1);
		fisier.write((char*)(&timpAnalizare), sizeof(timpAnalizare));
		fisier.write((char*)(&esteComplex), sizeof(esteComplex));
		fisier.write((char*)(&nrDetinatori), sizeof(nrDetinatori));

		for (int i = 0; i < nrDetinatori; ++i) {
			int lungime = departamente[i].length();
			fisier.write((char*)(&lungime), sizeof(lungime));
			fisier.write(departamente[i].c_str(), lungime);
		}

		fisier.close();
	}

	void citesteFisBinar(const string& numeFisier) {
		ifstream fisier(numeFisier, ios::binary | ios::in);
		if (!fisier) {
			cout << "Eroare la deschiderea fișierului!" << endl;
			return;
		}

		int lungime1;
		fisier.read((char*)(&lungime1), sizeof(lungime1));
		char* temp = new char[lungime1 + 1];
		fisier.read(temp, lungime1);

		nume = temp;
		delete[]temp;
		fisier.read((char*)(&timpAnalizare), sizeof(timpAnalizare));
		fisier.read((char*)(&esteComplex), sizeof(esteComplex));
		fisier.read((char*)(&nrDetinatori), sizeof(nrDetinatori));

		delete[] departamente;
		departamente = new string[nrDetinatori];
		for (int i = 0; i < nrDetinatori; ++i) {
			int lungime;
			fisier.read((char*)(&lungime), sizeof(lungime));
			char* buffer = new char[lungime + 1];
			fisier.read(buffer, lungime);
			buffer[lungime] = '\0';
			departamente[i] = string(buffer);
			delete[] buffer;
		}

		fisier.close();
	}

};

int Antivirus::versiune(2023);

istream& operator>>(istream& in, Antivirus& a)
{
	cout << " \nNume:";
	in >> a.nume;
	cout << " \nTimp analizare:";
	in >> a.timpAnalizare;
	cout << " Complex? true - 1 / false - 0: ";
	in >> a.esteComplex;
	cout << " \n Nr detinatori:";
	in >> a.nrDetinatori;
	if (a.departamente != NULL)
	{
		delete[]a.departamente;
	}
	a.departamente = new string[a.nrDetinatori];
	for (int i = 0; i < a.nrDetinatori; i++)
	{
		cout << " Departamentul " << i + 1 << " : ";
		in >> a.departamente[i];
	}

	return in;
}


ostream& operator<<(ostream& out, const Antivirus a)
{
	cout << " Programul ";
	out << a.nume;
	cout << " are numarul specific ";
	out << a.numar;
	out << " ,are versiunea aferenta anului "; out << a.versiune;
	cout << " , are timpul de analizare de ";
	out << a.timpAnalizare;
	(a.esteComplex == 1) ? (cout << " ,minute ,prezinta complexitate, ") : (cout << " minute, nu prezinta complexitate ");
	cout << "  iar cei ";
	out << a.nrDetinatori;
	cout << " detinatori sunt departamentele: ";
	if (a.nrDetinatori == 0)
	{
		cout << " - ";
	}
	else
	{
		for (int i = 0; i < a.nrDetinatori; i++)
			out << "\n" << a.departamente[i] << " ";
		cout << endl;
	}
	cout << endl;
	return out;
}

float conversieMinToHr(Antivirus a)
{
	return a.timpAnalizare / 60;
}

class DispozitivElectronic
{
public:
	virtual void porneste() = 0;
	virtual void opreste() = 0;
};

class Calculator:public DispozitivElectronic
{
private:
	const int id;
	static int driver;
	string culoare;
	float pret;
	bool areInternet;
	int nrComponente;
	string* componente;

public:
	Calculator() : id(0)
	{
		this->culoare = "neagra";
		this->pret = 0;
		this->areInternet = false;
		this->nrComponente = 0;
		this->componente = NULL;

	}

	Calculator(string culoare, float pret) : id(4)
	{
		this->culoare = culoare;
		this->pret = pret;
		this->areInternet = false;
		this->nrComponente = 0;
		this->componente = NULL;
	}

	Calculator(int id, string culoare, float pret, bool areInternet, int nrComponente, string* componente) : id(id)
	{
		this->culoare = culoare;
		this->pret = pret;
		this->areInternet = areInternet;
		this->nrComponente = nrComponente;
		this->componente = new string[nrComponente];
		if (nrComponente == 0)
			cout << " - ";
		else
			for (int i = 0; i < nrComponente; i++)
				this->componente[i] = componente[i];
	}

	Calculator(const Calculator& c) : id(c.id)
	{
		this->culoare = c.culoare;
		this->pret = c.pret;
		this->areInternet = c.areInternet;
		this->nrComponente = c.nrComponente;
		this->componente = new string[c.nrComponente];
		if (nrComponente == 0)
			cout << " - ";
		else
			for (int i = 0; i < c.nrComponente; i++)
				this->componente[i] = c.componente[i];
	}

	const Calculator& operator=(const Calculator& c)
	{
		if (this != &c)
		{
			if (this->componente != NULL)
				delete[]this->componente;
			this->culoare = c.culoare;
			this->pret = c.pret;
			this->areInternet = c.areInternet;
			this->nrComponente = c.nrComponente;
			this->componente = new string[c.nrComponente];
			if (nrComponente == 0)
				cout << " - ";
			else
				for (int i = 0; i < c.nrComponente; i++)
					this->componente[i] = c.componente[i];
		}
		return *this;
	}

	~Calculator()
	{
		if (this->componente != NULL)
			delete[]this->componente;
	}

	void afisare()
	{
		cout << "Calculatorul " << id << " are driverele aferente anului " << driver << ",are culoare " << culoare << " ,costa " << pret << " lei, ";
		(areInternet == true) ? (cout << " are internet ") : (cout << " nu are internet ");
		cout << " si contine " << nrComponente << " componente:";
		if (nrComponente == 0)
			cout << " - ";
		else
			for (int i = 0; i < nrComponente; i++)
				cout << "\n" << i + 1 << "." << componente[i] << " ";
		cout << endl;

	}
	static void setDriver(int driver)
	{
		Calculator::driver = driver;
	}
	static int getDriver()
	{
		return Calculator::driver;
	}

	int getId()
	{
		return this->id;
	}

	string getCuloare()
	{
		return this->culoare;
	}

	float getPret()
	{
		return this->pret;
	}

	int getNrComponente()
	{
		return this->nrComponente;
	}

	string* getComponente()
	{
		return this->componente;
	}

	void setCuloare(string culoare)
	{
		this->culoare = culoare;
	}

	void setPret(float pret)
	{
		this->pret = pret;
	}

	void setComponente(int nrComponente, string* componente)
	{
		if (nrComponente >= 0)
		{
			this->nrComponente = nrComponente;
			if (this->componente != NULL)
			{
				delete[]this->componente;

				this->componente = new string[nrComponente];
				for (int i = 0; i < nrComponente; i++)
				{
					this->componente[i] = componente[i];
				}
			}
		}
	}

	void setAreInternet(bool areInternet)
	{
		this->areInternet = areInternet;
	}

	bool getAreInternet()
	{
		return this->areInternet;
	}

	friend istream& operator>>(istream& in, Calculator& c);
	friend ostream& operator<<(ostream& out, Calculator c);
	friend class Programator;



	friend ofstream& operator<<(ofstream& ofs, Calculator c)
	{
		ofs << c.culoare << " " << c.pret << " " << c.areInternet << " " << c.nrComponente;
		for (int i = 0; i < c.nrComponente; i++) {
			ofs << " " << c.componente[i] << " ";
		}
		return ofs;
	}

	friend ifstream& operator>>(ifstream& ifs, Calculator& c) {
		ifs >> c.culoare;
		ifs >> c.pret;
		ifs >> c.areInternet;
		ifs >> c.nrComponente;
		delete[] c.componente;
		c.componente = new string[c.nrComponente];
		for (int i = 0; i < c.nrComponente; i++) {
			ifs >> c.componente[i];
		}
		return ifs;
	}



	bool operator!=(const Calculator& c)
	{
		bool ok1 = false;
		int check = 0;
		bool ok2 = false;
		if (this->culoare == c.culoare && this->pret == c.pret && this->areInternet == c.areInternet && this->nrComponente == c.nrComponente)
		{
			ok1 = true;
		}
		for (int i = 0; i < nrComponente; i++)
		{
			if (this->componente[i] == c.componente[i])
			{
				check = check + 1;
			}
		}
		if (check == this->nrComponente)
		{
			ok2 = true;
		}
		if (ok1 == false || ok2 == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Calculator& operator!()
	{
		this->areInternet = !this->areInternet;
		return *this;
	}


	Calculator	operator+(const Calculator& c)
	{
		Calculator aux;
		aux.culoare = this->culoare;
		aux.pret = this->pret + c.pret;
		if (this->areInternet == true || c.areInternet == true)
		{
			aux.areInternet = true;
		}
		else
		{
			aux.areInternet = false;
		}

		aux.nrComponente = this->nrComponente + c.nrComponente;
		if (aux.componente != NULL)
		{
			delete[]aux.componente;
		}
		aux.componente = new string[this->nrComponente + c.nrComponente];
		for (int i = 0; i < this->nrComponente; i++)
		{
			aux.componente[i] = this->componente[i];
		}
		for (int j = this->nrComponente; j < aux.nrComponente; j++)
		{
			aux.componente[j] = c.componente[j - this->nrComponente];
		}
		return aux;
	}
	virtual void metoda()
	{
		cout << "Acesta este un simplu calculator";
	}

	void porneste()
	{
		cout << "Se porneste calculatorul...";
		cout << " Calculatorul a fost pornit cu succes";
	}

	void opreste()
	{
		cout << " Se opreste calculatorul...";
		cout << " Calculatorul a fost oprit cu succes";
	}
};
int Calculator::driver(2023);

istream& operator>>(istream& in, Calculator& c)
{
	cout << " \nCuloare:";
	in >> c.culoare;
	cout << " \nPret:";
	in >> c.pret;
	cout << " Are Internet? Da - 1 / Nu - 0: ";
	in >> c.areInternet;
	cout << " \n Nr componente:";
	in >> c.nrComponente;
	if (c.componente != NULL)
	{
		delete[]c.componente;
	}
	c.componente = new string[c.nrComponente];
	for (int i = 0; i < c.nrComponente; i++)
	{
		cout << " Componenta " << i + 1 << " : ";
		in >> c.componente[i];
	}

	return in;
}


ostream& operator<<(ostream& out, const Calculator c)
{
	cout << " Calculatorul de culoare ";
	out << c.culoare;
	cout << " are id-ul ";
	out << c.id;
	out << " ,are driverele instalate aferente anului "; out << c.driver;
	cout << " , are pretul de ";
	out << c.pret;
	(c.areInternet == 1) ? (cout << " ,RON, prezinta conexiune la internet ") : (cout << " RON, nu prezinta conexiune la internet ");
	cout << "  iar cele ";
	out << c.nrComponente;
	cout << "  componente sunt: ";
	if (c.nrComponente == 0)
	{
		cout << " - ";
	}
	else
	{
		for (int i = 0; i < c.nrComponente; i++)
			out << "\n" << c.componente[i] << " ";
		cout << endl;
	}
	cout << endl;
	return out;
}



class CalculatorGaming :public Calculator
{
private:
	bool iluminareRGB;
	int nrVentilatoare;
	float temperaturaSuportata;
	int* vitezeVentilatoare;

public:

	void porneste()
	{
		cout << "Se porneste calculatorul de gaming...";
		cout << " Calculatorul de gaming a fost pornit cu succes";
	}

	void opreste()
	{
		cout << " Se opreste calculatorul de gaming...";
		cout << " Calculatorul de gaming a fost oprit cu succes";
	}

	CalculatorGaming() : Calculator()
	{
		this->iluminareRGB = false;
		this->nrVentilatoare = 3;
		this->temperaturaSuportata = 80.6;
		this->vitezeVentilatoare = new int[nrVentilatoare];
		for (int i = 0; i < nrVentilatoare; i++)
		{
			this->vitezeVentilatoare[i] = 150;
		}
	}

	CalculatorGaming(bool iluminareRGB, int nrVentilatoare, float temperaturaSuportata, int* vitezeVentilatoare) : Calculator()
	{
		this->iluminareRGB = iluminareRGB;
		this->nrVentilatoare = nrVentilatoare;
		this->temperaturaSuportata = temperaturaSuportata;
		this->vitezeVentilatoare = new int[this->nrVentilatoare];
		for (int i = 0; i < nrVentilatoare; i++)
		{
			this->vitezeVentilatoare[i] = vitezeVentilatoare[i];
		}

	}

	CalculatorGaming(bool iluminareRGB, int nrVentilatoare, float temperaturaSuportata, int* vitezeVentilatoare, string culoare, float pret, bool areInternet, int nrComponente, string* componente) :Calculator(199, culoare, pret, areInternet, nrComponente, componente)
	{
		this->iluminareRGB = iluminareRGB;
		this->nrVentilatoare = nrVentilatoare;
		this->temperaturaSuportata = temperaturaSuportata;
		this->vitezeVentilatoare = new int[this->nrVentilatoare];
		for (int i = 0; i < nrVentilatoare; i++)
		{
			this->vitezeVentilatoare[i] = vitezeVentilatoare[i];
		}
	}

	CalculatorGaming(const CalculatorGaming& cg) : Calculator(cg)
	{
		this->iluminareRGB = cg.iluminareRGB;
		this->nrVentilatoare = cg.nrVentilatoare;
		this->temperaturaSuportata = cg.temperaturaSuportata;
		this->vitezeVentilatoare = new int[this->nrVentilatoare];
		for (int i = 0; i < nrVentilatoare; i++)
		{
			this->vitezeVentilatoare[i] = cg.vitezeVentilatoare[i];
		}
	}

	CalculatorGaming& operator=(const CalculatorGaming& cg)
	{
		if (this != &cg)
		{
			Calculator::operator=(cg);
			this->iluminareRGB = cg.iluminareRGB;
			this->nrVentilatoare = cg.nrVentilatoare;
			this->temperaturaSuportata = cg.temperaturaSuportata;
			if (this->vitezeVentilatoare != NULL)
			{
				delete[]this->vitezeVentilatoare;
				this->vitezeVentilatoare = new int[cg.nrVentilatoare];
				for (int i = 0; i < cg.nrVentilatoare; i++)
				{
					this->vitezeVentilatoare[i] = cg.vitezeVentilatoare[i];
				}
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const CalculatorGaming cg)
	{
		out << (Calculator)cg;
		out << endl;
		out << " Temperatura suportata este de " << cg.temperaturaSuportata << " grade" << endl;
		(cg.iluminareRGB == true) ? (out << " Este iluminat RGB, ") : (out << "Nu este iluminat RGB, ");
		out << " contine " << cg.nrVentilatoare << " ventilatoare, acestea avand vitezele de: " << endl;
		for (int i = 0; i < cg.nrVentilatoare; i++)
		{
			out << i + 1 << ". " << cg.vitezeVentilatoare[i] << " RPM " << endl;
		}

		return out;

	}

	friend istream& operator>>(istream& in, CalculatorGaming& cg)
	{
		in >> (Calculator&)cg;
		cout << " Are iluminare RGB? (0-nu / 1-da) : ";
		in >> cg.iluminareRGB;
		cout << " Temperatura suportata : ";
		in >> cg.temperaturaSuportata;
		cout << " Nr ventialtoare : ";
		in >> cg.nrVentilatoare;
		if (cg.vitezeVentilatoare != NULL)
		{
			delete[]cg.vitezeVentilatoare;
			cg.vitezeVentilatoare = new int[cg.nrVentilatoare];
			for (int i = 0; i < cg.nrVentilatoare; i++)
			{
				cout << " Viteza ventilator " << i + 1 << " : ";
				in >> cg.vitezeVentilatoare[i];
			}
		}

		return in;
	}
	~CalculatorGaming()
	{
		delete[]this->vitezeVentilatoare;
	}

	bool getIluminareRGB()
	{
		return this->iluminareRGB;
	}

	void setIluminareRGB(bool iluminareRGB)
	{
		this->iluminareRGB = iluminareRGB;
	}

	int getNrVentilatoare()
	{
		return this->nrVentilatoare;
	}

	int* getVitezeVentilatoare()
	{
		return this->vitezeVentilatoare;
	}

	void setVentilatoare(int nrVentilatoare, int* vitezeVentilatoare)
	{
		if (nrVentilatoare > 0)
		{
			this->nrVentilatoare = nrVentilatoare;
			if (this->vitezeVentilatoare != NULL)
			{
				delete[]this->vitezeVentilatoare;
				this->vitezeVentilatoare = new int[nrVentilatoare];
				for (int i = 0; i < nrVentilatoare; i++)
				{
					this->vitezeVentilatoare[i] = vitezeVentilatoare[i];
				}
			}
		}
	}

	float getTemperaturaSuportata()
	{
		return this->temperaturaSuportata;
	}
	void setTemperaturaSuportata(float temperaturaSuportata)
	{
		this->temperaturaSuportata = temperaturaSuportata;
	}

	void metoda()
	{
		cout << "Acesta este un calculator de gaming";
	}


};

class Programator
{
private:
	static int nrProgramatori;
	string nume;
	Calculator calculator;
	int nrPrograme;
	Program* programe;
	bool esteIncepator;


	DispozitivElectronic* *calculatorDE;
	Actualizabil* *programeAC;

public:
	Programator()
	{
		this->nume = " JohnDoe ";


		this->calculator.culoare = " neagra ";
		this->calculator.pret = 0;
		this->calculator.areInternet = false;
		this->calculator.nrComponente = 0;
		this->calculator.componente = NULL;
		this->nrPrograme = 0;
		this->esteIncepator = true;
		this->programe = NULL;

		this->nrProgramatori++;


		this->calculatorDE = new DispozitivElectronic* [1];
		calculatorDE[0] = new Calculator();
		this->programeAC = new Actualizabil * [3];
		for (int i = 0; i < 3; i++)
		{
			programeAC[i] = new Program();
		}

	}

	Actualizabil*& operator[](int index)
	{
		if (index >= 0 && index < 3)
		{
			return this->programeAC[index];
		}
	}

	DispozitivElectronic*& intoarceDE(int index)
	{
		if (index ==0)
		{
			return this->calculatorDE[index];
		}
	}

	Programator(string nume, bool esteIncepator, Calculator& c, int nrPrograme, Program* programe)
	{
		this->nume = nume;


		this->calculator.culoare = c.culoare;
		this->calculator.pret = c.pret;
		this->calculator.areInternet = c.areInternet;
		this->calculator.nrComponente = c.nrComponente;
		if (calculator.componente != NULL)
		{
			delete[]this->calculator.componente;
		}
		calculator.componente = new string[calculator.nrComponente];
		for (int i = 0; i < c.nrComponente; i++)
		{
			this->calculator.componente[i] = c.componente[i];
		}

		this->nrPrograme = nrPrograme;
		this->esteIncepator = esteIncepator;

		if (this->programe != NULL)
		{
			delete[]this->programe;
		}
		this->programe = new Program[this->nrPrograme];
		for (int i = 0; i < this->nrPrograme; i++)
		{
			this->programe[i] = programe[i];
		}


		this->nrProgramatori++;
	}

	Programator(const Programator& p)
	{

		this->nume = p.nume;


		this->calculator.culoare = p.calculator.culoare;
		this->calculator.pret = p.calculator.pret;
		this->calculator.areInternet = p.calculator.areInternet;
		this->calculator.nrComponente = p.calculator.nrComponente;
		if (calculator.componente != NULL)
		{
			delete[]this->calculator.componente;
		}
		calculator.componente = new string[p.calculator.nrComponente];
		for (int i = 0; i < p.calculator.nrComponente; i++)
		{
			this->calculator.componente[i] = p.calculator.componente[i];
		}

		this->nrPrograme = p.nrPrograme;
		this->esteIncepator = p.esteIncepator;

		if (this->programe != NULL)
		{
			delete[]this->programe;
		}
		this->programe = new Program[this->nrPrograme];
		for (int i = 0; i < this->nrPrograme; i++)
		{
			this->programe[i] = p.programe[i];
		}


		this->nrProgramatori++;

	}

	const Programator& operator=(const Programator& p)
	{
		if (this != &p)
		{
			this->nume = p.nume;


			this->calculator.culoare = p.calculator.culoare;
			this->calculator.pret = p.calculator.pret;
			this->calculator.areInternet = p.calculator.areInternet;
			this->calculator.nrComponente = p.calculator.nrComponente;
			if (calculator.componente != NULL)
			{
				delete[]this->calculator.componente;
			}
			calculator.componente = new string[p.calculator.nrComponente];
			for (int i = 0; i < p.calculator.nrComponente; i++)
			{
				this->calculator.componente[i] = p.calculator.componente[i];
			}

			this->nrPrograme = p.nrPrograme;
			this->esteIncepator = p.esteIncepator;

			if (this->programe != NULL)
			{
				delete[]this->programe;
			}
			this->programe = new Program[this->nrPrograme];
			for (int i = 0; i < this->nrPrograme; i++)
			{
				this->programe[i] = p.programe[i];
			}


			this->nrProgramatori++;
		}
		return *this;
	}
	~Programator()
	{
		delete[]programe;

	}

	static int getNrProgramatori()
	{
		return Programator::nrProgramatori;
	}

	string getNume()
	{
		return this->nume;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setEsteIncepator(bool esteIncepator)
	{
		this->esteIncepator = esteIncepator;
	}
	bool getEsteIncepator()
	{
		return this->esteIncepator;
	}


	string getCalculatorCuloare()
	{
		return this->calculator.getCuloare();
	}
	void setCalculatorCuloare(string culoare)
	{
		this->calculator.setCuloare(culoare);
	}

	float getCalculatorPret()
	{
		return this->calculator.getPret();
	}
	void setCalculatorPret(float pret)
	{
		this->calculator.setPret(pret);
	}

	bool getCalculatorAreInternet()
	{
		return this->calculator.getAreInternet();
	}
	void setCalculatorAreInternet(bool areInternet)
	{
		this->calculator.setAreInternet(areInternet);
	}

	int getCalculatorNrComponente()
	{
		return this->calculator.getNrComponente();
	}
	string* getCalculatorComponente()
	{
		return this->calculator.getComponente();
	}
	void setCalculatorComponente(int nrComponente, string* Componente)
	{
		this->calculator.setComponente(nrComponente, Componente);
	}

	int getNrPrograme()
	{
		return this->nrPrograme;
	}
	string getProgramNume()
	{
		return this->programe->getNume();
	}
	float getProgramStocare()
	{
		return this->programe->getStocare();
	}
	int getProgramNrLimbaje()
	{
		return this->programe->getNrLimbajeFolosite();
	}
	string* getProgramLimbaje()
	{
		return this->programe->getLimbajeFolosite();
	}
	Program* getPrograme()
	{
		return this->programe;
	}
	void setPrograme(int nrPrograme, Program* programe)
	{
		if (nrPrograme > 0)
		{
			this->nrPrograme = nrPrograme;

			if (this->programe != NULL)
			{
				delete[]this->programe;
			}
			this->programe = new Program[nrPrograme];
			for (int i = 0; i < this->nrPrograme; i++)
			{
				this->programe[i] = programe[i];
			}
		}
	}
	friend class Calculator;
	friend class Program;
	friend ostream& operator<<(ostream& out, const Programator& p)
	{
		out << "Programatorul cu numele " << p.nume << " detine urmatorul calculator : " << endl << endl;
		out << p.calculator << endl;
		(p.esteIncepator == true) ? (out << "De asemenea, el este incepator ") : (out << "De asemenea, el nu este incepator ");
		out << " este cunoscator de " << p.nrPrograme << " programe, acestea fiind " << endl;
		for (int i = 0; i < p.nrPrograme; i++)
		{
			out << "Programul " << i + 1 << ". " << endl;
			out << (Program)p.programe[i] << endl;
		}
		out << " Exista in corporatie " << p.nrProgramatori << " programatori activi";
		return out;
	}
	friend istream& operator>>(istream& in, Programator& p)
	{
		cout << "Nume : ";
		in >> p.nume;
		cout << " Despre calculator..." << endl;
		in >> p.calculator;
		cout << " Este incepator?(0-Nu / 1 - Da): ";
		in >> p.esteIncepator;
		cout << " Nr programe cunoscute ";
		in >> p.nrPrograme;
		cout << "Acestea sunt : " << endl;
		if (p.programe != NULL)
		{
			delete[]p.programe;
		}
		p.programe = new Program[p.nrPrograme];
		for (int i = 0; i < p.nrPrograme; i++)
		{
			cout << "Programul " << i + 1 << ". ";
			in >> (Program&)p.programe[i];
		}

		return in;
	}




	friend ifstream& operator>>(ifstream& fin, Programator& p)
	{
		fin >> p.nume;
		fin >> p.esteIncepator;


		fin >> p.calculator;


		fin >> p.nrPrograme;
		delete[]p.programe;
		p.programe = new Program[p.nrPrograme];
		for (int i = 0; i < p.nrPrograme; i++)
		{
			fin >> p.programe[i];
		}
		return fin;
	}

	bool operator!=(const Programator& p)
	{
		return this->nrPrograme != p.nrPrograme;
	}

	bool operator==(const Programator& p)
	{
		return this->nrPrograme == p.nrPrograme;
	}

	bool operator<=(const Programator& p)
	{
		return this->nrPrograme <= p.nrPrograme;
	}






};
int Programator::nrProgramatori = 0;

ofstream& operator<<(ofstream& fout, Programator& p)
{
	fout << p.getNume() << " ";
	fout << p.getEsteIncepator() << " " << endl;



	fout << p.getCalculatorCuloare() << " " << p.getCalculatorPret() << " " << p.getCalculatorAreInternet() << " " << p.getCalculatorNrComponente();
	for (int i = 0; i < p.getCalculatorNrComponente(); i++) {
		fout << " " << p.getCalculatorComponente()[i] << " ";
	}


	fout << endl << p.getNrPrograme() << " ";
	for (int i = 0; i < p.getNrPrograme(); i++)
	{

		fout << p.getPrograme()[i];

	}
	return fout;
}


class AplicatieMobil : public Program
{
private:
	string sistemOperare;
	int numarDescarcari;
	float dimensiuneDescarcare;
	string* dispozitiveTestate;
public:

	void verificaActualizari()
	{
		cout << "Se verifica daca aplicatia mobila necesita actualziari...";
	}

	void aplicaActualizari()
	{
		cout << " Actualizari au fost aplicate cu succes aplicatiei mobile!";
	}

	AplicatieMobil() : Program("Default Mobile-App", 100)
	{
		this->sistemOperare = " Android";
		this->numarDescarcari = 0;
		this->dimensiuneDescarcare = 100;
		this->dispozitiveTestate = NULL;
	}

	AplicatieMobil(string nume, string sistemOperare, int numarDescarcari, float dimensiuneDescarcare, string* dispozitiveTestate) : Program(nume, dimensiuneDescarcare)
	{
		this->sistemOperare = sistemOperare;
		this->numarDescarcari = numarDescarcari;
		this->dimensiuneDescarcare = dimensiuneDescarcare;
		this->dispozitiveTestate = new string[numarDescarcari];
		for (int i = 0; i < numarDescarcari; i++)
		{
			this->dispozitiveTestate[i] = dispozitiveTestate[i];
		}
	}

	AplicatieMobil(const AplicatieMobil& am) : Program(am)
	{
		this->sistemOperare = am.sistemOperare;
		this->numarDescarcari = am.numarDescarcari;
		this->dimensiuneDescarcare = am.dimensiuneDescarcare;
		this->dispozitiveTestate = new string[am.numarDescarcari];
		for (int i = 0; i < am.numarDescarcari; i++)
		{
			this->dispozitiveTestate[i] = am.dispozitiveTestate[i];
		}
	}

	~AplicatieMobil()
	{
		delete[]this->dispozitiveTestate;
	}

	AplicatieMobil& operator=(const AplicatieMobil& am)
	{
		if (this != &am)
		{
			Program::operator=(am);
			this->sistemOperare = am.sistemOperare;
			this->numarDescarcari = am.numarDescarcari;
			this->dimensiuneDescarcare = am.dimensiuneDescarcare;
			if (this->dispozitiveTestate != NULL)
			{
				delete[]this->dispozitiveTestate;
			}
			this->dispozitiveTestate = new string[am.numarDescarcari];
			for (int i = 0; i < am.numarDescarcari; i++)
			{
				this->dispozitiveTestate[i] = am.dispozitiveTestate[i];
			}

		}
		return *this;
	}


	string getSistemOperare()
	{
		return this->sistemOperare;
	}
	void setSistemOperare(string sistemOperare)
	{
		this->sistemOperare = sistemOperare;
	}

	float getDimensiuneDescarcare()
	{
		return this->dimensiuneDescarcare;
	}
	void setDimensiuneDescarcare(float dimensiuneDescarcare)
	{
		if (dimensiuneDescarcare >= 0)
		{
			this->dimensiuneDescarcare = dimensiuneDescarcare;
		}
	}

	int getNumarDescarcari()
	{
		return this->numarDescarcari;
	}
	string* getDispozitiveTestate()
	{
		return this->dispozitiveTestate;
	}
	void setDispozitiveTestate(int numarDescarcari, string* dispozitiveTestate)
	{
		if (numarDescarcari >= 0)
		{
			this->numarDescarcari = numarDescarcari;
			if (this->dispozitiveTestate != NULL)
			{
				delete[]this->dispozitiveTestate;
				this->dispozitiveTestate = new string[numarDescarcari];
				for (int i = 0; i < numarDescarcari; i++)
				{
					this->dispozitiveTestate[i] = dispozitiveTestate[i];
				}
			}
		}
	}



	friend ostream& operator<<(ostream& out, AplicatieMobil am)
	{
		out << (Program)am;
		out << endl;
		out << " De asemenea, prezinta sistemul de operare " << am.sistemOperare << " , " << am.numarDescarcari << " descarcari." << endl;
		out << " Are dimensiunea descarcarii de " << am.dimensiuneDescarcare << " MB, iar dispozitivele pe care a fost testata aplicatia sunt: " << endl;
		for (int i = 0; i < am.numarDescarcari; i++)
		{
			out << "Dispozitivul " << i + 1 << " : " << am.dispozitiveTestate[i] << endl;
		}
		return out;
	}

	friend istream& operator>>(istream& in, AplicatieMobil& am)
	{
		in >> (Program&)am;
		cout << endl << " Sistem de operare : ";
		in >> am.sistemOperare;
		cout << " Numar Descarcari : ";
		in >> am.numarDescarcari;
		cout << "Dimensiune Descarcare : ";
		in >> am.dimensiuneDescarcare;
		if (am.dispozitiveTestate != NULL)
		{
			delete[]am.dispozitiveTestate;
		}
		am.dispozitiveTestate = new string[am.numarDescarcari];
		for (int i = 0; i < am.numarDescarcari; i++)
		{
			cout << "Dispozitivul " << i + 1 << " : ";
			in >> am.dispozitiveTestate[i];
		}

		return in;
	}

	void metoda()
	{
		cout << " Aceasta este o aplicatie pentru telefon";
	}

};
int main()
{
	/*Program program1;
	program1.afisare();

	Program program2("Destroyer", 80);
	program2.afisare();

	string* limbajeFolosite = new string[2];
	limbajeFolosite[0] = "JavaScript";
	limbajeFolosite[1] = "Python";

	Program::setCorporatie("Atos INC");
	Program program3(5, "Creare Matrice", 100, 2, limbajeFolosite);
	program3.afisare();
	cout << endl;

	Program program4(program2);
	program4.afisare();

	cout << endl;
	Antivirus antivirus1;
	antivirus1.afisare();

	Antivirus antivirus2("Savior", 2);
	antivirus2.afisare();

	string* departamente = new string[3];
	departamente[0] = "Marketing";
	departamente[1] = "Logistica";
	departamente[2] = "Arhitectura Retea Interna";

	Antivirus antivirus3(10, "Panda +", 10, true, 3, departamente);
	antivirus3.setVersiune(2024);
	antivirus3.afisare();
	cout << endl;

	Antivirus antivirus4(antivirus3);
	antivirus4.afisare();

	cout << endl;
	Calculator calculator1;
	calculator1.afisare();

	Calculator calculator2("rosie", 4000);
	calculator2.afisare();

	string* componente = new string[3];
	componente[0] = " Placa video ";
	componente[1] = " Procesor ";
	componente[2] = " Memorie RAM ";

	Calculator calculator3(100, "alba", 10000, true, 3, componente);
	calculator3.setDriver(2024);
	calculator3.afisare();
	cout << endl;

	Calculator calculator4(calculator2);
	calculator4.afisare();

	cout << endl;

	Antivirus antivirus5;
	antivirus5 = antivirus4;

	Program program5;
	program5 = program3;

	Calculator calculator5;
	calculator5 = calculator3;

	antivirus5.afisare();
	program5.afisare();
	calculator5.afisare();

	cout << " Antivirusul " << antivirus5.getNume() << " are acum numele ";
	antivirus5.setNume("AntiTrojan");
	cout << antivirus5.getNume() << " cu id-ul " << antivirus5.getNumar() << " si poseda specificatiile: ";
	cout << "\n Timp analizare (ieri:  ";
	cout << antivirus5.getTimpAnalizare();
	cout << " ) (azi: ";
	antivirus5.setTimpAnalizare(20);
	cout << antivirus5.getTimpAnalizare() << " )";
	cout << "\n Complexitate(1-da/0-nu) (ieri:  ";
	cout << antivirus5.getEsteComplex();
	cout << " ) (azi: ";
	antivirus5.setEsteComplex(false);
	cout << antivirus5.getEsteComplex() << " )";
	cout << "\n Departamente (ieri:  ";
	for (int i = 0; i < antivirus5.getNrDetinatori(); i++)
	{
		cout << " " << *(antivirus5.getDepartamente() + i);
	}
	cout << " ) (azi: ";
	string* departamente1 = new string[4]{ "HR", "BACKEND" ,"LOGISTICA","VANZARI" };

	antivirus5.setDepartamente(4, departamente1);
	for (int i = 0; i < antivirus5.getNrDetinatori(); i++)
	{
		cout << " " << *(antivirus5.getDepartamente() + i);
	}
	cout << " )";



	cout << " \n\nProgramul " << program5.getNume() << " are acum numele ";
	antivirus5.setNume("ItsyBitsy");
	cout << antivirus5.getNume() << " cu id-ul " << program5.getId() << " si poseda specificatiile: ";
	cout << "\n Stocare (ieri:  ";
	cout << program5.getStocare();
	cout << " ) (azi: ";
	program5.setStocare(20);
	cout << program5.getStocare() << " )";
	cout << "\n Corporatia (ieri:  ";
	cout << program5.getCorporatie();
	cout << " ) (azi: ";
	program5.setCorporatie("OMW");
	cout << program5.getCorporatie() << " )";
	cout << "\n Limbaje folosite (ieri:  ";
	for (int i = 0; i < program5.getNrLimbajeFolosite(); i++)
	{
		cout << " " << *(program5.getLimbajeFolosite() + i);
	}
	cout << " ) (azi: ";
	string* limbaje1 = new string[4]{ "Python", "C++" ,"Malbolge","LOLCODE" };

	program5.setLimbajeFolosite(4, limbaje1);
	for (int i = 0; i < program5.getNrLimbajeFolosite(); i++)
	{
		cout << " " << *(program5.getLimbajeFolosite() + i);
	}
	cout << " )";



	cout << " \n\nCalculatorul " << " cu id-ul " << program5.getId() << " poseda specificatiile: ";
	cout << "\n Culoare (ieri:  ";
	cout << calculator5.getCuloare();
	cout << " ) (azi: ";
	calculator5.setCuloare("Mov");
	cout << calculator5.getCuloare() << " )";
	cout << "\n Drivere aferente (ieri:  ";
	cout << calculator5.getDriver();
	cout << " ) (azi: ";
	calculator5.setDriver(2024);
	cout << calculator5.getDriver() << " )";
	cout << "\n Pret (ieri:  ";
	cout << calculator5.getPret();
	cout << " ) (azi: ";
	calculator5.setPret(200000);
	cout << calculator5.getPret() << " )";
	cout << "\n Nr componente (ieri:  ";
	for (int i = 0; i < calculator5.getNrComponente(); i++)
	{
		cout << " " << *(calculator5.getComponente() + i);
	}
	cout << " ) (azi: ";
	string* componente1 = new string[4]{ "Placa_video", "Placa_sunet" ,"Placa_retea","Adaptor_VHS->HDMI" };

	calculator5.setComponente(4, componente1);
	for (int i = 0; i < calculator5.getNrComponente(); i++)
	{
		cout << " " << *(calculator5.getComponente() + i);
	}
	cout << " )";
	cout << endl;

	cout << program5.getStocare() << " GB = " << conversieGbToMb(program5) << " MB\n";
	cout << antivirus5.getTimpAnalizare() << " min = " << conversieMinToHr(antivirus5) << " Hours \n";

	Program program100;
	cin >> program100;
	Program program101;

	program101 = program100++;
	cout << program100;
	cout << program101;

	Program program102;
	program102 = ++program101;
	cout << program102;



	Antivirus antivirus100;
	cin >> antivirus100;
	Antivirus antivirus101;
	antivirus101 = antivirus100--;
	Antivirus antivirus102;
	antivirus102 = --antivirus100;
	cout << antivirus100;
	cout << antivirus101;
	cout << antivirus102;

	Calculator calculator100;
	cin >> calculator100;
	cout << calculator100;

	Calculator calculator105;
	calculator105 = calculator5 + calculator3;
	cout << calculator105;

	Calculator calculator50, calculator60;
	cin >> calculator50;
	cin >> calculator60;

	(calculator50 != calculator60) ? (cout << "Ai dreptate, nu sunt egale") : (cout << "Nu ai dreptate, sunt cam egale");
	Calculator calculator1000;
	Calculator calculator1001;
	cin >> calculator1000;
	cout << calculator1000;
	calculator1001 = (!calculator1000);
	cout << calculator1001;

	Antivirus antivirus500;
	Antivirus antivirus600;
	cin >> antivirus500;
	cin >> antivirus600;
	(antivirus500 == antivirus600) ? (cout << "sunt egali") : (cout << " nu sunt egali");
	Program* programV = new Program[3];
	Antivirus* antivirusV = new Antivirus[3];
	Calculator* calculatorV = new Calculator[3];
	//CITIRE AFISARE VECTORI OBIECTE
	for (int i = 0; i < 3; i++)
	{
		cin >> programV[i];
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout<< programV[i];
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> antivirusV[i];
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << antivirusV[i];
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> calculatorV[i];
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << calculatorV[i];
		cout << endl;
	}
	 //MATRICE
	Antivirus** antivirusMAT = new Antivirus* [2];

		for (int i = 0; i < 2; i++)
	{
		antivirusMAT[i] = new Antivirus[2];
	}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> antivirusMAT[i][j];
				cout<< endl;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << i << j << endl;
				cout << antivirusMAT[i][j];
				cout << endl;
			}
		}

		delete[]programV;
		delete[]antivirusV;
		delete[]calculatorV;
		for (int k = 0; k < 2; k++)
		{
			delete[]antivirusMAT[k];
		}
		delete[]antivirusMAT;*/


		/*string* componente = new string[4]{ "Placa_Video","RAM","Proc_Intel","Placa_sunet" };
		Calculator c1(16, "Roz", 15000, true, 4, componente);
		Program* programe = new Program[2];
		cin>>programe[0];
		cin>>programe[1];

		Programator p1("Andrei", true, c1, 2, programe);
		Programator p2(p1);
		cout << p2;

		Programator p3;
		cin >> p3;
		cout << p3;

		cout << "Programatorul cu numele " << p1.getNume() << " detine urmatorul calculator : " << endl << endl;
		cout << p1.getCalculatorCuloare()<<endl<<p1.getCalculatorPret()<<endl<<p1.getCalculatorAreInternet()<<endl<<p1.getCalculatorNrComponente()<<endl << endl;
		for (int i = 0; i < p1.getCalculatorNrComponente(); i++)
		{
			cout << *(p1.getCalculatorComponente() + i) << endl;
		}
		(p1.getEsteIncepator() == true) ? (cout << "De asemenea, el este incepator, ") : (cout << "De asemenea, el nu este incepator,  ");
		cout << " este cunoscator de " << p1.getNrPrograme() << " programe, acestea fiind " << endl;
		for (int i = 0; i < p1.getNrPrograme(); i++)
		{
			cout << "Programul " << i + 1 << ". " << endl;
			cout <<p1.getPrograme()[i] << endl;
		}
		cout << " Exista in corporatie " << p1.getNrProgramatori() << " programatori activi";



		p1.setNume("Costel");
		p1.setCalculatorCuloare("VERNIL");
		p1.setCalculatorPret(666);
		p1.setCalculatorAreInternet(true);

		string* componente1 = new string[1]{"COMPONENTA"};

		p1.setCalculatorComponente(1,componente1) ;

		p1.setEsteIncepator(false);
		Program* programeNoi = new Program[1];
		cin>>programeNoi[0];
		p1.setPrograme(1,programeNoi);






		cout << "Programatorul cu numele " << p1.getNume() << " detine urmatorul calculator : " << endl << endl;
		cout << p1.getCalculatorCuloare() << endl << p1.getCalculatorPret() << endl << p1.getCalculatorAreInternet() << endl << p1.getCalculatorNrComponente() << endl << endl;
		for (int i = 0; i < p1.getCalculatorNrComponente(); i++)
		{
			cout << *(p1.getCalculatorComponente() + i) << endl;
		}
		(p1.getEsteIncepator() == true) ? (cout << "De asemenea, el este incepator, ") : (cout << "De asemenea, el nu este incepator,  ");
		cout << " este cunoscator de " << p1.getNrPrograme() << " programe, acestea fiind " << endl;
		for (int i = 0; i < p1.getNrPrograme(); i++)
		{
			cout << "Programul " << i + 1 << ". " << endl;
			cout << p1.getPrograme()[i] << endl;
		}
		cout << " Exista in corporatie " << p1.getNrProgramatori() << " programatori activi";

		Programator p4;
		cin >> p4;
		Programator p5;
		p5 = p4;
		cout << p5;

		if (p1 == p2)
		{
			cout<<"adevarat"<<endl;
		}
		else
		{
			cout<<"false" << endl;
		}
		if (p1 != p2)
		{
			cout << "adevarat" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
		if (p1 <= p2)
		{
			cout << "adevarat"<<endl;
		}
		else
		{
			cout << "false" << endl;
		}*/



		//faza 6


///*string* limbaje = new string[2]{ " Java " , " C# " };
//Program p10(10, "Gephy", 199, 2, limbaje);

//ofstream fisout("fis.txt", ios::out);
//fisout << p10;
//fisout.close();

//ifstream fisin("fis.txt", ios::in);
//Program p11;
//fisin >> p11;
//cout << p11;
//fisin.close();

//

//ofstream fisout("fis2.txt", ios::out);
//string* componente = new string[3]{ "Ecran","Monitor","Sursa" };
//Calculator c10(10, "Rosu", 1965, true, 3, componente);
//fisout << c10;
//fisout.close();

//ifstream fisin("fis2.txt", ios::in);
//Calculator c11;
//fisin >> c11;
//cout << c11;*/

///*string* componente = new string[4]{ "Placa_Video","RAM","Proc_Intel","Placa_sunet" };
//Calculator c1(16, "Roz", 15000, true, 4, componente);
//string* limbaje = new string[2]{ "C++", "C#"};
//Program* programe = new Program[2];
//cin >> programe[0];
//cin >> programe[1];

//Programator pr10("Andrei", true, c1, 2, programe);
//ofstream fisout("fis3.txt", ios::out);
//fisout << pr10;
//fisout.close();*/
//

///*Programator pr11;
//ifstream fisin("fis3.txt", ios::in);
//fisin >> pr11;
//cout << pr11;*/

///*string* limbaje = new string[3]{ "C++", "C#","Python"};
//Program p5(10, "Trojan", 345, 3, limbaje);
//p5.scrieFisBinar("fis4.bin");
//Program p6;
//p6.citesteFisBinar("fis4.bin");
//cout << p6;*/

///*string* departamente = new string[2]{ "Logistica","Front_End" };
//Antivirus a10(10, "Hero", 11.5, true, 2, departamente);
//a10.scrieFisBinar("fis5.bin");*/


///*Antivirus a5;
//a5.citesteFisBinar("fis5.bin");
//cout << a5;*/


	//faza 7
	///*int* vitezeVentilatoare = new int[3] {123, 321, 666};
	//CalculatorGaming cg1(false, 3, 150, vitezeVentilatoare);
	//cout << cg1;
	//CalculatorGaming cg2(cg1);
	//cg2.setTemperaturaSuportata(151);
	//cg2.setIluminareRGB(true);
	//cout << cg2;
	//CalculatorGaming cg3;
	//cin >> cg3;
	//cout << cg3;

	//CalculatorGaming cg4;
	//cg4 = cg3;
	//cout << cg4;

	//cout << " Calculatorul pentru gaming ";
	//(cg4.getIluminareRGB() == true) ? (cout << "are ") : (cout << "nu are ");
	//cout << "iluminare RGB" << endl;
	//cout << "Calculatorul are " << cg4.getNrVentilatoare() << " ventilatoare, acestea avand viteze de ";
	//for (int i = 0; i < cg4.getNrVentilatoare(); i++)
	//{
	//	cout << " " << *(cg4.getVitezeVentilatoare() + i) << "RPM "<< " ";
	//}
	//cout << endl << " si suporta temperatura de " << cg4.getTemperaturaSuportata()<<endl<<endl;*/



	///*string* dispozitiveTestate = new string[3]{ "S23_Ultra"," Huawei_Honor_15", "A20+" };
	//AplicatieMobil am1("TicTacToe", "Android", 3, 199, dispozitiveTestate);
	//cout << am1;
	//
	//AplicatieMobil am2(am1);
	//am2.setSistemOperare("IOS");
	//am2.setDimensiuneDescarcare(200);
	//cout << am2;
	//
	//AplicatieMobil am3;
	//am3 = am2;
	//string* dispozitivetestate2 = new string[2]{ "Iphone_15","Iphone_14_PRO" };
	//am3.setDispozitiveTestate(2, dispozitivetestate2);
	//cout << am3;

	//AplicatieMobil am4;
	//cin >> am4;
	//cout << am4;

	//cout << endl << " Aplicatia are " << am4.getNumarDescarcari() << " descarcari, foloseste sistem de operare " << am4.getSistemOperare() << " , prezinta o dimensiune de descarcare de " << am4.getDimensiuneDescarcare() << " iar dispozitivele pe care a fost testata aplicatia sunt : ";
	//for (int i = 0; i < am4.getNumarDescarcari(); i++)
	//{
	//	cout << " " << *(am4.getDispozitiveTestate() + i) << " ";

	//}*/
	//
	///*Program programobj;
	//programobj.metoda();
	//cout << endl;

	//Program* programp = new AplicatieMobil();
	//programp->metoda();
	//cout << endl;

	//Calculator calculatorobj;
	//calculatorobj.metoda();
	//cout << endl;

	//Calculator* calculatorp = new CalculatorGaming();
	//calculatorp->metoda();*/


//faza 8

//DispozitivElectronic** de = new DispozitivElectronic* [5];
//de[0] = new Calculator();
//de[1] = new CalculatorGaming();
//de[2] = new Calculator();
//de[3] = new CalculatorGaming();
//de[4] = new Calculator();
//
//for (int i = 0; i < 5; i++)
//{
//	cout << endl;
//	de[i]->porneste();
//	cout << endl;
//}
//
//cout << endl;
//
//Actualizabil** ac = new Actualizabil * [5];
//ac[0] = new Program();
//ac[1] = new AplicatieMobil();
//ac[2] = new Program();
//ac[3] = new AplicatieMobil();
//ac[4] = new Program();
//
//for (int i = 0; i < 5; i++)
//{
//	cout << endl;
//	ac[i]->verificaActualizari();
//	cout << endl;
//}
//
//Programator prg100;
//prg100[0] = new Program();
//prg100[1] = new AplicatieMobil();
//prg100[2] = new Program();
//
//prg100.intoarceDE(0) = new CalculatorGaming();
//
//for (int i = 0; i < 3; i++)
//{
//	cout << endl;
//	prg100[i]->aplicaActualizari();
//	cout << endl;
//}
//cout << endl;
//prg100.intoarceDE(0)->porneste();









////toate stergerile de alocari dinamice
//delete[]limbajefolosite;
//delete[]departamente;
//delete[]componente;
//delete[]departamente1;
//delete[]limbaje1;
//delete[]programe;
//delete[]componente1;
//delete[]programeNoi;

}
