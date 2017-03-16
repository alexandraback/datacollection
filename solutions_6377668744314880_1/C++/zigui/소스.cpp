#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MX = 3000;
const double pi = acos(-1);

pii D[MX];
int cnt[MX*3];
double angle[MX*3];
int N;

int solve(int x)
{
	if(N <= 2) return 0;
	angle[x] = -99;
	for(int i = 0; i < N; i++){
		if( i == x ) continue;
		angle[i] = atan2(D[i].first - D[x].first, D[i].second - D[x].second);
	}
	sort(angle, angle+N);
	for(int i = N; i < 2*N-1; i++) angle[i] = angle[i-N+1] + 2*pi;
	cnt[0] = 0;
	for(int i = 1; i < 2*N-1; i++){
		if( angle[i] == angle[i-1] ) cnt[i] = cnt[i-1] + 1;
		else cnt[i] = 1;
	}
	int st = 1, en = N-1, mi = 1, ans = N, p = 0, q;
	while( en < 2*N-1 ){
		while( mi < en && angle[st] + pi >= angle[mi+1] ) mi++;
		int p = mi - st, q = en - mi;
		if( angle[st] + pi == angle[mi] ) p -= cnt[mi];
		ans = min(ans, min(p, q));
		int tmp = st;
		while(angle[tmp] == angle[st]) st++;
		en = st+N-2;
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d%d", &D[i].first, &D[i].second);
		printf("Case #%d:\n", t);
		for(int i = 0; i < N; i++){
			printf("%d\n", solve(i));
		}
	}
	return 0;
}