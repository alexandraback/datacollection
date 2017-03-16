#include <bits/stdc++.h>
using namespace std;

int n, total, t;
priority_queue<pair<int, char> > s;
pair<int, char> p;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d:", tt);
    scanf("%d", &n);
    total = 0;
    for (int i = 0; i<n; i++) {
      int aux;
      scanf("%d", &aux);
      total+=aux;
      p = pair<int, char>(aux, i+'A');
      //printf("Teste: %c\n", p.second);
      s.push(p);
    }
    if (total%2) {
      p = s.top();
      s.pop();
      printf(" %c", p.second);
      p.first--;
      s.push(p);
      total--;
    }

    while(total) {
      p = s.top();
      s.pop();
      printf(" %c", p.second);
      p.first--;
      s.push(p);
      p = s.top();
      s.pop();
      printf("%c", p.second);
      p.first--;
      s.push(p);
      total-=2;
    }
    printf("\n");
  }
  return 0;
}
