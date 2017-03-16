/*****************************************************************************************/
/*																		     			 */
/*  					Adarsh Pugalia 										 			 */
/*																			 			 */
/*****************************************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <limits.h>


/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
/* Data structure helpers. */ 
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())
 
/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */ 
#define max_size 100005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

void preprocess() {
}

vector<pair<ll, ll> > s;

void init() {
	s.clear();
}

void solve(int test_case) {
	init();
	cout<<"Case #"<<test_case<<": ";

	ll n;
	cin>>n;

	ll mini = -1;

	rep(i,0,n-1) {
		ll a;
		cin>>a;

		s.pb(mp(a, i));
		if(mini<0 || mini>a)
			mini = a;
	}

	sort(all(s));


	while(s[n-1].f>s[0].f) {
		// for(int i=0; i<n; i++) {
		// 	cout<<s[i].f<<":"<<(char)s[i].s+'A'<<" ";
		// }
		// cout<<endl;
		//cout<<"here\n";
		int pos = s.size()-1;
		for(; pos>0;) {
			if(s[pos].f==s[0].f)
				break;

			if(pos-1>0 && s[pos-1].f>s[0].f) {
				cout<<(char)(s[pos].s+'A')<<(char)(s[pos-1].s+'A')<<" ";
				s[pos].f--;
				s[pos-1].f--;
				pos -= 2;
			}
			else {
				cout<<(char)(s[pos].s+'A')<<" ";
				s[pos].f--;
				pos--;
			}
		}
	}

	int pos = 0;
	if(n&1) {
		while(s[0].f) {
			if(s[0].f>1) {
				cout<<(char)(s[0].s+'A')<<(char)(s[0].s+'A')<<" ";
				s[0].f -= 2;
			}
			else {
				cout<<(char)(s[0].s+'A')<<" ";
				s[0].f--;
			}

		}
		pos++;
	}

	while(pos<n) {
		while(s[pos].f>0) {
			cout<<(char)(s[pos].s+'A')<<(char)(s[pos+1].s+'A')<<" ";
			s[pos].f--;
			s[pos+1].f--;
		}

		pos += 2;
	}

	cout<<endl;
}

int main() {
	preprocess();
	int t = 1;
	sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
