//
// Created by 幻想家 on 2020/8/13.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int current_index = 0;
    int len = input.length();
    int totalNum = 0;


    while (current_index < len)
    {
        if (input[current_index] == 'P')
        {
            for (int i = current_index + 1; i < len; ++i)
            {
                if (input[i] == 'A')
                {
                    for (int j = i + 1; j < len; ++j)
                    {
                        if (input[j] == 'T')
                            totalNum++;
                    }
                }
            }
        }
        current_index++;
    }

    if (totalNum >= 1000000007)
        totalNum %= 1000000007;
    cout << totalNum;
    return 0;

}