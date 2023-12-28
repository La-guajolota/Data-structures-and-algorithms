class FOCO{
    private://ESTADOS

        //Class variables
        static int TotalBulbCount;

        //Varibes de las instancias
        bool isON;

    public:
        //Constructor
        FOCO();

        // Class Method
        static int getBulbCount();

        //Instance method
        virtual void turnON();
        virtual void turnOFF();
        virtual bool isONFun();
};

FOCO::FOCO(){//Inicializa el objeto
    isON = false;
    TotalBulbCount++;
}

int FOCO::getBulbCount(){
    return TotalBulbCount;
}

void FOCO::turnON(){
    isON = true;
}

void FOCO::turnOFF(){
    isON = false;
}

bool FOCO::isONFun(){
    return isON;
}
