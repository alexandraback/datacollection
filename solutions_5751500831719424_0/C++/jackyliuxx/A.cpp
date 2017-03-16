//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int ss[120][120][2];
char s[120][120];

int main () {
	int t,k=1;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++){
			int pp=0;
			ss[i][0][0]=s[i][0];
			ss[i][0][1]=1;
			ss[i][1][0]=0;
			for(j=1;s[i][j];j++){
				if(s[i][j]==ss[i][pp][0])
					ss[i][pp][1]++;
				else{
					pp++;
					ss[i][pp][0]=s[i][j];
					ss[i][pp][1]=1;
					ss[i][pp+1][0]=0;
				}
			}
		}
		int kg=1;
		for(i=0;kg>0;i++){
			kg=-1;
			for(j=0;j<n;j++){
				if(kg==-1)
					kg=ss[j][i][0];
				else if(kg!=ss[j][i][0]){
					kg=-1;
					break;
				}
			}
		}
		int ans=0;
		if(kg!=-1){
			for(i=0;ss[0][i][0];i++){
				vector<int> v;
				v.clear();
				for(j=0;j<n;j++)
					v.push_back(ss[j][i][1]);
				sort(v.begin(),v.end());
				int md=v[n/2];
				for(j=0;j<v.size();j++)
					ans+=abs(v[j]-md);
			}
		}

		printf("Case #%d: ",k++);
		if(kg==-1)
			puts("Fegla Won");
		else
			printf("%d\n",ans);
	}
}
