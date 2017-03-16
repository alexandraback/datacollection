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
int N;
const int mn = 1e4+10;
int ms[mn];
int main(){
  int T;
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> N;
    FOR(i,N) cin >> ms[i];
    int r1,r2;
    r1 = r2 = 0;
    FOR(i,N-1) {
      if(ms[i]>ms[i+1]) {
        r1+=-ms[i+1]+ms[i];
        r2 = max(r2,-ms[i+1]+ms[i]);
      }
    }
    int rr = 0;
    FOR(i,N-1){
       rr += min(r2,ms[i]);
    }
    cout << r1 << " " << rr << endl;
  }
  
  


	return 0;
}
