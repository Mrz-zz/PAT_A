#include <iostream>
#include <map>
#include <vector>


using namespace std;

map<int, char> rec = {{10, 'J'},
                      {11, 'Q'},
                      {12, 'K'}};

vector<string> ret;

int main()
{
    string A, B;
    cin >> A >> B;
    int len_A = A.length();
    int len_B = B.length();
    int temp_B, temp_A;
    string temp_ret;

    int i = 1;
    for (; (len_B - i >= 0 && len_A - i >= 0); ++i)
    {
        int pos_B = len_B - i;
        int pos_A = len_A - i;

        temp_B = B[pos_B] - '0', temp_A = A[pos_A] - '0';


        if (i % 2 != 0)
        {
            int temp = (temp_A + temp_B) % 13;
            if (temp >= 10)
                temp_ret = rec[temp];
            else
                temp_ret = to_string(temp);
        }
        else
        {
            int temp = temp_B - temp_A;
            if (temp < 0)
                temp += 10;
            temp_ret = to_string(temp);
        }
        ret.push_back(temp_ret);
    }


    if (len_B > len_A)
    {
        int dif = len_B - len_A;
        for (int j = dif - 1; j >= 0; j--)
        {
            temp_ret = B[j];
            ret.push_back(temp_ret);
        }
    }


    for (int t = ret.size() - 1; t >= 0; t--)
        cout << ret[t];

    return 0;

}