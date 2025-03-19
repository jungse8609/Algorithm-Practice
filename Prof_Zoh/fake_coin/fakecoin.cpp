#include <iostream>
#include <algorithm>
#include "fakecoin.h"
using namespace std;

int balanced_left[22] = {0, };
int balanced_right[22] = {0, };

void print(int result)
{
    for (int i=0; i<22; ++i)
    {
        cout << balanced_left[i];
    }
    cout << '\n';
    for (int i=0; i<22; ++i)
    {
        cout << balanced_right[i];
    }
    cout << '\n' << result << '\n';
}

int main()
{
    load_coins();

    int result = 0;

    int size1 = 7;
    int size2 = 3;
    int size3 = 1;

    int startIndex = 0;
    int endIndex = 22; // index < endIndex

    // ####################################################
    // div 1
    for (int i=startIndex; i<startIndex + size1; ++i)
    {
        balanced_left[i] = 1;
        balanced_right[i + size1] = 1;
    }
    int result1 = balance(balanced_left, balanced_right);

    //print(result1);

    if (result1 == 1)
    { // right weight > left weight
        startIndex = startIndex + size1;
    }
    else if (result1 == -1)
    { // left weight > right weight
        startIndex = startIndex;
    }
    else if (result1 == 0)
    { // choose remain
        startIndex = startIndex + 2 * size1;
    }
    else
    {
        cout << "Result wrong";
    }
    // ####################################################
    // div 2

    // init array
    fill_n(balanced_left, 22, 0);
    fill_n(balanced_right, 22, 0);
    for (int i=startIndex; i<startIndex + size2; ++i)
    {
        balanced_left[i] = 1;
        balanced_right[i + size2] = 1;
    }
    int result2 = balance(balanced_left, balanced_right);
    
    //print(result2);

    if (result2 == 1)
    { // right weight > left weight
        startIndex = startIndex + size2;
    }
    else if (result2 == -1)
    { // left weight > right weight
        startIndex = startIndex;
    }
    else if (result2 == 0)
    { // choose remain
        startIndex = startIndex + 2 * size2;
    }
    else
    {
        cout << "Result wrong";
    }
    // ####################################################
    // div 3

    // init array
    fill_n(balanced_left, 22, 0);
    fill_n(balanced_right, 22, 0);
    for (int i=startIndex; i<startIndex + size3; ++i)
    {
        balanced_left[i] = 1;
        balanced_right[i + size3] = 1;
    }
    int result3 = balance(balanced_left, balanced_right);
    
    //print(result3);

    if (result3 == 1)
    { // right weight > left weight
        report_coin(startIndex + size3);
    }
    else if (result3 == -1)
    { // left weight > right weight
        report_coin(startIndex);
    }
    else if (result3 == 0)
    { // last one
        report_coin(startIndex + 2 * size3);
    }
    else
    {
        cout << "Result wrong";
    }

}