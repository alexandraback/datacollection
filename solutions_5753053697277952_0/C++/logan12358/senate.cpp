#include <cstdio>
#include <queue>
using namespace std;

int main() {
  int t; scanf("%d", &t);
  for(int _i=1; _i<=t; _i++) {
    printf("Case #%d: ", _i);
    int n; scanf("%d", &n);
    priority_queue<pair<int, char> > q;
    int t=0;
    for(int i=0; i<n; i++) {
      int x; scanf("%d", &x);
      t+=x;
      q.push(make_pair(x, 'A'+i));
    }
    while(!q.empty()) {
      int x = q.top().first;
      int p = q.top().second;
      q.pop();
      if(x>1) q.push(make_pair(x-1, p));
      printf("%c", p);
      t--;
      if(!q.empty()) {
        x = q.top().first;
        p = q.top().second;
        q.pop();
        t--;
        if(!q.empty() and q.top().first > t-q.top().first) {
          t++;
          q.push(make_pair(x, p));
        } else {
          if(x>1) q.push(make_pair(x-1, p));
          printf("%c", p);
        }
      }
      printf(" ");
    }
    printf("\n");
  }
}
