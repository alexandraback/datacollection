#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>


#define FNAME ""

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < b; i++)
#define gcd __gcd
 
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

using namespace std;

template <class T> T sqr(const T &a) {return a * a;}

int T, n, m[300], boo, pos[300], pos1[300], sum, ans;
string s[300];
char t[300][300];
int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d", &T);
	forn(q, T)
	{
		scanf("%d\n", &n);
		forn(i, n)
		{
			gets(t[i]);
			s[i] = "";
			s[i] += t[i][0];
			m[i] = strlen(t[i]);
			forn(j, m[i] - 1)
				if (t[i][j] != t[i][j + 1])
					s[i] += t[i][j + 1];					
		}
		boo = 1;
		forab(i, 1, n)
			if (s[i]  != s[0])
				boo = 0;
		if (!boo)
		{
			printf("Case #%d: Fegla Won\n", q + 1);
			continue;
		}
		forn(i, n)
			pos[i] = 0;
		ans = 0;	
		forn(i, s[0].length())
		{
			sum = 0;
	    	forn(j, n)
	    	{
	    		pos1[j] = pos[j];
	    		while (pos[j] < m[j] && t[j][pos[j]] == s[0][i])
	    			pos[j]++, sum++; 
	    	}
	    	sum = int(round(1.0 * sum / n) + 0.001);
	    	forn(j, n)
	    		ans += abs(sum - (pos[j] - pos1[j]));
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
}


