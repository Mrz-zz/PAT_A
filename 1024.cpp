//
// Created by 幻想家 on 2020/7/29.
//


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string example,number="";
    float base;
    int expon,PosORNeg;
    char Sign_A, Sign_B;

    Sign_A = example[0];
    (Sign_A == '+') ? PosORNeg=1 :PosORNeg=-1;

    int index = 1;
    while (example[index] != 'E')
    {
        number += example[index];
        index++;
    }
    base = ;



}