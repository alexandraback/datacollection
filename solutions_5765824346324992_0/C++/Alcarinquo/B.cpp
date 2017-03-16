#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
  if(a < b) return a;
  return b;
}

long long int gcd(long long int a, long long int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b) {
  return (a/gcd(a, b))*b;
}

int simula(int tempos[], int B, int N) {
  int ocupado[1010];
  for(int i = 0; i < B; i++)
    ocupado[i] = 0;

  while(N > 0) {
    for(int i = 0; i < B; i++) {
      if(ocupado[i] == tempos[i]){
        ocupado[i] = 0;
      }
      if(ocupado[i] == 0) {
        ocupado[i] = 1;
        N--;
      } else {
        ocupado[i]+= 1;
      }
      if(N == 0) return i+1;
    }
  }
  return 1;
}

int main() {
  int T;
  int caso = 1;
  int N;
  int B;
  int tempos[1010];
  cin >> T;

  while(caso <= T) {
    cin >> B >> N;
    long long int mmc = 1;

    for(int i = 0; i < B; i++) {
      cin >> tempos[i];
      mmc = lcm(mmc, tempos[i]);
    }

    //cout << "mmc: " << mmc << endl;
    int pessoas = 0;
    for(int i = 0; i < B; i++) {
      pessoas += mmc/tempos[i];
    }

    N = (N-1)%pessoas+1;
    //cout << "pessoas: " << pessoas << "   N: " << N << endl;

    int barber = simula(tempos, B, N);

    printf("Case #%d: %d\n", caso, barber);
    caso++;
  }

  return 0;
}

