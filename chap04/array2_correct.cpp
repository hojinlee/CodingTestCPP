#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() 
{
	int T, N; // T: 테스트 케이스, N: 행렬의 길이
	cin >> T;

	int buf;
	for (int i = 0; i < T; i++)
	{
		// matrix[0]은 행의 값, matrix[1]은 열의 값, 1000은 충분히 큰 임의의 값
		int matrix[2][1000] = { 0, }; 

		cin >> N;
		memset(matrix, 0x0, sizeof(int) * 2000);		
		for (int r = 0; r < N; r++) // N * N 행렬 
		{
			for (int c = 0; c < N; c++)
			{
				cin >> buf;
				matrix[0][r] += buf;
				matrix[1][c] += buf;
			}
		}
		
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cout << matrix[j][k] << " ";
			}
			cout << endl;
		}
		
	}	

	return 0;
}

