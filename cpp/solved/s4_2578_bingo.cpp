// Bak S4 2578 ���� 

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /*

    �� ���� �θ� ������ 25�� Ž��.
    ���� ���� Ȯ�� 12 x 5 = 60��(���� 5, ���� 5, �밢�� 2)

    �� 85���� Ž���� �Ͼ�� �̸� ����ϸ�
    O(N) = 85 x 25

    ���� Brute Force�� �ص� �� �� ����.

    */

    int board[5][5] = {0, };
    bool ox[5][5] = {0, }; // for check
    int call[25] = {0, };

    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            cin >> board[i][j];

    for (int i=0; i<25; ++i)
        cin >> call[i];

    // call�� �ϳ��ϳ� ����
    for (int i=0; i<25; ++i)
    {
        for (int x=0; x<5; ++x)
        {
            for (int y=0; y<5; ++y)
            {
                // call�� ��ġ�ϴ� ���ڸ� board���� ã�Ƽ� ǥ��
                if (call[i] == board[x][y])
                {
                    // ���� ���� Ȯ��
                    int count = 0;

                    ox[x][y] = true;
                    
                    // 1. ����
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
                    // 2. ����
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
                    // 3. �밢�� ������
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

                    // 4. �밢�� �����
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

                    // ���� 3�� �̻��̸� ����
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