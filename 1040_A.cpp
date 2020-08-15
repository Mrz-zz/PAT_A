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

    int countP = 0;
    int countT = 0;
    int count = 0;

    for (char i : input)
    {
        if (i == 'T')
            countT++;
    }

    for (char i : input)
    {
        if (i == 'P')
            countP++;
        if (i == 'T')
            countT--;
        if (i == 'A')
            count = (count + (countP * countT) % 1000000007) % 1000000007;
    }

    cout << count;
    return 0;

}