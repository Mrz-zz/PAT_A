#include <iostream>
#include <array>
#include <vector>

using namespace std;


vector<vector<int>> rec;


void merges(int *s_array, int first, int middle, int last, int length);

void split(int *arr, int start, int end, int length)
{
    if (start == end)
        return;

    int len = end - start;
    int mid = start + len / 2;

    split(arr, start, mid, length);
    split(arr, mid + 1, end, length);
    merges(arr, start, mid, end, length);
}


void merges(int *s_array, int first, int middle, int last, int length)
{
//    array<int, 10> temp = {};

    int i = first, j = middle + 1;
    int k = 0;
    int *temp = new int[last - first + 1];
    while (i <= middle && j <= last)
        temp[k++] = s_array[i] < s_array[j] ? s_array[i++] : s_array[j++];
    while (i <= middle)
        temp[k++] = s_array[i++];
    while (j <= last)
        temp[k++] = s_array[j++];

    for (int t = 0; t < k; ++t)
        s_array[t + first] = temp[t];


    vector<int> temp_vec;
    // show the sort progress
    for (int t = 0; t < length; ++t)
        temp_vec.push_back(s_array[t]);
    rec.push_back(temp_vec);

    delete[] temp;


}


int main()
{

    int N;
    cin >> N;

    int *src = new int[N];

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        src[i] = temp;
    }

    split(src, 0, N - 1, N);
    cout << "--------------------Sort-Progress----------------------" << endl;
    for (vector<vector<int>>::iterator i = rec.begin(); i < rec.end(); ++i)
    {
        for (vector<int>::iterator j = i->begin(); j < i->end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;
    }


//    for (int i = 0; i < N; ++i)
//    {
//        if (i != N - 1)
//            cout << src[i] << " ";
//        else
//            cout << src[i];
//    }

    delete[] src;
    return 0;

}