/*
Nombre: Daniela Flores
ID: A01023226
*/
#include <iostream>

using namespace std;

class Computadora{
	protected:
		Computadora(){}

		string tipo;
		float ram;
		string procesador;
		string motherboard;
		string hard_disk;

	public:
		virtual ~Computadora(){}
		void select_de_componentes(){
			cout << "\n\t-Componentes de " << tipo;
			cout <<"\n\t   ---RAM:";
			cin >> ram;
			cout <<"\t   ---Procesador:";
			cin >> procesador;
			cout <<"\t   ---Motherboard:";
			cin >> motherboard;
			cout <<"\t   ---Hard disk:";
			cin >> hard_disk;

		}
		void ensam_de_componentes(){
			cout << "\n\t-Ensamble de " << tipo << " programado.";
		}
		void insconfig_software(){
			cout << "\n\t-Software de " << tipo << " programado";
		}
		void empaquetado_computador(){
			cout << "\n\t-Empaquetado de " << tipo << " programado." << endl;
		}

};

class Crear_Computadoras{
	protected:
		Crear_Computadoras(){}
		static Crear_Computadoras* computadora;

	public:
		
        // Implementacion del Singleton
        static Crear_Computadoras* crear(){
			if (!computadora){
				computadora = new Crear_Computadoras;
			}
			return computadora;
		}

		// Implementacion de FactoryMethod
        template<class Tipo>
        Tipo* Crear_c(){
            return new Tipo;
        }
};

// Clonacion
template<class Tipo>
class Clonar : public Computadora{
	protected:
		Clonar(){}

	public:
		Computadora * clone(){
			return new Tipo(dynamic_cast<Tipo&>(*this));
		}
};

class Desktop : public Clonar<Desktop>{
	
	friend class Crear_Computadoras;
	
	private:
		Desktop(){
			tipo = "Desktop";
		}

};

class Laptop : public Clonar<Laptop>{
	
	friend class Crear_Computadoras;
	
	private:
		Laptop(){
			tipo = "Laptop";
		}

};

class Netbook : public Clonar<Netbook>{
	
	friend class Crear_Computadoras;
	
	private:
		Netbook(){
			tipo = "Netbook";
		}

};

class Tablet : public Clonar<Tablet>{
	
	friend class Crear_Computadoras;
	
	private:
		Tablet(){
			tipo = "Tablet";
		}

};

class Rack : public Clonar<Rack>{
	
	friend class Crear_Computadoras;
	
	private:
		Rack(){
			tipo = "Server_Rack";
		}

};

class Tower : public Clonar<Tower>{
	
	friend class Crear_Computadoras;
	
	private:
		Tower(){
			tipo = "Server_Tower";
		}
};