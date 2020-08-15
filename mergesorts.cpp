#include <iostream>
#include <vector>

int length = 10;




using namespace std;

void merge(int *p, int start, int middle, int end)
{
    int i, j, k = 0;
    int *temp = new int[end - start + 1];
    i = start, j = middle + 1;

    while (i <= middle && j <= end)
        temp[k++] = p[i] < p[j] ? p[i++] : p[j++];

    while (i <= middle)
        temp[k++] = p[i++];

    while (j <= end)
        temp[k++] = p[j++];

    for (int t = 0; t < k; t++)
    {
        p[t + start] = temp[t];
    }


    delete[] temp;

}

void mergesort(int *alist, int start, int end)
{
    if (start == end)
        return;

    int mid, len;
    len = end - start, mid = start + len / 2;

    //devide
    mergesort(alist, start, mid);
    mergesort(alist, mid + 1, end);

    //merge
    merge(alist, start, mid, end);

}


int main()
{
    int s[10] = {4, 1, 2, 3, 9, 7, 8, 0, 5, 6};
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    cout << "---------After Sorting-----------" << endl;
    mergesort(s, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}
