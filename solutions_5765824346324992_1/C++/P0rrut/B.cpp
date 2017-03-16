#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
long long N;
int B;
const int mn = 1010;
long long ms[mn];
int main(){
  int T;
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> B >> N;
    FOR(i,B) cin >> ms[i];
    long long l,r;
    l = 0; r = 10000000000000000LL;
    while(l<r){
      long long mid = l+r+1>>1;
      long long tot = 0LL;
      FOR(i,B){
        tot+=(mid+ms[i]-1)/ms[i];
      }
      if(tot>=N)
        r = mid-1;
      else l = mid;
    }
    long long n = N;
    vector<pair<int,int> > ot(B);
   // cout << "l=" << l << endl;
    FOR(i,B){
      n-=(l+ms[i]-1)/ms[i];
      ot[i]=mp((l)%ms[i],i+1);
    }
    sort(ot.begin(),ot.end());
    cout << ot[n-1].second << endl;
    
  }
	return 0;
}
