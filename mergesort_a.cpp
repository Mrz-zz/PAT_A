#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;
vector<vector<int>> result;

void Mergesort(vector<int> arr,vector<int> ret, int start, int end)
{
    if (start >= end)
        return;

    int len = end -start, mid  = start + len/2;
    int start_1 = start; int end_1 = mid;
    int start_2 = mid+1; int end_2 = end;

    Mergesort(arr, ret, start_1, end_1);
    Mergesort(arr, ret, start_2, end_2);

    int sort_time = 0;
    int k = start;
    while (start_1 <= end_1 && start_2 <= end_2)
    {
        if (arr[start_1] < arr[start_2])
        {
            ret.push_back(arr[start_1]);
            start_1++;
        }
        else
        {
            ret.push_back(arr[start_2]);
            start_2++;

        }
    }

    while (start_1 <= end_1)
        ret.push_back(arr[start_1++]);
    while (start_2 <= end_2)
        ret.push_back(arr[start_2++]);



    for (int i = start; i < end; ++i)
    {
        ret.push_back(arr[i]);
    }


    for (int i = 0; i < len; ++i)
    {
        result[sort_time].push_back(ret[i]);
    }

    for (int i = 0; i < len; ++i)
    {
        cout << result[sort_time][i] << " ";
    }
    cout << endl;


    sort_time++;
}





// Mergesort的步骤
// 1. 切分列表，直到切分的元素为单个元素无法继续切分为止
// 2. 对切分后的元素进行排序，将其组装到一个列表中
//  分而治之

int main()
{
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin>> temp;
        a.push_back(temp);
    }

    int start = 0, end = N - 1;

    Mergesort(a,b,start,end);










}
