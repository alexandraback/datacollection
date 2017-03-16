#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

char ch[110][110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)scanf("%s",ch[i]+1);
		vector <Pi> v[110];
		for(i=1;i<=n;i++){
			int now = 1;
			while(ch[i][now]){
				int t = now;
				while(ch[i][t] == ch[i][now])t++;
				v[i].push_back(Pi(t-now, ch[i][now]));
				now = t;
			}
			//for(int j=0;j<v[i].size();j++)printf("%d %d\n",v[i][j].X,v[i][j].Y);
		}
		int sz = v[1].size();
		for(i=2;i<=n;i++)if(v[i].size() != sz){
			puts("Fegla Won");
			break;
		}
		if(i != n+1)continue;
		for(i=2;i<=n;i++){
			int j;
			for(j=0;j<sz;j++){
				if(v[i][j].Y != v[1][j].Y)break;
			}
			if(j != sz)break;
		}
		if(i != n+1){
			puts("Fegla Won");
			continue;
		}
		int ans = 0;
		for(i=0;i<sz;i++){
			vector <int> v2;
			for(int j=1;j<=n;j++)v2.push_back(v[j][i].X);
			sort(v2.begin(),v2.end());
			int t = v2.size() / 2;
			for(int j=0;j<n;j++){
				ans += abs(v2[j] - v2[t]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
