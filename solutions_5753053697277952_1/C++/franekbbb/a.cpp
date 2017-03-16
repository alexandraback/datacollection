#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define FOREACH(i,c) for( __typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const bool print=false;
const int MAXN=69;
int t[MAXN];

main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int n;scanf("%d",&n);
		int suma=0;
		FOR(i,1,n) {
			scanf("%d",&t[i]);
			suma+=t[i];
		}
		vector<PII> ans;
		while(suma>0){
			vector<PII> V;
			FOR(i,1,n) V.eb(t[i],i);
			sort(ALL(V)),reverse(ALL(V));
			//case 1: two biggest parties
			int b1=V[0].e2,b2=V[1].e2,b3=0;
			if(V.size()>2) b3=V[2].e2;
			if(suma>1&&t[b1]-1<=(suma-2)/2&&t[b2]-1<=(suma-2)/2&&t[b3]<=(suma-2)/2){
				t[b1]--,t[b2]--;suma-=2;
				ans.eb(b1,b2);
				continue;
			}
			
			//case 2: two from the biggest party
			if(t[b1]-2<=(suma-2)/2&&t[b2]<=(suma-2)/2){
				t[b1]-=2;suma-=2;
				ans.eb(b1,b1);
				continue;
			}
			
			
			//case 3: one from the biggest party
			if(t[b1]-1<=(suma-1)/2&&t[b2]<=(suma-1)/2){
				t[b1]--;suma--;
				ans.eb(b1,-1);
				continue;
			}
			puts("GOWNO");
		}
		printf("Case #%d: ",casenr);
		for(auto it:ans) {
			if(it.e2==-1) printf("%c ",'A'+it.e1-1);
			else printf("%c%c ",it.e1+'A'-1,it.e2+'A'-1);
		}puts("");
	}
}
			
			
			
