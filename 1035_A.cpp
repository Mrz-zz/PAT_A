#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> RecInsert;
vector<vector<int>> RecMerge;
vector<int> list;
vector<int> Given;


void InsertionSort(vector<int> *p)
{
    int _size = p->size();
    for (int i = 1; i < _size; ++i)
    {
        int current = (*p)[i];
        int j = i - 1;
        for (; j > -1; --j)
        {
            if (current < (*p)[j])
                (*p)[j + 1] = (*p)[j];
            else
                break;
        }
        (*p)[j + 1] = current;
        RecInsert.push_back(*p);
    }
}

void merges(int *s_array, int first, int middle, int last, int length)
{
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
    RecMerge.push_back(temp_vec);

    delete[] temp;
}


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
        list.push_back(temp);
    }

    for (int j = 0; j < N; ++j)
    {
        int m;
        cin >> m;
        Given.push_back(m);
    }

    InsertionSort(&list);
    split(src, 0, N - 1, N);
    bool found = false;


    for (vector<vector<int>>::iterator i = RecMerge.begin(); i < RecMerge.end(); ++i)
    {
        if (*i == Given)
        {
            found = true;
            cout << "Merge Sort" << endl;
            for (vector<int>::iterator j = (i + 1)->begin(); j < (i + 1)->end(); ++j)
            {
                if (j != (i + 1)->end() - 1)
                    cout << *j << " ";
                else
                    cout << *j << endl;
            }
            break;
        }

    }


    if (!found)
    {
        for (vector<vector<int>>::iterator i = RecInsert.begin(); i < RecInsert.end(); ++i)
        {
            if (*i == Given)
            {
                cout << "Insertion Sort" << endl;
                for (vector<int>::iterator j = (i + 1)->begin(); j < (i + 1)->end(); ++j)
                {
                    if (j != (i + 1)->end() - 1)
                        cout << *j << " ";
                    else
                        cout << *j << endl;
                }
                break;
            }
        }
    }



    delete[] src;
    return 0;

}
