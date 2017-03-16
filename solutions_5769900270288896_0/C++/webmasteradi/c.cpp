#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>

using namespace std;


#define LL 				"%I64d"
#define sz(a) 			int((a).size())
#define pb 				push_back
#define mp 				make_pair
#define F				first
#define S				second
#define all(c) 			(c).begin(),(c).end()
#define tr(c,i) 		for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x) 	((c).find(x) != (c).end())
#define cpresent(c,x) 	(find(all(c),x) != (c).end()) 
#define INF				(int(1e9))
#define INFL			(int(1e18))
#define EPS				1e-12
const int inf = 100010;
const int MOD = 1000000007;
const double pi=acos(-1.0);


#define iabs(x)  ((x) > 0 ? (x) : -(x))

#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )

#define rep(i,a)	for(i=0;i<a;i++)
#define FOR(i,a,b)	for(i=a;i<b;i++)

long long gcd(long long a,long long b) {return (b==0?a:gcd(b,a%b));}
long long lcm(long long a,long long b) {return (a*(b/gcd(a,b)));}
int fx[]={0,0,1,-1};
int fy[]={-1,1,0,0};

long arr[1010];
int ti[1010];


int next_comb(int comb[], int k, int n) {
//	cout<<n<<endl;
	int i = k - 1;
	++comb[i];
	while ((i >= 0) && (comb[i] >= n - k + 1 + i)) {
		--i;
		++comb[i];
	}

	if (comb[0] > n - k) /* Combination (n-k, n-k+1, ..., n) reached */
		return 0; 
	
	for (i = i + 1; i < k; ++i)
		comb[i] = comb[i - 1] + 1;

	return 1;
}




int main() {
	ios_base::sync_with_stdio(0);
	long long i=0,j;
//	long long n,t,T;
	int T,t;
	long long y;
//	int ans=0;
	int flg;
	int n,r,c;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>T;
	
	int comb[17];
	FOR(t,1,T+1) {
		
		cin>>r>>c>>n;
		int chk[r+1][c+1];
		
		int k = n;
		n = r*c;
		int maxx;
		maxx = 99999;
		if(k) {
		for(i=0;i<k;i++) {
			comb[i] = i;
			
		}
//		printc(comb, k);
		 
		rep(i,r+1) {
			rep(j,c+1) {
				chk[i][j]=0;
				}
			}
		int ans;
		ans=0;
		
		
		rep(i,k) {
				chk[(comb[i])/c ][(comb[i])%c ] =1;
//				+comb[i]=1;
			}
//		rep(i,r+1) {
//			rep(j,c+1) {
//				cout<<chk[i][j]<<" ";
//				}
//			cout<<endl;
//			}
		rep(i,r) {
				rep(j,c) {
					if(chk[i][j] ==1) {
						if(chk[i+1][j]) {
							ans++;	
						}
						if(chk[i][j+1]) {
							ans++;	
						}
					}
				}
			}
			maxx = min(maxx,ans);
		while (next_comb(comb, k, n)) {
			ans=0;
//			printc(comb, k);
			rep(i,r+1) {
			rep(j,c+1) {
				chk[i][j]=0;
				}
			}
			rep(i,k) {
				chk[(comb[i])/c][(comb[i])%c ] =1;
			}
			rep(i,r) {
				rep(j,c) {
					if(chk[i][j] ==1) {
						if(chk[i+1][j]) {
							ans++;	
						}
						if(chk[i][j+1]) {
							ans++;	
						}
					}
				}
			}
			maxx = min(maxx,ans);
			
		}
//		printc(comb, k);
		
		}
		else {
			 maxx = 0;
		}
		cout<<"Case #"<<t<<": "<<maxx<<endl;
	}
	
	
	
	
	
	
	
	
	
	return 0;
}	
