#include <iostream>
#include <stdint.h>
using namespace std;

bool building[10000];
int minVal;

int R, C;
int N;
int size;
void dfs(int pos, int count, int curMinVal)
{
	if (minVal == 0)
	{
		return;
	}
	if (curMinVal > minVal)
	{
		return;
	}
	if (count > N)
	{
		if (curMinVal < minVal)
		{
			minVal = curMinVal;
			return;
		}
	}
	if (pos >= size)
	{
		return;
	}
	building[pos] = true;
	//计算此时的不愉快值
	int addNum = 0;
	int r = pos / C;
	int c = pos % C;
	//left
	if (c > 0 && building[r * C + c - 1] == true)
	{
		++addNum;
	}
	//right
	/*if (c < C - 1 && building[r * C + c + 1] == true)
	{
		++addNum;
	}*/
	//up
	if (r > 0 && building[(r - 1) * C + c] == true)
	{
		++addNum;
	}
	//down
	/*if (r < R - 1 && building[(r + 1) * C + c] == true)
	{
		++addNum;
	}*/
	dfs(pos + 1, count + 1, curMinVal + addNum);
	building[pos] = false;
	dfs(pos + 1, count, curMinVal);
}

int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k)
	{
		memset(building, 0, sizeof(bool) * 10000);
		cin >> R >> C;
		cin >> N;

		size = R * C;
		minVal = R * (C - 1) + (R - 1) * C;
		
		cout << "Case #" << (k + 1) << ": ";

		if (N <= 1)
		{
			cout << 0;
		}
		else
		{
			dfs(0, 1, 0);
			cout << minVal;
		}
		cout << endl;
	}

	return 0;
}

//uint64_t  reverse(uint64_t n)
//{
//	uint64_t result = 0;
//	while (n > 0)
//	{
//		result = result * 10 + (n % 10);
//		n /= 10;
//	}
//	return result;
//}
//int main()
//{
//	int T;
//	uint64_t N;
//	cin >> T;
//	for (int k = 0; k < T; ++k)
//	{
//		cin >> N;
//
//		cout << "Case #" << (k + 1) << ": ";
//		
//		uint64_t num = 1;
//		while (N != 1)
//		{
//			if (N % 10 == 1 && reverse(N) < N)
//			{
//				N = reverse(N);
//				++num;
//			}
//			else
//			{
//				--N;
//				++num;
//			}
//		}
//
//		cout << num << endl;
//	}
//
//	return 0;
//}