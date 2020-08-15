#include <iostream>
#include <array>
using namespace std;

class Person
{
public:
    string Name;
    string Birth;
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


    int correct_num = 0;
    int min_index = 0, max_index = 0;

    string lower_limit = "1814/09/06";  // 不能低于这一年份
    string upper_limit = "2014/09/06";  // 不能超过这一年份

    string min_year = Arr[0].Birth; //年龄大，但是年份数值小，这里算的是最年长者
    string max_year = Arr[0].Birth; //年龄小，但是年份数值大，这里算的是最年轻者

    
    for (int i = 0; i < N; ++i)
    {
        bool isRight = false;

        string current_year = Arr[i].Birth;

        if (current_year <= upper_limit && current_year >= lower_limit)
        {
            correct_num++;
            isRight = true;
        }

        if (isRight)
        {
            if (current_year <= min_year) //发现更年长者
            {
                min_year = current_year;
                min_index = i;
            }

            if (current_year >= max_year)
            {
                max_year = current_year;
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

