#include <iostream>
#include <vector>
using namespace std;

vector<int> chapter;
int n, k;

/*
@param : 그룹 중 최댓값
maxSum보다 작으면서 가장 큰 그룹들을 만들어
그룹 개수가 k개를 넘으면 return false
k개 이하이면 return true
*/
bool canParticipate(int maxSum)
{
    int groupSum = 0;
    int groupCount = 1;
    
    // cout << "MAX SUM = " << maxSum << '\n';

    for (int i=0; i<n; ++i)
    {
        if (groupSum + chapter[i] > maxSum)
        {
            groupCount += 1;
            // cout << groupCount << "그룹 까지의 합 : " << groupSum << '\n'; 

            groupSum = 0;
        }

        groupSum += chapter[i];
    }

    if (groupCount > k)
        return false;

    //cout << "이번 MAX SUM은 가능!\n";

    return true;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> n >> k;

    // 이진 탐색의 left, right가 된다.
    int sumAll = 0, maxOne = 0;

    chapter = vector<int>(n);    
    for (auto& e : chapter)
    {
        cin >> e;
        sumAll += e;
        maxOne = max(maxOne, e);
    }

    int left = maxOne, right = sumAll;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        //cout << "[" << left << ", " << right << "]\n";
        if (canParticipate(mid))
        {
            right = mid - 1;
            result = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result;
}