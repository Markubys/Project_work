#include <iostream>
#include <vector>

struct Time
{
    int hour = 0;
    int minute = 0;
    Time(int h, int m)
    {
        if (h >= 0 && m < 60 && m >= 0)
        {
            hour = h;
            minute = m;
        }
        else
            std::cout << "Введены неправильные данные" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<Time> times;
    Time time1(1, 40);
    Time time2(2, 50);
    Time time3(6, 10);
    Time time4(12, 15);
    Time time5(8, 44);
    Time time6(4, 18);
    times.push_back(time1);
    times.push_back(time2);
    times.push_back(time3);
    times.push_back(time4);
    times.push_back(time5);
    times.push_back(time6);

    int generalTime = 0;
    int minimumTime = INT_MAX;

    for (int i = 0; i < times.size(); i++)
    {
        generalTime += times[i].hour * 60 + times[i].minute;
        int currentTime = times[i].hour * 60 + times[i].minute;
        if (currentTime < minimumTime)
            minimumTime = currentTime;
    }

    int hours = generalTime / 60;
    int minutes = generalTime - hours * 60;
    if ((hours % 10 >= 5) || (hours >= 10 && hours < 21) || (hours % 10 == 0))
        printf("Общее время: %d часов", hours);

    else if (hours % 10 == 1)
        printf("Общее время: %d час", hours);

    else if (hours % 10 < 5 && hours % 10 >= 1)
        printf("Общее время: %d часа", hours);

    if ((minutes % 10 >= 5) || (minutes >= 10 && minutes < 21) || (minutes % 10 == 0))
        printf(", %d минут\n", minutes);

    else if (minutes % 10 == 1)
        printf(", %d минутa\n", minutes);

    else if (minutes % 10 < 5 && minutes % 10 >= 1)
        printf(", %d минуты\n", minutes);

    hours = minimumTime / 60;
    minutes = minimumTime - hours * 60;
    if ((hours % 10 >= 5) || (hours >= 10 && hours < 21) || (hours % 10 == 0))
        printf("Минимальное время: %d часов", hours);

    else if (hours % 10 == 1)
        printf("Минимальное время: %d час", hours);

    else if (hours % 10 < 5 && hours % 10 >= 1)
        printf("Минимальное время: %d часа", hours);

    if ((minutes % 10 >= 5) || (minutes >= 10 && minutes < 21) || (minutes % 10 == 0))
        printf(", %d минут\n", minutes);

    else if (minutes % 10 == 1)
        printf(", %d минутa\n", minutes);

    else if (minutes % 10 < 5 && minutes % 10 >= 1)
        printf(", %d минуты\n", minutes);
    return 0;
}