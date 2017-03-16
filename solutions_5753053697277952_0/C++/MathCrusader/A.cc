#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

pair<int,char> A[MAX_N];

void do_case(){
  int n; cin >> n;
  for(int i=0;i<n;i++) {
    cin >> A[i].first;
    A[i].second = char('A'+i);
  }
  sort(A,A+n);
  while(A[n-1].first > A[n-2].first){
    cout << " " << A[n-1].second;
    A[n-1].first--;
  }
  for(int i=0;i<n-2;i++)
    for(int j=0;j<A[i].first;j++)
      cout << " " << A[i].second;
  for(int i=0;i<A[n-1].first;i++)
    cout << " " << A[n-1].second << A[n-2].second;
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ":";
    do_case();
  }
  
  return 0;
}
