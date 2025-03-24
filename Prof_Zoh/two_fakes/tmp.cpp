#include <iostream>
#include "twofakes.h"
using namespace std;
int balance_3_3(int left[], int right[])
{
    int arr1[11] = {0, };
    int arr2[11] = {0, };
    for (int i=0; i<3; ++i)
    {
        arr1[left[i]] = 1;
        arr2[right[i]] = 1;
    }
    return balance(arr1, arr2);
}
int balance_in_3(int arr[])
{
    int arr1[11] = {0, }; arr1[arr[0]] = 1;
    int arr2[11] = {0, }; arr2[arr[1]] = 1;
    int onetwo = balance(arr1, arr2);
    if (onetwo == -1) return arr[0];
    else if (onetwo == 1) return arr[1];
    else return arr[2];
}

pair<int, int> balance_in_3(int arr[], bool isTwo)
{
    if (balance_in_3(arr) == arr[0]) return {arr[0], arr[2]};
    else if (balance_in_3(arr) == arr[1]) return {arr[1], arr[2]};
    else return {arr[0], arr[1]};
}

int main()
{
    int fake1, fake2;
    load_coins();

    int arr1[3] = {0,1,2};
    int arr2[3] = {3,4,5};
    int arr3[3] = {6,7,8};
    int onetwo = balance_3_3(arr1, arr2);
    int onethr = balance_3_3(arr1, arr3);
    if (onetwo == 1)
    { // arr2에 fake 존재
        
        if (onethr == 1)
        { // arr3에 fake 존재
            // 결국 arr2, arr3에 가짜가 하나씩 있다.
            fake1 = balance_in_3(arr2);
            fake2 = balance_in_3(arr3);
        }
        else if (onethr == -1) {} // 불가능
        else if (onethr == 0)
        { // arr2와 나머지 2개에 fake가 있음
            int remain[3] = {0, 9, 10}; // 진짜 코인 하나 추가
            int res = balance_3_3(arr2, remain);
            if (res == -1)
            { // arr2에 fake 2개
                pair<int, int> fakes = balance_in_3(arr2, true);
                fake1 = fakes.first;
                fake2 = fakes.second;
            }
            else if (res == 1)
            { // {9, 10} 이 답
                fake1 = 9;
                fake2 = 10;
            }
            else
            { // arr2에 하나 remain에 하나
                fake1 = balance_in_3(arr2);
                fake2 = balance_in_3(remain);
            }
        }
    }
    else if (onetwo == -1)
    { // arr1에 fake 존재        
        if (onethr == -1)
        { // arr1와 나머지 2개에 fake가 있음
            int remain[3] = {3, 9, 10}; // 진짜 코인 하나 추가
            int res = balance_3_3(arr1, remain);
            if (res == -1)
            { // arr1에 fake 2개
                pair<int, int> fakes = balance_in_3(arr1, true);
                fake1 = fakes.first;
                fake2 = fakes.second;
            }
            else if (res == 1)
            { // {9, 10} 이 답
                fake1 = 9;
                fake2 = 10;
            }
            else
            { // arr2에 하나 remain에 하나
                fake1 = balance_in_3(arr1);
                fake2 = balance_in_3(remain);
            }
        }
        else if (onethr == 1) {} // 불가능
        else if (onethr == 0)
        { // 결국 arr1, arr3에 가짜가 하나씩 있다.
            fake1 = balance_in_3(arr1);
            fake2 = balance_in_3(arr3);
        }
    }
    else if (onetwo == 0)
    { // arr1 weight = arr2 weight        
        if (onethr == 1)
        { // arr3와 나머지 2개에 fake가 있음
            int remain[3] = {0, 9, 10}; // 진짜 코인 하나 추가
            int res = balance_3_3(arr3, remain);
            if (res == -1)
            { // arr3에 fake 2개
                pair<int, int> fakes = balance_in_3(arr3, true);
                fake1 = fakes.first;
                fake2 = fakes.second;
            }
            else if (res == 1)
            { // {9, 10} 이 답
                fake1 = 9;
                fake2 = 10;
            }
            else
            { // arr2에 하나 remain에 하나
                fake1 = balance_in_3(arr3);
                fake2 = balance_in_3(remain);
            }
        }
        else if (onethr == -1)
        { // arr1과 arr2에 fake가 1개씩 있음
            fake1 = balance_in_3(arr1);
            fake2 = balance_in_3(arr2);
        }
        else if (onethr == 0)
        { // 나머지 2개가 모두 fake임
            fake1 = 9;
            fake2 = 10;
        }
    }

    cout << "fake1 = " << fake1 << ", fake2 = " << fake2 << '\n';
    
    two_fakes(fake1, fake2);
}