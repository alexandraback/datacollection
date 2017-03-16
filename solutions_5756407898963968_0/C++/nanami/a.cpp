#include <cstdio>
int ca,n,m,a[5][5],b[5][5];
void init()
{
	scanf("%d",&n);
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) scanf("%d",&a[i][j]);
	scanf("%d",&m);
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) scanf("%d",&b[i][j]);
}
void solve()
{
	int cnt = 0,ans;
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(a[n - 1][i] == b[m - 1][j]){
				++cnt;
				ans = a[n - 1][i];
			}
	printf("Case #%d: ",++ca);
	if(cnt == 0){
		printf("Volunteer cheated!\n");
		return;
	}
	if(cnt >= 2) printf("Bad magician!\n");
	else printf("%d\n",ans);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		solve();
	}
	return 0;
}

