#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

unsigned long long method1(const vector<int>& V){
  unsigned long long ret = 0;
  for (size_t i = 1; i < V.size(); ++i)
    if (V[i] < V[i-1])
      ret += V[i-1] - V[i];
  return ret;
}

unsigned long long method2(const vector<int>& V){
  unsigned long long ret = 0;
  int maxdrop = 0;
  for (size_t i = 1; i < V.size(); ++i)
    if (V[i-1] - V[i] > maxdrop)
      maxdrop = V[i-1] - V[i];
  for (size_t i = 0; i < V.size() - 1; ++i)
    ret += min(V[i], maxdrop);
  return ret;
}

int main(){
  int T; cin >> T;
  for (size_t i = 1; i <= T; ++i){
    int N; cin >> N;
    vector<int> V(N);
    for (size_t j = 0; j < N; ++j)
      cin >> V[j];
    
    cout << "Case #" << i << ": " << method1(V) << " " << method2(V) << endl;
  }
}
