#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <vector> 
#include <sstream> 
#include <string> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <queue>
using namespace std; 
#pragma comment(linker, "/STACK:256000000") 
#define mp make_pair 
#define pb push_back 
#define all(C) (C).begin(), (C).end() 
#define sz(C) (int)(C).size() 
#define PRIME 1103 
#define PRIME1 31415 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef pair<int, int> pii; 
typedef vector<int> vi; 
typedef vector<vector<int> > vvi; 
//------------------------------------------------------------ 
const int N = 1000010;
priority_queue<pii> qq;
int n;
int mas[20][20];

int solve()
{
	int r, c;
	scanf("%d %d %d", &r, &c, &n);
	int p = r * c;
	int ans = 1e9;
	for(int i = 0; i < (1 << p); ++i)
	{
		int k = i, co = 0;
		while(k)
		{
			co += k & 1;
			k >>= 1;
		}
		if (co != n)
			continue;
		memset(mas, 0, sizeof mas);
		for(int j = 0; j < r; ++j)
			for(int k = 0; k < c; ++k)
				mas[j][k] = ((1 << (j * c + k)) & i);
		int t = 0;
		for(int j = 0; j < r; ++j)
			for(int k = 0; k < c; ++k)
			{
				if (mas[j][k] && mas[j + 1][k])
					t++;
				if (mas[j][k] && mas[j][k + 1])
					t++;
			}
		ans = min(t, ans);
	}
	return ans;
	
}
int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(0);
	
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("Case #%d: %d\n", i + 1, solve());
	}
	
}