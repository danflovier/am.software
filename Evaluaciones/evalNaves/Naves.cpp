/*
 -- EXAMEN 2 PARCIAL --

 - Nombre: Daniela Flores
 - ID: A01023226

 - NOTA: Usar -std=c++11
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#define SIZE 8
#define NUMBER_OBJECTS 7

using namespace std;

template <class T> 
class Iterator; 


/******** Clase Collection ********/
template <class T> 
class Collection{
	protected:
		T* array;
		int size;
		int cont;

	public: 
		friend class Iterator<T>;

		Collection(){
			size = NUMBER_OBJECTS;
			cont = 0;
			array = new T[size];
		}

		void addElement(T value){
			if (cont <= size){
				array[cont++] = value;
				return;
			}
			else{
				cout << "\nYa no hay espacio para agregar elementos" << endl;
			}
		}

		Iterator<T>* getIterator();

		T at(int pos){
			return array[pos];
		}
};

/******** Clase Iterator ********/
template <class T> 
class Iterator{
	protected:
		Collection<T> coll;
		int cont = 0;

	public:
		Iterator(const Collection<T>& coll) : coll(coll){}
	
		bool hasNext(){
			if (cont < coll.cont)
				return true;
			return false;
		}

		T Next(){
			return coll.at(cont++);
		}
};

template <class T> 
Iterator<T>* Collection<T>:: getIterator(){
	return new Iterator<T>(*this);
}

/******** Clase Galaxia********/
class Galaxia{
	protected:
		Galaxia() = default;
  		static Galaxia* instance;
  		
	public:
		// Implementacion del Singleton
		static Galaxia* getInstance(){
			if(!instance) 
				instance = new Galaxia;
				
    			return instance;  		
    		}
    	// Implementación del factoryMethod
    	template<class T>
    	T* factoryMethod(){
    		T *grafico = new T;
    		
			return grafico;
		}
};

/******** Clase Gráfico ********/
class Grafico{
	
	public:
		int id;
		int Xi;
		int Yi;
		string nombre;
		bool flag = true;

		Grafico() = default;

		// Métodos para el acceso a los atributos
		string getNombre(){ return nombre; }
		int getX(){ return Xi; }
		int getY(){ return Yi; }
		bool getFlag(){ return flag; }
		
		void graficoColisionado(){ flag = false; }

		// Notificación para las colisiones generadas
		void notificar(int x, int y, Iterator<Grafico*> it){
    		while(it.hasNext()) {
      			cout << endl << "\t::ALERTA:: " << it.Next()->nombre << ": Colisión de " << nombre 
      			     << " observada en [ "<< x << " , " << y << " ] ";
      			it.Next();
    		}
  		}
};


/********** Spacecraft **********/
class Spacecraft : public Grafico{
	protected:
		Spacecraft() = default;
};

class PlanetExplorationShips : public Spacecraft{
	friend class Galaxia;
	protected:
		PlanetExplorationShips(){
			nombre = "Exploration Sh";
		}
};

class ColonizationShips :  public Spacecraft{
	friend class Galaxia;
	protected:
		ColonizationShips(){
			nombre = "Colonization S";
		}
};

class PlanetObservationShips : public Spacecraft{
	friend class Galaxia;
	protected:
		PlanetObservationShips(){
			nombre = "Observation Sh";
		}
};

/********** Asteroids ***********/
class Asteroid : public Grafico{
	protected:
		Asteroid() = default;
};

class StonyMeteorites : public Asteroid{
	friend class Galaxia;
	protected:
		StonyMeteorites(){
			nombre = "Stony Meteorit";
		}
};

class IronMeteorites : public Asteroid{
	friend class Galaxia;
	protected:
		IronMeteorites(){
			nombre = "Iron Meteorite";
		}
};

/************ Planets ***********/
class Planet : public Grafico{
	protected:
		Planet() = default;
};

class DesertPlanet : public Grafico{
	friend class Galaxia;
	protected:
		DesertPlanet(){
			nombre = "Desert Planets";
		}
};

class EarthAnalog : public Grafico{
	friend class Galaxia;
	protected:
		EarthAnalog(){
			nombre = "Earth Analogss";
		}
};



class Juego{
	
	protected:
		int cont = 1;
		int t = 0;
		int tablero[SIZE][SIZE] = {{0}};
		
	public:
		Juego(){}
		vector<Grafico*> graficos;
		Collection<Grafico*> i; // Observer
		Iterator<Grafico*> *it; // iterator
		
		void crearJuego(){
			Galaxia* galaxia = Galaxia::getInstance();
			Juego* juego = galaxia->factoryMethod<Juego>();

			cout << endl << "\t..:: Posiciones iniciales ::.." << endl;
			cout << "\t\t\t     [X , Y]" << endl;
			
			// Galaxia tiene Spacecrafts
			PlanetExplorationShips* p1 = galaxia->factoryMethod<PlanetExplorationShips>();
			ColonizationShips* p2 = galaxia->factoryMethod<ColonizationShips>();
			PlanetObservationShips* p3 = galaxia->factoryMethod<PlanetObservationShips>();
			
			// Galaxia tiene Asteroides
			StonyMeteorites* p4 = galaxia->factoryMethod<StonyMeteorites>();
			IronMeteorites* p5 = galaxia->factoryMethod<IronMeteorites>();
	
			// Galaxia tiene Planetas
			DesertPlanet* p6 = galaxia->factoryMethod<DesertPlanet>();
			EarthAnalog* p7 = galaxia->factoryMethod<EarthAnalog>(); 
			juego->agregarGrafico(p1);
			juego->agregarGrafico(p2);
			juego->agregarGrafico(p3);
			juego->agregarGrafico(p4);
			juego->agregarGrafico(p5);
			juego->agregarGrafico(p6);
			juego->agregarGrafico(p7);

			cout << "\n\t..:: TABLERO INICIAL::..";
			juego->imprimirTablero();

			cout << "\n\t....:::: PARTIDAS ::::....";
			juego->empezar();
		}

