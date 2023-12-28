#ifndef lib_shapes_H
#define lib_shapes_H

#include <cmath>

/*
    Shape is an abstract class. And its instance cannot be created. Those classes,
    which extend it, need to implement these two functions to become concrete class
    whose instances can be created.
*/
//Abstract class
class Shape{
    public:
        //Abstract methods
        virtual double area() = 0;
        virtual double perimeter() = 0;
};

/*
    Circle is a class which extends shape class and implement area() 
    and perimeter() methods.
*/
class Circle : public Shape{
    private:
        double radius = 0;
    
    public:
        //Contructers
        Circle();
        Circle(double r);

        //Instances' methods
        virtual void setRadius(double r);
        virtual double area() override;
        virtual double perimeter() override;
};

Circle::Circle():
    Circle(1)//Inicializa al objeto con radio 1
{}

Circle::Circle(double r){
    radius = r;
}

void Circle::setRadius(double r){
    radius = r;
}

double Circle::area(){
    return M_PI*std::pow(radius,2);
}

double Circle::perimeter(){
    return 2 * M_PI * radius;
}

class Rectangle : public Shape{
    private:
        double width = 0, length = 0;
    public:
        //Constructs
        Rectangle();
        Rectangle(double w, double l);

        //methods
        virtual void setWidth(double w);
        virtual void setLength(double l);
        virtual double area() override;
        virtual double perimeter() override;
};

Rectangle::Rectangle() :
    Rectangle(1, 1)
{ }

Rectangle::Rectangle(double w, double l){
    width = w;
    length = l;
}
void Rectangle::setWidth(double w){
    width = w;
}

void Rectangle::setLength(double l){
    length = l;
}

double Rectangle::area(){
    return width * length; // Area = width * length
}

double Rectangle::perimeter(){
    return 2 * (width + length); // Perimeter = 2(width + length)
}

#endif  