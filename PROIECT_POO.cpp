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
		this -> nrLimbajeFolosite = 0;
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

	friend float conversieGbToMb(Program p);

};
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
};

int Antivirus::versiune(2023);
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
};
int Calculator::driver(2023);

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
	cout << "\n Timp analizare (ieri:  " ;
	cout<< antivirus5.getTimpAnalizare();
	cout << " ) (azi: ";
	antivirus5.setTimpAnalizare(20);
	cout << antivirus5.getTimpAnalizare() << " )";
	cout << "\n Complexitate(1-da/0-nu) (ieri:  ";
	cout << antivirus5.getEsteComplex();
	cout << " ) (azi: ";
	antivirus5.setEsteComplex(false);
	cout << antivirus5.getEsteComplex() << " )";
	cout << "\n Departamente (ieri:  " ;
		for (int i = 0; i < antivirus5.getNrDetinatori(); i++)
	{
		cout <<" " << *(antivirus5.getDepartamente() + i);
	}
	cout << " ) (azi: ";
	string* departamente1 = new string[4]{ "HR", "BACKEND" ,"LOGISTICA","VANZARI" };
	
	antivirus5.setDepartamente(4, departamente1);
		for (int i = 0; i < antivirus5.getNrDetinatori(); i++)
		{
			cout << " "<< * (antivirus5.getDepartamente() + i);
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
	


	cout << " \n\nCalculatorul " <<  " cu id-ul " << program5.getId() << " poseda specificatiile: ";
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

	cout << program5.getStocare()<< " GB = "<< conversieGbToMb(program5)<< " MB\n";
	cout << antivirus5.getTimpAnalizare() << " min = " << conversieMinToHr(antivirus5) << " Hours \n";
	


}
