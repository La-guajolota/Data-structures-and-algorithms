#include "lib_shapes.h"
#include <iostream>

int main(){

    double width =2, length =3;
    Shape *rectangle = new Rectangle(width,length);

    std::cout << "Rectangle width: " << width << " and length: " << length << " Area: " << rectangle->area() << " Perimeter: " << rectangle->perimeter() << std::endl;

    double radius = 10;
    Shape *circle = new Circle(radius);

    std::cout << "Circle radius: " << radius << " Area: " << circle->area() << " Perimeter: " << circle->perimeter() << std::endl;
    
    return 0;
}

/*
     Se crea un objeto dinámico de tipo Rectangle mediante el operador new. 
     La variable rectangle es un puntero que apunta al objeto creado en el montón 
     (heap). La notación Shape * indica que rectangle es un puntero a un objeto de
      tipo Shape
*/