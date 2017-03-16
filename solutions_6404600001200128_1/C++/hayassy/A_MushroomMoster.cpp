#include <iostream>
#include <string>
using namespace std;

int min(int a, int b){
  return a<b ? a : b;
}

int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int N;
    int ms[10000]={};
    cin >> N; cin.ignore();
    for(int j=0; j<N; j++){
      cin >> ms[j];
    } cin.ignore();
    //
    int count1 = 0;
    int maxd = 0;
    // 1
    for(int j=0; j<N-1; j++){
      int d = ms[j] - ms[j+1];
      if(d>0){
        count1 += d;
        if(d >= maxd){
          maxd = d;
        }
      }
    }
    // 2
    int count2 = 0;
    for(int j=0; j<N-1; j++){
      count2 += min(ms[j], maxd);
    }

    cout << "Case #" << i+1 << ": " << count1 << " " << count2 << endl;
  }

  return 0;
}
