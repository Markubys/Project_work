#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N = 0, m = 0;
	cout << "Введите N ";
	cin >> N;
	vector<int> arr;
	arr.resize(N);
	cout << "Введите числа ";
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (abs(arr[j + 1]) > abs(arr[j])) {
				m = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = m;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int sum = 0;
	float res = 0, k = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 0) {
			sum += arr[i];
			k++;
		}
		res = sum / k;
	}
	cout <<"Среднее арифметическое положительных чисел " << res << endl;
	return 0;
}

