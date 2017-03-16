#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;
typedef complex<double> point;

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

const int N = 30;
int n, sum;
int ar[N];

int main()
{
	ios_base::sync_with_stdio(false);

	int nt; cin >> nt;
	rep(ii, nt) {
		cin >> n;
		sum = 0;
		rep(i, n) {
			cin >> ar[i];
			sum += ar[i];
		}
	//	cerr << "sum " << sum << endl;
		cout << "Case #" << ii+1 << ":";
		while(sum) {
			int x1 = -1, x2 = -1, cnt = 0;
			rep(i, n) {
				if(x2==-1 || ar[x2] < ar[i])
					x2 = i;
				if(x1==-1 || (x2!=-1 && ar[x1] < ar[x2]))
					swap(x1, x2);
			}
			rep(i, n)
				if(ar[i]==ar[x1])
					++cnt;

			//cerr << "GO " << x1 << ' ' << x2 << endl;
			if(cnt>2 || ar[x1] != ar[x2]) {
				cout << ' ' << char('A' + x1);
				--ar[x1];
				--sum;
			}
			else {
				cout << ' ' << char('A' + x1) << char('A' + x2);
				--ar[x1];
				--ar[x2];
				sum -= 2;
			}
		}
		cout << endl;
	}

}



