#include <math.h>
#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;
class Circle
{
private:
	double radius;//radius of the circle
	double * area;//area of the circle
	double * circumference;//circumferencee of the circle
	static const double pi=3.1415;// the value of pi
public:
	Circle(){radius=0;area=new double;area=0;circumference= new double;}
	void set_rad(double rad){radius = rad;};
	double compute_area()
	{return (pi*pow(radius,2.0));}
	double compute_circumference()
	{return 2*pi*radius;}
	~Circle();
};
#endif
