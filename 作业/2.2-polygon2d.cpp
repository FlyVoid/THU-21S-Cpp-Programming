#include <iostream>
#include <cmath>
using namespace std;

class Polygon2D{
public:
	Polygon2D(double len1);
	virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Polygon2D(){}
protected:
	double len1; 
};
Polygon2D::Polygon2D(double k): len1(k){ }

//三角形
class Triangle2D: public Polygon2D{
public:
    Triangle2D(double len1, double len2, double len3);
    double area();
    double perimeter();
    ~Triangle2D(){}
protected:
    double len2;     //成员为三角形三条边的长度 
    double len3;
};

Triangle2D::Triangle2D(double a, double b, double c): Polygon2D(a), len2(b),len3(c){ }
double Triangle2D::area(){
    //海伦公式:由三边长求三角形面积
	double p = (len1 + len2 + len3)/2;
	return sqrt((p*( p - len1 )*( p - len2 )*( p - len3 ))); 
}
double Triangle2D::perimeter(){ 
	return ( len1 + len2 +len3 ); 
}


//矩形 
class Rectangle2D: public Polygon2D{
public:
    Rectangle2D(double len1, double width);
    double area();
    double perimeter();
    ~Rectangle2D (){}
protected:
    double width;   //成员为长、宽 
};

Rectangle2D::Rectangle2D(double m, double n): Polygon2D(m), width(n){ }
double Rectangle2D::area(){
	double s = len1 * width;
	return s; 
}
double Rectangle2D::perimeter(){ 
	return 2* (len1 + width); 
}




int main(){
    Polygon2D *p = new Triangle2D(3.0, 4.0, 5.0);
    cout<<"The area of Triangle is "<<p->area()<<endl;
    cout<<"The perimeter of Triangle is "<<p->perimeter()<<endl;
  
    p = new Rectangle2D(11.0,11.0);
    cout<<"The area of Rectangle is "<<p->area()<<endl;
    cout<<"The perimeter of Rectangle is "<<p->perimeter()<<endl;
    return 0;
}


