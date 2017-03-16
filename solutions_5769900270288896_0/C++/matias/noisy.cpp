#include<iostream>
using namespace std;

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int R,C,N;
    cin>>R>>C>>N;
    int N2 = N;

    if (R>C) {
      int tmp = R;
      R = C;
      C = tmp;
    }
    int odd = (R%2) + (C%2);
    N-=(R*C+1)/2;
    int unhappy = 0;
    while(N>0) {
      if (R == 1) {
	unhappy = 2*N-odd+1;
	break;
      }
      int edge = R+C-2;
      if (odd != 2) {
	if (N==1) {
	  unhappy+=2;
	  break;
	}
	unhappy+=4;
	edge+=2;
	N-=2;
      }
      int ex = min(edge,N);
      unhappy+=3*ex;
      N-=ex;
      unhappy+=4*N;
    }
    int unhappy2 = R*(C-1) + C*(R-1);
    int cap = ((R-2)*(C-2)+1)/2;
    int mis = R*C-N2;
    if (mis<=cap) {
      unhappy2-=4*mis;
      if (unhappy2<unhappy) {
	unhappy = unhappy2;
      }
    }
    cout<<"Case #"<<t<<": "<<unhappy<<endl;
  }
}

