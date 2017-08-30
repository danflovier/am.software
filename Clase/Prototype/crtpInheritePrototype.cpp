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

template <class Base, class SubClass>
class Clone : public Base{
	public:
		Base* clone(){
			return new SubClass(dynamic_cast<SubClass&>(*this));
		}
};

class Princesa : public Clone<Personaje,Princesa>{
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