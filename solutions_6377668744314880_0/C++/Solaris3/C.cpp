#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pii pt;
const int inft = 1000000009;
const int MAXN = 1000006;//10^6

pii P[MAXN];
ll vec(pt a,pt b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
ll det(pt a,pt b,pt c){return vec(pii(b.x-a.x,b.y-a.y),pii(c.x-a.x,c.y-a.y));}

bool praword(pt X,pt Y,pt Z){return det(X,Y,Z)<0;} //gdy chcemy katy 180st. to <-eps

// zwraca otoczke w kierunku przeciwzegarowym, 
// kolejne wierzcholki wyniku nie sa wspolliniowe
// dziala tez na pii po zmianie w praword x->fi, y->se i pt->pii
// nie trzeba wtedy definiowac pt ani == ani <
vector<pair<pii,int> > otoczka(vector<pair<pii,int> > ab) {
//	printf("otoczka dla: ");tr(it,ab)printf("%d ",it->y);puts("");
	sort(ab.begin(),ab.end());
	int l=ab.size(),i,j,k;
	vector<pair<pt,int> > wyn(2*l+2);
	if (l<3) return ab;
	j=0;
	for(i=0;i<l;i++) {
		while (j-2>=0 && praword(wyn[j-2].x,wyn[j-1].x,ab[i].x)) j--;
		wyn[j++]=ab[i];
	}
	k=j;
	for(i=l-2;i>=0;i--) {
		while (j-1>=k && praword(wyn[j-2].x,wyn[j-1].x,ab[i].x)) j--;
		wyn[j++]=ab[i];
	}
	if (wyn[j-1]==wyn[0]) j--;
	return vector<pair<pt,int> >(wyn.begin(),wyn.begin()+j);
}
vi licz(vi A)
{
	vector<pair<pii,int> > B,C;
	tr(it,A)B.pb(make_pair(P[*it],*it));
	C=otoczka(B);   
	vi AN;
	tr(it,C)AN.pb(it->y);
	return AN;

}
void solve() {
	int n;
	scanf("%d",&n);
	fru(i,n)scanf("%d%d",&P[i].x,&P[i].y);
	vi ANS(n,0);
	fru(i,1<<n)if(i)
	{
		int a=__builtin_popcount(i);
//	printf("sprawdzam %d\n",i);
		vi K,A;
		fru(j,n)if(i&(1<<j))K.pb(j);
		A=licz(K);
		tr(it,A)ANS[*it]=max(ANS[*it],a);
	}
	fru(i,n)printf("%d\n",n-ANS[i]);
}

int main(){
	int t=1;scanf("%d",&t);
	fru(i,t)
	{
		printf("Case #%d:\n",i+1);
		solve();
	}
	return 0;
}

