//
// Created by 幻想家 on 2020/8/2.
//
#include <iostream>
#include <string>
#include <map>
#include <array>

using namespace std;

array<int, 6> counts = {};


int main()
{
    string word;
    string example = "PATest";
    bool isRight;

    cin >> word;
    for (unsigned int i = 0; i < word.length(); ++i)
    {
        int index = 0;
        isRight = false;
        for (unsigned int j = 0; j < example.length(); ++j)
        {
            if (word[i] == example[j])
            {
                isRight = true;
                index = j;
                break;
            }
        }

        if (isRight)
        {
            counts[index] += 1;
        }
    }

    int total_times = 0;
    for (unsigned int i = 0; i < example.length(); ++i)
    {
        total_times += example[i];
    }


    string ret;
    for (unsigned int i = 0; i < total_times; ++i)
    {
        int j = i % 6;
        if (counts[j] != 0)
        {
            ret += example[j];
            counts[j]--;
        }
    }
    cout << ret ;
    return 0;
}