#include <iostream>

using namespace std;

class Shape{
protected:
    int dim1, dim2;
public:
    Shape(){dim1 = 0, dim2 = 0;}
    Shape(int dim){dim1 = dim2 = dim;}
    Shape(int dim1, int dim2){
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    virtual float calculateArea() = 0;
};

class Circle:public Shape{
public:
    Circle():Shape(){}
    Circle(int dim):Shape(dim){}
    float calculateArea(){
        return(3.14*dim1*dim2);
    }
};
class Traingle:public Shape{
public:
    Traingle():Shape(){};
    Traingle(int dim1, int dim2):Shape(dim1, dim2){}
    float calculateArea(){
        return(0.5*dim1*dim2);
    }
};
class Rectangle:public Shape{
public:
    Rectangle():Shape(){};
    Rectangle(int dim1, int dim2):Shape(dim1, dim2){}
    float calculateArea(){
        return(dim1*dim2);
    }
};
class Square:public Rectangle{
public:
    Square():Rectangle(){}
    Square(int dim):Rectangle(dim, dim){}
};

class GeoShape{
    Shape* ptr[4];


public:
    GeoShape(Shape *pc, Shape *pt, Shape *pr, Shape *ps){
        ptr[0] = pc;
        ptr[1] = pt;
        ptr[2] = pr;
        ptr[3] = ps;
    }

    float totalAreas(){
        float temp;
        for(int i = 0; i < 4; i++){
            temp += ptr[i]->calculateArea();
        }
        return temp;
    }
};

int main(){
    Circle c(5);
    Traingle t(5,10);
    Rectangle r(5,10);
    Square s(5);

    GeoShape g(&c,&t,&r,&s);
    cout << g.totalAreas() <<endl;

    return 0;
}
