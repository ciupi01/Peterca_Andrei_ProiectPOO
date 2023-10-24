//PETERCA ANDREI GRUPA 1049
//PROGRAM, ANTIVIRUS, CALCULATOR




#include<iostream>
using namespace std;

class Program
{
public:
	const int id;
	static string corporatie;
	string nume;
	float stocare;
	int nrLimbajeFolosite;
	string* limbajeFolosite;

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

	~Program()
	{
		if (limbajeFolosite != NULL)
		{
			delete[]this->limbajeFolosite;
		}
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
	
	static void setCorporatie(string corporatie)
	{
		Program::corporatie = corporatie;
	}
};

string Program::corporatie = "HoneyWell";

class Antivirus
{public:

	const int numar;
	static int versiune;
	string nume;
	float timpAnalizare;
	bool esteComplex;
	int nrDetinatori;
	string* departamente;

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

	Antivirus(int numar, string nume, float timpAnalizare, bool esteComplex, int nrDetinatori , string* departamente) : numar(numar)
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

	~Antivirus()
	{
		if (this->departamente != NULL)
			delete[]this->departamente;
	}

	void afisare()
	{
		cout << " Antivirusul " << nume << " are id-ul " << numar <<" ,are actualizarile aferente anului  "<< versiune << " , un timp de analizare de " << timpAnalizare << " minute " << " , ";
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
};

int Antivirus::versiune(2023);

class Calculator 
{public:
	const int id;
	static int driver;
	string culoare;
	float pret;
	bool areInternet;
	int nrComponente;
	string* componente;

	Calculator() : id(0)
	{
		this->culoare = "neagra";
		this->pret = 0;
		this->areInternet = false;
		this->nrComponente = 0;
		this->componente = NULL;

	}

	Calculator(string culoare , float pret) : id(4)
	{
		this->culoare = culoare;
		this->pret = pret;
		this->areInternet = false;
		this->nrComponente = 0;
		this->componente = NULL;
	}

	Calculator(int id , string culoare, float pret, bool areInternet, int nrComponente, string* componente) : id(id)
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

	~Calculator()
	{
		if (this->componente != NULL)
			delete[]this->componente;
	}

	void afisare()
	{
		cout << "Calculatorul " << id << " are driverele aferente anului "<< driver << ",are culoare " << culoare << " ,costa " << pret << " lei, ";
		(areInternet == true) ? (cout << " are internet ") : (cout << " nu are internet ");
		cout << " si contine " << nrComponente << " componente:";
		if (nrComponente == 0)
			cout << " - ";
		else
			for (int i = 0; i < nrComponente; i++)
				cout << "\n" << i+1 << "." << componente[i] << " ";
		cout << endl;

	}
	static void setDriver(int driver)
	{
		Calculator::driver = driver;
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
	Program program3( 5, "Creare Matrice", 100, 2, limbajeFolosite);
	program3.afisare();

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

	Calculator calculator1;
	calculator1.afisare();

	Calculator calculator2("rosie", 4000);
	calculator2.afisare();

	string* componente = new string[3];
	componente[0] = " Placa video ";
	componente[1] = " Procesor ";
	componente[2] = " Memorie RAM ";

	Calculator calculator3(100, "alba", 10000, true, 3, componente);
	//calculator3.setDriver(2024);
	calculator3.afisare();



}