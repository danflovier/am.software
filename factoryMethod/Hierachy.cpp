/*
Name: Daniela Flores Javier
ID: A01023226
*/

#ifndef PRODUCTH_
#define PRODUCTH_

#include <iostream>

using namespace std;

class Product{
    public:
        void operation(){
            cout << "Estoy en operacion1" << endl;
        }
    
        void operation2(){
            cout << "Estoy en operacion2" << endl;
        }
};

class Creator{
    private:
        virtual Product* createProduct(int type) = 0;
        
    public:
        Product* factoryMethod(int type){
            Product *p = createProduct(type);
            p->operation();
            return p;
        }
};

class CreatorA : public Creator{
    public:
        Product* createProduct(int type){
            if (type == 1){
                return new Product;
            }
        }
};

#endif

int main(){
    //Create debería ser un singleton
    //Creator concretos con constructor privado
    Creator* c = new CreatorA;
    Product* p = c->factoryMethod(1);
    p->operation2();
    
    delete p;
    delete c;
}