#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
void checkmax(int&a, int b) { if (b>a) a=b; }
int M[1010], B, N;
priority_queue<pair<long long, int>> Q;
void init()
{
  while(!Q.empty())
  {
    Q.pop();
  }
  cin >> B >> N;
  for(int i=1; i<=B; ++i)
  {
    cin >> M[i];
  }
}
int R[1010];
int work()
{
  /*
  return -Q.top().second;
  */
  double sum = 0;
  for(int i=1; i<=B; ++i)
  {
    sum += 1.0/M[i];
  }
  double scale = max(N-100, 0)/sum;
  int total = 0;
  for(int i=1; i<=B; ++i)
  {
    R[i] = scale/M[i];
    total += R[i];
  }
  /*
  for(int i=1; i<=B; ++i)
    printf("%d ", R[i]);
  printf("\n");
  */
  for(int i=1; i<=B; ++i)
    Q.push(make_pair(-1LL*R[i]*M[i], -i));
  //printf("%d %d\n", N, total);
  for(int i=total+1; i<N; ++i)
  {
    auto p = Q.top();
    Q.pop();
    p.first -= M[-p.second];
    Q.push(p);
    //printf("c%d with b%d\n", i, -p.second);
  }
  return -Q.top().second;
}
int main()
{
  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    init();
    printf("Case #%d: %d\n", i, work());
  }
}
