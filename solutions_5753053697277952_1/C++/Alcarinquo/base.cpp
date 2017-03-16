#include <bits/stdc++.h>

using namespace std;

int N, Tot;
vector<int> P;
vector<pair<int, int> > res;
bool solved;

void solve(int i) {
  if(solved) return;
  if(i == 0) {
    solved = true;
    for(int j = 0; j < res.size(); j++) {
      printf(" %c", res[j].first + 'A');
      if(res[j].second != -1)
        printf("%c", res[j].second + 'A');
    }
    return;
  }
  if(i == 1)
    return;

  int M1 = 0, M2 = 0, M3 = 0, i1, i2, i3;

  i1 = i2 = i3 = -1;
  for(int j = 0; j < N; j++) {
    if(P[j] > M1) {
      i3 = i2;
      M3 = M2;
      i2 = i1;
      M2 = M1;
      M1 = P[j];
      i1 = j;
    } else if(P[j] > M2) {
      i3 = i2;
      M3 = M2;
      i2 = j;
      M2 = P[j];
    } else if(P[j] > M3) {
      i3 = j;
      M3 = P[j];
    }
  }

  if(M1 >= 2 && 2*M2 <= i-2 && 2*(M1-2) <= i-2) {
    i -= 2;
    P[i1] -= 2;
    res.push_back(make_pair(i1, i1));
    solve(i);
    res.pop_back();
    P[i1] += 2;
    i += 2;
  }
  if(2*(M1-1) <= i-1 && 2*M2 <= i-1) {
    i -= 1;
    P[i1] -= 1;
    res.push_back(make_pair(i1, -1));
    solve(i);
    res.pop_back();
    P[i1] += 1;
    i += 1;
  }
  if(2*(M1-1) <= i-2 && 2*(M2-1) <= i-2 && (i3 == -1 || 2*M3 <= i-2)) {
    i -= 2;
    P[i1] -= 1;
    P[i2] -= 1;
    res.push_back(make_pair(i1, i2));
    solve(i);
    res.pop_back();
    P[i1] += 1;
    P[i2] += 1;
    i += 2;
  }

}

int main() {
  int T;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    Tot = 0;

    scanf("%d", &N);
    P.resize(N);

    for(int i = 0; i < N; i++) {
      scanf("%d", &P[i]);
      Tot += P[i];
    }

    solved = false;
    res.clear();

    printf("Case #%d:", caso);
    solve(Tot);

    printf("\n");
  }
  return 0;
}
