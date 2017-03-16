#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

pair<int, int> a[30];
int sum;

int main() {
	freopen("senate_evacuation.in", "r", stdin);
	freopen("senate_evacuation.out", "w", stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int n;
		cin>>n;
		sum=0;
		for (int i=0;i<n;i++) {
			int x;
			cin>>x;
			a[i]=make_pair(x, i);
			sum+=x;
		}
		vector<string> ret;
		
		while (sum>0) {
			sort(a, a+n);
			int x=n-1, y=n-2;
			a[x]=make_pair(a[x].first - 1, a[x].second);
			string r="";
			r+=(char)('A'+a[x].second);
			sum--;
			bool ok = true;
			for (int i=0;i<n;i++)
				if (a[i].first * 2 > sum) ok = false;
			if (!ok) {
				a[y]=make_pair(a[y].first - 1, a[y].second);
				r+=(char)('A'+a[y].second);
				sum--;
			}
			ret.push_back(r);
		}
		cout<<"Case #"<<nt++<<":";
		for (int i=0;i<ret.size();i++)
			cout<<" "<<ret[i];
		cout<<endl;
	}
}
