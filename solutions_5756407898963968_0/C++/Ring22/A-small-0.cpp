#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include "set"
#include "iostream"

using namespace std;
typedef long long i64;

vector<int> read()
{
  vector<int> d(16,0);
  for(int i=0;i<16;i++)
    cin >> d[i];
  return d;
}

int main() {
  int T;
  cin >> T;
  for (int Ti = 1; Ti <= T; ++Ti) {
    int k1,k2;
    cin >> k1;
    vector<int> a = read();
    cin >> k2;
    vector<int> b = read();
    set<int> aa(a.begin()+(k1-1)*4,a.begin()+(k1)*4);
    set<int> bb(b.begin()+(k2-1)*4,b.begin()+(k2)*4);
    set<int> cc;
    for(set<int>::const_iterator i=aa.begin();i!=aa.end();i++)
    if( bb.count(*i) ) cc.insert(*i);

    cout << "Case #" << Ti << ": ";
    if( cc.size() == 0 ) cout << "Volunteer cheated!";
    else if( cc.size() == 1 ) cout <<  *cc.begin();
    else cout << "Bad magician!";
    cout << endl;
  }
  return 0;
}
