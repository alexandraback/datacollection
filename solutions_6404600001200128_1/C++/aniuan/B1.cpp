#include<iostream>
using namespace std;
const int maxN=1010;
int a[maxN],n;
int main(){
	int kase,T,i,m,ans,s;
	freopen("A-large-2.in","r",stdin);
	freopen("A-large-2.out","w",stdout);
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		
		ans=0; m=0;
		for(i=1;i<n;i++){
			if(a[i]<a[i-1]) ans+=a[i-1]-a[i];
			if(a[i-1]-a[i]>m) m=a[i-1]-a[i];
		}
		s=0;
		for(i=0;i<n-1;i++)
			if(a[i]>=m) s+=m;
			else s+=a[i];
		printf("Case #%d: %d %d\n",kase,ans,s);
	}
	return 0;
}
