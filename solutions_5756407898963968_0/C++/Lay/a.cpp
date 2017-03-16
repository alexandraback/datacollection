#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>

using namespace std;

int main()
{
	const string bad="Bad magician!";
	const string cheat="Volunteer cheated!";

	int T;
	cin>>T;

	for(int i=1;i<=T;i++){
		int r1,r2,c1[4][4],c2[4][4],res,count;
		cin>>r1;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++) cin>>c1[j][k];
		}
		cin>>r2;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++) cin>>c2[j][k];
		}
		res=-1; count=0;

		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(c1[r1-1][j]==c2[r2-1][k]){res=c1[r1-1][j]; count++;}
			}
		}

		if(count==1) printf("Case #%d: %d\n",i,res);
		else if(count>1) printf("Case #%d: %s\n",i,bad.c_str());
		else printf("Case #%d: %s\n",i,cheat.c_str());
	}

	return 0;
}
