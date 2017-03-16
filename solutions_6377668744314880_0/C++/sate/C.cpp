#include<bits/stdc++.h>
using namespace std;



typedef complex<double> P; //Point
typedef pair<P,P> L; //Line, Segment

const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);

namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
}

double dot(P a, P b){ return real(conj(a)*b); }
double cross(P a, P b){ return imag(conj(a)*b); }

double getAngle(P a,P b){
  return atan2(b.imag()-a.imag(),b.real()-a.real());
}
double getDeg(double rad){
  return 180.0/M_PI*rad;
}

typedef pair<double,P> Pa;

int T;
int N;
P p[3111];


int main(){
  cin >> T;
  for(int ttt=1;ttt<=T;ttt++){
    cin >> N;
    for(int i=0;i<N;i++){
      cin >> p[i].real() >> p[i].imag();
    }
    cout << "Case #" << ttt << ":" << endl;
    for(int i=0;i<N;i++){
      vector<double> ang;
      for(int j=0;j<N;j++){
	if( i == j ) continue;
	ang.push_back( getAngle(p[i],p[j]) );
      }
      sort(ang.begin(),ang.end());
      for(int i=0;i<N-1;i++) ang.push_back( ang[i]+2*M_PI );


      int res = N-1;
      int bid = 0;
      int cnt = 1;
      //      cout << "0 -> " << getDeg(ang[0]) << endl;

      for(int j=1;j<2*(N-1);j++){


	cnt++;
	while( abs(ang[j] - ang[bid]) > M_PI + EPS ){
	  bid++;
	  cnt--;
	} 
	//	cout << j << " -> " << getDeg(ang[j]) << " cnt = " << cnt <<endl;
	res = min(res,(N-1)-cnt);
      }
      cout << res << endl;
    }
  }
}
