#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int st[200];
string s[200];
int n;

void gao() {
	string u,w;
	int i,j,k,mid,ans=0,sum;
	u="";
	for (j=0;j<s[1].size();j++) 
		if (!j || s[1][j]!=s[1][j-1]) u+=s[1][j];
	for (i=1;i<=n;i++) {
		w="";
		for (j=0;j<s[i].size();j++) 
			if (!j || s[i][j]!=s[i][j-1]) w+=s[i][j];
		if (u!=w) {
			puts("Fegla Won");
			return;
		}
	}
	memset(st,0,sizeof(st));
	for (i=0;i<u.size();i++) {
		vector<int> a;
		for (k=1;k<=n;k++) {
			for (j=st[k];;j++) 
				if (j==s[k].size() || s[k][j]!=u[i]) break;
			a.push_back(j-st[k]);
			st[k]=j;
		}
		sort(a.begin(),a.end());
		mid=a[n/2];
		sum=0;
		for (k=0;k<a.size();k++) sum+=abs(a[k]-mid);
		ans+=sum;
	}
	printf("%d\n",ans);
}

int main() {
	int tt,te,i;
	char tmp[200];
	scanf("%d",&tt);
	for (te=1;te<=tt;te++) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%s",tmp);
			s[i]=tmp;
		}
		printf("Case #%d: ",te);
		gao();
	}
}
