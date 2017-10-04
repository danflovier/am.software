#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Subject{
    //Lets keep a track of all the shops we have observing

   vector<Observer*> list;

   /*
   vector<Mvs*> mvs;
   vector<Televisa*> televisa;
   vector<RadioReal*> radioreal;
   vector<NoticiasInternacionales*> notinter;
	*/

public:
    void Attach(Observer* observer){
    	list.push_back(observer);
    }
    void Detach(Observer* observer){
    	list.erase(remove(list.begin(), list.end(), observer), list.end());    
    }

    void Notificar(string anuncio){
    	for(vector<Observer*>::const_iterator iter = observers.begin(); iter != observers.end(); ++iter){
        	if(*iter != 0){
            	(*iter)->publica(anuncio);
        	}
        }

    }
};


class Trump : public Subject{
public:
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};

class Pena : public Subject{
public:
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};

class KimJongUn : public Subject{
public:
    void Anuncia(string anuncio){
    	Notificar(anuncio);
    }
};


class Observer{
	Subject* anuncio;

	public:
    	virtual void publica(string anuncio) = 0;
};


class Mvs : Observer{
    string anuncio;

	public:
    	Mvs() = default;
    	void publica(string anuncio){
    		Trump trump = new Trump;
    	}       
};

class Televisa : Observer{
    string anuncio;

	public:
    	Televisa() = default;
    	void publica(string anuncio){
    		anuncio = an;
    		Trump trump = new Trump;
    		trump.Anuncia()
    		Pena pena = new Pena;
    	}          
};

class RadioReal : Observer{
    string anuncio;

	public:
    	RadioReal() = default;
    	void publica(string an){
    		anuncio = an;
    		Trump trump = new Trump;
    		Pena pena = new Pena;
    	}        
};

class NoticiasInternacionales : Observer{
     string anuncio;

	public:
    	NoticiasInternacionales() = default;
    	void publica(string an){
    		anuncio = an;
    		Trump trump = new Trump;
    		KimJongUn kimjongun = new KimJongUn;
    	}     
};

