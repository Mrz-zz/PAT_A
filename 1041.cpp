#include <iostream>
#include <array>

using namespace std;

struct EaxmSeat
{
    long long int ID;
    int testNum;
    int examNum;
};

int main()
{
    int N = 0;
    cin >> N;

    array<EaxmSeat, 1000> ExamStore;

    for (int i = 0; i < N; ++i)
    {
        EaxmSeat temp;
        long long int ID;
        int test, exam;
        scanf("%lld %d %d", &ID, &test, &exam);
        temp.ID = ID;
        temp.testNum = test;
        temp.examNum = exam;
        ExamStore[i] = temp;
    }

//    int QueryNum = 0;
////    array<int, 1000> QueryArr;
//    cin >> QueryNum;
//    for (int i = 0; i < QueryNum; ++i)
//        cin >> QueryArr[i];


//
//    for (int j = 0; j < N; ++j)
//    {
//        int current_testNum = ExamStore[j].testNum;
//        if (current_testNum == QueryArr[j])
//            cout << ExamStore[j].ID << " " << ExamStore[j].examNum << endl;
//    }


    int QueryNum = 0;
    cin >> QueryNum;

    for (int i = 0; i < QueryNum; ++i)
    {
        int temp_testNum;
        cin >> temp_testNum;
        for (int j = 0; j < N; ++j)
        {
            if (ExamStore[j].testNum == temp_testNum)
            {
                cout << ExamStore[j].ID << " " << ExamStore[j].examNum << endl;
                break;
            }
        }
    }

    return 0;
}