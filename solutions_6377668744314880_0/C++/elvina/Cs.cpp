#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

#define x first
#define y second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int n;
pun tab[N];

pun operator-(pun a,pun b)
{
	return make(a.x-b.x,a.y-b.y);
}

long long int wek(pun a,pun b)
{
	return a.x*(ll)b.y - a.y*(ll)b.x;
}

vector <int> wiel;
int odp[N];

int algo()
{
	for (int i=0;i<wiel.size();i++)
	{
		bool ok = 1;
		int x;
		if ( i > 0 ) x = 0;
		else x = 1;
		for (int j=0;j<wiel.size();j++)
			if ( j!=i && wek( tab[ wiel[j] ]-tab[wiel[i]], tab[wiel[x]]-tab[wiel[i]] ) < 0 )
				x = j;
		for (int j=0;j<wiel.size();j++)
			if ( j!=i && wek( tab[ wiel[j] ]-tab[wiel[i]], tab[wiel[x]]-tab[wiel[i]] ) < 0 )
				x = j;
//		printf("x dla %d to %d\n",wiel[i],wiel[x]);
		for (int j=0;j<wiel.size();j++)
			if ( j!=i && j!=x && wek( tab[ wiel[j] ]-tab[wiel[i]], tab[ wiel[x] ] -tab[wiel[i]] ) < 0 )
			{
//				printf("nieok dla %d\n",wiel[j]);
				ok = 0;
			}
		if ( ok ) odp[ wiel[i] ] = max( odp[ wiel[i] ], (int)wiel.size() );
	}
}

void test()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) odp[i] = 1;
	for (int i=0;i<n;i++) scanf("%d%d",&tab[i].x,&tab[i].y);
	for (int maska=0;maska<(1<<n);maska++)
	{
		wiel.clear();
//		printf("algo %d %d\n",tab[i].x,tab[i].y);
		for (int j=0;j<n;j++)
			if ( (1<<j)&maska ) wiel.push_back(j);
		if ( wiel.size() > 1 ) algo();
	}
	for (int i=0;i<n;i++) printf("%d\n",n-odp[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d:\n",i);
		test();
	}
}
