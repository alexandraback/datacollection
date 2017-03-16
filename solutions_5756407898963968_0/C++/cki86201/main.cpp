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

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int t=1;t<=Tc;t++){
		int p[5][5], q[5][5];
		int chk[20];
		memset(chk,0,sizeof chk);
		int i, j;
		int x, y;
		scanf("%d",&x);
		for(i=0;i<4;i++)for(j=0;j<4;j++)scanf("%d",p[i]+j);
		scanf("%d",&y);
		for(i=0;i<4;i++)for(j=0;j<4;j++)scanf("%d",q[i]+j);
		for(i=0;i<4;i++)chk[p[x-1][i]]++, chk[q[y-1][i]]++;
		int ans = -1;
		for(i=1;i<=16;i++){
			if(chk[i] == 2 && ans == -1)ans = i;
			else if(chk[i] == 2)ans = -2;
		}
		printf("Case #%d: ",t);
		if(ans == -1)printf("Volunteer cheated!\n");
		else if(ans == -2)printf("Bad magician!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
