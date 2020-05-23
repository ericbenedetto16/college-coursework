#include<iostream>
#include<cmath>
using namespace std;

double const pi = 3.14159265;
double radius(double x1, double y1, double x2, double y2);
double circumference(double radius);
double area(double radius);

int main()
{
	double x1, y1, x2, y2;
	double r;
	double c;
	double a;
	cout << "Enter 4 numbers corresponding to the";
		cout << " coordinates of two points:\n";
	cin >> x1 >> y1 >> x2 >> y2;

	r = radius(x1, y1, x2, y2);
	c = circumference(r);
	a = area(r);

	cout << "The radius is: " << r << endl;
	cout << "The circumference is " << c << endl;
	cout << "The area is " << a << endl;
	system("pause");
	return 0;
}

double radius(double x1, double y1, double x2, double y2) {
	int x = x2 - x1;
	int y = y2 - y1;
	return sqrt(pow(x, 2) + pow(y, 2));
}

double circumference(double radius) {
	return 2 * pi * radius;
}

double area(double radius) {
	return pi * pow(radius, 2);
}