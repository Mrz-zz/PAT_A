#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> vect;
    vector<int> vec_1;
    vector<int> vec_2;

    for (int i = 0; i < 2; ++i)
    {
        vec_1.push_back(i);
    }
    for (int i = 2; i < 4; ++i)
    {
        vec_2.push_back(i);
    }

    vect.push_back(vec_1);
    vect.push_back(vec_2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}