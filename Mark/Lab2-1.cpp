#include <iostream>

using namespace std;

int main()
{
	float x = 0, y = 0;
	cout << "Enter x & y: ";
	cin >> x >> y;
	if ((y <= 0 && y >= -2 && x <= 1 && x >= -2) || (y <= 1 && y >= 0 && x >= -2 && x <= -1) || (x <= 0 && x >= -1 && y <= 1 && y >= 0 && (x + y) <= 0))
		cout << "The point belongs to the area";
	else
		cout << "The point doesn't belongs to the area";
	return 0;
}