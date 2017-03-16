#include <iostream>

using namespace std;

int T,R,C,N;

int occupied(int S,int i,int j) {
  return S >> (i*C+j) & 1;
};

int main() {
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> R >> C >> N;
    int answer = (R-1)*C+R*(C-1);
    for (int S=0; S < 1<<R*C; S++) {
      int occ = 0;      
      for (int S0=S; S0>0; S0>>=1) 
	if (S0 & 1) occ++;
      if (occ == N) {
	int solution = 0;
	for (int r=0; r<R; r++)
	  for (int c=0; c<C-1; c++)
	    if (occupied(S,r,c) && occupied(S,r,c+1)) solution ++;
	for (int r=0; r<R-1; r++)
	  for (int c=0; c<C; c++)
	    if (occupied(S,r,c) && occupied(S,r+1,c)) solution ++;
	answer = min(answer,solution);
      };
    };
    cout << "Case #" << t << ": " << answer << endl;
  };
};
