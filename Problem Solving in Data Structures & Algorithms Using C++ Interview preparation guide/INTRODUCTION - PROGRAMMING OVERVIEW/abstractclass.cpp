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


int main(){

    Bulb b;// Crea objeto b de la clase BUlb

    std::cout << "bulb is on return : " << b.isOnFun() << std::endl;
    b.turnOn();
    std::cout << "bulb is on return : " << b.isOnFun() << std::endl;

    return 0;
}