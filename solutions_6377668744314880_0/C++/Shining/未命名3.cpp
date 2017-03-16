#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define rep(a,b,c) for(int a=b;a<=c;++a)
#define per(a,b,c) for(int a=b;a>=c;--a)
#define X first
#define Y second
#define PII pair<int,int>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

typedef long long ll;

int TT,T,n,sz,dl;
PII p[3333],sc[3333],cmin;
int ans[3333];
bool ok[3333];
vector<PII >::iterator it;

bool operator <(PII A,PII B){
	if	(A.Y<B.Y || (A.Y==B.Y && A.X<B.X))	return	1;
	else	return	0;
}

PII operator -(PII A,PII B){
	return	mp(A.X-B.X,A.Y-B.Y);
}

ll chaji(PII A,PII B){
	return	ll(A.X)*B.Y-ll(A.Y)*B.X;
}

bool cmp(PII A,PII B){
	if	(A.X==0 && A.Y==0)	return	0;
	if	(B.X==0 && B.Y==0)	return	1;
	if	(A.X==0)
		if	(B.X==0)	return	A.Y<B.Y;
		else	return	1;
	else
		if	(B.X==0)	return	0;
		else 	return	1.0*A.Y/A.X>1.0*B.Y/B.X;
}

void check(int sit){
	PII cmin;cmin.X=cmin.Y=1e7;dl=0;
	rep(i,1,n)	if	((sit>>(i-1))&1)	ok[i]=1;else	ok[i]=0,dl++;
	rep(i,1,n)	if	(ok[i] && cmin>p[i])	cmin=p[i];
	rep(i,1,n)	rep(j,i+1,n)
		if	(cmp(p[i]-cmin,p[j]-cmin))	swap(p[i],p[j]),swap(ok[i],ok[j]);
	vector<PII > cur;cur.clear();sz=0;
	rep(i,1,n)
		if	(ok[i]){
			while	(sz>=2 && chaji(p[i]-cur[sz-2],cur[sz-1]-cur[sz-2])>0){
				it=cur.end();it--;sz--;
				cur.erase(it);
			}
			cur.pb(p[i]);sz++;
		}
	rep(i,1,n)	rep(j,0,sz-1)
		if	(sc[i]==cur[j])	ans[i]=min(ans[i],dl);
}

int main(){
	//freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%d",&TT);
	rep(T,1,TT){
		scanf("%d",&n);
		rep(i,1,n){
			scanf("%d%d",&p[i].X,&p[i].Y);
			sc[i]=p[i];
		}
		
		rep(i,1,n)	ans[i]=n;
		per(i,(1<<n)-1,0)	
			check(i);
		printf("Case #%d:\n",T);
		rep(i,1,n)	printf("%d\n",ans[i]);
	}
}

