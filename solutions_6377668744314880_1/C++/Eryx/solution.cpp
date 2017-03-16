// working on the Pandora game console!

#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
//#include <iostream>
#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

int err;

#define LS <
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))

#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)

#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
#define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)

int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}

// template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
// template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
// template<class T> T operator >? (T x, T y) {return x>y?x:y;}
// template<class T> T operator <? (T x, T y) {return x<y?x:y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

/// ----

#define BUFSIZE 1000000
char buf[BUFSIZE];

#ifdef DEBUG
#define DEB(x) x
#else
#define DEB(x)
#endif

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int getNum() {
  string s = getLine();
  return atoi(s.c_str());
  }

vi parsevi(string s) {
  s = s + " ";
  int q = 0;
  bool minus = false;
  vi res;
  FOR(l,0, Size(s)) {
    if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
    else if(s[l] == '-') { minus = true; }
    else { q = q * 10 + s[l] - '0'; }
    }
  return res;
  }

int Tests, cnum;

//Eryx

// !FDI

int N, x[9999], y[9999];

pair<int,int> pt[9999];

bool atsort(pair<int,int> p1, pair<int,int> p2) {
  return atan2(p1.first, p1.second) <
    atan2(p2.first, p2.second);
  }

bool bad(pair<int,int> p1, pair<int,int> p2) {
  ll kros =
    ll(p1.first)*p2.second - ll(p2.first)*p1.second;
  //printf("k%lld\n", kros);
  if(kros<0) return true;
     
  return false;
  }

bool noc(pair<int,int> p1, pair<int,int> p2) {
  ll kros =
    ll(p1.first)*p2.second - ll(p2.first)*p1.second;
  //printf("k%lld\n", kros);
  if(kros) return true;
  if(kros == 0) {
    if(p1.first<0 && p2.first<0) return false;
    if(p1.first>0 && p2.first>0) return false;
    if(p1.second<0 && p2.second<0) return false;
    if(p1.second>0 && p2.second>0) return false;
    }
    
  return true;
  }

int solve(int a) {
  int u=0;
  FOR(t,0,N) if(t!=a) 
    pt[u++]=make_pair(x[t]-x[a], y[t]-y[a]);
  sort(pt, pt+u, atsort);
  FOR(z,0,u) pt[u+z] = pt[z];
  int firstok = 0;
  int best = 9999;
  //printf("u=%d\n", u);
  FOR(z,0,u) {
    while(firstok<z+u && (firstok <= z || bad(pt[z], pt[firstok]))) 
      firstok++;
    //printf("%d %d z %d %d\n", z, firstok, pt[z].first, pt[z].second);
    if(noc(pt[z], pt[firstok]) && firstok-z < best) 
      best = firstok-z;
    }
  if(best>7000) return 1;
  return best;
  }
  
void solveCase() {
  int res = 0;

  scanf("%d", &N);
  FOR(n,0,N) scanf("%d%d", x+n, y+n);
  
  // proceed
  
  printf("Case #%d:\n", cnum);
  FOR(n,0,N) printf("%d\n", solve(n)-1);
  }

int main() {

  if(0)
    Tests = 1;
  else if(1)
    err = scanf("%d", &Tests);
  else {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
