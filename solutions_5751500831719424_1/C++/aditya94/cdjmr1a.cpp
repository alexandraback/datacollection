#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
void rpt(int idx){
	int n,numb,median,tot=0,k;
	char curr;
	scanf("%d",&n);
	char a[102][102];
	int num[102],nxt[102];
	for(int i=0;i<n;i++){
		nxt[i]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	curr=a[0][0];
	while(curr!='\0'){
		//curr=str[0][nxt[0]];
		for(int j=0;j<n;j++){
			//numb=0;
			k=nxt[j];
			while(a[j][k]==curr) k++;
			num[j]=k-nxt[j];
			nxt[j]=nxt[j]+num[j];
		}
		sort(num,num+n);
		if(num[0]==0) {
			printf("Case #%d: Fegla Won\n",idx);
			return;
		}
		median=num[n/2];
		for(int x=0;x<n;x++){
			tot+=abs(median-num[x]);
		}
		curr=a[0][nxt[0]];
	}
	for(int i=0;i<n;i++){
		if(a[i][nxt[i]]!='\0'){
			printf("Case #%d: Fegla Won\n",idx);
			return;
		}
	}
	if(num[0]!=0)
	printf("Case #%d: %d\n",idx,tot);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		rpt(i);
	}
}