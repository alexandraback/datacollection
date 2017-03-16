#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,B,N;
int M[1111];
int main(){
  cin >> T;
  for(int ttt=0;ttt<T;ttt++){
    cin >> B >> N;
    for(int i=0;i<B;i++) cin >> M[i];
    
    ll st = 0, ed = 100000000000000LL;
    ll ret=ed;
    while( st <= ed ){
      ll h = (st+ed)/2;
      ll count = 0;
      for(int i=0;i<B;i++){
	count += h/(ll)M[i];
	count++;
      }
      //     cout << " h = " << h << "  count = " << count << endl;
      if( count >= (ll)N ){
	ret = min ( ret, h );
	ed = h-1;
      }
      else st = h+1;
    }
    //cout << ret << endl;
    ll co = 0;
    for(int i=0;i<B;i++){
      co += ret/(ll)M[i];    
      if( ret%M[i] != 0 )
	co++;
    }
    for(int i=0;i<B;i++){
      if( ret%(ll)M[i] == 0 ){
	co++;
	if( co == (ll)N ){	
	  cout << "Case #" << ttt+1 << ": " << i+1 << endl;
	  break;
	}
      }
    }

  }
}
