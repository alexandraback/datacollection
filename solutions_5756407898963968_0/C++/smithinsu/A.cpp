#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int main() {
  int T,pos[32],r,temp;
  while(cin>>T) {
      int kase = 0;
    while(T--) {
      for(int i=1;i<=16;i++) {
        pos[i] = 0;
      }
      for(int t=0;t<2;t++) {
        cin>>r;r--;
        for(int j=0;j<4;j++) {
          for(int k=0;k<4;k++) {
            cin>>temp;
            if(r == j) {
              pos[temp]++;
            }
          }
        }
      }
      int ans = -1;
      for(int i=1;i<=16;i++) {
        if(pos[i] == 2) {
          if(ans == -1) {
            ans = i;
          } else {
            ans = 17;
          }
        }
      }

      printf("Case #%d: ",++kase);
      if(ans == -1) {
        printf("Volunteer cheated!\n");
      } else if(ans == 17) {
        printf("Bad magician!\n");
      } else {
        printf("%d\n",ans);
      }
    }
  }
  return 0;
}
