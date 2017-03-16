#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int grid1[4][4], grid2[4][4];

void solveCase(int t) {
	int ans1,ans2;
	cin>>ans1;
	ans1--;
	for (int i=0;i<4;++i) {
		for (int j=0;j<4;++j) {
			cin>>grid1[i][j];
		}
	}
	cin>>ans2;
	ans2--;
	for (int i=0;i<4;++i) {
		for (int j=0;j<4;++j) {
			cin>>grid2[i][j];
		}
	}
	int colans=0;
	int ans=-1;
	for (int i=0;i<4;++i) {
		for (int j=0;j<4;++j){
			if (grid1[ans1][i] == grid2[ans2][j]) {
				colans++;
				ans=grid1[ans1][i];
			}
		}
	}
	if (colans == 0) {
		printf("Case #%d: Volunteer cheated!\n",t+1);
	} else if (colans > 1) {
		printf("Case #%d: Bad magician!\n",t+1);
	} else {
		printf("Case #%d: %d\n",t+1,ans);
	}
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;++i) {
		solveCase(i);
	}
	return 0;
}