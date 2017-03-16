#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc,caso;
int A[10005], B[10005];

int main()
{
	cin >> tc;
	while(tc--)
	{
		int r,c; cin >> r >> c;
		int n; cin >> n;
		int pa = 0, pb = 0;
		f(i,0,r) f(j,0,c)
		{
			int neig = 0;
			if (i+1 < r) neig++;
			if (i) neig++;
			if (j) neig++;
			if (j+1 < c) neig++;

			if ( (i+j)&1 ) A[pa++] = neig;
			else B[pb++] = neig;
		}
		int tam = r*c + 1;
		f(i,pa,tam) A[i] = 0;
		f(i,pb,tam) B[i] = 0;
		sort(A, A + tam);
		sort(B, B + tam);
		f(i,1,tam) A[i] += A[i-1];
		f(i,1,tam) B[i] += B[i-1];
		f(i,0,tam) mini(A[i], B[i]);
//		adebug(A,r*c);


		printf("Case #%d: ", ++caso);
		cout << A[n] << endl;
	}
}

