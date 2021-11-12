#include <iostream>
#include <ctime>

using namespace std;

const int N1 = 12, N2 = 12;

template<class T>
void SwapStrings(T(&arr)[N1][N2], int it1, int it2)
{
    for (int i = 0; i < N1; i++)
    {
        swap(arr[it1][i], arr[it2][i]);
    }
}
template<class T>
void SwapColumns(T(&arr)[N1][N2], int it1, int it2)
{
    for (int i = 0; i < N2; i++)
    {
        swap(arr[i][it1], arr[i][it2]);
    }
}
template<class T>
void AddStrings(T(&arr)[N1][N2], int Str, int Col)
{
    if (arr[Str - 1][Col] == 0)
        SwapStrings(arr, Str, Str - 1);
    else
    {
        float k = -1 * (arr[Str][Col] / (float)arr[Str - 1][Col]);
        for (int i = Col; i < N2; i++)
        {
            arr[Str][i] += k * arr[Str - 1][i];
            arr[Str][i] = floor(arr[Str][i] * 100) / 100;
            //
            // If you wanna accurate calculations, comment upper string.
            //
        }
        arr[Str][Col] = 0;
        //
        // Using to delete calculation mistake, that accumulates after much calculations. Don't worry about warning.
        //
    }
}
template<class T>
void PrepareMatrix(T(&arr)[N1][N2])
{
    for (int i = 0; i < (N1 > N2 ? N2 : N1); i++)
    {
        if (arr[i][i] == 0)
            for (int j = i; j < N1; j++)
            {
                bool isBreak = false;
                for (int m = i; m < N2; m++)
                    if (arr[j][m] != 0)
                    {
                        SwapStrings(arr, i, j);
                        SwapColumns(arr, i, m);
                        isBreak = true;
                        break;
                    }
                if (isBreak)
                    break;
            }
        else
            continue;
    }
}
template<class T>
void ChangeMatrix(T(&arr)[N1][N2])
{
    PrepareMatrix(arr);

    int k = 0;
    for (int j = 0; j < N2 - 1; j++)
    {
        for (int i = N1 - 1; i > k; i--)
        {
            AddStrings(arr, i, j);
        }
        k++;
    }
}
template<class T>
int FindCountOfStringsWhichAverageSmallerThenNumber(T(&arr)[N1][N2], float number)
{
    int count = 0;

    for (int i = 0; i < N1; i++)
    {
        int countofitems = 0;
        float currentAverage = 0, sum = 0;

        for (int j = 0; j < N2; j++)
            if (arr[i][j] != 0)
            {
                countofitems++;
                sum += arr[i][j];
            }
        currentAverage = sum / countofitems;

        if (currentAverage < number)
            count++;
    }
    return count;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));

    float arr[N1][N2];

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            arr[i][j] = rand() % 20 - 10; // rand -> 0 - 32768
        }
    }

    cout << "Generated matrix: " << endl;
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    ChangeMatrix(arr);

    cout << "Triangle matrix:" << endl;
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    float number;
    cout << "Enter number: ";
    cin >> number;

    cout << "Count Of Strings Which Average Smaller Then Number: "
        << FindCountOfStringsWhichAverageSmallerThenNumber(arr, number) << endl;

    return 0;
}
