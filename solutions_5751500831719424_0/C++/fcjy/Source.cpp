#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, char> > v[1000];
char c[1000], s[1000];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T, cases = 1;
	int N;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%d", &N);
		for( int i = 0; i < N; ++i )
		{
			v[i].clear();
			scanf("%s", s);
			int len = strlen(s);
			for( int j = 1, k = 1; j <= len; ++j )
			{
				if( j == len || s[j] != s[j-1] )
				{
					v[i].push_back(make_pair(k, s[j-1]));
					k = 1;
				}
				else
					k++;
			}
		}

		bool ok = 1;
		for( int i = 1; ok && i < N; ++i )
		{
			if( v[i].size() != v[0].size() )
				ok = 0;
			else
			{
				for( int j = 0; j < v[0].size(); ++j )	if( v[i][j].second != v[0][j].second )
					ok = 0;
			}
		}

		if( ok )
		{
			int ans = 0;
			for( int i = 0; i < v[0].size(); ++i )
			{
				vector<int> h;
				for( int j = 0; j < N; ++j )
					h.push_back(v[j][i].first);
				sort(h.begin(), h.end());
				for( int j = 0; j < N; ++j )
					ans += abs(h[j] - h[N/2]);
			}
			printf("Case #%d: %d\n", cases++, ans);
		}
		else
			printf("Case #%d: Fegla Won\n", cases++);
	}

	return 0;
}