#include <iostream>
#include <array>
#include <sstream>

using namespace std;


class Person
{
public:
    string Name;
    string Birth;
    int year,month,day;

    int getSum() const
    {
        return this->year * 360 + this->month * 30 + this->day;
    }
};

array<Person,100000> Arr = {};



int main()
{
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >>Arr[i].Name;
        cin >>Arr[i].Birth;
    }


    for (int i = 0; i < N; ++i)
    {
        string year, month, day;
        year  = Arr[i].Birth.substr(0,4);
        month = Arr[i].Birth.substr(5,2);
        day = Arr[i].Birth.substr(8,2);
        stringstream s_1(year);
        s_1 >> Arr[i].year;
        stringstream s_2(month);
        s_2 >> Arr[i].month;
        stringstream s_3(day);
        s_3 >> Arr[i].day;
    }


    int correct_num = 0;

    int min = 1814*360+9*30+6;
    int max = 2014*360+9*30+6;

    int min_index = 0, max_index = 0;
    int min_num = Arr[0].getSum();
    int max_num = Arr[0].getSum();


    for (int i = 0; i < N; ++i)
    {
        bool isRight = false;

        int current_num = Arr[i].getSum();
        if (current_num >= min && current_num < max)
        {
            correct_num++;
            isRight = true;
        }

        if (isRight)
        {
            if (current_num < min_num)
            {
                min_num = current_num;
                min_index = i;
            }

            if (current_num > max_num)
            {
                max_num = current_num;
                max_index = i;
            }

        }

    }
    if (correct_num == 0)
    {
        cout << 0;
    }
    else
    {
        cout << correct_num << " " << Arr[min_index].Name << " " << Arr[max_index].Name;
    }

    return 0;


}

