#include <iostream>
#include <vector>

using namespace std;

vector<int> SearchSimpleNumbers(int max)
{
	vector<int> arr1;
	for (int i = 2; i < sqrt(max); i++)
		for (int j = 2; j < sqrt(i); j++) {
			if (i % j != 0)
				arr1.push_back(i);
		}
	return arr1;
}

void DeleteNumber(vector<int> arr)
{
	int max = arr[0], id = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
			id = i;
		}
	}
	vector<int> smpn = SearchSimpleNumbers(max);
	for (int i = 0; i < smpn.size(); i++) {
		cout << smpn[i];
	}
}

int main()
{
	int N = 0;
	cout << "Enter N ";
	cin >> N;
	vector<int> arr;
	arr.resize(N);
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 200 - 100;
	}
	cout << "Generated numbers: ";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

