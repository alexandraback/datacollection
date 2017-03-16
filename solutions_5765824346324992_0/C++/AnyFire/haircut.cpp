#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1005;

int T;
int a[N], n, t;

int jud(LL p)
{
	LL tot(0);
	for(int i=1; i<=n; i++) tot += p / a[i] + 1;
	return tot >= t;
}

int work()
{
	scanf("%d%d", &n, &t);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	
	LL l=0, r=1e13+1, md;
	for(; l<=r; ) if(jud(md=((l+r)>>1))) r=md-1; else l=md+1;
	
	LL under(0);
	for(int i=1; i<=n; i++) under += (l-1) / a[i] + 1;
	t -= under;
	
	if(!t) return 0;
	for(int i=1; i<=n; i++)
	{
		if(l % a[i] == 0) --t;
		if(!t) return i;
	}
	return 0;
	
}

int main()
{
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	
	scanf("%d", &T);
	for(int i=1; i<=T; i++) printf("Case #%d: %d\n", i, work());
	
	return 0;
}
