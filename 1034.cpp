//
// Created by 幻想家 on 2020/8/3.
//

#include <iostream>
#include <cstdio>


using namespace std;

long long int GreatestCD(long long int a,long long int b)
{
    return (a % b == 0 ? b : GreatestCD(b,a%b)) ;
}





void cal(long long int a, long long int b) // a:分子 b: 分母
{
    int flag;
    long long int num,integer;
    long long int GreatestComDiv = GreatestCD(a,b);

    a = a / GreatestComDiv;
    b = b / GreatestComDiv;

    if ((a < 0 && b > 0)  ||(a > 0 && b< 0)) flag = -1;
    else flag = 1;

    integer = abs(a / b);
    num = abs(a % b);

    if (integer != 0 && num != 0)
    {
        if (flag < 0)
            cout << "(-";
        cout << integer << " " << num << "/" << abs(b);
        if (flag < 0)
            cout << ")";
    }


    if (integer == 0 && num == 0)
        cout << "0" ;

    else
    {
        if (integer == 0)
        {
            if (flag < 0)
                cout << "(-";
            cout << num << "/" << abs(b);
            if (flag < 0)
                cout << ")";
        }

        if (num == 0)
        {
            if (flag < 0)
                cout << "(-";
            cout << integer;
            if (flag < 0)
                cout << ")";

        }
    }





}



int main()
{
    long long int a_1, a_2, b_1, b_2;
    scanf("%lld/%lld %lld/%lld", &a_1, &a_2, &b_1, &b_2);
    cal(a_1,a_2);cout<< " + " ; cal(b_1,b_2); cout << " = "; cal(a_1*b_2+ a_2*b_1,a_2*b_2); cout << endl;
    cal(a_1,a_2);cout<< " - " ; cal(b_1,b_2); cout << " = "; cal(a_1*b_2- a_2*b_1,a_2*b_2); cout << endl;
    cal(a_1,a_2);cout<< " * " ; cal(b_1,b_2); cout << " = "; cal( a_1*b_1,a_2*b_2); cout << endl;
    cal(a_1,a_2);cout<< " / " ; cal(b_1,b_2); cout << " = ";
    if (b_1 == 0)
    {
        cout <<"Inf";
    }
    else
    {
        cal(a_1*b_2, b_1*a_2); cout << endl;
    }

    return 0;

}