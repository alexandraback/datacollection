#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii > vii;

int abs(int a){
	return a>0?a:-a;
}

int main(){
	int t,l=1,i,j,k,p;
	scanf("%d",&t);
	while(l<=t){
		int n;
		int ans=0;
		int res=0,mx,mn;
		scanf("%d",&n);
		char arr[n+2][105];
		for(i=0;i<n;i++)
			scanf("%s",arr[i]);
		i=0;
		int cnt[105][105]={0};
		char val[105][105];
		for(j=0;j<n;j++){
			i=0;
			k=0;
			while(arr[j][i]){
				char id=arr[j][i];
				val[j][k]=id;
				while(arr[j][i] && arr[j][i]==id){
					cnt[j][k]++;
					i++;
				}
				k++;
			}
			val[j][k]='\0';
		}
		for(j=1;j<n;j++)
			if(strcmp(val[0],val[j]))
				break;
		if(j==n){
			for(i=0;i<k;i++){
				mx=0;
				for(j=0;j<n;j++){
					//cout << cnt[j][i]
					if(cnt[j][i]>mx)
						mx=cnt[j][i];
				}
				mn=100000000;
				for(p=1;p<=mx;p++){
					res=0;
					for(j=0;j<n;j++){
						res+=abs(p-cnt[j][i]);
					}
					if(res<mn)
						mn=res;
				}
				ans+=mn;
			}
			printf("Case #%d: %d\n",l,ans);
		}
		else
			printf("Case #%d: Fegla Won\n",l);
		l++;
	}
	return 0;
}