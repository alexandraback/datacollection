#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int N;
int i, j;
char s[100][200];
int p[100];
int l[100];

int main() {
  
  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
      scanf("%s", s[i]);
    
    for (i = 0; i < N; i++) {
      p[i] = 0; l[i] = 0;
    }
    
    bool ok = true;
    
    int sol = 0;
    
    while (1) {
      char c = s[0][p[0]];
      l[0] = 1;
      j = 1;      
      while (s[0][j] != 0 && s[0][j] == c) {
	j++;
	l[0]++;
      }      
      for (i = 0; i < N; i++) {
        if (s[i][p[i]] != c) {ok = false; break;}
        l[i] = 1;
        j = p[i] + 1;      
        while (s[i][j] != 0 && s[i][j] == c) {
	  j++;
	  l[i]++;
        }      	
      }
      
      if (!ok) break;
      
      //for (i = 0; i < N; i++) {
	//printf("%d %d\n", p[i], l[i]);
      //}
      
      int minv = 1000;
      int maxv = 0;
      for (i = 0; i < N; i++) {
	if (l[i] > maxv) maxv = l[i];
	if (l[i] < minv) minv = l[i];
      }
      
      int L;
      int mm = 1000000000;
      for (L = minv; L <= maxv; L++) {
	int cur = 0;
	for (i = 0; i < N; i++) {
	  if (l[i] >= L)
	    cur += (l[i] - L);
	  else
	    cur += (L - l[i]);
	}
	if (cur < mm) mm = cur;
      }      
      
      sol += mm;
      
      bool done = true;
      for (i = 0; i < N; i++) {
	p[i] += l[i];
	if (s[i][p[i]] != 0) done = false;
      }
      if (done) break;
    }
    
    if (ok)
      printf("Case #%d: %d\n", c, sol);
    else
      printf("Case #%d: Fegla Won\n", c);
  }
  return 0;
}