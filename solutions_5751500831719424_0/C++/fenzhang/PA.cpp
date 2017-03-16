#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long int lnt;
typedef double dou;

int n;
char s[1514][1514];
char a[1514];
#include<vector>
vector<int>b[1514];
void sol(int uuu){
	scanf("%d",&n);
	int t=0;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;s[0][i];i++){
		if(i==0||s[0][i]!=s[0][i-1]){
			a[t++]=s[0][i];
		}
	}
	int flag=1;
	for(int i=0;i<n;i++){
		int j=0;
		int tt=0;
		for(;s[i][j];tt++){
			int k=j;
			for(;s[i][j]==s[i][k];j++);
			if(tt>=t||s[i][k]!=a[tt]){
				flag=0;
				break;
			}
			b[tt].push_back(j-k);
		}
		if(tt<t){
			flag=0;
		}
		if(flag==0){
			break;
		}
	}
	printf("Case #%d: ",uuu);
	if(flag==0){
		puts("Fegla Won");
	}
	else{
		int ans=0;
		for(int i=0;i<t;i++){
			sort(b[i].begin(),b[i].end());
			int tn=(int)b[i].size();
			for(int j=0;j<tn;j++){
				ans+=abs(b[i][j]-b[i][tn/2]);
			}
		}
		printf("%d\n",ans);
	}
	for(int i=0;i<t;i++){
		b[i].clear();
	}
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("pa_s.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)sol(ti);
	return 0;
}

