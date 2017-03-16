#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 105;

char str[maxn][maxn];
int s[maxn];
int cnt[maxn][maxn];

int main()
{
	srand(time(NULL));
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	scanf("%d\n", &t);
	
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		scanf("%d\n", &n);
		
		for (int i = 0; i < n; i++)
		{
			gets(str[i]);
			s[i] = strlen(str[i]);
		}
		
		vector < char > gr;
		
		for (int i = 0; i < s[0]; i++)
		{
			int j = i;
			while (j < s[0] && str[0][i] == str[0][j]) j++;
			
			gr.pb(str[0][i]);
			
			i = j - 1;
		}
		
		bool bad = false;
		
		for (int i = 0; i < n; i++)
		{
			int g = 0;
			for (int j = 0; j < s[i]; j++)
			{
				int h = j;
				while (h < s[i] && str[i][h] == str[i][j]) h++;
				
				if (g >= gr.size() || gr[g] != str[i][j])
				{
					bad = true;
					break;
				}
				
				cnt[i][g] = h - j;
				g++;
				
				j = h - 1;
			}
			
			if (g != gr.size())
				bad = true;
		}
		
		if (bad)
		{
			cout << "Case #" << tt << ": " << "Fegla Won" << endl;
			continue;
		}
		
		int ans = 0;
		
		for (int i = 0; i < gr.size(); i++)
		{
			int m = 1e9;
			
			for (int j = 0; j < maxn; j++)
			{
				int curr = 0;
				
				for (int h = 0; h < n; h++)
					curr += abs(cnt[h][i] - j);
					
				m = min(m, curr);
			}
			
			ans += m;
		}
		
		cout << "Case #" << tt << ": " << ans << endl;
	}
	
	
	return 0;
}


