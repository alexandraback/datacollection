#include <stdio.h>

int barber[6];
int occupied[6];

int gcd(int a, int b) {
  while (1) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

/* only call if all barbers occupied */
int incrementTime(int B, int currTime) {
  int minTime = 200000, i, neededTime;
  for (i = 0; i < B; i++) {
    neededTime = barber[i] - (currTime % barber[i]);
    minTime = neededTime < minTime? neededTime : minTime;
  }
  for (i = 0; i < B; i++) {
    if (barber[i] - (currTime % barber[i]) == minTime) {
      occupied[i] ^= 1;
    }
  }
  return currTime + minTime;
}

int main() {
  int T, B, N, i, j, t, LCM, cutCycle, yourPlace, existsFree;
  FILE *fin = fopen("B-small.in", "r");
  FILE *fout = fopen("B-small.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    fscanf(fin, "%d %d\n", &B, &N);
    LCM = 1, cutCycle = 0, t = 0;
    for (j = 0; j < B; j++) { occupied[j] = 0; }
    for (j = 0; j < B; j++) {
      fscanf(fin, "%d ", &barber[j]);
      LCM = lcm(LCM, barber[j]);
    }
    for (j = 0; j < B; j++) {
      cutCycle += LCM/barber[j];
    }
    if (cutCycle < N) N = (N % cutCycle) + cutCycle;

    for (j = 0; j < B && N > 1; j++) {
      if (!occupied[j]) {
        N--;
        occupied[j] ^= 1;
      }
    }
    while (N > 1) {
      t = incrementTime(B, t);
      for (j = 0; j < B && N > 1; j++) {
        if (!occupied[j]) {
          N--;
          occupied[j] ^= 1;
        }
      }
    }

    existsFree = 0;
    for (j = 0; j < B; j++) {
      if (!occupied[j]) {
        existsFree = 1;
        yourPlace = j+1;
        break;
      }
    }

    if (!existsFree) {
      incrementTime(B, t);
      for (j = 0; j < B; j++) {
        if (!occupied[j]) {
          yourPlace = j+1;
          break;
        }
      }
    }

    fprintf(fout, "Case #%d: %d\n", i, yourPlace);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
