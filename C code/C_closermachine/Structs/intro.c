#include <stdio.h>

/*
    The struct declaration doesn’t allocate memory for the struct and its doesn’t
    create an instance of the struct that you can use. What it does is to create a
    struct type called myStruct, which can be used in a variable declaration just
    like int.
*/
struct myStruct
{
    char name[25];
    int age;
};

// No solo se declaro la estructur apero se creo una instacnia a la vez llamada Yoko_original
struct Yoko
{
    int num;
} Yoko_original;

struct
{
    char fabricante[25];
    unsigned char timers;
    unsigned char adcs;
} ESP32, Psoc5lp, RasberPico;

int main()
{
    struct myStruct me = {"Adrián", 21}; // Creamos una instancia de la estructrura

    Yoko_original.num = 1; // Yoko es la primera

    /*
        Podemos utilizar las instancia de los
        microcontroladores, pero no podemos crear nuevas
        yas que nunca se especificó el nombre de este
        tipo de dato
    */
    // !ESP32.fabricante = "ESPRESIFF";

    struct myStruct people[25]; // Array de datos mystruct
    people[7].age = 99;         // La septima persona tiene 77 años

    return 0;
}