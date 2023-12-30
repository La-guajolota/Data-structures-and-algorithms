#include <iostream>

/*
You press the button turn on and the bulb start glowing. C++ does not have any
interface keyword, it just define some functions as abstract function by making it
“= 0” thereby making the whole class abstract.
*/
class BulbInterface{ //Esto es una abtract class
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool isOnFun() = 0;
};

// implements BulbInterface
class Bulb : public BulbInterface{
    private:
        // Instance Variables
        bool isOn;

    public:
        // Constructor
        Bulb();

        // Instance Method
        virtual void turnOn();
        // Instance Method
        virtual void turnOff();
        // Instance Method
        virtual bool isOnFun();
};

Bulb::Bulb(){//Inicializa el objeto
    isOn = false;
}
void Bulb::turnOn(){
    isOn = true;//Enciende
}
void Bulb::turnOff(){
    isOn = false;//Apaga
}
bool Bulb::isOnFun(){
    return isOn;//Regresa el estado del objeto foco
}

/**************************************
AdvanceBulb is sub-class of Bulb class. 
Demonstrating inheritance

AdvanceBulb is a sub-class of Bulb. When an object
of AdvanceBulb is created, all public and protected 
methods of Bulb class are also accessible to it
**************************************/
class AdvanceBulb : public Bulb{
    private:
        // Instance Variables
        int intensity;

    public:
        //Constructor
        AdvanceBulb();
        
        // Instance Method
        virtual void setIntersity(int i);
        // Instance Method
        virtual int getIntersity();
};

AdvanceBulb::AdvanceBulb(){
    intensity = 0;
}

void AdvanceBulb::setIntersity(int i){
    intensity = i;
}
int AdvanceBulb::getIntersity(){
    return intensity;
}


//APLCACIONES DE LAS CLASES
int main(){

    Bulb b;// Crea objeto b de la clase BUlb

    std::cout << "bulb is on return : " << b.isOnFun() << std::endl;
    b.turnOn();
    std::cout << "bulb is on return : " << b.isOnFun() << std::endl;

    AdvanceBulb bUP;

    std::cout << "bUP is on return : " << bUP.isOnFun() << std::endl;
    bUP.turnOn();
    std::cout << "uUP is on return : " << bUP.isOnFun() << std::endl;
    std::cout << "bUP intensity : " << bUP.getIntersity() << std::endl;
    bUP.setIntersity(25);
    std::cout << "uUP intensity : " << bUP.getIntersity() << std::endl;
    
    return 0;
}