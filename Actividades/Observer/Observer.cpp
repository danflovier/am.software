#include <vector>
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////
/////////// OBSERVER ///////////
///////////////////////////////
class Observer{
	public:
    	virtual void publica(string anuncio) = 0;
};


class Mvs : public Observer{
	private:
		string noticiero;

	public:	
		Mvs(string n){ noticiero = n; }
    	void publica(string anuncio){
    		cout << "\t - Noticieros " << noticiero << ": " << anuncio << endl;
    	}       
};

class Televisa : public Observer{
	private:
		string noticiero;

	public:
		Televisa(string n){ noticiero = n; }
    	void publica(string anuncio){
    		cout << "\t - Noticieros " << noticiero << ": " << anuncio << endl;
    	}          
};

class RadioReal : public Observer{
	private:
		string noticiero;

	public:
		RadioReal(string n){ noticiero = n; }
    	void publica(string anuncio){
    		cout << "\t - Noticieros " << noticiero << ": " << anuncio << endl;
    	}
};

class NoticiasInternacionales : public Observer{
	private:
		string noticiero;

	public:
		NoticiasInternacionales(string n){ noticiero = n; }
    	void publica(string anuncio){
    		cout << "\t - Noticias " << noticiero << ": " << anuncio << endl;
    	}     
};


/////////////////////////////////
/////////// SUBJECT ////////////
///////////////////////////////
class Subject{
   vector<Observer*> list;

public:
	Subject() = default;
    void AgregarObservador(Observer* observer){
    	list.push_back(observer);
    }
    
    void Notificar(string anuncio){
    	for(int i = 0; list.size()>i; i++){
        	list[i]->publica(anuncio);
        }
    }
};

class Trump : public Subject{
public:
	Trump() = default;
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};

class Pena : public Subject{
public:
	Pena() = default;
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};

class KimJongUn : public Subject{
public:
	KimJongUn() = default;
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};

/////////////////////////////////
///////////// MAIN  ////////////
///////////////////////////////
int main(){
	// Observers
	Mvs* mvs = new Mvs("MVS");
	Televisa* televisa = new Televisa("Televisa");
	RadioReal* radioreal = new RadioReal("Radio Real");
	NoticiasInternacionales* noticiasint = new NoticiasInternacionales("Internacionales");

	// Subjects
	Trump* trump = new Trump();
	Pena* pena = new Pena();
	KimJongUn* kimjongun = new KimJongUn();


	// Relación pres-televisoras
	trump->AgregarObservador(mvs);
	trump->AgregarObservador(televisa);
	trump->AgregarObservador(radioreal);
	trump->AgregarObservador(noticiasint);
	

	pena->AgregarObservador(televisa);
	pena->AgregarObservador(radioreal);

	kimjongun->AgregarObservador(noticiasint);

	// Notificaciones - Actualizaciones
	cout << endl << "..::DONALD TRUMP::.." << endl;
	trump->Notificar("We need to build the Wall.");

	cout << endl << "..::PEÑA NIETO::.." << endl;
	pena->Notificar("No cederemos a la construcción del muro.");

	cout << endl << "..::KIM JONG UN::.." << endl;
	kimjongun->Notificar("Enviaremos misiles a Japón.");
	cout << endl;
	

	return 0;
}

