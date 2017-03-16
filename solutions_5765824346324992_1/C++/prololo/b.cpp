#include <cstdio>
#include <assert.h>

typedef long int li;

void solve_problem(int case_num)
{
  int ans;
  li n;
  int b;
  int m[1000];
  int fastest = 1000000;
  li barbared = 0;
  li barbared_min;
  li t = 0;
  li t_min;
  li t_max;
  int res;
  assert(scanf("%d %ld", &b, &n) != EOF);
  for (int k = 0; k < b; k++){
    assert(scanf("%d", &m[k]) != EOF);
    if (m[k] < fastest){
      fastest = m[k];
    }
  }
  
  barbared_min = b;
  t_min = 0;
  t_max = fastest * n;
  t = (t_max + t_min) / 2;
  if (b < n){
    while ((t != t_max) && (t != t_min)){
      barbared = 0;
      for (int k = 0; k < b; k++){
        barbared += t / m[k] + 1;
      }
      if (barbared < n){
        t_min = t;
        barbared_min = barbared;
      } else {
        t_max = t;
      }
      t = (t_max + t_min) / 2;
    }
    res = n - barbared_min;
  } else {
    t_max = 0;
    res = n;
  }
  for (int k = 0; k < b; k++){
    if (t_max % m[k] == 0){
      if (res == 1) {
        ans = k + 1;
      }
      res = res - 1;
    }
  }

  printf("Case #%d: %d\n", case_num, ans);
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
