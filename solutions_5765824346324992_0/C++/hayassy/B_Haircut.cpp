#include <iostream>
#include <string>
using namespace std;

int euclid(int a, int b){
  if(a<b) return euclid(b,a);
  if(b==0) return a;
  int nb = a%b;
  return euclid(b,nb);
}

int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int B;
    long long N;
    cin >> B >> N; cin.ignore();
    int ms[1000]={};
    int time[1000]={};
    int gcd;
    long long lcm=1;
    for(int j=0; j<B; j++){
      cin >> ms[j];
      //time[j] = ms[j];

      if(j==0){
        lcm = ms[0];
      } else {
        gcd = euclid(lcm, ms[j]);
        lcm = lcm * ms[j] / gcd;
      }
    } cin.ignore();

    if(N <= B){
      cout << "Case #" << i+1 << ": " << N << endl;
      continue;
    }
    int s=0;
    for(int j=0; j<B; j++){
      s += lcm / ms[j];
    }
    cerr << lcm << " " << gcd << endl;
    N %= s;
    if(N==0) N=s;
    cerr << N << " " << s << endl;

    int minid;
    for(int j=0; j<N; j++){
      minid = 0;
      for(int k=0; k<B; k++){
        if(time[k] < time[minid]){
          minid = k;
        }
      }
      int d = time[minid];
      time[minid] += ms[minid];
      if(d==0){
        continue;
      }
      for(int k=0; k<B; k++){
        time[k] -= d;
      }
    }
    cout << "Case #" << i+1 << ": " << minid+1 << endl;
  }
  return 0;
}
