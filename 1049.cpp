#include <iostream>
#include <vector>

using namespace std;
vector<float> ret;


int main()
{
    int N;
    cin >> N;
    float *ArrNum = new float[N];
    float sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> ArrNum[i];
    }

    for (int j = 0; j < N; ++j)
    {
        float temp_sum = 0;
        for (int k = j; k < N; ++k)
        {
            temp_sum += ArrNum[k];
            ret.push_back(temp_sum);
        }
    }


    for (int t = 0; t < ret.size(); ++t)
        sum += ret[t];

    printf("%.2f", sum);
    return 0;

}