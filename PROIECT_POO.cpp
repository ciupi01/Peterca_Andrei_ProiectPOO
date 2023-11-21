//PETERCA ANDREI GRUPA 1049
//PROGRAM, ANTIVIRUS, CALCULATOR




#include<iostream>
using namespace std;

class Program
{
private:
	const int id;
	static string corporatie;
	string nume;
	float stocare;
	int nrLimbajeFolosite;
	string* limbajeFolosite;

public:
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

	Program operator++(int )
	{                                      /*post*/
		Program aux = *this;
		this->stocare = this->stocare + 34;
		return aux;
	}
	friend float conversieGbToMb(Program p);
	friend istream& operator>>(istream& in, Program& p);
	friend ostream& operator<<(ostream& out, Program p);
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

ostream& operator<<(ostream& out,  Program p)
{
	out << " Programul ";
	out << p.nume;
	out << " are id-ul ";
	out << p.id;
	out << " ,este folosit de "; out << p.corporatie;
	out << " , ocupa spatiu de ";
	out << p.stocare;
	out << " GB , iar pentru cele ";
	out << p.nrLimbajeFolosite;
	out<< " limbaje s-au folosit: ";
	if (p.nrLimbajeFolosite == 0)
	{
		out << " - ";
	}
	else
	{
		for (int i = 0; i < p.nrLimbajeFolosite; i++)
			out << "\n" << p.limbajeFolosite[i] << " ";
		out << endl;
	}
	out << endl;
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

	Antivirus operator--(int )              //post
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
		bool ok1 = false ;
		bool ok2 = false;
		int check = 0;
		if (this->nume == a.nume && this->timpAnalizare == a.timpAnalizare && this-> esteComplex == a.esteComplex && this->nrDetinatori == a.nrDetinatori)
		{
			ok1 = true;
		}
		for (int i = 0; i < this->nrDetinatori; i++)
		{
			if (this->departamente[i] == a.departamente[i])
			{
				check=check +1;
			}
		}
		if (check == this->nrDetinatori )
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
	out << " ,are versiunea aferenta anului "; out <<a.versiune;
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

class Calculator
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
		if (nrComponente > 0)
		{
			this->nrComponente = nrComponente;
			if (this->componente != NULL)
			{
				delete[]this->componente;
			}
			this->componente = new string[nrComponente];
			for (int i = 0; i < nrComponente; i++)
			{
				this->componente[i] = componente[i];
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
	/*const int id;
	static int driver;
	string culoare;
	float pret;
	bool areInternet;
	int nrComponente;
	string* componente;*/

	Calculator operator+(const Calculator& c)
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
		for (int j = this->nrComponente;j< aux.nrComponente;j++)
		{
			aux.componente[j] = c.componente[j - this->nrComponente];
		}
		return aux;
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

int main()
{
	Program program1;
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
	Antivirus** antivirusMAT = new Antivirus * [2];

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
}