		// Agrega el gráfico al tablero del juego
		void agregarGrafico (Grafico* g){
			it = i.getIterator();
			g->Xi = rand() % SIZE;
			g->Yi = rand() % SIZE;

			// Evitar colisiones al principio y tener los 7 gráficos
			if (tablero[g->getX()][g->getY()] != 0){
				g->Xi = rand() % SIZE;
				g->Yi = rand() % SIZE;
				g->Xi = rand() % SIZE;
				g->Yi = rand() % SIZE;
			}
			// Asigno lugar al gráfico en el tablero con 1
			tablero[g->getX()][g->getY()] = 1;
			// Asigno un ID
			g->id = cont;
			// Agrego al vector
			graficos.push_back(g);
			// Agrego al observer
			i.addElement(g);
			// Imprime los objetos iniciales con sus valores respectivos
			cout << "\t" << g->getNombre() << "\t"  << g->id << " -> " 
				 << "("  << g->getX() << " , " << g->getY() << ")" << endl;
			cont++;
		}

		// Start del juego
		void empezar(){
			while (t < NUMBER_OBJECTS - 1){
				jugar();
			}
			cout << endl << "\tFIN: El juego ha terminado" << endl;
		}
		
		// Mecánica del juego
		void jugar(){
			int opc;

			//cout << "\t NOMBRE \t\t   INI   FIN";
			for (int i = 0; graficos.size()>i; i++) {
				// Corremos el juego si el status de la bandera es true
				if (graficos.at(i)->getFlag()){
					//cout << endl;
					// Notificamos si hubo colisión
					if (tablero[graficos.at(i)->getX()][graficos.at(i)->getY()] == -1){
						graficos.at(i)->graficoColisionado();
						graficos.at(i)->notificar(graficos.at(i)->getX(),graficos.at(i)->getY(),*it);
      					t++;
      					break;
      				}
      				
      				else{
      					cout << endl << "\tI " << graficos.at(i)->getNombre() << " " 
      					     << "[" << graficos.at(i)->getX() << "," << graficos.at(i)->getY() << "]";
      					
      					// Eliminamos posición inicial del gráfico para moverlo
      					tablero[graficos.at(i)->getX()][graficos.at(i)->getY()] = 0;
      					
      					//Elegimos al azar un movimiento
      					opc = 1 + rand() % ((4 + 1) - 1);
      					switch (opc){
      						case 1: 
      							// Derecha (RIGHT)
      							if (graficos.at(i)->Xi < SIZE && tablero[graficos.at(i)->getX() + 1][graficos.at(i)->getY()] != -1 ){
      								//cout << "→" << " "; 
      								graficos.at(i)->Xi++;
      							}

      						case 2:
      							// Izquierda (LEFT)
      							if (graficos.at(i)->Xi != 0 && tablero[graficos.at(i)->getX() - 1][graficos.at(i)->getY()] != -1) { 
      								//cout << "←" << " "; 
      								graficos.at(i)->Xi--; 
      							}

      						case 3:
      							// Abajo (DOWN)
      							if (graficos.at(i)->Yi < SIZE && tablero [graficos.at(i)->getX()][graficos.at(i)->getY() + 1] != -1){
									//cout << "↓" << " "; 
      								graficos.at(i)->Yi++;
      							}

        					case 4: 
        						// Arriba (UP)
        						if (graficos.at(i)->Yi != 0 && tablero[graficos.at(i)->getX()][graficos.at(i)->getY() - 1] != -1) { 
        							//cout << "↑" << " ";
        							graficos.at(i)->Yi--; 
        						}
      					}
      					
      					// Determinamos si el movimiento del gráfico cayó en una posición válida
      					if (tablero[graficos.at(i)->getX()][graficos.at(i)->getY()] == 0){
      						tablero[graficos.at(i)->getX()][graficos.at(i)->getY()] = 1;
      					}
      					else{
      						// Notificamos colisión
      						tablero[graficos.at(i)->getX()][graficos.at(i)->getY()] = -1;
      						graficos.at(i)->graficoColisionado();
      						graficos.at(i)->notificar(graficos.at(i)->getX(),graficos.at(i)->getY(),*it);
      						t++;
      					}
      					cout << endl << "\tF " << graficos.at(i)->getNombre() << " " 
      						 << "[" << graficos.at(i)->getX() << "," << graficos.at(i)->getY()<< "]";	
      				} 
      			} 
      		}
      		//cout << endl;
      		imprimirTablero();
      	}

		// Imprime tablero
		void imprimirTablero(){
			cout << endl;
			cout << endl << "\t(x)0  1  2  3  4  5  6  7" << endl;
			cout << "\t---------------------------" << endl;
			for (int j = 0; j < SIZE; j++) {
				cout << "\t" << j <<"|";
            	for (int i = 0; i < SIZE; i++) {
            		cout << " " << tablero[i][j] << " ";
            	}
            	cout << "|" << endl;
        	}
        	cout << "\t---------------------------" <<endl;
    	}
};


Galaxia* Galaxia::instance = 0;

int main(){
	srand(time(NULL));
	
	Juego* juego;
	juego->crearJuego();

	return 0;
}