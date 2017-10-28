#include <iostream>

using namespace std;

// Forward Declaration. Avisar que voy a usar la clase pa usarla 
// Uso de apuntaores. 
template <class T> 
class IntIterator; 

template <class T> 
class IntCollection{
	protected:
		T* array;
		int size;
		int cont;

	public: 
		friend class IntIterator<T>;

		IntCollection(){
			size = 10;
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

		IntIterator<T>* getIterator();

		T at(int pos){
			return array[pos];
		}
};

template <class T> 
class IntIterator{
	protected:
		IntCollection<T> coll;
		int cont = 0;

	public:
		IntIterator(const IntCollection<T>& coll) : coll(coll){}
	
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
IntIterator<T>* IntCollection<T>:: getIterator(){
	return new IntIterator<T>(*this);
}

template<class T>
bool pares(T n){
    if (n % 2 == 0){
        cout << "\nES PAR" << endl;
    	return 1;
    }
    else{
        cout << "\nES IMPAR" << endl;
    	return 0;
    }

}

template<class T, class F>
void find_if(IntIterator<T> i, F func){
   
    while (i.hasNext()){
		T n = i.Next();
		func(n);
	}
    
}

int main(){
	/*
	IntCollection<string> i;
	i.addElement("a");
	i.addElement("b");
	i.addElement("c");
	i.addElement("d");

	IntIterator<string>* it = i.getIterator();
	while (it->hasNext()){
		cout << it->Next() << endl;
	}
	*/

	IntCollection<int> i;
	i.addElement(4);
	i.addElement(1);
	i.addElement(2);
	i.addElement(3);

	IntIterator<int>* it = i.getIterator();
	while (it->hasNext()){
		cout << it->Next() << endl;
	}

	IntIterator<int>* ite = i.getIterator();
	//funcion<entero,tipofuncion&tipo_recibe> (*parametro, nombre_funcion)
	find_if<int,bool(&)(int)>(*ite,pares<int>);

	delete it;

	return 0;

}