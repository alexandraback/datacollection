#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
char str[101][200];

int f(int *a, int n){
	int c[200];
	for(int i = 0;i<n;i++)c[i] = a[i];
	sort(c,c+n);
	int t = c[n/2];
	int ans = 0;
	for(int i = 0;i<n;i++)ans+=abs(t-c[i]);
	return ans;
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int casenum = 1;casenum<=t;++casenum){
		int n;	
		scanf("%d",&n);
		int from[200];
		int coun[200];
		for(int i = 0;i<n;i++)
			scanf("%s",str[i]);
		for(int i = 0;i<n;i++)
			from[i]  = coun[i] = 0;
		bool ok = 1;
		int ans = 0;
		bool ised = 0;
		while(1){
			char c = str[0][from[0]];
			for(int i  = 0;i<n;i++)
			{
				coun[i] = 0;
				int j;
				for(j = from[i] ;  str[i][j]  ;  j++){
					if(str[i][j]==c)coun[i]++;
					else
						break;
				}
				from[i] = j;
				if(coun[i] == 0){
					ok = 0;
					break;
				}
				if(from[i]==strlen(str[i]))ised = 1;
			}
			if(!ok){
				break;
			}
			ans+=f(coun,n);
			if(ised){
				break;
			}
		}
		if(!ok){
			printf("Case #%d: Fegla Won\n",casenum);
			continue;
		}
		if(ised){
			bool loca = 1;
			for(int i = 0;i<n;i++)if(from[i]!=strlen(str[i])){
				loca = 0;
				break;
			}
			if(loca==0){
				printf("Case #%d: Fegla Won\n",casenum);
				continue;
			}
		}
		printf("Case #%d: %d\n",casenum, ans);
	}
	return 0;
}