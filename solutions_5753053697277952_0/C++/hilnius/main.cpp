#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

char nth_letter(int n)
{
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}

int main() {
    //freopen("x.in", "r", stdin);

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);

  int T, t; cin >> T;

  F1(t,T) {
    //cerr << tt << endl;
    int P, p, tc = 0;
    std::vector<int> parties;
    cin >> P;
    F0(i,P) {
      cin >> p;
      parties.push_back(p);
      tc += p;
    }

    std::vector<string> plan;
    int c = tc;
    while (c != 0) {
      int p1 = -1, p2 = -1, mp1 = 0, mp2 = 0;
      F0(j, P) {
        if (parties[j] > mp1) {
          mp1 = parties[j];
          p1 = j;
        } else {
          if (parties[j] > mp2) {
            mp2 = parties[j];
            p2 = j;
          }
        }
      }
      parties[p1] = parties[p1] - 1;
      c--;
      bool canRemove = true;
      F0(j, P) {
        if (parties[j] > (int)(c / 2)) {
          canRemove = false;
        }
      }
      if (canRemove) {
        char val[2];
        val[0] = nth_letter(p1);
        val[1] = '\0';
        plan.push_back(string(val));
      } else {
        parties[p2] = parties[p2] - 1;
        c--;
        char val[3];
        val[0] = nth_letter(p1);
        val[1] = nth_letter(p2);
        val[2] = '\0';
        plan.push_back(std::string(val));
      }
    }

    cout << "Case #" << t << ": ";
    F0(i, plan.size()) {
      cout << plan[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
