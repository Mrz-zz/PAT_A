//
// Created by 幻想家 on 2020/7/29.
//

#include <iostream>
#include <array>

using namespace std;

array<int,100000>school = {};



int main()
{
    int total_num;
    cin >> total_num;

    for (int i = 0; i < total_num; ++i)
    {
        int school_num, score;
        cin >> school_num >> score;
        school[school_num] += score;
    }

    int max_index = 0, max_score = school[max_index];
    for (int j = 1; j < total_num ; ++j)
    {
        if (school[j] > school[max_index])
        {
            max_index = j;
            max_score = school[max_index];
        }
    }

    cout << max_index <<" " << max_score;
    return 0;

}