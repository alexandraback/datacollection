#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

const long long INFM = 100001LL;
const long long INFN = 1000000001LL;
const long long INF = INFM*INFN;

int B, N;
int M[1009];

long long value(long long t)
{
  long long v = 0;
  for (int i = 0; i < B; ++i)
    v += t/M[i]+1;
  return v;
}

long long bisect(long long l, long long r)
{
  if (l == r)
    return l;
  long long m = (l+r)/2;
  long long v = value(m);
  if (v < N)
    return bisect(m+1, r);
  return bisect(l, m);
}

int solve()
{
  cin >> B >> N;
  for (int i = 0; i < B; ++i) {
    cin >> M[i];
  }
  long long t = bisect(0, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  int c = 0;
  for (int i = 0; i < B; ++i) {
    int bc = (t-1)/M[i]+1;
    q.push(make_pair(bc*M[i], i));
    c += bc;
  }
  for (int i = c+1; i < N; ++i) {
    int t, b;
    std::tie(t, b) = q.top();
    q.pop();
    q.push(make_pair(t+M[b], b));
  }
  return q.top().second;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
    cout << "Case #" << i << ": " << solve()+1 << endl;
  return 0;
}
