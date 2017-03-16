#include <vector>
#include <string>
#include <iostream>
using namespace std;

int DEBUG=0;

bool p(long long t, long long N, vector<int> &v) {
  long long ret=0;
  for(int i=0;i<v.size();i++) {
    ret+=t/v[i]+1;
  }
  if(ret<N) return false;
  return true;
}

int getBarber(long long t, long long N, vector<int> &v) {
  for(int i=0;i<v.size();i++) {
    N=N-((t-1)/v[i])-1;
  }
  for(int i=0;i<v.size();i++) {
    if(t%v[i]==0) {
      N--;
      if(N==0) return i+1;
    }
  }
  return -100;
}
    

int doit(vector<int> &v, long long N) {
  long long lo=0;
  long long hi=(1ll<<50)-1;
  long long val;
  while(lo<hi) {
    long long mid=lo+(hi-lo)/2;
    if(p(mid,N,v)) hi=mid;
    else lo=mid+1;
  }
  if(lo==0) {
    return N;
  }
  return getBarber(lo,N,v);
}

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {    
    int B,N;
    cin >> B >> N;
    vector<int> v;
    for(int j = 0; j < B; j++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    cout << "Case #" << (i+1) << ": " << doit(v,N) << endl;
  }
  return 0;
}
