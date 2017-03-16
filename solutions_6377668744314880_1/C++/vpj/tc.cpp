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

const double PI = atan2(0, -1);
const double EPS = 1e-9;

int N, M;
int x[10000];
int y[10000];
double a[10100];

void read(ifstream &fin) {
 fin >> N;
 M = N - 1;
 frr(i, N)
  fin >> x[i] >> y[i];
}

void calcAngles(int n) {

 for(int j = 0, k = 0; j < N; ++j, ++k) {
  if(n == j) {
   --k;
   continue;
  }
  a[k] = atan2(double(y[j] - y[n]), double(x[j] - x[n]));
 }

 sort(a, a + M);
//  frr(j, M)
//   cout << a[i][j] << '\t';
//  cout << endl;
}

int calcRemove() {
 int i = 0, j = 0;
 int ans = M;
 while(j < M) {
  if(a[j] - a[i] < PI - EPS) {
   if(j >= i)
    ans = min(ans, M - (j - i) - 1);
   ++j;
  } else if(a[j] - a[i] > PI + EPS) {
   if(i >= j) cout << "SHIT";
   ans = min(ans, min(M - (j - i), j - i - 1));
   ++i;
  } else {
   if(i >= j) cout << "SHIT";
   int k = 0;
   for(; j + k < M; ++k) {
    if(a[j + k] - a[i] > PI + EPS || a[j + k] - a[i] < PI - EPS)
     break;
   }
   --k;
   if(M - (j - i) - 1 - k < 0)
    cout << "OOP" << endl;
   ans = min(ans, min(M - (j - i) - 1 - k, j - i - 1));
   ++i;
  }
 }

// cout << ans << endl;
 return ans;
}

void proc(ofstream &fout) {
 fout << endl;
 //calcAngles(10);
 //cout << calcRemove() << endl;
 //return;
 frr(i, N) {
  calcAngles(i);
  fout << calcRemove() << endl;
 }
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
