#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,TC,n,p,len[102],num[102];
char s[102][102],ili[102];
int base[102];
bool test=false;
int main(){
	if(!test){
		freopen("A-small-attempt1.in","rb+",stdin);
		freopen("A1.out","wb+",stdout);
	}
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		printf("Case #%d: ",i);
		for(int j=1;j<=n;j++){
			scanf("\n%s",s[j]);
			len[j]=strlen(s[j]);
		}
		ili[0]=s[1][0],p=1;
		for(int j=1;j<len[1];j++){
			if(s[1][j]!=ili[p-1]){
				ili[p++]=s[1][j];
			}
		}
		memset(base,0,sizeof(base));
		int ans=0;
		for(int i=0;i<p;i++){
			for(int j=1;j<=n;j++){
				if(base[j]>=len[j] || s[j][base[j]]!=ili[i]){
					printf("Fegla Won\n");
					goto gg;
				}
				num[j]=0;
				while(base[j]<len[j] && s[j][base[j]]==ili[i]) base[j]++,num[j]++;
			}
			sort(num+1,num+n+1);
			int med=num[(n+1)/2];
			for(int j=1;j<=n;j++) ans=ans+abs(num[j]-med);
		}
		for(int j=1;j<=n;j++){
			if(base[j]!=len[j]){
				printf("Fegla Won\n");
				goto gg;
			}
		}
		printf("%d\n",ans);
		gg:;
	}
	return 0;
}
