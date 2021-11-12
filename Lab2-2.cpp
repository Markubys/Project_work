#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N = 0;
	cout << "Введите N ";
	cin >> N;
	vector<int> arr;
	arr.resize(N);
	cout << "Введите числа ";
	for (int i = 0; i < N; i++) {
		int x = 0, res = 0;
		cin >> x;
		while (x > 0) {
			res *= 10;
			res += x % 10;
			x /= 10;
		}
		arr[i] = res;
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

