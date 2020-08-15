#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, char> rec = {{10, 'J'},
                      {11, 'Q'},
                      {12, 'K'}};

vector<string> ret;

void extendStr(string &A, int len)
{
    for (int i = 0; i < len; ++i)
        A = '0' + A;
}


int main()
{
    string A, B;
    cin >> A >> B;
    int dif_time;
    int max_len = A.length() > B.length() ? A.length() : B.length();

    if (A.length() < max_len)
        extendStr(A, max_len - A.length());
    else
        extendStr(B, max_len - B.length());

    int temp_B, temp_A;
    string temp_ret;


    for (int i = 1; max_len - i >= 0; ++i)
    {
        int pos = max_len - i;
        temp_B = B[pos] - '0', temp_A = A[pos] - '0';

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
    for (int t = ret.size() - 1; t >= 0; t--)
        cout << ret[t];
    return 0;
}