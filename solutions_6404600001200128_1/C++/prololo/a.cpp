#include <cstdio>
#include <assert.h>

void solve_problem(int case_num)
{
  int ans1 = 0;
  int ans2 = 0;
  int n;
  int m[1000];
  int d[1000];
  int min_d = 0;
  assert(scanf("%d", &n));
  for (int i = 0; i < n; i++){
    assert(scanf("%d", &m[i]));
  }
  
  for (int i = 0; i < n - 1; i++){
    d[i] = m[i + 1] - m[i];
    if (d[i] < 0){
      ans1 += -d[i];
    }
    if (d[i] < min_d){
      min_d = d[i];
    }
  }
  for (int i = 0; i < n - 1; i++){
    if (m[i] < -min_d){
      ans2 += m[i];
    } else {
      ans2 += -min_d;
    }
  }

  printf("Case #%d: %d %d\n", case_num, ans1, ans2);
  return ;
}

int main()
{
  int t;
  assert(scanf("%d", &t) != EOF);

  for (int i = 1; i <= t; i++){
    solve_problem(i);
  }

  return 0;
}
