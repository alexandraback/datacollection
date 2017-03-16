#include <cstdio>
#include <algorithm>
#include <string>
#include <set>

char buf[102];

void tcase(int t) {
  int cnt = 0;
  std::set<std::string> st;

  int S; scanf("%d\n", &S);
  for (int i = 0; i < S; i++)
    fgets(buf, 100, stdin);

  int Q; scanf("%d\n", &Q);
  for (int i = 0; i < Q; i++) {
    fgets(buf, 100, stdin);
    if (!st.count(buf)) {
      if (st.size() == S - 1) {
        cnt++;
        st.clear();
      }
      st.insert(buf);
    }
  }

  printf("Case #%d: %d\n", t, cnt);
}

int main() {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; t++)
    tcase(t);
}
