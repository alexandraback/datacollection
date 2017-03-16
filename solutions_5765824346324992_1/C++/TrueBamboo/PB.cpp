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
	long long n,b,a[1100],i,j,l,r,m,s;
	int x,T,t;
	cin>>T;
	for (t=1;t<=T;t++) {
		cin>>b>>n;
		for (i=0;i<b;i++) {
			scanf("%d",&x);
			a[i]=x;
		}
		if (n<=b)
		cout<<"Case #"<<t<<": "<<n<<endl;
		else {
			l=0;
			r=10000000000000000LL;
			while (l<r) {
				m=(l+r)/2;
				s=0;
				for (i=0;(i<b && s<n);i++)
				s+=m/a[i]+1;
				if (s<n)
				l=m+1;
				else r=m;
			}
			s=0;
			for (i=0;i<b;i++)
			s+=(l-1)/a[i]+1;
			for (i=0;i<b;i++) {
				if (l%a[i]==0)
				s++;
				if (s==n)
				break;
			}
			cout<<"Case #"<<t<<": "<<i+1<<endl;
		}
	}
    return 0;
}
