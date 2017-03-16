#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll __int64
using namespace std;
template<class T> T gcd(T x,T y){while(T t=x%y)x=y,y=t;return y;}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;

#define pmul(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define xmul(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))

#define FR(i,N) for(int i=0,__n__=(N);i<__n__;i++)
#define FRR(i,N) for(int i=(N)-1;i>=0;i--)
#define FRS(i,S,E) for(int i=S,__n__=E;i<=__n__;i++)
#define FRD(i,S,E) for(int i=S,__n__=E;i>=__n__;i--)
#define SZ(x) ((int)(x).size())
#define fill(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define lowbit(x) ((x)&(-(x)))

bool isdig(char x){return x>='0'&&x<='9';}
bool isup(char x){return x>='A'&&x<='Z';}
bool isdown(char x){return x>='a'&&x<='z';}
bool islet(char x){return isup(x)||isdown(x);}

void FILE_IO(string s = "")
{
	if(s == "")return;
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

//--------CODE----------
ll N, B;
ll sp[1005];
void get_data()
{  
	cin>>B>>N;
	FR(i, B)cin>>sp[i];
}  

bool ok(ll x)
{
	ll sum = 0;
	FR(i, B)
	{
		sum += (x + sp[i] - 1) / sp[i];
	}
	return sum < N;
}

bool ok2(ll x)
{
	ll sum = 0;
	FR(i, B)
	{
		sum += (x + sp[i] - 1) / sp[i];
	}
	return sum >= N;
}

void run()
{
	ll h = (ll)1000000000 * 100000, l = 0, mid;
	while(h > l)
	{
		mid = (h + l + 1) / 2;
		if (ok (mid))l = mid;
		else h = mid - 1;
	}
	ll t1 = h;
	ll need = 0;
	FR(i, B)need += (t1 + sp[i] - 1) / sp[i];
	need = N - need;
	
	ll h2 = (ll)1000000000 * 10000, l2 = 0, mid2;
	while(h2 > l2)
	{
		mid2 = (h2 + l2) / 2;
		if (ok2 (mid2))h2 = mid2;
		else l2 = mid2 + 1;
	}
	ll t2 = h2;
	
	FR(i, B)if((t2 + sp[i] - 1) / sp[i] > (t1 + sp[i] - 1) / sp[i])
	{
		need--;
		if(need == 0)
		{
		printf("%d\n", i + 1);
		break;
		}
	}
}
int main()
{
	FILE_IO("B-large");
	
	int t = 1;
	cin>>t;
	FR(i, t)	
	{
		get_data();
		printf("Case #%d: ", i + 1);
		run();
	}
	return 0;
}
// 3 5 7 11 13 17
// 1 2 3 4 5 6 1 2 1 3 1 2 4 5 3
