#include <iostream>
using namespace std;

int main()
{
    int T, N; // T: 테스트 케이스, N: 행렬의 길이
    cin >> T;

    int buf;                    // 사용자 입력값을 받는 버퍼
    for (int i = 0; i < T; i++) // 테스트 케이스
    {
        // matrix[0]은 행의 값, matrix[1]은 열의 값, 1000은 충분히 큰 임의의 값
        int matrix[2][1000] = {
            0,
        };

        cin >> N;
        for (int r = 0; r < N; r++) // N * N 행렬
        {
            for (int c = 0; c < N; c++)
            {
                cin >> buf;
                matrix[0][r] += buf; // r행의 합에 더합니다.
                matrix[1][c] += buf; // c열의 합에 더합니다.
            }
        }
        // 행과 열을 출력하기 위해 2번 반복합니다. 0:행, 1:열
        for (int j = 0; j < 2; j++)
        {
            // 헹렬의 길이만큼 반복합니다.
            for (int k = 0; k < N; k++)
            {
                cout << matrix[j][k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}