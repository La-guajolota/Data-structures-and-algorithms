class FOCO{
    private://ESTADOS
        //Varibes de las instancias
        bool isON;
    public:
        //Constructor
        FOCO();

        //Metodos
        virtual void turnON();
        virtual void turnOFF();
        virtual bool isONFun();
}