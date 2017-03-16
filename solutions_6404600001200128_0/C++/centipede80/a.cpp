#include <vector>
#include <string>
#include <iostream>
using namespace std;

int doit(vector<int> v) {
  int ret=0;
  int cur=v[0];
  for(int i=1;i<v.size();i++) {
    int now=v[i];
    if(now<cur) {
      ret+=cur-now;
    }
    cur=now;
  }
  return ret;
}

bool p(long long rate, vector<int> v, long long &ret) {
  long long cur=v[0];
  ret=0;
  for(int i=1;i<v.size();i++) {
    ret+=min(rate,cur);
    cur-=rate;
    if(cur>v[i]) return false;
    cur=v[i];
  }
  return true;
}

long long doit2(vector<int> v) {
  long long lo=0;
  long long hi=(1ll<<35)-1;
  long long val;
  while(lo<hi) {
    long long mid=lo+(hi-lo)/2;
    if(p(mid,v,val)) hi=mid;
    else lo=mid+1;
  }
  p(lo,v,val);
  return val;
}

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {    
    int n;
    cin >> n;
    vector<int> v;
    for(int j = 0; j < n; j++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    cout << "Case #" << (i+1) << ": " << doit(v) << " " << doit2(v) << endl;
  }
  return 0;
}
