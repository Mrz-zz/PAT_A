#include <iostream>
#include <algorithm>
#include <array>


using namespace std;

bool compare(int i, int j)
{
    return (i > j);
}


int main()
{
    int N;
    cin >> N;
    int *rec = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> rec[i];

    sort(rec, rec + N, compare);


    // 判断矩阵的大小
    int m;

    int min_dif = N - 1, n = N;
    for (m = 1; m <= N; m++)
    {
        int current_dif, current_n;
        if (N % m == 0)
        {
            current_n = N / m;
            current_dif = m - current_n;
            if (current_dif <= min_dif && current_dif >= 0)
            {
                min_dif = current_dif;
                n = current_n;
            }
        }

    }
    m = N / n; //行


    int **spiral_matrix = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        spiral_matrix[i] = new int[n];
    }


}

