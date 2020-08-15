#include <iostream>

using namespace std;


int main()
{
    int N;
    cin >> N;
    auto *ArrNum = new double[N];
    long long sum = 0;
    double temp;
    for (int i = 1; i <= N; ++i)
    {
        cin >> temp;
        sum += (long long) (temp * 1000 * (N - i + 1) * i);
    }
    printf("%.2f", sum / 1000.0);
    return 0;

}