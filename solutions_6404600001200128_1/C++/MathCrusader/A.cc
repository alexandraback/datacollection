#include <iostream>
using namespace std;

const int MAX_N = 10030;

void do_case(){
  int N,A[MAX_N];
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> A[i];
  
  int x = 0;
  for(int i=1;i<N;i++)
    if(A[i] < A[i-1])
      x += A[i-1] - A[i];
  
  int y = 0;
  for(int i=1;i<N;i++)
    if(A[i-1] - A[i] > y) y = A[i-1] - A[i];
  
  int ctr = 0;
  for(int i=1;i<N;i++)
    ctr += min(y,A[i-1]);
  
  cout << x << " " << ctr << endl;
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
