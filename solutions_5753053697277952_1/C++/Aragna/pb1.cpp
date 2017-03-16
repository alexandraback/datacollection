#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main (){
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0 ; i < N ; ++i){
      cin >> P[i];
    }
    int max1, max2;
    if(P[1] > P[0]){
      max1 = 1;
      max2 = 0;
    }
    else{
      max1 = 0;
      max2 = 1;
    }
    for (int i = 2; i < N ; ++i){
      if (P[i] > P[max2]){
        if (P[i] > P[max1]){
          max2 = max1;
          max1 = i;
        }
        else{
          max2 = i;
        }
      }
    }
    cout << "Case #" << t << ": ";
    char A = 'A';
    while (P[max1] > P[max2]){
      cout << char('A'+max1) << ' ';
      P[max1]--;
    }
    // P[max1] = P[max2]
    for (int i = 0; i < N ; ++i){
      if (i != max1 && i != max2 ){
        while(P[i]>1){
          cout << char('A'+i) << char('A'+i) << ' ';
          P[i]+= -2;
        }
        if (P[i] == 1){
          cout << char('A'+i) << ' ';
        }
      }
    }
    while (P[max1] > 0){
      cout << char('A'+max1) << char('A'+max2) << ' ';
      P[max1]--;
    }
   
    cout << endl;
  }

}
