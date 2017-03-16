#include <iostream>
#include <algorithm>
using namespace std;

int T, N, R, C;


inline bool occupied(int x, int y, unsigned u) {
  int i = C*y+x;
  return (u&(1<<i)) != 0;
}


int main() {
  cin>>T;
  for (int t=1; t<=T; t++) {
    cin>>R>>C>>N;
    unsigned U = 1<<(R*C);
    
    int RES = 0x7fffffff;
    for (unsigned u=0; u<U; u++) {
      int res = 0;
      int bits = __builtin_popcount(u);
      if (bits != N) continue;
      for (int x=0; x+1<C; x++)
	for (int y=0; y<R; y++)
	  if (occupied(x, y, u) && occupied(x+1, y, u))
	    res++;

      for (int x=0; x<C; x++)
	for (int y=0; y+1<R; y++)
	  if (occupied(x, y, u) && occupied(x, y+1, u))
	    res++;
      
      RES = min(RES, res);
    }
    
    cout<<"Case #"<<t<<": "<<RES<<endl;
  }
}
