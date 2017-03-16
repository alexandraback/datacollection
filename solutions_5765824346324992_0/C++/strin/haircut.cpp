#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int64 lcm(int64 a, int64 b)
{
  return (a*b)/gcd(a,b);
}

int64 lcm(const vector<int64>& nums) {
  int64 res = 1;
  for(int64 n : nums) {
    res = lcm(res, n);
  }
  return res;
}

int64 serve(const vector<int64>& nums, int64 cm) {
  int64 res = 0;
  for(int64 n : nums) {
    res += cm / n;
  } 
  return res;
}

struct Haircut {
  int64 time;
  int id;
  Haircut(int64 time, int id) 
    :time(time), id(id) {}
};

class CompareHair {
public:
  bool operator() (const Haircut& h1, const Haircut& h2) const {
    if(h1.time > h2.time) return true;
    else if(h1.time == h2.time and h1.id > h2.id) return true;
    else return false;
  }
};

size_t T;
int64 N;
int B;
vector<int64> M;
priority_queue<Haircut, vector<Haircut>, CompareHair> q;

int main(int argc, char* argv[]) {
  ifstream file_in(string(argv[1]) + ".in");
  ofstream file_out(string(argv[1]) + ".out");
  
  file_in >> T;

  for(size_t t = 1; t <= T; t++) {
    file_out << "Case #" << t << ": ";
    file_in >> B >> N;
    q = priority_queue<Haircut, vector<Haircut>, CompareHair>();
    M.resize(B, 0);
    for(int i = 0; i < B; i++) {
      file_in >> M[i];
    }
    int64 cm = lcm(M);
    int64 served = serve(M, cm);
    N %= served;
    if(N == 0) N = served;
    for(int i = 0; i < B; i++) {
      q.push(Haircut(0, i));
    }
    cout << "N " << N << endl;
    for(int64 i = 0; i < N-1; i++) {
      Haircut c = q.top();
      c.time += M[c.id];
      q.pop();
      q.push(c);
    }
    Haircut mine = q.top();
    file_out << mine.id + 1 << endl;
  }

  file_in.close();
  file_out.close();
  return 0;
}