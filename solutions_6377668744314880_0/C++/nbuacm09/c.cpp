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
struct point { int ind;double x, y; };
bool mult(point sp, point ep, point op){
 return (sp.x - op.x) * (ep.y - op.y)
  > (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r){
 return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnta[], int n, point res[]){

 int i, len, k = 0, top = 1;
 point pnt[255];
 FR(i, n)pnt[i] = pnta[i];
 sort(pnt, pnt + n);
 if (n == 0) return 0; res[0] = pnt[0];
 if (n == 1) return 1; res[1] = pnt[1];
 if (n == 2) return 2; res[2] = pnt[2];
 for (i = 2; i < n; i++) {
  while (top && mult(pnt[i], res[top], res[top-1]))
   top--;
  res[++top] = pnt[i];
 }
 len = top; res[++top] = pnt[n - 2];
 for (i = n - 3; i >= 0; i--) {
  while (top!=len && mult(pnt[i], res[top],
   res[top-1])) top--;
  res[++top] = pnt[i];
 }
 return top;       // 返回凸包中点的个数
}
int N;
point pt[160];
int resa[160];
void get_data()
{  
	cin>>N;
	FR(i, N){cin>>pt[i].x>>pt[i].y;pt[i].ind = i;}
	FR(i, N)resa[i] = N - 1;	
}  
point tp[160], op[160];

void dfs(int ind, int n)
{
	if (ind == N)
	{
		int on = graham(tp, n, op);
		FR(i, on)
		{
			resa[op[i].ind] = min(resa[op[i].ind], N - n);
		}
		return;
	}
	return;
	dfs(ind + 1, n);
	tp[n] = pt[ind];
	dfs(ind + 1, n + 1);
}
void run()
{
	int nn = 1<<N;
	FR(i, nn)
	{
		int tn = 0;
		FR(j, N)
		{
			if((1<<j) & i)tp[tn++] = pt[j];
		}
		dfs(N, tn);
	}
	FR(i, N)printf("%d\n", resa[i]);
}
int main()
{
	FILE_IO("C-small-attempt1");
	
	int t = 1;
	cin>>t;
	FR(i, t)	
	{
		get_data();
		printf("Case #%d:\n", i + 1);
		run();
	}
	return 0;
}
