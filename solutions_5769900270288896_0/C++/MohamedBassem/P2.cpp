#include <bits/stdc++.h>

using namespace std;

int r,c,n;

int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  int t;
  cin >> t;
  int tc =1;
  while(t--){
    cin >> r >> c >> n;
    int area = r*c;
    int ans = (1<<30);
    for(int mask = 0;mask<(1<<area);mask++){
      int num = __builtin_popcount(mask);
      if( num != n ) continue;
      int dx[] = {1,0};
      int dy[] = {0,1};
      int val = 0;
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          if( (mask & ( 1<<(i*c + j))) == 0 )
            continue;
          for(int k=0;k<2;k++){
            int newi = i+dx[k];
            int newj = j+dy[k];
            if( newi < 0 || newi >= r || newj < 0 || newj >= c ) continue;
            val += ( (mask & (1<<(newi*c + newj) )) != 0 );
          }
        }
      }
      ans = min(ans,val);
    }
    cout << "Case #" << tc++ << ": " << ans << endl;
  }
  
}
