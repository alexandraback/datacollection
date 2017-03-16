#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, char> ic;
int T, tt;
int n;
priority_queue<ic> q;

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    q.push(ic(tmp, 'A' + i));
  }
  while(!q.empty()) {
    ic a = q.top(); q.pop();
    printf(" %c", a.second);
    if(a.first > 1)
      q.push(ic(a.first - 1, a.second));
    if(a.first == 1 && q.size() == 2)
      continue;
    ic b = q.top(); q.pop();
    printf("%c", b.second);
    if(b.first > 1)
      q.push(ic(b.first - 1, b.second));
    // scanf("%*s");
  }
  printf("\n");
}

int main() {
  scanf("%d", &T);
  for(tt = 1; tt <= T; tt++) {
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
