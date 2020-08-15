#include <iostream>
#include <vector>

using namespace std;

void merges(int* s_array, int first, int middle, int last);

void split(int* arr, int start, int end)
{
    if (start == end)
        return;

    int len = end - start;
    int mid = start + len / 2;

    split(arr, start, mid);
    split(arr, mid + 1, end);
    merges(arr, start, mid, end);
}


void merges(int* s_array, int first, int middle, int last)
{
//    array<int, 10> temp = {};

    int i = first, j = middle + 1;
    int k = 0;
    int *temp = new int[last-first];
    while (i <= middle && j <= last)
        temp[k++] = s_array[i] < s_array[j] ? s_array[i++] : s_array[j++];
    while (i <= middle)
        temp[k++] = s_array[i++];
    while (j <= last)
        temp[k++] = s_array[j++];

    for (int t = 0; t < k; ++t)
        s_array[t+first] = temp[t];

    delete [] temp;


}


int main()
{
    int N;
    cin >> N;

    vector<int> src;


    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        src.push_back(temp);
    }

    split(src, 0, N-1);

    for (int i = 0; i < N; ++i)
    {
        if (i != N-1)
            cout << src[i] << " ";
        else
            cout << src[i];
    }


    return 0;

}