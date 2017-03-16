#include <iostream>
using namespace std;

const int MAX_N = 100030;

void do_case(){
  long long B,N,M[MAX_N];
  cin >> B >> N;
  
  long long sum = 0;
  
  for(int i=0;i<B;i++){
    cin >> M[i];
    sum += M[i];
  }
  sum *= N;
  long long lo = 0,hi = sum+1;
  while(hi - lo > 1){
    long long ctr = 0;
    long long mid = (hi + lo)/2;
    for(int i=0;i<B;i++)
      ctr += (mid + M[i] - 1) / M[i];
    if(ctr >= N) hi = mid;
    else lo = mid;
  }
  
  long long mid = hi,ctr=0;
  for(int i=0;i<B;i++)
    ctr += (mid + M[i] - 1) / M[i];
  //cout << mid << " " << ctr << " * ";
  if(ctr >= N){
    ctr = 0;
    mid--;
    for(int i=0;i<B;i++)
      ctr += (mid + M[i] - 1) / M[i];
  }
  
  //cout << mid << " " << ctr << " -- ";
  
  long long b = 0;
  for(;b<B;b++)
    if(mid % M[b] == 0){
      ctr++;
      if(ctr == N){
        cout << b+1 << endl;
        return;
      }
    }
  cout << "OH NO!" << endl;
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  return 0;
}
