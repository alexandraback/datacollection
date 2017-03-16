/*************************************************************************

       Author:            palayutm
       Created Time :     Sun 08 May 2016 04:54:07 PM CST

       File Name:         a.cc
       Description:       new style, new life

 ************************************************************************/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define clr(x,y) memset(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define FOR(i,n,m) for (int i = n; i <= m; i ++)
#define ROF(i,n,m) for (int i = n; i >= m; i --)
#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

/**************************************END************************************/

int main (){
	int T;
	cin >> T;
	FOR (cas, 1, T){
		priority_queue<PII> q;
		int n;
		cin >> n;
		int sum = 0;
		FOR (i, 0, n-1){
			int t;
			cin >> t;
			q.push(MP (t, i));
			sum += t;
		}
		vector<string> ans;
		if (sum&1){
			PII x = q.top();
			q.pop();
			string s;
			s += x.second + 'A';
			ans.PB (s);
			q.push (MP(x.first-1, x.second));
		}
		while (true){
			PII x = q.top();
			q.pop();
			PII y = q.top();
			q.pop();
			if (x.first == 0){
				break;
			}
			if (x.first == y.first){
				string s;
				s += (char)(x.second + 'A');
				s += (char)(y.second + 'A');
				ans.PB (s);
				q.push(MP(x.first-1, x.second));
				q.push(MP(y.first-1, y.second));
			}else{
				string s;
				s += (char)(x.second + 'A');
				s += (char)(x.second + 'A');
				ans.PB (s);
				q.push(MP(x.first-2, x.second));
				q.push(y);
			}
		}
		printf ("Case #%d:", cas);
		FOR (i, 0, SIZE (ans)-1){
			cout << " " << ans[i];
		}
		cout << endl;
	}
}

