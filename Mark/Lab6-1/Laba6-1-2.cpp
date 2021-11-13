﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string FILE_NAME_IN = "mybinaryfile.bin";
std::string FILE_NAME_OUT = "mybinaryfile.txt";

template<class T>
char* as_bytes(T& i)
{
    void* addr = &i;
    return static_cast<char*>(addr);
}

bool isSimpleNumber(int number)
{
	int j = 1;
	while (j <= sqrt(number))
	{
		if (number % j == 0 && j != 1 && j != number)
			return false;
		j++;
	}
	return true;
}

int findNegativeMaximumIndex(std::vector<int> arr)
{
    int max = INT_MIN, index = -1;

    for (int i = 0; i < arr.size(); i++)  
        if (arr[i] > max && arr[i] < 0)
        {
            max = arr[i];
            index = i;
        }
    
    return index;
}
int findSimpleMaximumIndex(std::vector<int> arr)
{
    int max = INT_MIN, index = -1;
    for (int i = 0; i < arr.size(); i++)
        if (isSimpleNumber(arr[i]) && arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    
    return index;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> arr;

    std::ifstream ifs(FILE_NAME_IN.c_str(), std::ios_base::binary);

    int j = 0;
    while (ifs.read(as_bytes(j), sizeof(int)))
        arr.push_back(j);
    ifs.close();

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int index1 = findSimpleMaximumIndex(arr), index2 = findNegativeMaximumIndex(arr);
    if (index1 * index2 > 0 && (index1 + index2) >= 0)
    {
        std::swap(arr[index1], arr[index2]);
        std::cout << "Элементы массива успешно поменяны!" << std::endl;
    }
    else
        std::cout << "Нет подходящих элементов массива" << std::endl;

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::ofstream ofs(FILE_NAME_OUT.c_str());
    for (int i = 0; i < arr.size(); i++)
    {
        ofs << arr[i] << " ";
    }
    ofs.close();
    
    std::cout << "Массив успешно сохранен!" << std::endl;
    system("pause");
    return 0;
}

