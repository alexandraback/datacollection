#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101][101],b[101][101],c[101];
int N;
char str[1000];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,Tnum=0;
	scanf("%d",&T);
	for (;T;--T){
		int n;
		scanf("%d",&n);
		N=0;
		int flag=0;
		for (int i=1; i<=n; ++i){
			scanf("%s",str);
			int m=strlen(str);
			int M=0;
			for (int j=0; j<m; ++j){
				++M;
				a[i][M]=str[j];
				b[i][M]=1;
				while (j+1<m && str[j+1]==str[j]){
					++b[i][M];
					++j;
				}
			}
			if (N && N!=M) flag=1;
			N=M;
		}
		printf("Case #%d: ",++Tnum);
		if (flag){
			puts("Fegla Won");
			continue;
		}
		for (int i=1; i<=N; ++i)
			for (int j=2; j<=n; ++j)
				if (a[j][i]!=a[j-1][i]) flag=1;
		if (flag){
			puts("Fegla Won");
			continue;
		}
		int ans=0;
		for (int i=1; i<=N; ++i){
			for (int j=1; j<=n; ++j) c[j]=b[j][i];
			sort(c+1,c+1+n);
			int sum=0,ans1=10000000;
			for (int j=1; j<=n; ++j)
				sum+=c[j];
			for (int j=1; j<=n; ++j){
				sum=sum-2*c[j];
				ans1=min(ans1,sum-(n-j)*c[j]+j*c[j]);
			}
			ans+=ans1;
		}
		printf("%d\n",ans);
	}
}
