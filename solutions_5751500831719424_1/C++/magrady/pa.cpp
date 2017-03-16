#include<stdio.h>
#include<algorithm>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define CASE(T) printf("Case #%d: \n",T)
#define eprintf(...) printf(__VA_ARGS__)
#else
#define CASE(T) printf("Case #%d: ",T)
#define eprintf(...) 
#endif
char str[101][101];
char t[101][101];
int slen[101],tlen[101];
int cnt[101][101];
int diff(int x,int y){
	return x>y?x-y:y-x;
}
int solve(){
	int i,j,k;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	for(i=0;i<n;i++)for(j=0;j<=100;j++)cnt[i][j]=0;
	for(i=0;i<n;i++){
		for(j=0;str[i][j];j++);
		slen[i]=j;
		tlen[i]=0;
		for(j=0;j<slen[i];j++){
			if(!j||str[i][j]!=str[i][j-1]){
				cnt[i][tlen[i]]=1;
				t[i][tlen[i]++]=str[i][j];
			} else {
				cnt[i][tlen[i]-1]++;
			}
		}
		t[i][tlen[i]]=0;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(t[i],t[j]))return -1;
		}
	}
	int m=tlen[0];
	int ret=0;
	for(i=0;i<m;i++){
		int miny=1000000;
		for(j=1;j<=100;j++){
			int y=0;
			for(k=0;k<n;k++){
				y+=diff(j,cnt[k][i]);
			}
			if(miny>y)miny=y;
			
		}
		ret+=miny;
	}
	return ret;	
	
}
int main(){
	int T,TN=1000000;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		CASE(T);
		int ans=solve();
		if(ans<0)puts("Fegla Won"); else printf("%d\n",ans);
	}
}
