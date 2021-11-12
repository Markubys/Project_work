#include <iostream>
#include <vector>

using namespace std;

vector<int> SearchSimpleNumbers(int max, int N)
{
    int n = 0;
    vector<bool> arr1(n + 1, true);
    arr1[0] = arr1[1] = false;
    for (int i = 2; i * i <= n; ++i)   // valid for n < 46340^2 = 2147395600
        if (arr1[i])
            for (int j = i * i; j <= n; j += i)
                arr1[j] = false;
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
        if (arr[i] < 0)
            arr[i] = arr[i] * (-1);
        cout << arr[i] << " ";
    }
    SearchSimpleNumbers(arr);

    return 0;
}