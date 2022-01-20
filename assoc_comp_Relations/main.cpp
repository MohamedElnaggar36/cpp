#include <iostream>
#include <cstdlib>

using namespace std;

class Point{
private:
    int x, y;

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x){
        this->x = x;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    int getX(){return x;}
    int getY(){return y;}

};

class Rectangle_Asoc{
    Point *p1;
    Point *p2;
    int length;
    int width;

public:
    Rectangle_Asoc(){
        p1 = p2 = NULL;
        length = 0;
        width = 0;
    }
    void setP1(Point *p){
        p1 = p;
        if(p1 != NULL && p2 != NULL){
            length = abs(p1->getX() - p2->getX());
            width = abs(p1->getY() - p2->getY());
        }
        else{
            length = width = 0;
        }
    }
    void setP2(Point *p){
        p2 = p;
        if(p1 != NULL && p2 != NULL){
            length = abs(p1->getX() - p2->getX());
            width = abs(p1->getY() - p2->getY());
        }
        else{
            length = width = 0;
        }
    }
    int area(){
        return (length * width);
    }
};

class Rect_comp{
    Point p1;
    Point p2;
    int length;
    int width;
public:
        Rect_comp(){
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
        length = width = 0;
    }
    Rect_comp(int x1, int y1, int x2, int y2){
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        length = (x2 - x1);
        width = (y2 - y2);
    }

    void setP1(int a, int b){
        p1.setX(a);
        p1.setY(b);
        length = abs(p2.getX() - a);
        width = abs(p2.getY() - b);

    }
    void setP2(int a, int b){
        p2.setX(a);
        p2.setY(b);
        length = abs(p1.getX() - a);
        width = abs(p1.getY() - b);

    }
    int area(){
        return (length * width);
    }

};
int main()
{
    Rectangle_Asoc rect;
    Point p1(10, 10);
    Point p2(5, 5);
    rect.setP1(&p1);
    rect.setP2(&p2);
    cout << "Area of rectangle using association: ";;
    cout << rect.area() << endl;

    Rect_comp comp;
    comp.setP1(10, 10);
    comp.setP2(5, 5);
    cout << "Area of rectangle using composition: ";
    cout << comp.area();

    return 0;
}
