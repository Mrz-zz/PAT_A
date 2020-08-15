
#include <iostream>
#include <array>
#define N 100


using namespace std;

array<int,100> List = {}; //保存数组元素
array<array<int,100>,100> Arr_Insert = {}; // 保存每一次插入排序之后的列表
array<array<int,100>,100> Arr_Merge = {}; // 保存每一次归并排序之后的列表


void InsertSort(array<int,100> *p)
{

    int total = p->size();
    for (int i = 1; i < total ; ++i)
    {
        int current = (*p)[i];
        for (int j = i - 1; j > 0 ; j--)  // 排序
        {
            if (current < (*p)[j])
                (*p) [j+1] = (*p)[j];
            else
                (*p) [j] = current;
        }

       Arr_Insert[i] = *p;

    }

    //打印元素
    for (int i = 0; i < total; ++i)
    {
        for (int j = 0; j < total; ++j)
        {
            cout << Arr_Insert[i][j] << "  ";
        }
        cout << endl;

    }
}






int main()
{
    int total = 0;
    cin >> total;


    for (int i = 0; i < total; ++i)
    {
        cin >> List[i];
    }

    InsertSort(&List);





}