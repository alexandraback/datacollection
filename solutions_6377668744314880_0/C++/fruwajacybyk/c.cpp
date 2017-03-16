#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

#define max_n 100005

vector<PII> trees;
int best[3005];

lint ccw(int i,int j,int k){
  return (trees[j].st-trees[i].st)*1LL*(trees[k].nd-trees[i].nd)-
    (trees[j].nd-trees[i].nd)*1LL*(trees[k].st-trees[i].st);
}

void solve(){
  trees.clear();
  make(n);
  FOR(i,0,n){
    make2(x,y); trees.pb(mp(x,y));
  }
  if(n==1){
    printf("0\n");
    return ;
  }
  FOR(i,0,n) best[i] = n+1;
  FOR(i,0,n) FOR(j,i+1,n){
    int a1 = 0, a2 = 0;
    if(i==j) continue;
    FOR(k,0,n){
      lint u = ccw(i,j,k); 
      if(u>0) a1++;
      if(u<0) a2++;
    }
    a1 = min(a1,a2);
    best[i] = min(best[i],a1);
    best[j] = min(best[j],a1);
  }
  FOR(i,0,n) printf("%d\n",best[i]);

}

int main(){
  make(z);
  FOR(tt,1,z+1){
    printf("Case #%d:\n",tt);
    solve();
  }
}
