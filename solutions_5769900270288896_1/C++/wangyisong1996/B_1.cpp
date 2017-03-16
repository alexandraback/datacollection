#include <stdio.h>
#include <string.h>
#include <algorithm>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

int ans;

int r,c,n;

inline int work(int x)
begin
	int i,j;
	int cnt=0;
	for i=1;i<=r;i++ do begin
		for j=1;j<=c;j++ do begin
			if (i+j)%2==x then begin
				++cnt;
			end;
		end;
	end;
	if cnt>=n then return 0;
	int A[5]={0,0,0,0,0};
	for i=1;i<=r;i++ do begin
		for j=1;j<=c;j++ do begin
			if (i+j)%2!=x then begin
				++A[(i>1)+(i<r)+(j>1)+(j<c)];
			end;
		end;
	end;
	int ret=0;
	int n=::n;
	n-=cnt;
	if n<=A[1] then begin
		ret+=n;
	end else begin
		ret+=A[1];
		n-=A[1];
		if n<=A[2] then begin
			ret+=n*2;
		end else begin
			ret+=A[2]*2;
			n-=A[2];
			if n<=A[3] then begin
				ret+=n*3;
			end else begin
				ret+=A[3]*3;
				n-=A[3];
				ret+=n*4;
			end;
		end;
	end;
	return ret;
end;

inline void solve()
begin
	scanf("%d%d%d",&r,&c,&n);
	ans=std::min(work(0),work(1));
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