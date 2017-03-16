#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 128;
const int MAX2 = 7000;
const int BASE = 1000000000;

int T;
int n;
string A[MAX];
vector < pair<char, int> > Q[MAX];

void Init()
{
	FOR (i,0,MAX)
	{
		A[i] = "";
		Q[i].clear();
	}
}

void SolveTest(int test)
{
	scanf("%d", &n);
	FOR (i,0,n)
	{
		cin >> A[i];
		int pos = 0;
		while (pos < SZ(A[i]))
		{
			int cnt = 0;
			while (pos+cnt < SZ(A[i]) && A[i][pos+cnt] == A[i][pos])
				++ cnt;
			Q[i].PB(MP(A[i][pos], cnt));
			pos += cnt;
		}
	}
	int cnt = 0;
	bool res = 1;
	FOR (i,1,n)
	{
		if (SZ(Q[i]) != SZ(Q[0]))
		{
			res = 0;
			break;
		}
		FOR (j,0,SZ(Q[i]))
		{
			if (Q[i][j].first != Q[0][j].first)
			{
				res = 0;
				break;
			}
		}
	}
	printf("Case #%d: ", test+1);
	if (res == 0)
	{
		printf("Fegla Won\n");
		return;
	}
	FOR (i,0,SZ(Q[0]))
	{
		VI V;
		FOR (j,0,n)
			V.PB(Q[j][i].second);
		sort(ALL(V));
		int mid = n / 2;
		int val = V[mid];
		FOR (j,0,n)
			cnt += abs(val - Q[j][i].second);
	}
	printf("%d\n", cnt);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("A-large.in", "r", stdin);
		//freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	scanf("%d", &T);
	FOR (test,0,T)
	{
		Init();
		SolveTest(test);
	}

	return 0;
}