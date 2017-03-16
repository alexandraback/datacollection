// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

// O(nlogn)
template <class T>
vector<T> intersect_vector(const vector<T>& a, const vector<T>& b)
{
	vector<T> sa(a), sb(b);
	sort(sa.begin(),sa.end());
	sort(sb.begin(),sb.end());

	vector <T> result;
	vector <T>::const_iterator ia=sa.begin(), ib=sb.begin();

	while (ia!=sa.end() && ib!=sb.end())
	{
		if (*ia<*ib) ++ia;
		else if (*ib<*ia) ++ib;
		else {
			result.push_back(*ia);
			++ia; ++ib;
		}
	}
	return result;
}

// O(nlogn)
template <class T>
set<T> intersect_set(const set<T>& a, const set<T>& b)
{
	set<T> sa(a), sb(b);

	set <T> result;
	set <T>::const_iterator ia=a.begin(), ib=b.begin();

	while (ia!=a.end() && ib!=b.end())
	{
		if (*ia<*ib) ++ia;
		else if (*ib<*ia) ++ib;
		else {
			result.insert(*ia);
			++ia; ++ib;
		}
	}
	return result;
}

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase <= T; ++testcase)
	 {
		 int row[2];
		 set <int> rowset[2];

		 for (int i = 0; i < 2; ++i)
		 {
			 scanf("%d",&row[i]);
			 for (int y = 0; y < 4; ++y)
			 {
				 for (int x = 0; x < 4; ++x)
				 {
					 int tmp;
					 scanf("%d",&tmp);
					 if(y+1==row[i])
					 {
						 rowset[i].insert(tmp);
					 }
				 }
			 }
		 }

		 set<int> ans = intersect_set(rowset[0],rowset[1]);
		 if(SZ(ans)==1)
		 {
			 printf("Case #%d: %d\n",testcase,*ans.begin());
		 }
		 else if(SZ(ans)>1)
		 {
			 printf("Case #%d: Bad magician!\n",testcase);
		 }
		 else
		 {
			 printf("Case #%d: Volunteer cheated!\n",testcase);
		 
		 }
	}

	return 0;
}
