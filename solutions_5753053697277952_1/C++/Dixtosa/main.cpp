/*
ID: dixtosa1
PROG: milk2
LANG: C++11
*/
#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
//#include <string.h>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional> //std::greater<int>
//#include <tuple>

//#include "Biginteger.cpp"
//#include "sqrt.cpp"
//#include "tree.cpp"
//#include "funcs.cpp"

typedef long long ll;
typedef std::pair<ll, ll> pii;
#define ALL(x)           (x).begin(), (x).end()
#define forn(N)          for(long long i = 0; i < (long long)N; i++)
#define fornj(N)         for(long long j = 0; j < (long long)N; j++)
#define fornk(N)         for(long long k = 0; k < (long long)N; k++)
#define foreach(c,itr)   for(auto itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433
#define LINF (1LL<<60)
#define INF (1<<30)
#define awesome vector<int> A(N); forn(N) scanf("%d", &A[i]);
#define v vector
#define File "Patterns"
using namespace std;

int N;
pair<int, char> A[26];

void solve3(int ind)
{
	while (A[ind].first > A[ind + 1].first)
	{
		A[ind].first--;
		cout << A[ind].second << " ";
	}

	while (A[ind + 1].first > A[ind + 2].first)
	{
		A[ind].first--;
		A[ind + 1].first--;
		cout << A[ind].second << A[ind + 1].second << " ";
	}
}
void solve2(int ind)
{
	while (A[ind].first > A[ind + 1].first)
	{
		A[ind].first--;
		cout << A[ind].second << " ";
	}
}

void SOLVE2(int ind)
{
	while (A[ind].first != 0)
	{
		A[ind].first--;
		A[ind + 1].first--;
		cout << A[ind].second << A[ind + 1].second << " ";
	}
}
void SOLVE3(int ind)
{
	while (A[ind].first > 1)
	{
		A[ind].first--;
		A[ind + 1].first--;
		A[ind + 2].first--;
		cout << A[ind].second << A[ind + 1].second << " ";
		cout << A[ind + 2].second << " ";
	}

	cout << A[ind].second << " ";
	cout << A[ind + 1].second << A[ind + 2].second << " ";
}
void solve()
{
	sort(A, A + N);
	reverse(A, A + N);

	for (int i = 0; i < N; i += 2)
	{
		if (i + 2 == N - 1)
		{
			solve3(i); break;
		}
		else
			solve2(i);
	}
	for (int i = 0; i < N; i += 2)
	{
		if (i + 2 == N - 1)
		{
			SOLVE3(i); break;
		}
		else
			SOLVE2(i);
	}
}
int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(File".in", "r", stdin); freopen(File".out", "w", stdout);
#endif

	int T; cin >> T;
	for (int test = 1; test <= T; test++)
	{
		cin >> N;
		forn(N) {
			cin >> A[i].first;
			A[i].second = i + 'A';
		}
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	//printf("\n\ntime-%.3lf", clock()*1e-3);
	return 0;
}