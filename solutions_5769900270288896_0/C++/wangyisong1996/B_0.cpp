#include <stdio.h>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

int ans;

int r,c,n;

bool f[17][17];

inline void check()
begin
	int i,j;
	int t=0;
	int cnt=0;
	for i=1;i<=r;i++ do begin
		for j=1;j<=c;j++ do begin
			if i<r && f[i][j] && f[i+1][j] then ++t;
			if j<c && f[i][j] && f[i][j+1] then ++t;
			cnt+=f[i][j];
		end;
	end;
	if cnt!=n then return;
	if t<ans then ans=t;
end;

inline void dfs(int x,int y)
begin
	if x==r && y==c then begin
		check();
		return;
	end;
	++y;
	if y>c then ++x,y=1;
	f[x][y]=1;
	dfs(x,y);
	f[x][y]=0;
	dfs(x,y);
end;

inline void solve()
begin
	scanf("%d%d%d",&r,&c,&n);
	ans=100000;
	dfs(1,0);
	printf("%d\n",ans);
end;

int main()
begin
	int T;
	scanf("%d",&T);
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end