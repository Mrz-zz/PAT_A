//
// Created by 幻想家 on 2020/7/29.
//

//
// Created by 幻想家 on 2020/7/29.
//

#include <iostream>
#include <array>
using namespace std;

array<int,10000>ret = {};



int main()
{
    long long A, B,sum;
    int C;
    cin >> A >> B >> C;
    sum = A + B;
    int index_num = 0;

    if (sum==0)
        cout << "0" ;
    else
    {
        while (sum != 0)
        {
            int remainder = 0;
            remainder = sum % C;
            ret[index_num] = remainder;
            sum = sum / C;
            index_num += 1;
        }


        for (int i =index_num-1 ; i >= 0 ; --i)
        {
            cout << ret[i];
        }
    }

    return 0;

}