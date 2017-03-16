#include<stdio.h>
#include<vector>
using namespace std;
int f[4][4];
int s[4][4];
vector<int> ans;
int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		ans.clear();
		int x,y;
		int i,j;
		scanf("%d",&x);
		for(i=0;i<4;i++)for(j=0;j<4;j++)scanf("%d",&f[i][j]);
		scanf("%d",&y);
		for(i=0;i<4;i++)for(j=0;j<4;j++)scanf("%d",&s[i][j]);
		x--;y--;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(f[x][i]==s[y][j])ans.push_back(f[x][i]);
			}
		}
		printf("Case #%d: ",di+1);
		if(ans.size()>1)printf("Bad magician!");
		else if(ans.size()==0)printf("Volunteer cheated!");
		else printf("%d",ans[0]);
		puts("");
	}
	return 0;
}
