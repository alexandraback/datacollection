#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<iterator>
#include<stack>
#include<queue>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

int main() {
	int T,t,n,m,i,j,a[1100],l,r,mid,ans;
	cin>>T;
	for (t=1;t<=T;t++) {
		cin>>n;
		for (i=0;i<n;i++)
		scanf("%d",a+i);
		printf("Case #%d: ",t);
		ans=0;
		for (i=0;i<n;) {
			for (j=i+1;(j<n && a[j]<=a[j-1]);j++);
			ans+=a[i]-a[j-1];
			i=j;
		}
		printf("%d ",ans);
		l=0;
		r=10000;
		while (l<r) {
			mid=(l+r)/2;
			for (i=1;i<n;i++)
			if (a[i-1]-mid>a[i])
			break;
			if (i<n)
			l=mid+1;
			else r=mid;
		}
		ans=0;
		for (i=1;i<n;i++)
		ans+=min(a[i-1],l);
		printf("%d\n",ans);
	}
    return 0;
}
