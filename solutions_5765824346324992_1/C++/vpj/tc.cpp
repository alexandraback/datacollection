#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define PRINT(x) cout << "DEBUG " << #x << " = " << x <<  endl;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

int B, N;
int a[1100];

void read(ifstream &fin) {
 fin >> B >> N;
 frr(i, B)
  fin >> a[i];
}

int which(ll M) {
 ll cutting = 0, open = 0;

 frr(i, B) {
  cutting += (M + a[i] - 1) / a[i];
  if(M % a[i] == 0) {
   open++;
  }
 }

 if(cutting < N && cutting + open >= N) {
  frr(i, B) {
   if(M % a[i] == 0) {
    if(cutting == N - 1)
     return i;
    cutting++;
   }
  }
  cout << "SHIT" << endl;
  return 0;
 } else if(cutting + open < N)
  return -1;
 else
  return -2;
}

void proc(ofstream &fout) {
 ll hi = 1LL << 60, lo = 0;
 //hi = 20;
 int ans = -1;
 while(lo <= hi) {
  ll m = (hi + lo) / 2;
  ans = which(m);
  if(ans == -2)
   hi = m - 1;
  else if(ans == -1)
   lo = m + 1;
  else
   break;
 }

 fout << ans + 1 << endl;
}

int main() {
 int i;
 int NT;

 ifstream fin("in");
 ofstream fout("out");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
