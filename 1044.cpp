#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <sstream>

using namespace std;


map<int, string> baseDight = {{0,  "tret"},
                              {1,  "jan"},
                              {2,  "feb"},
                              {3,  "mar"},
                              {4,  "apr"},
                              {5,  "may"},
                              {6,  "jun"},
                              {7,  "jly"},
                              {8,  "aug"},
                              {9,  "sep"},
                              {10, "oct"},
                              {11, "nov"},
                              {12, "dec"}};


map<int, string> higherDight = {{1,  "tam"},
                                {2,  "hel"},
                                {3,  "maa"},
                                {4,  "huh"},
                                {5,  "tou"},
                                {6,  "kes"},
                                {7,  "hei"},
                                {8,  "elo"},
                                {9,  "syy"},
                                {10, "lok"},
                                {11, "mer"},
                                {12, "jou"}};


int GetBaseKey(string value)
{
    int ret = 0;
    for (int i = 0; i < 13; ++i)
    {
        if (baseDight[i] == value)
        {
            ret = i;
            break;
        }

    }
    return ret;
}

int GetHigerKey(string value)
{
    int ret = 0;
    for (int i = 0; i < 13; ++i)
    {
        if (higherDight[i] == value)
        {
            ret = i;
            break;
        }

    }
    return ret;
}


int main()
{

    int Num;
    scanf("%d\n", &Num);


    vector<string> vec;
    for (int i = 0; i < Num; ++i)
    {
        string temp;
        getline(cin, temp); // 整行输入
        vec.push_back(temp);
    }


    for (int j = 0; j < Num; ++j)
    {
        string temp;
        temp = vec[j];
        if (temp[0] >= '0' && vec[j][0] <= '9') // is a number
        {
            int num;
            int base, higher;

            stringstream ss;
            ss << temp;
            ss >> num;
            base = num % 13;
            higher = num / 13;

            if (higher != 0)
            {
                if (base == 0)
                {
                    cout << higherDight[higher] << endl;
                }
                else
                {
                    cout << higherDight[higher] << " " << baseDight[base] << endl;
                }

            }
            else
            {
                cout << baseDight[base] << endl;
            }

        }

        else // is a character
        {
            int i = 0;
            int index = 0, result = -1;
            string str_2;
            string str_1;
            if (temp.length() <= 4)
            {
                for (int k = 0; k < temp.length(); ++k)
                {
                    str_1 += temp[k];
                }

                result = GetBaseKey(str_1);
                if (result > 0)
                {
                    cout << result << endl;
                }
                else
                {
                    result = GetHigerKey(str_1) * 13;
                    cout << result << endl;
                }


            }
            else
            {
                int k = 0;
                int index_1, index_2, ret;
                while (temp[k] != ' ')
                {
                    str_1 += temp[k];
                    k++;
                }

                for (int l = k + 1; l < temp.length(); ++l)
                {
                    str_2 += temp[l];
                }

                index_1 = GetHigerKey(str_1);
                index_2 = GetBaseKey(str_2);
                ret = index_1 * 13 + index_2;

                cout << ret << endl;
            }


        }
    }

    return 0;
}
