/*******************
  	Rahul Bhati
	CHARUSAT UNIVERSITY
	***********************/

#include <bits/stdc++.h>

using namespace std;

/* Time saving techniques :D */

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define ln              length()
#define rep(i,n)        for(int i=0;i<n;i++)
#define fu(i,a,n)       for(int i=a;i<=n;i++)
#define fd(i,n,a)       for(int i=n;i>=a;i--)
#define foreach(it,v)   for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define all(a)          a.begin(),a.end()
#define INF             (int)1e9
#define EPS             (1e-9)
#define INF_MAX         2147483647
#define INF_MIN         -2147483647
#define pi              acos(-1.0)
#define countones(s)    __builtin_popcount(s)
#define si(n)           scanf("%d",&n)
#define sll(n)          scanf("%lld",&n)
#define dbg(x)          { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y)       { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define mset(a, s)      memset(a, s, sizeof (a))
#define precout(a,b)    cout<<fixed << setprecision((b)) << (a)
#define FI              freopen("in.txt", "r", stdin);
#define FO              freopen("out.txt", "w", stdout);

int arr[1 << 18];
int R, C, N;

int calc(int i){
	int cnt=0;
	for (int r=0;r<R;r++){
		for (int c=0; c < C; c++){
			if (c>0 && (i & (1<<(r*C+c))) && (i&(1<<(r*C+c-1))))
                cnt++;
			if (r>0 && (i&(1<<(r*C+c))) && (i&(1<<(r*C+c-C))))
				cnt++;
		}
	}
	return cnt;
}


int main(){ FI FO
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>R>>C>>N;

		int ans= R*C*N*100;
		for (int i=1;i<(1<<(R*C));i++){
			arr[i] = arr[i - (i & -i)] + 1;
			if (arr[i] == N) ans = min(ans, calc(i));
		}
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
    cin.tie(0);
    return 0;
}

