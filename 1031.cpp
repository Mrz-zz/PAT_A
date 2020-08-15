//
// Created by 幻想家 on 2020/7/31.
//

#include <map>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


array<int,17> weight = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
map<string,string> cri_dict = {{"0", "1"}, {"1","0"},{"2","X"}, {"3","9"},
                           {"4", "8"}, {"5","7"},{"6","6"}, {"7","5"},
                           {"8","4"}, {"9","3"}, {"10","2"}};

int main()
{
    int total = 0, sum;
    int correct_num = 0;
    cin >> total;
    vector<string> vec;
    vector<string> vec_error;

    bool IsAllNum;
    for (int i = 0; i <total ; ++i)
    {
        string temp;
        cin >> temp;
        vec.push_back(temp);
    }

    for (int j = 0; j < total; ++j)
    {
        IsAllNum = true;
        sum = 0;
        string current_str = vec[j];
        for (int k = 0; k < 17 ; ++k)
        {
            if (current_str[k] != 'X')
                sum += (current_str[k] -'0') * weight[k];
            else
            {
                IsAllNum = false;
                vec_error.push_back(current_str);
                break;
            }
        }

        if (IsAllNum)
        {
            sum = sum % 11;
            stringstream ss;
            ss << sum;
            string sum_str = ss.str();

            string ret,check_num;
            ret = cri_dict[sum_str];
            check_num = current_str[17];
            if ( ! ret.compare(check_num))
                correct_num++;
            else
                vec_error.push_back(current_str);
        }
    }

    if (correct_num == total)
        cout << "All passed";
    else
    {
        for (int i = 0; i < vec_error.size(); ++i)
        {
            if (i != vec_error.size()-1)
                cout << vec_error[i] << endl;
            else
                cout << vec_error[i] ;
        }
    }

    return 0;
}