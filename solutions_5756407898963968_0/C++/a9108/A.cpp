#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

bool f[20];

void load(){
	int r;
	scanf("%d",&r);
	for (int i=1;i<=4;i++)
		for (int j=0;j<4;j++){
			int k;
			scanf("%d",&k);
			if (i!=r) f[k]=false;
		}
}

int main(int argc,char** argv){
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;z++){
		printf("Case #%d: ",z);
		memset(f,1,sizeof(f));
		load();
		load();
		vector<int> ans;
		ans.clear();
		for (int i=1;i<=16;i++)
			if (f[i]) ans.PB(i);
		if (ans.size()==0)
			printf("Volunteer cheated!\n");
		else if (ans.size()>1)
			printf("Bad magician!\n");
		else printf("%d\n",ans[0]);
	}
	return 0;
}