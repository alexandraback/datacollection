#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
  if(a < b) return a;
  return b;
}

int main() {
  int T;
  int caso = 1;
  int N;
  int cogumelos[1010];
  cin >> T;

  while(caso <= T) {
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> cogumelos[i];
    int met1 = 0;
    int maxim = 0;
    int aux;

    for(int i = 0; i < N-1; i++) {
      if(cogumelos[i+1] < cogumelos[i]){
        aux = cogumelos[i]-cogumelos[i+1];
        met1 += aux;
        if(maxim < aux) maxim = aux;
      }
    }

    int met2 = 0;
    for(int i = 0; i < N-1; i++) {
      met2 += min(cogumelos[i], maxim);
    }


    printf("Case #%d: %d %d\n", caso, met1, met2);
    caso++;
  }

  return 0;
}
