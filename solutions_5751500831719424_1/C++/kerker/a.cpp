#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char s[105][105];
int len[105],where[105];

int ABS(int x){
	return x>=0 ? x : -x;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	scanf(" %d",&T);
	for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
		for(int n=0;n<N;n++){
			scanf(" %s",s[n]);
			len[n] = strlen(s[n]);
		}
		memset(where,0,sizeof(where));
		int re = 1, ans = 0;
		while(1){
			int end = 0;
			for(int i=0;i<N;i++)
				if(where[i]==len[i])
					end++;
			if(end>0){
				if(end!=N)	re = 0;
				break;
			}
			char ch = s[0][where[0]];
			vector <int> v;
			v.clear();
			for(int i=0;i<N;i++){
				int c = 0;
				if(s[i][where[i]]!=ch){
					re = 0;
					break;
				}
				for(;where[i]<len[i];where[i]++){
					if(s[i][where[i]]!=ch)	break;
					c++;
				}
				v.push_back(c);
			}
			int need = 100000000;
			for(int i=1;i<=100;i++){
				int cc = 0;
				for(int j=0;j<N;j++){
					cc += ABS(v[j]-i);
				}
				need = min(need,cc);
			}
			ans += need;
			if(re==0)	break;
		}
		if(re==0)	printf("Case #%d: Fegla Won\n",t+1);
		else	printf("Case #%d: %d\n",t+1,ans);
	}
    
    return 0;
}