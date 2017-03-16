#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int r,c,n;
queue<ii> q;
set<ii> s;
int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};
int main() {
	int tc;
	scanf("%d",&tc);
	for (int kk=0;kk<tc;kk++) {
		int cur=0;
		scanf("%d%d%d",&r,&c,&n);
		while(!q.empty()) q.pop();
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				if ((i+j)%2==1-cur) {
					q.push(mp(i,j));
				}
			}
		}
		q.push(mp(0,0));
		if ((r-1+c-1)%2==cur) q.push(mp(r-1,c-1));
		if ((c-1)%2==cur) q.push(mp(0,c-1));
		if ((r-1)%2==cur) q.push(mp(r-1,0));
		for (int j=1;j<c-1;j++) {
			if (j%2==cur) q.push(mp(0,j));
			if ((r-1+j)%2==cur) q.push(mp(r-1,j));
		}
		for (int i=1;i<r-1;i++) {
			if (i%2==cur) q.push(mp(i,0));
			if ((i+c-1)%2==cur) q.push(mp(i,c-1));
		}
		for (int i=1;i<r-1;i++) {
			for (int j=1;j<c-1;j++) {
				if ((i+j)%2==cur) q.push(mp(i,j));
			}
		}
		s.clear();
		int ans=0;
		int k=0;
		while(k<n) {
			ii p=q.front();
			q.pop();
			if (s.count(p)) continue;
			for (int i=0;i<4;i++) {
				int x=p.first+dirx[i],y=p.second+diry[i];
				if (s.count(mp(x,y))) ans++;
			}
			s.insert(p);
			k++;
		}
		cur=1;
		while(!q.empty()) q.pop();
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				if ((i+j)%2==1-cur) {
					q.push(mp(i,j));
				}
			}
		}
		q.push(mp(0,0));
		if ((r-1+c-1)%2==cur) q.push(mp(r-1,c-1));
		if ((c-1)%2==cur) q.push(mp(0,c-1));
		if ((r-1)%2==cur) q.push(mp(r-1,0));
		for (int j=1;j<c-1;j++) {
			if (j%2==cur) q.push(mp(0,j));
			if ((r-1+j)%2==cur) q.push(mp(r-1,j));
		}
		for (int i=1;i<r-1;i++) {
			if (i%2==cur) q.push(mp(i,0));
			if ((i+c-1)%2==cur) q.push(mp(i,c-1));
		}
		for (int i=1;i<r-1;i++) {
			for (int j=1;j<c-1;j++) {
				if ((i+j)%2==cur) q.push(mp(i,j));
			}
		}
		s.clear();
		int ans2=0;
		k=0;
		while(k<n) {
			ii p=q.front();
			q.pop();
			if (s.count(p)) continue;
			for (int i=0;i<4;i++) {
				int x=p.first+dirx[i],y=p.second+diry[i];
				if (s.count(mp(x,y))) ans2++;
			}
			s.insert(p);
			k++;
		}
		printf("Case #%d: %d\n", kk+1,min(ans,ans2));
	}
}