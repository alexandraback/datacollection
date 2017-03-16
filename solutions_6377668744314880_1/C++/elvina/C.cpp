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

bool side(pun a)
{
	if ( a.y == 0 ) return a.x < 0;
	return a.y < 0;
}

bool cmp(pun a,pun b)
{
	bool as = side(a);
	bool bs = side(b);
	if ( as != bs ) return as < bs;
	if ( wek(a,b) == 0 )
	{
		if ( a.x != b.x ) return abs( a.x ) < abs( b.x );
		return abs( a.y ) < abs( b.y );
	}
	return wek( a, b ) > 0;
}

vector <pun> wiel;

int algo()
{
	sort( wiel.begin(), wiel.end(), cmp );
	for (int i=0;i<n-1;i++) wiel.push_back( wiel[i] );
//	printf("wiel: ");
//	for (int i=0;i<wiel.size();i++) printf("%d, %d\n",wiel[i].x,wiel[i].y);
	int koniec = 0;
	int wynik = n-1;
	for (int i=0;i<wiel.size();i++)
	{
		koniec = max(koniec,i+1);
		while( koniec < wiel.size() && wiel[i] != wiel[koniec] && wek( wiel[i], wiel[ koniec ] ) >= 0 ) koniec ++;
		if ( koniec == wiel.size() ) break;
		wynik = min( wynik, n - koniec + i - 1 );
	}
	return wynik;
}

void test()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&tab[i].x,&tab[i].y);
	for (int i=0;i<n;i++)
	{
		wiel.clear();
//		printf("algo %d %d\n",tab[i].x,tab[i].y);
		for (int j=0;j<n;j++)
			if ( i != j ) wiel.push_back( tab[j] - tab[i] );
		printf("%d\n",algo());
	}
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
