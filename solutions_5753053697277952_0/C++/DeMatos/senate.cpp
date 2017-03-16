#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for(int test = 1; test <= t; test++) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i<n; i++) {
      scanf("%d", &p[i]);
      sum += p[i];
    }
    printf("Case #%d:", test);
    while(sum) {
      int maximum = 0;
      int nMaximum = 0;
      for(int i = 0; i<26; i++) {
        if(p[i] > maximum) {
          maximum = p[i];
          nMaximum = 1;
        }
        else if(p[i] == maximum) {
          nMaximum++;
        }
      }
      if(nMaximum == 2) {
        bool flag = false;
        for(int i = 0; i<26; i++) {
          if(p[i] == maximum) {
            if(!flag) printf(" ");
            printf("%c", i+'A');
            p[i]--;
            if(flag)
              break;
            flag = true;
          }
        }
        sum-=2;
      } else {
        for(int i = 0; i<26; i++) {
          if(p[i] == maximum) {
            printf(" %c", i+'A');
            p[i]--;
            break;
          }
        }
        sum--;

      }
    }
    printf("\n");
  }

  return 0;
}
