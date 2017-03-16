//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

//typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

//defines-general
#define to(a) __typeof(a)
#define all(vec)  vec.begin(),vec.end()
#define fill(a,val)  memset(a,val,sizeof(a))

//defines-iteration
#define repi(i,a,b) for(__typeof(b) i = a;i<b;i++)
#define repii(i,a,b) for(__typeof(b) i = a;i<=b;i++)
#define repr(i,b,a) for(__typeof(b) i = b;i>a;i--)
#define repri(i,b,a) for(__typeof(b) i = b;i>=a;i--)
#define tr(vec,it)  for(__typeof(vec.begin())  it = vec.begin();it!=vec.end();++it)



//defines-pair
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

// my own
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define slll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define fastio   std::ios_base::sync_with_stdio(false)


using namespace std;

int getAns(int r,int c,int n)
{
	vi V(r*c,0);
	for (int i = 0; i < n; ++i) {
		V[i]=1;
	}
	sort(V.begin(),V.end());
	int ans = INT_MAX;

	do{
		int M[r][c];
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				M[i][j] = V[i*c+j];

			}
		}

		int cnt=0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if(M[i][j]==0)
					continue;
				if((i+1<r)&&(M[i+1][j]==1))
					cnt++;
				if((j+1<c)&&(M[i][j+1]==1))
					cnt++;
			}
		}
		ans = min(ans,cnt);
	}while(next_permutation(V.begin(),V.end()));
	return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for (int i = 1; i <= T; i++) {
		int N,R,C;
		cin>>R>>C>>N;
		int ans = getAns(R,C,N);
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
