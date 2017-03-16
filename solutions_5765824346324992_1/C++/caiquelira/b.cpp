#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1100
typedef long long lint;

int n, b, m[MAX];

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 0; t < teste; t++) {
    scanf ("%d %d", &b, &n);
    for (int i = 0; i < b; i++) 
      scanf ("%d", &m[i]);
    if (b >= n) {
      printf ("Case #%d: %d\n", t + 1, n);
      continue;
    }
    lint bigM = m[0];
    for (int i = 0; i < b; i++) 
      bigM = max (bigM, (lint)m[i]);
    lint begin = 0, end = (n + 1)*(bigM + 1);
    while (begin < end - 1) {
      lint mid = (begin + end)/2;
      lint f = 0;
      for (int i = 0; i < b; i++) {
	lint aux = (mid/m[i]) + 1;
	//printf ("somando aux = %lld\n", aux);
	f += aux;
      }
      //printf ("b = %lld, e = %lld, mid = %lld, f = %lld\n", begin, end, mid, f);
      if (f < n) 
	begin = mid;
      else 
	end = mid;
    }
    lint time = end;
    lint aux = 0;
    for (int i = 0; i < b; i++) 
      aux += (time/m[i]) + 1;
    //printf ("n = %d, aux = %lld, time = %lld\n", n, aux, time);
    for (int i = 0; i < b; i++) 
      n -= ((time - 1)/m[i]) + 1;
    //printf ("n = %d\n", n);
    lint ret = -1;
    for (int i = 0; i < b; i++) {
      if (time%m[i] != 0)
	continue;
      if (n == 1) {
	ret = i + 1;
	break;
      }
      else
	n--;
    }
    printf ("Case #%d: %d\n", t + 1, ret);
  }
  return 0;
}
