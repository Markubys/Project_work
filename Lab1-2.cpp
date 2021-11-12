#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;


int main()
{
	float x0 = 0, y0 = 0, R = 0, a = 0, b = 0, D = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;
	cout << "R=";
	cin >> R;
	cout << "y=ax+b" << "\n";
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	D = (2 * a * b - 2 * a * y0 - 2 * x0) * (2 * a * b - 2 * a * y0 - 2 * x0) - 4 * (1 + a * a) * (x0 * x0 + b * b + y0 * y0 - 2 * b * y0 - R * R);
	if (D < 0) {
		cout << "There is no intersection";
	}
	if (D == 0) {
		x1 = (-2 * a * b + 2 * a * y0 + 2 * x0) / (2 * (1 + a * a));
		y1 = a * x1 + b;
		cout << "A straight line intersects a circle a point " << x1 << " " << y1;
	}
	if (D > 0) {
		x1 = ((-2 * a * b + 2 * a * y0 + 2 * x0) + sqrt((2 * a * b - 2 * a * y0 - 2 * x0) * (2 * a * b - 2 * a * y0 - 2 * x0) - 4 * (1 + a * a) * (x0 * x0 + b * b + y0 * y0 - 2 * b * y0 - R * R))) / (2 * (1 + a * a));
		y1 = a * x1 + b;
		x2 = ((-2 * a * b + 2 * a * y0 + 2 * x0) - sqrt((2 * a * b - 2 * a * y0 - 2 * x0) * (2 * a * b - 2 * a * y0 - 2 * x0) - 4 * (1 + a * a) * (x0 * x0 + b * b + y0 * y0 - 2 * b * y0 - R * R))) / (2 * (1 + a * a));
		y2 = a * x2 + b;
		cout << "A straight line intersects a circle a points " << x1 << " " << y1 << " " << x2 << " " << y2;
	}
	return 0;
}
