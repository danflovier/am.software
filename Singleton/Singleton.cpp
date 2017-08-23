/*
Name: Daniela Flores Javier
ID: A01023226
*/

#ifndef SINGLETONH_
#define SINGLETONH_

#include <iostream>

using namespace std;

class Singleton{
    public:
        static Singleton* getInstance();
        void operation();
        
    protected:
        static Singleton* instance;
        
    private:
        Singleton(){}
};
#endif

Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance(){
    if (!instance){
        instance = new Singleton;
    }
    return instance;
}

void Singleton::operation(){
    cout << "Dirección de Singleton: " << instance << endl;
}

int main(int arg, char** argv){
    Singleton* instance1 = Singleton::getInstance();
    instance1->operation();
    
    Singleton* instance2 = Singleton::getInstance();
    instance2->operation();
    
    Singleton* instance3 = Singleton::getInstance();
    instance3->operation();
    
    return 0;
}