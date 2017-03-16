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

int N;
string a[1000];
int s[1000];
int l[1000];

void read(ifstream &fin) {
 fin >> N;
 frr(i, N)
  fin >> a[i];
}

int countChar(char c, int start, string str) {
 int r = 0;
 for(int i = start; i < sz(str); ++i) {
  if(str[i] != c) break;
  r++;
 }

 return r;
}

void proc(ofstream &fout) {
 _cl(s);
 bool felga = false;
 int ans = 0;

 while(true) {
  if(s[0] >= sz(a[0])) {
   frr(i, N) if(s[i] < sz(a[i])) felga = true;
   break;
  }

  char c = a[0][s[0]];

  frr(i, N) {
   if(s[i] >= sz(a[i]) || a[i][s[i]] != c)
    felga = true;
  }
  if(felga) break;

  frr(i, N) {
   l[i] = countChar(c, s[i], a[i]);
   s[i] += l[i];
  }

  int m = 10000;
  frr(k, 100) {
   int d = 0;
   frr(i, N)
    d += abs(l[i] - k - 1);
   m = min(d, m);
  }
  ans += m;
 }

 if(felga)
  fout << "Fegla Won" << endl;
 else
  fout << ans << endl;
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
