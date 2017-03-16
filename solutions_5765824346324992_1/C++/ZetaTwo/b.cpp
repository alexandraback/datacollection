#include <iostream>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

// http://stackoverflow.com/questions/4229870/c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers

int gcd(int a, int b)
{
  for (;;)
  {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}

int lcm(int a, int b)
{
  int temp = gcd(a, b);

  return temp ? (a / temp * b) : 0;
}

typedef pair<long, size_t> barber;
struct cmp_pair {
  bool operator()(const barber& a, const barber& b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first > b.first;
  }
};

int main() {
  int T;
  int c = 1;
  cin >> T;
  while (T--) {
    int answer = 0;

    //Get test case
    int B;
    long N;
    cin >> B >> N;
    N--;
    vector<long> barbers(B);
    priority_queue<barber, vector<barber>, cmp_pair> line;
    for (size_t i = 0; i < B; i++)
    {
      cin >> barbers[i];
      line.push(make_pair(0, i));
    }

    long time_block = accumulate(barbers.begin(), barbers.end(), 1, lcm);
    long customers_per_block = 0;
    for (size_t i = 0; i < B; i++)
    {
      customers_per_block += time_block / barbers[i];
    }

    long place_in_block = N % customers_per_block;

    while (place_in_block > 0) {
      place_in_block--;
      answer++;
      barber next = line.top();
      line.pop();
      next.first += barbers[next.second];
      line.push(next);
    }

    //Output result
    cout << "Case #" << c++ << ": " << line.top().second+1 << endl;
  }


  return 0;
}