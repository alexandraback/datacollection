#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const int inf2 = 1000300;
using namespace std;

vector<long long> mas(inf2, 0);


long long solve(long long i);
long long R, C, N;
int main (int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T; // number of testcases
    for (int j = 0; j < T; j++)
	{
		cin >> R >> C >> N;
		long long answer = 100* R * C * N;
		long long proiz = R*C;
		for (int i = 1; i < (1 << proiz); i++)
		{
			mas[i] = mas[i - (i & -i)] + 1;
			if (mas[i] == N)
                answer = min(answer, solve(i));
		}
		printf("Case #%d: %d\n", j+1, answer);
	}
    return 0;
}

long long solve(long long n)
{
	long long answer = 0;
	long long temp = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if ((n & (1 << (i * C + j))) && (n & (1 << (i * C + j - 1))) && j > 0)
				temp += 1;
			if ((n & (1 << (i * C + j))) && (n & (1 << (i * C + j - C))) && i > 0)
				temp += 1;
		}
    answer = temp;
	return answer;
}
