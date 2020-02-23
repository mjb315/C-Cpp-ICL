// Programming II - Department of Bioengineering at Imperial College London
// 2015 Exam
// Question q6.cpp

#include <iostream>

using namespace std;

#define pi 3.14159265

// CLASS 1
class Shape
{
	public:
	Shape(int x_in = 0, int y_in = 0){
		x = x_in;
		y = y_in;
	}
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	
	protected:
		double x;
		double y;		
	
};

Shape:Shape(double x_in, double y_in){
	x = x_in;
	y = y_in;
}

class Rectangle: public Shape
{
	
	public:
		Rectangle(double x_in, double y_in, double w_in, double h_in);
		double getArea(){return h*w;};
		double getPerimeter(){return double(2*h+2*w);};
	
	protected:
		double w;								// width
		double h;								// height
		
};

Rectangle::Rectangle(int x_in, int y_in, int w_in, int h_in){
	x = x_in;
	y = y_in;
	w = w_in;
	h = h_in;
	
}
class Circle: public Shape
{
	public:
		Circle(int x_in, int y_in, int r_in);
		double getArea(){return pi*r*r;};
		double getPerimeter(){return 2*r*pi;};
		
	protected:
		double r;								// radius
};

Circle::Circle(int x_in, int y_in, int r_in){
	x = x_in;
	y = y_in;
	r = r_in;
}



int main()
{
	Shape* p_shape;
	
	Rectangle shape1(1,2,15,10);
	Circle shape2(3,2,10);

	cout << "shape 1 area:      " << shape1.getArea() << endl;
	cout << "shape 1 perimeter: " << shape1.getPerimeter() << endl;
	cout << "shape 2 area:      " << shape2.getArea() << endl;
	cout << "shape 2 perimeter: " << shape2.getPerimeter() << endl;
	
	p_shape = &shape1;
	cout << "shape 1 area:      " << p_shape->getArea() << endl;
	cout << "shape 1 perimeter: " << p_shape->getPerimeter() << endl;
	
	p_shape = &shape2;
	cout << "shape 2 area:      " << p_shape->getArea() << endl;
	cout << "shape 2 perimeter: " << p_shape->getPerimeter() << endl;
	
	return 0;
}