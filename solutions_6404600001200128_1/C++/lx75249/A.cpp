#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m[1010];
void init()
{
  cin >> n;
  for(int i=1; i<=n; ++i)
    cin >> m[i];
}
void checkmax(int&a, int b) { if (b>a) a=b; }
void work()
{
  int ans = 0;
  for(int i=1; i<n; ++i)
  {
    if (m[i] > m[i+1])
      ans += m[i]-m[i+1];
  }
  printf("%d ", ans);
  int rate = 0;
  for(int i=1; i<n; ++i)
    checkmax(rate, m[i]-m[i+1]);
  ans = 0;
  for(int i=1; i<n; ++i)
    ans += min(rate, m[i]);
  printf("%d\n", ans);
}
int main()
{
  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    init();
    printf("Case #%d: ", i);
    work();
  }
}
