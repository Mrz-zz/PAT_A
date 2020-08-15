//
// Created by 幻想家 on 2020/8/14.
//
#include <iostream>
#include <array>
using namespace std;

array<int,10000> rec = {};

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int teamNum,memNum,score;
        scanf("%d-%d %d",&teamNum,&memNum,&score);
        rec[teamNum] += score;
    }

    int max_teamNum = 0, max_score = rec[max_teamNum];
    for (int j = 1; j < 10000; ++j)
    {
        if (rec[j] > max_score)
        {
            max_score = rec[j];
            max_teamNum = j;
        }
    }

    cout << max_teamNum << " " << max_score;
    return 0;

}