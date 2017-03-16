#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 30

int t;
int n;

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		set< pair<int, char> > tree;
		int cntall = 0;

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			int x; scanf("%d", &x);
			tree.insert(mp(-x, 'A'+i));
			cntall += x;
		}
		
		printf("Case #%d:", tc);

		while(!tree.empty())
		{
			pair<int, char> p = *tree.begin();
			tree.erase(tree.begin());
			char c1 = p.se;
			int cnt = -p.fi;
			if(cnt >= 2) tree.insert(mp(-(cnt-1), c1));
			cntall--;

			char c2 = ' ';
			if(cntall >= 3 || cntall == 1)
			{
				p = *tree.begin();
				tree.erase(tree.begin());
				c2 = p.se;
				cnt = -p.fi;
				if(cnt >= 2) tree.insert(mp(-(cnt-1), c2));
				cntall--;
			}
			
			if(c2 != ' ') printf(" %c%c", c1, c2);
			else printf(" %c", c1);
		}
		puts("");
	}

	return 0;
}
