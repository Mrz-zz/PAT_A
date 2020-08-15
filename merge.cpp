#include <iostream>
#include <vector>


using namespace std;
vector<vector<int>>rec;


int loop = 0;




void merge(int A[], int start, int mid, int end)
{

    int k = 0;
    int i = start;
    int j = mid + 1;
    int *temp = new int[end-start+1];

    while (i <= mid && j <= end)
    {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= mid)
    {
        temp[k++] = A[i++];
    }

    while (j <= end)
    {
        temp[k++] = A[j++];
    }

    for (int t = 0; t < k; ++t)
    {
        A[start + t] = temp[t];

    }

//    for (int l = 0; l < 10; ++l)
//    {
//        rec[loop].push_back(A[l]);
//    }

    loop++;
    delete [] temp;
}


void mergesort(int* s, int start, int end)
{

    if (start >= end)
        return; // basic recursion condition


    int mid = start + (end - start) / 2;
    mergesort(s, start, mid); // sort for the left_half
    mergesort(s, mid + 1, end); // sort for the right_half
    merge(s, start, mid, end);
}


int main()
{
    int s[10] = {8, 5, 26, 9, 3, 15, 4, 60, 38, 43};
    mergesort(s, 0, 9);

    for (int i : s)
    {
        cout << i << " ";
    }
    return 0;
}