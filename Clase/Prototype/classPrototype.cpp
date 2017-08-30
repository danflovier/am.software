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

class Princesa : public Personaje{
	public:
		Princesa(string n): Personaje(n){}
		Princesa(const Princesa& p){
			nombre = p.nombre;
			telefono = p.telefono;
			mundo = new Mundo(p.mundo->nombre_mundo);
			correo = p.correo;
		}
		
		void grita(){
			cout << "AHHHHHH" << endl;
		}

		Personaje* clone(){
			//Manda llamar el copy construct para la copia de valores
			return new Princesa(*this); 
		}
};

class Villano : public Personaje{
	public:
		Villano(string n): Personaje(n){}
		Villano(const Villano& v){
			nombre = v.nombre;
			telefono = v.telefono;
			mundo = new Mundo(v.mundo->nombre_mundo);
			correo = v.correo;
		}

		void secuestra(){
			cout << "Te atrapé" << endl;
		}

		Personaje* clone(){
			return new Villano(*this); 
		}
};

class Heroe : public Personaje{
	public:
		Heroe(string n): Personaje(n){}
		Heroe(const Heroe& h){
			nombre = h.nombre;
			telefono = h.telefono;
			mundo = new Mundo(h.mundo->nombre_mundo);
			correo = h.correo;
		}

		void salvar(){
			cout << "Yo te rescataré" << endl;
		}

		Personaje* clone(){
			return new Heroe(*this); 
		}
};

int main(){
	Princesa* pri = new Princesa("Rapunzel");
	pri->correo = "princesitamoribunda@tec.mx";
	pri->telefono = 53470196;
	pri->mundo = new Mundo("Paleta");

	Princesa* p = dynamic_cast < Princesa* > (pri->clone()); // --> DownCasting (del padre al hijo)
	
	pri->nombre ="RAPUNZEL";
	pri->mundo->nombre_mundo="Paletón";

	cout << p->nombre << endl;
	cout << p->correo << endl;
	cout << p->telefono << endl;
	cout << p->mundo << endl;

}