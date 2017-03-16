#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <stack>
#include <string>
#include <queue>
  
using namespace std;
  
#define ABS(a) (((a) > 0)? (a): -(a))
#define Min(a, b) (((a) < (b))? (a): (b))
#define Max(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SQR(a) (a) * (a)
#define All(a) (a).begin(), (a).end()
#define PI 3.1415926535897932384626433832795
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

int sum, n;
int p[555];

bool check()
{
	FOR(i, 1, n)
	{
		if (p[i] * 2 > sum)
			return false;
	}
	return true;
}

bool first()
{
	FOR(i, 1, n)
	{
		if (p[i] == 0)
			continue;
		p[i]--;
		sum--;
		if (check())
		{
			printf(" %c", char(i + 64));
			return true;
		}
		p[i]++;
		sum++;
	}
	return false;
}

void second()
{
	FOR(i, 1, n)
	{
		FOR(j, i + 1, n)
		{
			if (p[i] * p[j] == 0)
				continue;
			p[i]--;
			p[j]--;
			sum -= 2;
			if (check())
			{
				printf(" %c%c", char(64 + i), char(64 + j));
				return;
			}
			p[i]++;
			p[j]++;
			sum += 2;
		}
	}
	throw;
}

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		cin >> n;
		sum = 0;
		printf("Case #%d:", test);
		FOR(i, 1, n)
		{
			cin >> p[i];
			sum += p[i];
		}
		while (sum)
		{
			if (!first())
				second();
		}
		cout << endl;
	}
}

/*-------------------*/
  
int main()
{
#ifdef Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
/*Test*/
//freopen("input.txt", "w", stdout);
long double OcZ2X = clock();
#else
//freopen("laboratory.in", "r", stdin);
//freopen("laboratory.out", "w", stdout);
#endif
/*
 　　　　　　　　　　　 　∧__∧
　　　　　　　　　　　 　( ° ͜ʖ°)
　　　　　　　　　　　 　⊂　　 つ
　　　　　　　　　　　　　(つ ﾉ
　　　　　　　　　　　　　 (ノ
　　　　　＼　　　　　　☆
　　　　　　　　　　　　　|　　　　　☆
　　　　　　　　　　(⌒ ⌒ヽ　　　/
　　　　＼　　（´⌒　　⌒　　⌒ヾ　　　／
　　　　　 （’⌒　;　⌒　　　::⌒　　）
　　　　　（´*/    solution();   /*:::　）　／
　　☆─　（´⌒;:　　　　::⌒`）　:;　　）
　　　　　（⌒::　　　::　　　　　::⌒　）
　　 　／　（　　　　ゝ　　ヾ　丶　　ソ　─
*/
#ifdef Time
long double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}