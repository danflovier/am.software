/*
Nombre: Daniela Flores
ID: A01023226
*/
#include <iostream>
#include <string>

using namespace std;

class Mundo{
public:
	Mundo(string nombre_mundo): nombre_mundo(nombre_mundo){}
	string nombre_mundo;
};

class Personaje{
	public:
		Personaje() = default;
		Personaje(string nombre): nombre(nombre){}
		
		virtual Personaje* clone() = 0;
		
		string nombre;
		int telefono;
		Mundo* mundo;
		string correo;
};

template<class SubClase>
class ClonPersonaje : public Personaje{
	public:
		Personaje* clone(){
			return new SubClase(dynamic_cast<SubClase&>(*this)); 
		}
};

class Princesa : public ClonPersonaje<Princesa>{
	public:
		Princesa(string n){
			nombre = n;
		}
		Princesa(const Princesa& p){
			nombre = p.nombre;
			telefono = p.telefono;
			mundo = new Mundo(p.mundo->nombre_mundo);
			correo = p.correo;
		}
		
		void grita(){
			cout << "AHHHHHH" << endl;
		}

};

class Villano : public ClonPersonaje<Villano>{
	public:
		Villano(string n){
			nombre = n;
		}
		Villano(const Villano& v){
			nombre = v.nombre;
			telefono = v.telefono;
			mundo = new Mundo(v.mundo->nombre_mundo);
			correo = v.correo;
		}
		
		void secuestra(){
			cout << "Te atrapé" << endl;
		}

};

class Heroe : public ClonPersonaje<Heroe>{
	public:
		Heroe(string n){
			nombre = n;
		}
		Heroe(const Heroe& h){
			nombre = h.nombre;
			telefono = h.telefono;
			mundo = new Mundo(h.mundo->nombre_mundo);
			correo = h.correo;
		}

		void salvar(){
			cout << "Yo te rescataré" << endl;
		}

};

int main(){
	Princesa* pri = new Princesa("Rapunzel");
	pri->correo = "princesitamoribunda@tec.mx";
	pri->telefono = 53470196;
	pri->mundo = new Mundo("Paleta");

	Princesa* p = dynamic_cast <Princesa*>(pri->clone()); // --> DownCasting (del padre al hijo)
	
	pri->nombre ="RAPUNZEL";
	pri->mundo->nombre_mundo="Paletón";

	cout << p->nombre << endl;
	cout << p->correo << endl;
	cout << p->telefono << endl;
	
	Princesa* pp = dynamic_cast<Princesa*>(p->clone());
	pp->mundo->nombre_mundo = "Paletita";
}
