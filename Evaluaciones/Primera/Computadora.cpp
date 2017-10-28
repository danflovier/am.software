/*
Nombre: Daniela Flores
ID: A01023226
*/

#include "Computadora.h"

Crear_Computadoras* Crear_Computadoras::computadora = 0;
void mostrar_operaciones(Computadora* computadora);

///////////////////////////////////////////////////////////////
////////////////////////// MAIN //////////////////////////////
/////////////////////////////////////////////////////////////

int main(){


	// Impl. Singleton
	Crear_Computadoras* compu = Crear_Computadoras::crear();
	
/// Creación de una laptop ///
	// Impl. FactoryMethod
	Laptop* laptop = compu->Crear_c<Laptop>();
	Computadora *computadora1 = laptop->clone();

	mostrar_operaciones(computadora1); //Operaciones de la fabrica

	//Clonación de la laptop
	// CRTP Prototype
	Laptop * laptop2 = dynamic_cast<Laptop*>(laptop->clone());

	

/// Creación de una desktop ///
	Desktop* desktop = compu->Crear_c<Desktop>();
	Computadora* computadora2 = desktop->clone();
	mostrar_operaciones(computadora2);
	Desktop* desktop2 = dynamic_cast<Desktop*>(desktop->clone());
	

/// Creación de una tablet///
	Tablet* tablet = compu->Crear_c<Tablet>();
	Computadora* computadora3 = tablet->clone();
	mostrar_operaciones(computadora3);
	Tablet* tablet2 = dynamic_cast<Tablet*>(tablet->clone());
	

	delete computadora1;
	delete laptop;

	delete computadora2;
	delete desktop;

	delete computadora3;
	delete tablet;

	return 0;
}

void mostrar_operaciones(Computadora* computadora){
	cout << "\n\t-----OPERACIONES-----";
	computadora->select_de_componentes();
	computadora->ensam_de_componentes();
	computadora->insconfig_software();
	computadora->empaquetado_computador();
}