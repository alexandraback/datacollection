#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
int ma[5][5][2];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,a,b;
	cin>>t;
	for(int cas=1;cas<=t;cas++) {
		scanf("%d",&a);
		for(int i=1;i<=4;i++) {
			for(int j=1;j<=4;j++) {
				scanf("%d",&ma[i][j][0]);
			}
		}
		scanf("%d",&b);
		for(int i=1;i<=4;i++) {
			for(int j=1;j<=4;j++) {
				scanf("%d",&ma[i][j][1]);
			}
		}
		int cnt=0,ans;
		for(int i=1;i<=4;i++) {
			for(int j=1;j<=4;j++) {
				if(ma[a][i][0]==ma[b][j][1]) {
					cnt++;
					ans=ma[a][i][0];
				}
			}
		}
		printf("Case #%d: ",cas);
		if(!cnt) puts("Volunteer cheated!");
		else if(cnt==1) printf("%d\n",ans);
		else puts("Bad magician!");
	}
    return 0;
}
