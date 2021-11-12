#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::string FILE_NAME_IN = "mynumbersfile.txt";

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> arr;

    std::ifstream ifs(FILE_NAME_IN.c_str());

    std::string line;

    std::string j;
    while (std::getline(ifs, line))
    {
        std::vector<int> temp;

        std::stringstream strStream(line);
        while (std::getline(strStream, j, ' '))
        {
            temp.push_back(atoi(j.c_str()));
        }
        bool needAppend = true;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] >= 10 && temp[i] < 100)
            {
                needAppend = false;
                break;
            }
        }
        if (needAppend) {
            for (int i = 0; i < temp.size(); i++)
                std::cout << temp[i] << " ";
            std::cout << std::endl;
        }
    }
    system("pause");
    return 0;
}