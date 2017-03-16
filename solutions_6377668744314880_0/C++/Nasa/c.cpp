#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAX 3001
#define X first
#define Y second
const double PI=(2*acos(0.0f));
typedef long long Long;
typedef pair<int,int> PII;
PII p[1001],q[1001];
int n;
#define LEN(a,b) ((Long)(a)*(a)+(Long)(b)*(b))

bool parallel(const PII& a, const PII &b){
	if ((Long)a.X*b.X<0) return false;
	if (a.X==0 && b.X==0) return ((Long)a.Y*b.Y>0);
	return ((Long)a.X*b.Y == (Long) a.Y*b.X);
}

int cmp(const void *pa, const void* pb){
    const PII *a=(const PII*)pa;
    const PII *b=(const PII*)pb;
    if (!parallel(*a, *b)){
		double A=atan2((double)a->second,(double)a->first), B=atan2((double)b->second,(double)b->first);
		if (A<0) A+=2*PI;
		if (B<0) B+=2*PI;
		if (A<B) return -1;
		return 1;
	}
    if (LEN(a->first,a->second)<LEN(b->first,b->second)) return -1;
    //if (LEN(a->first,a->second)>LEN(b->first,b->second)) return 1;
    //if ((Long)a->first*b->second==(Long)a->second*b->first) return 0;
    //return 0;
	return 1;
}

Long dot(PII& a, PII &b){
	return (Long)a.X*b.X+(Long)a.Y*b.Y;
}

int main(){
	int n,t,u,i,j,k,ans;
	cin>>t; for (u=0; u<t; u++){
		cin>>n; for (i=0; i<n; i++) cin>>p[i].X>>p[i].Y;
		cout<<"Case #"<<(u+1)<<":"<<endl;
		for (i=0; i<n; i++){
			ans=0;
			if (n>3){
				for (j=k=0; j<n; j++) if (j!=i){ q[k].X=p[j].X-p[i].X; q[k].Y=p[j].Y-p[i].Y; k++; }
				ans=n-1;
				qsort(q,n-1,sizeof(q[0]),cmp);
				int adv=0;
				for (j=0, k=1; j<n-1; j++){
					PII nor=make_pair(-q[j].Y,q[j].X);
					adv=0;
					while (adv<n-2 && j<n-1 && parallel(q[j],q[(j+1)%(n-1)])){
						j++;
						adv++;
						if (k==j) k=(j+1)%(n-1);
					}
					if (j<n-1){
						//while (k!=j && parallel(q[j],q[k])) k=(k+1)%(n-1);
						while (k!=j && dot(q[k],nor)>0) k=(k+1)%(n-1);
						if (k>j) 
							ans=min(ans,k-j-1);
						else 
							ans=min(ans,k+n-1-j-1);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
