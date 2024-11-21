// Bak S4 2578 빙고 

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /*

    한 숫자 부를 때마다 25번 탐색.
    빙고 여부 확인 12 x 5 = 60번(가로 5, 세로 5, 대각선 2)

    총 85번의 탐색이 일어나고 이를 계산하면
    O(N) = 85 x 25

    따라서 Brute Force로 해도 될 것 같다.

    */

    int board[5][5] = {0, };
    bool ox[5][5] = {0, }; // for check
    int call[25] = {0, };

    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            cin >> board[i][j];

    for (int i=0; i<25; ++i)
        cin >> call[i];

    // call에 하나하나 대응
    for (int i=0; i<25; ++i)
    {
        for (int x=0; x<5; ++x)
        {
            for (int y=0; y<5; ++y)
            {
                // call과 일치하는 숫자를 board에서 찾아서 표시
                if (call[i] == board[x][y])
                {
                    // 빙고 여부 확인
                    int count = 0;

                    ox[x][y] = true;
                    
                    // 1. 가로
                    for (int a=0; a<5; ++a)
                    {
                        bool isBingo = true;
                        for (int b=0; b<5; ++b)
                        {
                            if (ox[a][b] == false)
                            {
                                isBingo = false;
                                break;
                            }
                        }
                        if (isBingo)
                            count += 1;
                    }
                    // 2. 세로
                    for (int a=0; a<5; ++a)
                    {
                        bool isBingo = true;
                        for (int b=0; b<5; ++b)
                        {
                            if (ox[b][a] == false)
                            {
                                isBingo = false;
                                break;                                
                            }
                        }
                        if (isBingo)
                            count += 1;
                    }
                    // 3. 대각선 우하향
                    bool isBingo = true;
                    for (int a=0; a<5; ++a)
                    {
                        if (ox[a][a] == false)
                        {
                            isBingo = false;
                            break;                            
                        }
                    }
                    if (isBingo)
                        count += 1;

                    // 4. 대각선 우상향
                    isBingo = true;
                    for (int a=0; a<5; ++a)
                    {
                        if (ox[a][4-a] == false)
                        {
                            isBingo = false;
                            break;                            
                        }
                    }
                    if (isBingo)
                        count += 1;

                    // 빙고가 3개 이상이면 종료
                    if (count >= 3)
                    {
                        cout << i + 1 << '\n';
                        return 0;
                    }

                    break;
                }                
            }
        }
    }
}