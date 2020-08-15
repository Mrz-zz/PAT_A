//
// Created by 幻想家 on 2020/7/31.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string string_A,string_T;
    cin >> string_A >> string_T;
    bool found;
    int spare_num, miss_num = 0;


    for (int i = 0; i < string_T.length(); ++i)
    {
        for (int j = 0; j < string_A.length() ; ++j)
        {
            found = false;
            if (string_T[i] == string_A[j])
            {
                string_A[j] = '-';
                found  =true;
                break;
            }
        }
        if (not found)
            miss_num++;
    }

    if (miss_num==0)
    {
        spare_num = string_A.length() - string_T.length();
        cout << "Yes " << spare_num;
    }
    else
    {
        cout << "No " << miss_num;
    }

}