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
int N, B;
int sp[1005];
void get_data()
{  
	cin>>B>>N;
	FR(i, B)cin>>sp[i];
}  
int q[10];
int get_mn()
{
	int r = 0;
	FR(i, B)
	{
		if(q[i] < q[r])r = i;
	}
	return r;
}

void run()
{
	int mn = sp[0];
	FR(i, B)mn = mn * sp[i] / gcd(mn, sp[i]);
	int tn = 0;
	FR(i, B)tn += mn / sp[i];
	N %= tn;
	if (N == 0)N = tn;
	
	fill(q, 0);
	int ind = 0;
	while(N--)
	{
		ind = get_mn();
		q[ind] += sp[ind];
	}
	printf("%d\n", ind + 1);
}
int main()
{
	FILE_IO("B-small-attempt0");
	
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
