#include  <iostream>
#include <cmath>

using namespace std;
const double PI = 3.14159265;

class polar_c {
private:
	double raduis;
	double degree;
public:
	polar_c() : raduis(0.0), degree(0.0) {}
	polar_c(double r, double d) : raduis(r), degree(d) {}

	void get_coordinates() {
		cout << "Enter radius: ";
		cin >> raduis;
		cout << "Enter degree: ";
		cin >> degree; cout << endl;
	}

	void show_coordinates() const {
		cout << "Polar coordinates: \nRadius " << raduis << "\nDegree: " << degree << "\n\n";
	}

	polar_c operator+(polar_c) const; // adding polar coordinates
};

int main() {
	polar_c p1, p2, p3;
	p1.get_coordinates();
	p2.get_coordinates();

	p3 = p1 + p2;
	p3.show_coordinates();

	return 0;
}

polar_c polar_c::operator+(polar_c p2) const {
	polar_c p;
	double x1, y1, x2, y2, x, y, r, a, tg_a;

	x1 = raduis * cos(degree * PI / 180); // convert degrees to radians using PI/180
	y1 = raduis * sin(degree * PI / 180);
	x2 = p2.raduis * cos(p2.degree * PI / 180);
	y2 = p2.raduis * sin(p2.degree * PI / 180);

	// find radius
	x = x1 + x2;
	y = y1 + y2;
	r = sqrt(x * x + y * y); 
	
	// find degrees
	tg_a = y / x;
	a = atan(tg_a) * 180 / PI; // convert radians to degrees using 180/PI
	if (a < 0) a = 360 - a;

	return polar_c(r, a);
}