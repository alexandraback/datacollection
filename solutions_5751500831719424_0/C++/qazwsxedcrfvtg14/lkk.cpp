#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef pair<int,int> par;
typedef pair<par,int> pr;
char s[105][105];
char ss[105][105];
int ar[105][105];
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
			strcpy(ss[i],s[i]);
			ss[i][unique(ss[i],ss[i]+strlen(ss[i]))-ss[i]]=0;
			}
		int ok=1;
		for(int i=0;i<n;i++)
			if(strcmp(ss[0],ss[i]))ok=0;
		printf("Case #%d: ",T);
		if(!ok)
			puts("Fegla Won");
		else{
			int p=0;
			for(int i=0;i<n;i++){
				int len=strlen(s[i]);
				char now=s[i][0];
				int cnt=0;
				p=0;
				for(int j=0;j<len;j++){
					if(now==s[i][j])cnt++;
					else ar[p++][i]=cnt,cnt=1,now=s[i][j];
					}
				if(cnt)
					ar[p++][i]=cnt;
				}
			int ans=0;
			for(int i=0;i<p;i++){
				int tot=0,add=0x7fffffff;
				sort(ar[i],ar[i]+n);
				tot=ar[i][n/2];
				int sig=0;
				for(int j=0;j<n;j++){
					sig+=abs(tot-ar[i][j]);
					}
				add=min(add,sig);
				tot=ar[i][(n-1)/2];
				sig=0;
				for(int j=0;j<n;j++){
					sig+=abs(tot-ar[i][j]);
					}
				add=min(add,sig);
				ans+=add;
				}
			printf("%d\n",ans);
			}
		}
	return 0;
	}
