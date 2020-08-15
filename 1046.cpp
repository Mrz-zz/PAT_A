//
// Created by 幻想家 on 2020/8/14.
//

#include <iostream>
#include <array>


using namespace std;

int main()
{
    int N;
    int A_Drink = 0, B_Drink = 0;
    cin >> N;
    array<array<int, 4>, 100> rec = {};

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int temp;
            cin >> temp;
            rec[i][j] = temp;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (((rec[i][0] + rec[i][2] == rec[i][1]) && (rec[i][0] + rec[i][2] == rec[i][3]))
            || ((rec[i][0] + rec[i][2] != rec[i][1]) && rec[i][0] + rec[i][2] != rec[i][3]));
        else
        {
            if (rec[i][0] + rec[i][2] == rec[i][1])
            {
                B_Drink++;
            }
            if (rec[i][0] + rec[i][2] == rec[i][3])
            {
                A_Drink++;
            }
        }
    }


    cout << A_Drink << " " << B_Drink;
    return 0;
}
