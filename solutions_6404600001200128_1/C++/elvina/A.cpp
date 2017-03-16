#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int tab[N];

void test()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",tab+i);
	int rate = 0;
	int suma = 0;
	int drugi = 0;
	for (int i=1;i<n;i++)
		suma += max(0,tab[i-1]-tab[i]);
	for (int i=1;i<n;i++)
		rate = max( rate, tab[i-1]-tab[i] );
	for (int i=0;i<n-1;i++)
		drugi += min( rate, tab[i] );
	printf("%d %d\n",suma,drugi);
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		test();
	}
}
