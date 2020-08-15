//
// Created by 幻想家 on 2020/7/29.
//
#include <iostream>
#include <array>

using namespace std;

array<int,100000> scores = {};
array<int,100> counts = {};
array<int,100000> toCheck = {};

using namespace std;

int main()
{
    // N 代表学生人数， K为需要输出的成绩个数
    int N,K;
    //输入的是学生人数
    cin >> N;

    //第二行给出了学生的总成绩，利用循环将数据读入数组
    for (int i = 0; i < N ; ++i)
    {
        cin >> scores[i];
        counts[scores[i]]++;  //counts 记录每个成绩对应的人数
    }

    cin >> K;
    for (int j = 0; j < K ; ++j)
    {
        cin >> toCheck[j];
    }

    for (int m = 0; m < K; ++m)
    {
        if(m)
            cout << " " ;
        cout << scores[toCheck[m]];
    }
    return 0;
}
