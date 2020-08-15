//
// Created by 幻想家 on 2020/8/5.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> a;

void MergeSort(int arr[], int reg[],int start, int end)
{
    if (start == end)
        return; // 递归基本结束条件
    int len =  end - start, mid = (len>> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid, end2 = end;

    // 切分阶段
    MergeSort(arr,reg,start1,end1);
    MergeSort(arr,reg,start2,end2);

    //排序过程
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (int k = start; k < end; ++k)
    {
        arr[k] = reg[k];
    }




}