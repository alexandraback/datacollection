#include <bits/stdc++.h>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v3.0

struct Data
{
	ll x, y, id;
	Data(){}
};

Data arr[15];
Data tmp[15];
ll n, m, szhull, k;
ll hull[50], ans[15];

inline ll cross(Data O, Data A, Data B)
{
	A.x -= O.x; B.x -= O.x;
	A.y -= O.y; B.y -= O.y;
	return (1LL * A.x * B.y) - (1LL * A.y * B.x);
}

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n;
	FORN (tc, 1, n)
	{
		cin >> n;
		FOR (i,0,n)
		{
			ans[i] = n - 1;
			cin >> arr[i].x >> arr[i].y;
			arr[i].id = i;
		}
		sort(arr, arr + n, [](const Data &A, const Data &B) {return A.x < B.x || (A.x == B.y && A.y < B.y);});

		FOR (mask, 0, 1 << n)
		{
			m = 0;
			FOR (i,0,n)
				if (mask & (1 << i))
					tmp[m++] = arr[i];

			bitset<15> ada;
			ada.reset();

			szhull = 0;
			FOR (i,0,m)
			{
				while (szhull >= 2 && cross(tmp[hull[szhull-2]], tmp[hull[szhull-1]], tmp[i]) > 0LL) --szhull;
				hull[szhull++] = i;
			}

			FOR (i,0,szhull)
				ada.set(tmp[hull[i]].id, 1);

			szhull = 0;
			FORD (i, m - 1, 0)
			{
				while (szhull >= 2 && cross(tmp[hull[szhull-2]], tmp[hull[szhull-1]], tmp[i]) > 0LL) --szhull;
				hull[szhull++] = i;
			}

			FOR (i,0,szhull)
				ada.set(tmp[hull[i]].id, 1);

			//cerr << szhull << endl;

			int tmpans = n - (int)__builtin_popcount(mask);

			FOR (i,0,n)
				if (mask & (1 << i))
				{
					if (ada.test(i))
					{
						ans[i] = min(ans[i], 1LL * tmpans);
					}
				}
		}

		cout << "Case #" << tc << ":\n";
		FOR (i,0,n) cout << ans[i] << "\n";
	}
	return 0;
}
