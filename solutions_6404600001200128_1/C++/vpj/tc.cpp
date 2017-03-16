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
int a[1100];

void read(ifstream &fin) {
 fin >> N;
 frr(i, N)
  fin >> a[i];
}

ll minEat() {
 ll eat = 0;
 frr(i, N - 1) {
  if(a[i] - a[i + 1] > 0)
   eat += a[i] - a[i + 1];
 }
 return eat;
}

ll constRate() {
 int mx = 0;
 frr(i, N - 1) {
  mx = max(mx, a[i] - a[i + 1]);
 }
 ll eat = 0;
 frr(i, N - 1) {
  eat += min(mx, a[i]);
 }
 return eat;
}

void proc(ofstream &fout) {
 fout << minEat() << ' ' << constRate() << endl;
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
