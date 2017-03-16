#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <set>
#include <cassert>
#include <ctime>
#define MOD (int)1073741824
#define eps 1e-12
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define sz(a) a.size()
#define loop(i, n) for(int (i) = 0; (i) < (n) ; ++ (i))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>  
typedef long long ll;
typedef long double ld;

using namespace std;

/*@Sergey_Miller*/


void solve() {
  ll n;
  set <pll> p;
  cin >> n;
  ll sum = 0;
  loop(i,n) {
    int x;
    cin >> x;
    p.insert(mp(x,i));
    sum += x;
  }

  vector <pll> ans;

  while(!p.empty()) {
    // cout << p.size() << endl;
    pll t1,t2;
    auto it = p.end();
    --it;
    t1 =*it;
    if(p.size() > 1) {
    --it;
    t2 = *it;
    } 

    if(t2.first <= (sum - 1)/2) {
      ans.pb(mp(t1.second,-1));
      p.erase(t1);
      --t1.first;
      --sum;
      if(t1.first)
        p.insert(t1);
    } else {
      ans.pb(mp(t1.second,t2.second));
      p.erase(t1);
      p.erase(t2);
      --t1.first;
      --t2.first;
      sum -= 2;
      if(t1.first)
        p.insert(t1);
      if(t2.first) 
        p.insert(t2);
    }
  }

  loop(i,sz(ans)) {
     cout << char('A' + ans[i].first);

    if(ans[i].second != -1) {
      cout << char('A' + ans[i].second);
    }
    cout << " ";
  }
  cout << endl;
}


int main () {
    ios::sync_with_stdio(false);
    // srand(time(NULL));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    loop(i,n) {
      cout << "Case #" << i + 1 << ": ";
    solve();
    }
}